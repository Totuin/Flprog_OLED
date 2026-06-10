#pragma once
#include "flprogUtilites.h"
#include "../BasicGrapficWidgets/flprogOledAbstractGrapfixWidget.h"

class FlprogOledAbstractBooleanIndicatorWidget : public FlprogOledAbstractGrapficWidget
{
public:
  void setValue(bool value);
  void setColorForTrue(uint32_t color);
  void setColorForFalse(uint32_t color);
  void setFillColorForTrue(uint32_t color);
  void setFillColorForFalse(uint32_t color);
  void setThickness(uint8_t thickness);

protected:
  uint32_t _colorForTrue = RT_HW_OLED_FILL_WHITE;
  uint32_t _colorForFalse = RT_HW_OLED_FILL_WHITE;
  uint32_t _fillColorForTrue = RT_HW_OLED_FILL_WHITE;
  uint32_t _fillColorForFalse = RT_HW_OLED_FILL_BLACK;
  bool _value = false;
  uint8_t _thickness;
};

class FlprogOledRectBooleanIndicatorWidget : public FlprogOledAbstractBooleanIndicatorWidget
{
public:
  FlprogOledRectBooleanIndicatorWidget(uint8_t id, int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint8_t thickness);

  void setEndPoint(int16_t x, int16_t y);

  void setEndPointX(int16_t x) { setEndPoint(x, getEndPointY()); };
  void setEndPointY(int16_t y) { setEndPoint(getEndPointX(), y); };

  int16_t getEndPointX() { return _x1; };
  int16_t getEndPointY() { return _y1; };

protected:
  void privateDisplayOn(FlprogOledAbstractChip *chip);

  int16_t _x1;
  int16_t _y1;
};

class FlprogOledCircleBooleanIndicatorWidget : public FlprogOledAbstractBooleanIndicatorWidget
{

public:
  FlprogOledCircleBooleanIndicatorWidget(uint8_t id, int16_t x0, int16_t y0, int16_t r, uint8_t thickness);

  void setRadius(int16_t r);
  int16_t getRadius() { return _r; };

protected:
  void privateDisplayOn(FlprogOledAbstractChip *chip);

  int16_t _r;
};