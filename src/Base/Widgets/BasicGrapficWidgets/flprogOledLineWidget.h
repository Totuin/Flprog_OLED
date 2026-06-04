#pragma once
#include "flprogUtilites.h"
#include "flprogOledAbstractGrapfixWidget.h"

class FlprogOledLineWidget : public FlprogOledAbstractGrapficWidget
{
public:
  FlprogOledLineWidget(uint8_t id, int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint32_t color, uint8_t thickness);

  void setEndPoint(int16_t x, int16_t y);
  void setEndPointX(int16_t x) { setEndPoint(x, getEndPointY()); };
  void setEndPointY(int16_t y) { setEndPoint(getEndPointX(), y); };

  int16_t getEndPointX() { return _x1; };
  int16_t getEndPointY() { return _y1; };

  void setThickness(uint8_t thickness);

protected:
  void privateDisplayOn(FlprogOledAbstractChip *chip);

  int16_t _x1;
  int16_t _y1;
  uint8_t _thickness;
};