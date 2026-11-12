#include "flprogOledBooleanValueVidget.h"

FlprogOledBooleanValueWidget::FlprogOledBooleanValueWidget(uint8_t id, int16_t x0, int16_t y0, uint8_t scale, uint8_t style, uint32_t colorFigure, uint32_t colorBorders)
{
  initTextWidget(id, x0, y0, scale, style, colorFigure, colorBorders);

  _mode = FLPROG_OLED_NOT_CHANDGE_VALUE_MODE;
  privateSetValue();
}

void FlprogOledBooleanValueWidget::setValue(bool value)
{
  if (_value == value)
  {
    return;
  }
  _isNeedRepaint = true;
  _value = value;
}

void FlprogOledBooleanValueWidget::setTrueString(String value)
{
  if (_trueString.equals(value))
  {
    return;
  }
  _isNeedRepaint = true;
  _trueString = value;
}

void FlprogOledBooleanValueWidget::setFalseString(String value)
{
  if (_falseString.equals(value))
  {
    return;
  }
  _isNeedRepaint = true;
  _falseString = value;
}

void FlprogOledBooleanValueWidget::privateSetValue()
{
  if (_value)
  {
    RT_HW_Base.messSetVar(_message, _trueString, _mode);
  }
  else
  {
    RT_HW_Base.messSetVar(_message, _falseString, _mode);
  }
}