#include "flprogOledLineWidget.h"

FlprogOledLineWidget::FlprogOledLineWidget(uint8_t id, int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint32_t color, uint8_t thickness)
{
  _id = id;
  _x0 = x0;
  _y0 = y0;
  _x1 = x1;
  _y1 = y1;
  _color = color;
  _thickness = thickness;
}

void FlprogOledLineWidget::setStartPoint(int16_t x, int16_t y)
{
  if ((_x0 == x) && (_y0 == y))
  {
    return;
  }
  _isNeedRepaint = true;
  _x0 = x;
  _y0 = y;
}

void FlprogOledLineWidget::setEndPoint(int16_t x, int16_t y)
{
  if ((_x1 == x) && (_y1 == y))
  {
    return;
  }
  _isNeedRepaint = true;
  _x1 = x;
  _y1 = y;
}

void FlprogOledLineWidget::setColor(uint32_t color)
{
  if (_color == color)
  {
    return;
  }
  _isNeedRepaint = true;
  _color = color;
}

void FlprogOledLineWidget::setThickness(uint8_t thickness)
{
  if (_thickness == thickness)
  {
    return;
  }
  _isNeedRepaint = true;
  _thickness = thickness;
}

void FlprogOledLineWidget::privateDisplayOn(FlprogOledAbstractChip *chip)
{
  chip->_device.line(_id, _x0, _y0, _x1, _y1, _color, _thickness);
}