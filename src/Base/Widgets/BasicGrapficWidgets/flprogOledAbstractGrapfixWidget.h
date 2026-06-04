#pragma once
#include "flprogUtilites.h"
#include "../flprogOledAbstractWidget.h"

class FlprogOledAbstractGrapficWidget : public FlprogOledAbstractWidget
{
public:
  void setColorFigure(uint32_t color);

  void setColorBorders(uint32_t color);
  void setStartPoint(int16_t x, int16_t y);

protected:
  int16_t _x0;
  int16_t _y0;
  uint32_t _colorFigure = 0;
  uint32_t _colorBorders = RT_HW_OLED_FILL_NO;
};