#pragma once
#include "flprogUtilites.h"
#include "flprogOledAbstractValueWidget.h"

class FlprogOledBooleanValueWidget : public FlprogOledAbstractValueWidget
{
public:
  FlprogOledBooleanValueWidget(uint8_t id, int16_t x0, int16_t y0, uint8_t scale, uint8_t style, uint32_t colorFigure, uint32_t colorBorders);
  void setValue(bool value);
  void setTrueString(String value);
  void setFalseString(String value);

protected:
  void privateSetValue();
  String _trueString = "+";
  String _falseString = "-";
  bool _value = false;
};