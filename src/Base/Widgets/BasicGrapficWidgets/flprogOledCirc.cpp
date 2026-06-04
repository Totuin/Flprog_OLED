#include "flprogOledCirc.h"

FlprogOledCircletWidget::FlprogOledCircletWidget(uint8_t id, int16_t x0, int16_t y0, int16_t r, uint32_t colorFigure, uint32_t colorBorders, uint8_t thickness)
{
  _id = id;
  _x0 = x0;
  _y0 = y0;
  _r = r;
  _colorFigure = colorFigure;
  _colorBorders = colorBorders;
  _thickness = thickness;
}


void FlprogOledCircletWidget::setRadius(int16_t r)
{
  if (_r == r)
  {
    return;
  }
  _isNeedRepaint = true;
  _r = r;
}


void FlprogOledCircletWidget::setThickness(uint8_t thickness)
{
  if (_thickness == thickness)
  {
    return;
  }
  _isNeedRepaint = true;
  _thickness = thickness;
}

void FlprogOledCircletWidget::privateDisplayOn(FlprogOledAbstractChip *chip)
{
  chip->_device.circle(_id, _x0, _y0, _r, _colorFigure, _colorBorders, _thickness);
}