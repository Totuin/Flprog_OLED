#pragma once
#include "flprogUtilites.h"
#include "flprogOledAbstractValueWidget.h"

// Общая часть виджетов со списком подписей для отдельных значений.
class FlprogOledAbstractListValueWidget : public FlprogOledAbstractValueWidget
{
public:
  // Базовый конструктор оставлен для совместимости с существующим API.
  FlprogOledAbstractListValueWidget(){};
  FlprogOledAbstractListValueWidget(uint8_t id, int16_t x0, int16_t y0, uint8_t scale, uint8_t style, uint32_t colorFigure, uint32_t colorBorders, uint16_t listSize = 2);

protected:
  void privateSetValue();
  uint16_t _listSize = 0;
  String _currentText = "";
};

// Таблица соответствий целочисленных значений и текстовых подписей.
class FlprogOledNumberListValueWidget : public FlprogOledAbstractListValueWidget
{
public:
  using FlprogOledAbstractListValueWidget::FlprogOledAbstractListValueWidget;
  ~FlprogOledNumberListValueWidget();
  FlprogOledNumberListValueWidget(const FlprogOledNumberListValueWidget &) = delete;
  FlprogOledNumberListValueWidget &operator=(const FlprogOledNumberListValueWidget &) = delete;
  void setDefaultText(String text);
  void setValue(uint32_t value);
  void setTextItem(uint16_t index, uint32_t value, String text);

protected:
 
  uint32_t *_valueList = 0;
  String *_textList = 0;
  bool *_assigned = 0;   // Пустые позиции нельзя считать значением 0.
  uint32_t _value = 0;
  String _defaultText = "";
};

// Таблица соответствий вещественных значений и текстовых подписей.
class FlprogOledFloatListValueWidget : public FlprogOledAbstractListValueWidget
{
public:
  using FlprogOledAbstractListValueWidget::FlprogOledAbstractListValueWidget;
  ~FlprogOledFloatListValueWidget();
  FlprogOledFloatListValueWidget(const FlprogOledFloatListValueWidget &) = delete;
  FlprogOledFloatListValueWidget &operator=(const FlprogOledFloatListValueWidget &) = delete;
  void setDefaultText(String text);
  void setValue(float value);
  void setTextItem(uint16_t index, float value, String text);

protected:
 
  float *_valueList = 0;
  String *_textList = 0;
  bool *_assigned = 0;
  float _value = 0;
  String _defaultText = "";
};

// Две подписи для состояний false и true.
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