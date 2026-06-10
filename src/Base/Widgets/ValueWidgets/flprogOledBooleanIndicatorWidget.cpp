#include "flprogOledBooleanIndicatorWidget.h"

//--------------------- FlprogOledAbstractBooleanIndicatorWidget ---------------------

void FlprogOledAbstractBooleanIndicatorWidget::setValue(bool value)
{
  if (_value == value)
  {
    return;
  }
  _isNeedRepaint = true;
  _value = value;
  if (_value)
  {
    _colorFigure = _colorForTrue;
    _colorBorders = _fillColorForTrue;
  }
  else
  {
    _colorFigure = _colorForFalse;
    _colorBorders = _fillColorForFalse;
  }
}

void FlprogOledAbstractBooleanIndicatorWidget::setColorForTrue(uint32_t color)
{
  _colorForTrue = color;
  setValue(_value);
}

void FlprogOledAbstractBooleanIndicatorWidget::setColorForFalse(uint32_t color)
{
  _colorForFalse = color;
  setValue(_value);
}

void FlprogOledAbstractBooleanIndicatorWidget::setFillColorForTrue(uint32_t color)
{
  _fillColorForTrue = color;
  setValue(_value);
}

void FlprogOledAbstractBooleanIndicatorWidget::setFillColorForFalse(uint32_t color)
{
  _fillColorForFalse = color;
  setValue(_value);
}

void FlprogOledAbstractBooleanIndicatorWidget::setThickness(uint8_t thickness)
{
  if (_thickness == thickness)
  {
    return;
  }
  _isNeedRepaint = true;
  _thickness = thickness;
}

//--------------------- FlprogOledRectBooleanIndicatorWidget ---------------------

FlprogOledRectBooleanIndicatorWidget::FlprogOledRectBooleanIndicatorWidget(uint8_t id, int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint8_t thickness)
{
  _id = id;
  _x0 = x0;
  _y0 = y0;
  _x1 = x1;
  _y1 = y1;
  _thickness = thickness;
}

void FlprogOledRectBooleanIndicatorWidget::setEndPoint(int16_t x, int16_t y)
{
  if ((_x1 == x) && (_y1 == y))
  {
    return;
  }
  _isNeedRepaint = true;
  _x1 = x;
  _y1 = y;
}

void FlprogOledRectBooleanIndicatorWidget::privateDisplayOn(FlprogOledAbstractChip *chip)
{
  chip->_device.rect(_id, _x0, _y0, _x1, _y1, _colorBorders, _colorFigure, _thickness);
}

//--------------------- FlprogOledCircleBooleanIndicatorWidget ---------------------

FlprogOledCircleBooleanIndicatorWidget::FlprogOledCircleBooleanIndicatorWidget(uint8_t id, int16_t x0, int16_t y0, int16_t r, uint8_t thickness)
{
  _id = id;
  _x0 = x0;
  _y0 = y0;
  _r = r;
  _thickness = thickness;
}

void FlprogOledCircleBooleanIndicatorWidget::setRadius(int16_t r)
{
  if (_r == r)
  {
    return;
  }
  _isNeedRepaint = true;
  _r = r;
}

void FlprogOledCircleBooleanIndicatorWidget::privateDisplayOn(FlprogOledAbstractChip *chip)
{
  chip->_device.circle(_id, _x0, _y0, _r, _colorBorders, _colorFigure, _thickness);
}