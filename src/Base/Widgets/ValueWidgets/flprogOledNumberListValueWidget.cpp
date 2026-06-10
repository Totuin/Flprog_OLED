#include "flprogOledNumberListValueWidget.h"

//--------------------------------FlprogOledAbstractListValueWidget-------------------------------------

FlprogOledAbstractListValueWidget::FlprogOledAbstractListValueWidget(uint8_t id, int16_t x0, int16_t y0, uint8_t scale, uint8_t style, uint32_t colorFigure, uint32_t colorBorders, uint16_t listSize)
{
  initTextWidget(id, x0, y0, scale, style, colorFigure, colorBorders);
  _listSize = listSize;
  _mode = FLPROG_OLED_UINTX_VALUE_MODE;
  setValue();
}

void FlprogOledAbstractListValueWidget::setValue()
{
  RT_HW_Base.messSetVar(_message, _currentText, _mode);
}

//--------------------------------FlprogOledNumberListValueWidget-------------------------------------

void FlprogOledNumberListValueWidget::setDefaultText(String text)
{
  _defaultText = text;
  setValue(_value);
}

void FlprogOledNumberListValueWidget::setValue(uint32_t value)
{
  if (value == _value)
  {
    return;
  }
  _isNeedRepaint = true;
  _value = value;
  if ((_listSize == 0) || (_valueList == 0) || (_textList == 0))
  {
    _currentText = _defaultText;
    return;
  }
  for (uint16_t i = 0; i < _listSize; i++)
  {
    if (_valueList[i] == _value)
    {
      _currentText = _textList[i];
      return;
    }
  }
  _currentText = _defaultText;
}

void FlprogOledNumberListValueWidget::setTextItem(uint16_t index, uint32_t value, String text)
{
  if (index >= _listSize)
  {
    return;
  }
  if (_valueList == 0)
  {
    _valueList = new uint32_t[_listSize];
  }
  if (_textList == 0)
  {
    _textList = new String[_listSize];
  }
  _valueList[index] = value;
  _textList[index] = text;
  setValue(_value);
}

//--------------------------------FlprogOledFloatListValueWidget-------------------------------------

void FlprogOledFloatListValueWidget::setDefaultText(String text)
{
  _defaultText = text;
  setValue(_value);
}

void FlprogOledFloatListValueWidget::setValue(float value)
{
  if (value == _value)
  {
    return;
  }
  _isNeedRepaint = true;
  _value = value;
  if ((_listSize == 0) || (_valueList == 0) || (_textList == 0))
  {
    _currentText = _defaultText;
    return;
  }
  for (uint16_t i = 0; i < _listSize; i++)
  {
    if (_valueList[i] == _value)
    {
      _currentText = _textList[i];
      return;
    }
  }
  _currentText = _defaultText;
}

void FlprogOledFloatListValueWidget::setTextItem(uint16_t index, float value, String text)
{
  if (index >= _listSize)
  {
    return;
  }
  if (_valueList == 0)
  {
    _valueList = new float[_listSize];
  }
  if (_textList == 0)
  {
    _textList = new String[_listSize];
  }
  _valueList[index] = value;
  _textList[index] = text;
  setValue(_value);
}

//--------------------------------FlprogOledBooleanListValueWidget-------------------------------------

FlprogOledBooleanListValueWidget::FlprogOledBooleanListValueWidget(uint8_t id, int16_t x0, int16_t y0, uint8_t scale, uint8_t style, uint32_t colorFigure, uint32_t colorBorders)
{
  initTextWidget(id, x0, y0, scale, style, colorFigure, colorBorders);
  _mode = FLPROG_OLED_UINTX_VALUE_MODE;
  // setValue();
}

void FlprogOledBooleanListValueWidget::setValue(bool value)
{
  if (value == _value)
  {
    return;
  }
  _isNeedRepaint = true;
  _value = value;

  if (_value)
    _currentText = _textForTrue;
  else
    _currentText = _textForFalse;
}

void FlprogOledBooleanListValueWidget::setTrueText(String text)
{
  _textForTrue = text;
  setValue(_value);
}

void FlprogOledBooleanListValueWidget::setFalseText(String text)
{
  _textForFalse = text;
  setValue(_value);
}