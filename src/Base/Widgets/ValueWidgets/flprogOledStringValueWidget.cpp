#include "flprogOledStringValueWidget.h"

FlprogOledStringValueWidget::FlprogOledStringValueWidget(uint8_t id, int16_t x0, int16_t y0, uint8_t scale, uint8_t style, uint32_t colorFigure, uint32_t colorBorders)
{
  initTextWidget(id, x0, y0, scale, style, colorFigure, colorBorders);
  _message.str = _value;
}

void FlprogOledStringValueWidget::setValue(String value)
{
  if (_value.equals(value))
  {
    return;
  }
  _isNeedRepaint = true;
  _value = value;
}

void FlprogOledStringValueWidget::setValue()
{
  RT_HW_Base.messSetVar(_message, _value, _mode);
}