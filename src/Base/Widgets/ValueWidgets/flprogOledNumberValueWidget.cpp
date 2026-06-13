#include "flprogOledNumberValueWidget.h"

FlprogOledNumberValueWidget::FlprogOledNumberValueWidget(uint8_t id, int16_t x0, int16_t y0, uint8_t scale, uint8_t style, uint32_t colorFigure, uint32_t colorBorders)
{
  initTextWidget(id, x0, y0, scale, style, colorFigure, colorBorders);

  _mode = FLPROG_OLED_UINTX_VALUE_MODE;
  setValue();
}

void FlprogOledNumberValueWidget::setValue(uint32_t value)
{
  if (_value == value)
  {
    return;
  }
  _isNeedRepaint = true;
  _value = value;
}

void FlprogOledNumberValueWidget::setVarType(uint8_t value)
{
  if (_varType == value)
  {
    return;
  }
  _isNeedRepaint = true;
  _varType = value;
}

void FlprogOledNumberValueWidget::setValue()
{
  if (_varType == FLPROG_OLED_NUNBER_UINT8_TYPE)
  {
    RT_HW_Base.messSetVar(_message, (uint8_t)_value, _mode);
  }
  if (_varType == FLPROG_OLED_NUNBER_INT8_TYPE)
  {
    RT_HW_Base.messSetVar(_message, (int8_t)_value, _mode);
  }
  if (_varType == FLPROG_OLED_NUNBER_UINT16_TYPE)
  {
    RT_HW_Base.messSetVar(_message, (uint16_t)_value, _mode);
  }
  if (_varType == FLPROG_OLED_NUNBER_INT16_TYPE)
  {
    RT_HW_Base.messSetVar(_message, (int16_t)_value, _mode);
  }
  if (_varType == FLPROG_OLED_NUNBER_UINT32_TYPE)
  {
    RT_HW_Base.messSetVar(_message, (uint32_t)_value, _mode);
  }
  if (_varType == FLPROG_OLED_NUNBER_INT32_TYPE)
  {
    RT_HW_Base.messSetVar(_message, (int32_t)_value, _mode);
  }
}

void FlprogOledNumberValueWidget::setTrueString(String value)
{
  if (_trueString.equals(value))
  {
    return;
  }
  _isNeedRepaint = true;
  _trueString = value;
}

void FlprogOledNumberValueWidget::setFalseString(String value)
{
  if (_falseString.equals(value))
  {
    return;
  }
  _isNeedRepaint = true;
  _falseString = value;
}