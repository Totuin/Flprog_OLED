#pragma once
#include "flprogUtilites.h"
#include "flprogOledAbstractGrapfixWidget.h"

class FlprogOledTextWidget : public FlprogOledAbstractGrapficWidget
{
public:
  FlprogOledTextWidget(uint8_t id, int16_t x0, int16_t y0, String txt, uint8_t scale, uint8_t style, uint32_t colorFigure, uint32_t colorBorders);
  FlprogOledTextWidget() {};

  void
  setText(String text);
  void setScale(uint8_t scale);
  void setStyle(uint8_t style);

protected:
  void privateDisplayOn(FlprogOledAbstractChip *chip);

  String _text = "";

  uint8_t _scale = 0;
  uint8_t _style = 0;
};