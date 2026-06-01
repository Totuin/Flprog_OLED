#include "flprogOledScreen.h"

FlprogOledScreen::FlprogOledScreen(uint16_t widgetsSize)
{
  setWidgetsSize(widgetsSize);
}

void FlprogOledScreen::setWidgetsSize(uint16_t widgetsSize)
{
  _widgetsSize = widgetsSize;

  if (_widgetsSize == 0)
  {
    return;
  }
  _widgets = new FlprogOledAbstractWidget *[_widgetsSize];
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
  _widgets[index] = widget;
}

void FlprogOledScreen::isActive(bool value)
{
  if (value == _isActive)
  {
    return;
  }
  if (!_isActive)
  {
    setIsNeedRepaint();
  }
  _isActive = value;
}

void FlprogOledScreen::displayOn(FlprogOledAbstractChip *chip)
{
  if (!_isActive)
  {
    return;
  }
  if (_widgetsSize == 0)
  {
    return;
  }
  for (uint16_t i = 0; i < _widgetsSize; i++)
  {
    if (_widgets[i] != 0)
    {
      _widgets[i]->displayOn(chip);
    }
  }
}

bool FlprogOledScreen::isNeedRepaint()
{
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
