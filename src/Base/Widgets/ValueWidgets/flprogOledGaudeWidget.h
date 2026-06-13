#pragma once
#include "flprogUtilites.h"
#include "../BasicGrapficWidgets/flprogOledAbstractGrapfixWidget.h"

#define FLPROG_OLED_GAUDE_BOTTOM_TOP_DIRECTION 0
#define FLPROG_OLED_GAUDE_TOP_DOWN_DIRECTION 1
#define FLPROG_OLED_GAUDE_LEFT_RIGHT_DIRECTION 2
#define FLPROG_OLED_GAUDE_RIGHT_LEFT_DIRECTION 3

class FlprogOledGaudeWidget : public FlprogOledAbstractGrapficWidget
{
public:
  FlprogOledGaudeWidget(uint8_t id, int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint32_t colorFigure, uint32_t colorBorders, uint8_t thickness);

  void setValue(int32_t value);

  void setEndPoint(int16_t x, int16_t y);

  void setEndPointX(int16_t x) { setEndPoint(x, getEndPointY()); };
  void setEndPointY(int16_t y) { setEndPoint(getEndPointX(), y); };

  void setMaxValue(int32_t value);
  void setMinValue(int32_t value);

  void setDirection(uint8_t direction);

  int16_t getEndPointX() { return _x1; };
  int16_t getEndPointY() { return _y1; };

  int32_t getMaxValue() { return _maxValue; };
  int32_t getMinValue() { return _minValue; };

  void setLevelColor(uint32_t color);

protected:
  void privateDisplayOn(FlprogOledAbstractChip *chip);
  void calcRects();

  void calclBottomTopRects();
  void calclTopDownRects();
  void calclLeftRightRects();
  void calclRightLeftRects();

  int16_t levelPoint(int32_t outMax, int32_t outMinin);

  int16_t _x1;
  int16_t _y1;

  int16_t _empX0;
  int16_t _empY0;
  int16_t _empX1;
  int16_t _empY1;

  int16_t _fullX0;
  int16_t _fullY0;
  int16_t _fullX1;
  int16_t _fullY2;

  bool _hasEmp = false;
  bool _hasFull = false;

  int32_t _value = 0;
  int32_t _maxValue = 100;
  int32_t _minValue = 0;
  uint8_t _direction = FLPROG_OLED_GAUDE_BOTTOM_TOP_DIRECTION;

  uint32_t _levelColor = 0;
  uint8_t _thickness;
};