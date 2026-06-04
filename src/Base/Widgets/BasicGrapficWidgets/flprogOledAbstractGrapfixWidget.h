#pragma once
#include "flprogUtilites.h"
#include "../flprogOledAbstractWidget.h"

class FlprogOledAbstractGrapficWidget : public FlprogOledAbstractWidget
{
public:
  void setColorFigure(uint32_t color);

  void setColorBorders(uint32_t color);
  void setStartPoint(int16_t x, int16_t y);
  void setStartPointX(int16_t x) {  setStartPoint( x, getStartPointY()); };
  void setStartPointY(int16_t y) { setStartPoint(getStartPointX(), y); };

  int16_t getStartPointX() { return _x0; };
  int16_t getStartPointY() { return _y0; };

protected:
  int16_t _x0;
  int16_t _y0;
  uint32_t _colorFigure = 0;
  uint32_t _colorBorders = RT_HW_OLED_FILL_NO;
};