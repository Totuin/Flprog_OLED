#include "flprogOledDisplay.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// FlprogOledDisplay              УПРАВЛЕНИЕ ЭКРАНАМИ И ВЫВОДОМ FRAMEBUFFER
//
// Правила:
//   - одно изменение виджета формирует один запрос перерисовки;
//   - _isShow хранит признак ранее отображенного активного экрана;
//   - дополнительная перерисовка выполняется только для однократной очистки,
//     когда отключен последний активный экран;
//   - во время передачи framebuffer его содержимое не изменяется.
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//=================================================================================================
//                                  1. СОЗДАНИЕ ДИСПЛЕЯ
//=================================================================================================
FlprogOledDisplay::FlprogOledDisplay(uint16_t screensSize)
{
  _screensSize = screensSize;
  if (!_screensSize) {return;}
  _screens = new FlprogOledScreen *[_screensSize];
}

//=================================================================================================
//                                  2. ПРОВЕРКА ПЕРЕРИСОВКИ
//=================================================================================================
bool FlprogOledDisplay::isNeedRepaint()
{
  if (!_screensSize) {return false;}

  bool hasActiveScreen = false;

  for (uint16_t i = 0; i < _screensSize; i++)
  {
    if (!_screens[i]) {continue;}
    if (!_screens[i]->getIsActive()) {continue;}

    hasActiveScreen = true;

    if (_screens[i]->isNeedRepaint())
    {
      _isShow = true;
      return true;
    }
  }

  // Последний активный экран отключен: очистить framebuffer один раз.
  if (!hasActiveScreen && _isShow)
  {
    _isShow = false;
    return true;
  }

  return false;
}

//=================================================================================================
//                                  3. ЗАПРОС ПОЛНОЙ ПЕРЕРИСОВКИ
//=================================================================================================
void FlprogOledDisplay::setIsNeedRepaint()
{
  if (!_screensSize) {return;}

  for (uint16_t i = 0; i < _screensSize; i++)
  {
    if (_screens[i]) {_screens[i]->setIsNeedRepaint();}
  }
}

//=================================================================================================
//                                  4. РАЗРЕШЕНИЕ РАБОТЫ ДИСПЛЕЯ
//=================================================================================================
void FlprogOledDisplay::setEn(bool value)
{
  if (_en == value) {return;}
  if (!_en) {setIsNeedRepaint();}
  _en = value;
}

//=================================================================================================
//                                  5. ОБСЛУЖИВАНИЕ ДИСПЛЕЯ
//=================================================================================================
void FlprogOledDisplay::displayOn(FlprogOledAbstractChip *chip)
{
  if (!chip) {return;}
  if (!_en) {return;}
  if (!_screensSize) {return;}
  if (!chip->getNum()) {return;}
  if (!RT_HW_oled.checkDev(chip->getNum())) {return;}

  // Завершить инициализацию и продолжить ранее начатую передачу.
  chip->_device.direct(1);
  chip->_device.sendDevice();

  // Framebuffer нельзя изменять до полного завершения передачи.
  if (chip->_device.runDevice) {return;}
  if (!isNeedRepaint()) {return;}

  // Сформировать новый framebuffer. Отправка начнется на следующем проходе.
  chip->_device.clear(0, 0);

  for (uint16_t i = 0; i < _screensSize; i++)
  {
    if (_screens[i]) {_screens[i]->displayOn(chip);}
  }

  chip->_device.runDevice = 1;
}

//=================================================================================================
//                                  6. ПОДКЛЮЧЕНИЕ ЭКРАНА
//=================================================================================================
void FlprogOledDisplay::setScreen(uint16_t index, FlprogOledScreen *screen)
{
  if (!_screensSize) {return;}
  if (index >= _screensSize) {return;}
  if (!screen) {return;}
  _screens[index] = screen;
}
