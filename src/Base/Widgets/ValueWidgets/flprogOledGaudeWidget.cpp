#include "flprogOledGaudeWidget.h"

FlprogOledGaudeWidget::FlprogOledGaudeWidget(uint8_t id, int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint32_t colorFigure, uint32_t colorBorders, uint8_t thickness)
{
  _id = id;
  _x0 = x0;
  _y0 = y0;
  _x1 = x1;
  _y1 = y1;
  _colorFigure = colorFigure;
  _colorBorders = colorBorders;
  _thickness = thickness;
}

void FlprogOledGaudeWidget::setEndPoint(int16_t x, int16_t y)
{
  if ((_x1 == x) && (_y1 == y))
  {
    return;
  }
  _isNeedRepaint = true;
  _x1 = x;
  _y1 = y;
}

void FlprogOledGaudeWidget::setValue(int32_t value)
{
  if (_value == value)
  {
    return;
  }
  _isNeedRepaint = true;
  _value = value;
}

void FlprogOledGaudeWidget::setMaxValue(int32_t value)
{
  if (_maxValue == value)
  {
    return;
  }
  _isNeedRepaint = true;
  _maxValue = value;
}

void FlprogOledGaudeWidget::setMinValue(int32_t value)
{
  if (_minValue == value)
  {
    return;
  }
  _isNeedRepaint = true;
  _minValue = value;
}

void FlprogOledGaudeWidget::setDirection(uint8_t direction)
{
  if (_direction == direction)
  {
    return;
  }
  _isNeedRepaint = true;
  _direction = direction;
}

void FlprogOledGaudeWidget::setLevelColor(uint32_t color)
{
  if (_levelColor == color)
  {
    return;
  }
  _isNeedRepaint = true;
  _levelColor = color;
}

void FlprogOledGaudeWidget::privateDisplayOn(FlprogOledAbstractChip *chip)
{
  if (_isNeedRepaint)
  {
    calcRects();
  }
  if ((_colorBorders != RT_HW_OLED_FILL_NO) && (_hasEmp))
  {
    chip->_device.rect(_id, _empX0, _empY0, _empX1, _empY1, _colorBorders, RT_HW_OLED_FILL_NO, 1);
  }
  if (_hasFull)
  {
    chip->_device.rect(_id, _fullX0, _fullY0, _fullX1, _fullY2, _levelColor, RT_HW_OLED_FILL_NO, 1);
  }
  if (_colorFigure != RT_HW_OLED_FILL_NO)
  {
    chip->_device.rect(_id, _x0, _y0, _x1, _y1, RT_HW_OLED_FILL_NO, _colorFigure, _thickness);
  }
}

void FlprogOledGaudeWidget::calcRects()
{
  if (_levelColor == RT_HW_OLED_FILL_NO)
  {
    _hasEmp = true;
    _hasFull = false;
    _empX0 = _x0;
    _empY0 = _y0;
    _empX1 = _x1;
    _empY1 = _y1;

    return;
  }
  if (_maxValue >= _minValue)
  {
    if (_value >= _maxValue)
    {
      _hasEmp = false;
      _hasFull = true;
      _fullX0 = _x0;
      _fullY0 = _y0;
      _fullX1 = _x1;
      _fullY2 = _y1;
      return;
    }
    if (_value < _minValue)
    {
      _hasEmp = true;
      _hasFull = false;
      _empX0 = _x0;
      _empY0 = _y0;
      _empX1 = _x1;
      _empY1 = _y1;
      return;
    }
  }
  else
  {
    if (_value <= _maxValue)
    {
      _hasEmp = false;
      _hasFull = true;
      _fullX0 = _x0;
      _fullY0 = _y0;
      _fullX1 = _x1;
      _fullY2 = _y1;
      return;
    }
    if (_value > _minValue)
    {
      _hasEmp = true;
      _hasFull = false;
      _empX0 = _x0;
      _empY0 = _y0;
      _empX1 = _x1;
      _empY1 = _y1;
      return;
    }
  }
  _hasEmp = true;
  _hasFull = true;

  if (_direction == FLPROG_OLED_GAUDE_BOTTOM_TOP_DIRECTION)
  {
    calclBottomTopRects();
    return;
  }
  if (_direction == FLPROG_OLED_GAUDE_TOP_DOWN_DIRECTION)
  {
    calclTopDownRects();
    return;
  }
  if (_direction == FLPROG_OLED_GAUDE_LEFT_RIGHT_DIRECTION)
  {
    calclLeftRightRects();
    return;
  }
  if (_direction == FLPROG_OLED_GAUDE_RIGHT_LEFT_DIRECTION)
  {
    calclRightLeftRects();
    return;
  }
}

void FlprogOledGaudeWidget::calclBottomTopRects()
{
  int16_t yNew = levelPoint(_y0, _y1);
  _empX0 = _x0;
  _empY0 = _y0;
  _empX1 = _x1;
  _empY1 = yNew;
  _fullX0 = _x0;
  _fullY0 = yNew;
  _fullX1 = _x1;
  _fullY2 = _y1;
}

void FlprogOledGaudeWidget::calclTopDownRects()
{

  int16_t yNew = levelPoint(_y1, _y0);
  _empX0 = _x0;
  _empY0 = yNew;
  _empX1 = _x1;
  _empY1 = _y1;
  _fullX0 = _x0;
  _fullY0 = _y0;
  _fullX1 = _x1;
  _fullY2 = yNew;
}

void FlprogOledGaudeWidget::calclLeftRightRects()
{
  int16_t xNew = levelPoint(_x1, _x0);
  _empX0 = xNew;
  _empY0 = _y0;
  _empX1 = _x1;
  _empY1 = _y1;
  _fullX0 = _x0;
  _fullY0 = _y0;
  _fullX1 = xNew;
  _fullY2 = _y1;
}

void FlprogOledGaudeWidget::calclRightLeftRects()
{
  int16_t xNew = levelPoint(_x0, _x1);
  _empX0 = _x0;
  _empY0 = _y0;
  _empX1 = xNew;
  _empY1 = _y1;
  _fullX0 = xNew;
  _fullY0 = _y0;
  _fullX1 = _x1;
  _fullY2 = _y1;
}

int16_t FlprogOledGaudeWidget::levelPoint(int32_t outMax, int32_t outMinin)
{
  return (int16_t)((_value - _minValue) * (outMax - outMinin) / (_maxValue - _minValue) + outMinin);
}