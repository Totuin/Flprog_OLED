#pragma once
#include "flprogUtilites.h"
#include "flprogOledAbstractValueWidget.h"

class FlprogOledAbstractListValueWidget : public FlprogOledAbstractValueWidget
{
public:
  FlprogOledAbstractListValueWidget(){};
  FlprogOledAbstractListValueWidget(uint8_t id, int16_t x0, int16_t y0, uint8_t scale, uint8_t style, uint32_t colorFigure, uint32_t colorBorders, uint16_t listSize = 2);

protected:
  void privateSetValue();
  uint16_t _listSize;
  String _currentText = "";
};

class FlprogOledNumberListValueWidget : public FlprogOledAbstractListValueWidget
{
public:
  using FlprogOledAbstractListValueWidget::FlprogOledAbstractListValueWidget;
  void setDefaultText(String text);
  void setValue(uint32_t value);
  void setTextItem(uint16_t index, uint32_t value, String text);

protected:
 
  uint32_t *_valueList = 0;
  String *_textList = 0;
  uint32_t _value;
  String _defaultText = "";
};

class FlprogOledFloatListValueWidget : public FlprogOledAbstractListValueWidget
{
public:
  using FlprogOledAbstractListValueWidget::FlprogOledAbstractListValueWidget;
  void setDefaultText(String text);
  void setValue(float value);
  void setTextItem(uint16_t index, float value, String text);

protected:
 
  float *_valueList = 0;
  String *_textList = 0;
  float _value;
  String _defaultText = "";
};

class FlprogOledBooleanListValueWidget : public FlprogOledAbstractListValueWidget
{
public:
  FlprogOledBooleanListValueWidget(uint8_t id, int16_t x0, int16_t y0, uint8_t scale, uint8_t style, uint32_t colorFigure, uint32_t colorBorders);
  void setValue(bool value);
  void setTrueText(String text);
  void setFalseText(String text);

protected:
  bool _value = false;
  String _textForTrue = "";
  String _textForFalse = "";
};