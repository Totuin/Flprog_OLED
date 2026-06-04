#pragma once
#include "flprogUtilites.h"
#include "flprogOledAbstractGrapfixWidget.h"

class FlprogOledRectWidget : public FlprogOledAbstractGrapficWidget
{
public:
  FlprogOledRectWidget(uint8_t id, int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint32_t colorFigure, uint32_t colorBorders, uint8_t thickness);

  void setEndPoint(int16_t x, int16_t y);
  void setThickness(uint8_t thickness);

protected:
  void privateDisplayOn(FlprogOledAbstractChip *chip);

  int16_t _x1;
  int16_t _y1;
  uint8_t _thickness;
};