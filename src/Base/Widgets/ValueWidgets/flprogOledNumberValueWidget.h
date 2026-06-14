#pragma once
#include "flprogUtilites.h"
#include "flprogOledAbstractValueWidget.h"

#define FLPROG_OLED_NUNBER_UINT8_TYPE 0
#define FLPROG_OLED_NUNBER_INT8_TYPE 1
#define FLPROG_OLED_NUNBER_UINT16_TYPE 2
#define FLPROG_OLED_NUNBER_INT16_TYPE 3
#define FLPROG_OLED_NUNBER_UINT32_TYPE 4
#define FLPROG_OLED_NUNBER_INT32_TYPE 5

class FlprogOledNumberValueWidget : public FlprogOledAbstractValueWidget
{
public:
  FlprogOledNumberValueWidget(uint8_t id, int16_t x0, int16_t y0, uint8_t scale, uint8_t style, uint32_t colorFigure, uint32_t colorBorders);
  void setValue(uint32_t value);
  void setVarType(uint8_t value);

  void setTrueChar(char value);
  void setFalseChar(char value);

protected:
  void privateSetValue();

  uint8_t _varType = FLPROG_OLED_NUNBER_UINT32_TYPE;
  uint32_t _value = 0;
};