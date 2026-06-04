#pragma once
#include "flprogUtilites.h"
#include "flprogOledAbstractValueWidget.h"

class FlprogOledNumberValueWidget : public FlprogOledAbstractValueWidget
{
public:
  FlprogOledNumberValueWidget(uint8_t id, int16_t x0, int16_t y0, uint8_t scale, uint8_t style, uint32_t colorFigure, uint32_t colorBorders);
  void setValue(uint32_t value);

protected:
  void setValue();

  uint32_t _value = 0;
};