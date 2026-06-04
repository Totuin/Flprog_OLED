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

void FlprogOledNumberValueWidget::setValue()
{
  RT_HW_Base.messSetVar(_message, _value, _mode);
}