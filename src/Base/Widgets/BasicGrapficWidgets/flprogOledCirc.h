#pragma once
#include "flprogUtilites.h"
#include "flprogOledAbstractGrapfixWidget.h"

class FlprogOledCircletWidget : public FlprogOledAbstractGrapficWidget
{
public:
  FlprogOledCircletWidget(uint8_t id, int16_t x0, int16_t y0, int16_t r,  uint32_t colorFigure, uint32_t colorBorders, uint8_t thickness);


  void setRadius(int16_t r);
  int16_t getRadius() { return _r; };
  
  void setThickness(uint8_t thickness);

protected:
  void privateDisplayOn(FlprogOledAbstractChip *chip);

  int16_t _r;
  uint8_t _thickness;
};