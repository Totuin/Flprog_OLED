#pragma once
#include "flprogUtilites.h"
#include "flprogOledAbstractGrapfixWidget.h"

class FlprogOledIconWidget : public FlprogOledAbstractGrapficWidget
{
public:
  FlprogOledIconWidget(uint8_t id, int16_t x, int16_t y, int16_t w, int16_t h, int16_t index, uint8_t scale, uint8_t fillOn, uint8_t fillOff);

  void setSize(int16_t w, int16_t h);
  void setScale(int8_t scale);
  void setIndex(int16_t index);
  int16_t getIndex() { return _index; };

protected:
  void privateDisplayOn(FlprogOledAbstractChip *chip);
  int16_t _w = 8;
  int16_t _h = 8;
  uint8_t _scale;
  int16_t _index = -1;
};