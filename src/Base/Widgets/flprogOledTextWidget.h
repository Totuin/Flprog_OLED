#pragma once
#include "flprogUtilites.h"
#include "flprogOledAbstractWidget.h"

class FlprogOledTextWidget : public FlprogOledAbstractWidget
{
public:
  FlprogOledTextWidget(uint8_t id, int16_t x0, int16_t y0, String txt, uint8_t scale, uint8_t style, uint32_t colorFigure, uint32_t colorBorders);
  FlprogOledTextWidget() {};
  void setInsertPoint(int16_t x, int16_t y);
  void setText(String text);
  void setScale(uint8_t scale);
  void setStyle(uint8_t style);
  void setColorFigure(uint32_t color);
  void setColorBorders(uint32_t color);


protected:
  void privateDisplayOn(FlprogOledAbstractChip *chip);

  String _txt ="";
  int16_t _x0=0;
  int16_t _y0=0;
  uint8_t _scale=0;
  uint8_t _style=0;
  uint32_t _colorFigure=0;
  uint32_t _colorBorders=0;
};