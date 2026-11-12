#include "flprogOledScreen.h"

FlprogOledScreen::FlprogOledScreen(uint16_t widgetsSize)
{
  setWidgetsSize(widgetsSize);
}

FlprogOledScreen::~FlprogOledScreen()
{
  delete[] _widgets;
}

void FlprogOledScreen::setWidgetsSize(uint16_t widgetsSize)
{
  if (widgetsSize == _widgetsSize) {return;}
  if (!widgetsSize)
  {
    delete[] _widgets;
    _widgets = nullptr;
    _widgetsSize = 0;
    _needsRepaint = true;
    return;
  }

  // Новые слоты обязательно равны nullptr; старые указатели не удаляем.
  FlprogOledAbstractWidget **newWidgets = new FlprogOledAbstractWidget *[widgetsSize]();
  if (!newWidgets) {return;}
  uint16_t count = widgetsSize < _widgetsSize ? widgetsSize : _widgetsSize;
  for (uint16_t i = 0; i < count; ++i) {newWidgets[i] = _widgets[i];}
  delete[] _widgets;
  _widgets = newWidgets;
  _widgetsSize = widgetsSize;
  setIsNeedRepaint();
}

void FlprogOledScreen::setWidget(uint16_t index, FlprogOledAbstractWidget *widget)
{
  if (_widgetsSize == 0)
  {
    return;
  }
  if (index >= _widgetsSize)
  {
    return;
  }
  if (widget == 0)
  {
    return;
  }
  if (_widgets[index] == widget) {return;}
  _widgets[index] = widget;
  // Подмена виджета требует нового полного кадра.
  widget->setIsNeedRepaint();
  _needsRepaint = true;
}

void FlprogOledScreen::isActive(bool value)
{
  if (value == _isActive)
  {
    return;
  }
  _isActive = value;
  // Важно обновлять кадр и при выключении одного из НЕСКОЛЬКИХ экранов.
  _needsRepaint = true;
  if (value) {setIsNeedRepaint();}
}

void FlprogOledScreen::displayOn(FlprogOledAbstractChip *chip)
{
  if (!_isActive)
  {
    _needsRepaint = false;
    return;
  }
  for (uint16_t i = 0; i < _widgetsSize; i++)
  {
    if (_widgets[i]) {_widgets[i]->displayOn(chip);}
  }
  _needsRepaint = false;
}

bool FlprogOledScreen::isNeedRepaint()
{
  if (_needsRepaint) {return true;}
  if (!_isActive)
  {
    return false;
  }
  if (_widgetsSize == 0)
  {
    return false;
  }
  for (uint16_t i = 0; i < _widgetsSize; i++)
  {
    if (_widgets[i] != 0)
    {
      if (_widgets[i]->isNeedRepaint())
      {
        return true;
      }
    }
  }
  return false;
}

void FlprogOledScreen::setIsNeedRepaint()
{
  _needsRepaint = true;
  if (_widgetsSize == 0)
  {
    return;
  }
  for (uint16_t i = 0; i < _widgetsSize; i++)
  {
    if (_widgets[i] != 0)
    {
      _widgets[i]->setIsNeedRepaint();
    }
  }
}
