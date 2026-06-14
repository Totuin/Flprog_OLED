#pragma once
#include "flprogUtilites.h"
#include "flprogOledAbstractValueWidget.h"

class FlprogOledFloatValueWidget : public FlprogOledAbstractValueWidget
{
public:
  FlprogOledFloatValueWidget(uint8_t id, int16_t x0, int16_t y0, uint8_t scale, uint8_t style, uint32_t colorFigure, uint32_t colorBorders);
  void setValue(float value);

protected:
  void privateSetValue();

  float _value = 0;
};