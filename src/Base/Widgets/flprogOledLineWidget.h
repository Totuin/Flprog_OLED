#pragma once
#include "flprogUtilites.h"
#include "flprogOledAbstractWidget.h"

class FlprogOledLineWidget : public FlprogOledAbstractWidget
{
public:
  FlprogOledLineWidget(uint8_t id, int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint32_t color, uint8_t thickness);

  void setStartPoint(int16_t x, int16_t y);
  void setEndPoint(int16_t x, int16_t y);
  void setColor(uint32_t color);
  void setThickness(uint8_t thickness);

protected:
  void privateDisplayOn(FlprogOledAbstractChip *chip);

  int16_t _x0;
  int16_t _y0;
  int16_t _x1;
  int16_t _y1;
  uint32_t _color;
  uint8_t _thickness;
}