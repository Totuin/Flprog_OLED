#include "flprogOledIconWidget.h"

FlprogOledIconWidget::FlprogOledIconWidget(uint8_t id, int16_t x, int16_t y, int16_t w, int16_t h, int16_t index, uint8_t scale, uint8_t colorFigure, uint8_t colorBorders)
{
  _id = id;
  _x0 = x;
  _y0 = y;
  _w = w;
  _index = index;
  _h = h;
  _scale = scale;
  _colorFigure = colorFigure;
  _colorBorders = colorBorders;
}



void FlprogOledIconWidget::setSize(int16_t w, int16_t h)
{
  if ((_w == w) && (_h == h))
  {
    return;
  }
  _isNeedRepaint = true;
  _w = w;
  _h = h;
}

void FlprogOledIconWidget::setScale(int8_t scale)
{
  if (_scale == scale)
  {
    return;
  }
  _isNeedRepaint = true;
  _scale = scale;
}

void FlprogOledIconWidget::setIndex(int16_t index)
{
  if (_index == index)
  {
    return;
  }
  _isNeedRepaint = true;
  _index = index;
}

void FlprogOledIconWidget::privateDisplayOn(FlprogOledAbstractChip *chip)
{
  chip->_device.iconEx(_id, _x0, _y0, _w, _h, (icons_8x8[_index]), _scale, _colorFigure, _colorBorders);
}