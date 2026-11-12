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
  // Value-initialization обязательна: часть экранов может быть не назначена.
  _screens = new FlprogOledScreen *[_screensSize]();
  if (!_screens) {_screensSize = 0;}
}

FlprogOledDisplay::~FlprogOledDisplay()
{
  delete[] _screens;  // Сами FlprogOledScreen не удаляем: они принадлежат проекту.
}

//=================================================================================================
//                                  2. ПРОВЕРКА ПЕРЕРИСОВКИ
//=================================================================================================
bool FlprogOledDisplay::isNeedRepaint()
{
  if (!_screensSize) {return false;}

  bool hasActiveScreen = false;
  bool hasChanges = _needsRepaint;

  for (uint16_t i = 0; i < _screensSize; i++)
  {
    if (!_screens[i]) {continue;}
    // Изменение активности важно даже для уже отключённого экрана.
    if (_screens[i]->isNeedRepaint()) {hasChanges = true;}
    if (_screens[i]->getIsActive()) {hasActiveScreen = true;}
  }

  // Любое изменение состава или активности требует собрать ПОЛНЫЙ кадр:
  // оставшиеся активные экраны должны быть перерисованы после очистки.
  if (hasChanges)
  {
    _isShow = hasActiveScreen;
    return true;
  }

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
  // В RT_HW_OLED передача может быть асинхронной (в том числе DMA).
  if (chip->_device.runDevice || chip->_device.sendInProgress) {return;}
  if (!isNeedRepaint()) {return;}

  // Сформировать новый framebuffer. Отправка начнется на следующем проходе.
  chip->_device.clear(0, 0);

  for (uint16_t i = 0; i < _screensSize; i++)
  {
    if (_screens[i]) {_screens[i]->displayOn(chip);}
  }

  _needsRepaint = false;
  chip->_device.runDevice = 1;
}

//=================================================================================================
//                                  6. ПОДКЛЮЧЕНИЕ ЭКРАНА
//=================================================================================================
void FlprogOledDisplay::setScreen(uint16_t index, FlprogOledScreen *screen)
{
  if (!_screensSize) {return;}
  if (index >= _screensSize) {return;}
  if (_screens[index] == screen) {return;}
  _screens[index] = screen;
  _needsRepaint = true;
  // nullptr теперь допустим для отсоединения экрана без оставления старого кадра.
  if (screen) {screen->setIsNeedRepaint();}
}
