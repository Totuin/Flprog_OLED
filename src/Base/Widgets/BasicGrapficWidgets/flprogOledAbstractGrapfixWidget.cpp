#include "flprogOledAbstractGrapfixWidget.h"

void FlprogOledAbstractGrapficWidget::setColorFigure(uint32_t color)
{
  if (_colorFigure == color)
  {
    return;
  }
  _isNeedRepaint = true;
  _colorFigure = color;
}

void FlprogOledAbstractGrapficWidget::setColorBorders(uint32_t color)
{
  if (_colorBorders == color)
  {
    return;
  }
  _isNeedRepaint = true;
  _colorBorders = color;
}

void FlprogOledAbstractGrapficWidget::setStartPoint(int16_t x, int16_t y)
{
  if ((_x0 == x) && (_y0 == y))
  {
    return;
  }
  _isNeedRepaint = true;
  _x0 = x;
  _y0 = y;
}