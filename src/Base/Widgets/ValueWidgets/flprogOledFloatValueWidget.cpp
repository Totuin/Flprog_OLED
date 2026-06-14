#include "flprogOledFloatValueWidget.h"

FlprogOledFloatValueWidget::FlprogOledFloatValueWidget(uint8_t id, int16_t x0, int16_t y0, uint8_t scale, uint8_t style, uint32_t colorFigure, uint32_t colorBorders)
{
  initTextWidget(id, x0, y0, scale, style, colorFigure, colorBorders);

  _mode = FLPROG_OLED_FLOAT_2_VALUE_MODE;
  privateSetValue();
}

void FlprogOledFloatValueWidget::setValue(float value)
{
  if (_value == value)
  {
    return;
  }
  _isNeedRepaint = true;
  _value = value;
}

void FlprogOledFloatValueWidget::privateSetValue()
{
  RT_HW_Base.messSetVar(_message, _value, _mode);
}