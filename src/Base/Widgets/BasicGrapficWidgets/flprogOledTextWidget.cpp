#include "flprogOledTextWidget.h"

FlprogOledTextWidget::FlprogOledTextWidget(uint8_t id, int16_t x0, int16_t y0, String txt, uint8_t scale, uint8_t style, uint32_t colorFigure, uint32_t colorBorders)
{
  _id = id;
  _text = txt;
  _x0 = x0;
  _y0 = y0;
  _scale = scale;
  _style = style;
  _colorFigure = colorFigure;
  _colorBorders = colorBorders;
}

void FlprogOledTextWidget::setText(String text)
{
  if (_text.equals(text))
  {
    return;
  }
  _isNeedRepaint = true;
  _text = text;
}

void FlprogOledTextWidget::setScale(uint8_t scale)
{
  if (_scale == scale)
  {
    return;
  }
  _scale = scale;
  _isNeedRepaint = true;
}

void FlprogOledTextWidget::setStyle(uint8_t style)
{
  if (_style == style)
  {
    return;
  }
  _style = style;
  _isNeedRepaint = true;
}


void FlprogOledTextWidget::privateDisplayOn(FlprogOledAbstractChip *chip)
{
  chip->_device.drawString(_id, _x0, _y0, _text, _scale, _style, _colorFigure, _colorBorders);
}