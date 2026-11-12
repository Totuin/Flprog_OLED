#include "flprogOledNumberListValueWidget.h"

//--------------------------------FlprogOledAbstractListValueWidget-------------------------------------

FlprogOledAbstractListValueWidget::FlprogOledAbstractListValueWidget(uint8_t id, int16_t x0, int16_t y0, uint8_t scale, uint8_t style, uint32_t colorFigure, uint32_t colorBorders, uint16_t listSize)
{
  initTextWidget(id, x0, y0, scale, style, colorFigure, colorBorders);
  _listSize = listSize;
  _mode = FLPROG_OLED_UINTX_VALUE_MODE;
  privateSetValue();
}

void FlprogOledAbstractListValueWidget::privateSetValue()
{
  RT_HW_Base.messSetVar(_message, _currentText, _mode);
}

//--------------------------------FlprogOledNumberListValueWidget-------------------------------------

FlprogOledNumberListValueWidget::~FlprogOledNumberListValueWidget()
{
  delete[] _valueList;
  delete[] _textList;
  delete[] _assigned;
}

void FlprogOledNumberListValueWidget::setDefaultText(String text)
{
  if (_defaultText.equals(text)) {return;}
  _defaultText = text;
  setValue(_value);  // Повторно определяем текущую надпись без изменения числа.
}

void FlprogOledNumberListValueWidget::setValue(uint32_t value)
{
  String selected = _defaultText;
  if (_valueList && _textList && _assigned)
  {
    for (uint16_t i = 0; i < _listSize; ++i)
    {
      if (_assigned[i] && _valueList[i] == value)
      {
        selected = _textList[i];
        break;
      }
    }
  }
  if (_value == value && _currentText.equals(selected)) {return;}
  _value = value;
  _currentText = selected;
  _isNeedRepaint = true;
}

void FlprogOledNumberListValueWidget::setTextItem(uint16_t index, uint32_t value, String text)
{
  if (index >= _listSize) {return;}
  // Массивы выделяются единожды. Неприсвоенные ячейки не участвуют в поиске.
  if (!_valueList) {_valueList = new uint32_t[_listSize]();}
  if (!_textList) {_textList = new String[_listSize];}
  if (!_assigned) {_assigned = new bool[_listSize]();}
  if (!_valueList || !_textList || !_assigned) {return;}
  _valueList[index] = value;
  _textList[index] = text;
  _assigned[index] = true;
  setValue(_value);
}

//--------------------------------FlprogOledFloatListValueWidget-------------------------------------

FlprogOledFloatListValueWidget::~FlprogOledFloatListValueWidget()
{
  delete[] _valueList;
  delete[] _textList;
  delete[] _assigned;
}

void FlprogOledFloatListValueWidget::setDefaultText(String text)
{
  if (_defaultText.equals(text)) {return;}
  _defaultText = text;
  setValue(_value);
}

void FlprogOledFloatListValueWidget::setValue(float value)
{
  String selected = _defaultText;
  if (_valueList && _textList && _assigned)
  {
    for (uint16_t i = 0; i < _listSize; ++i)
    {
      if (_assigned[i] && _valueList[i] == value)
      {
        selected = _textList[i];
        break;
      }
    }
  }
  if (_value == value && _currentText.equals(selected)) {return;}
  _value = value;
  _currentText = selected;
  _isNeedRepaint = true;
}

void FlprogOledFloatListValueWidget::setTextItem(uint16_t index, float value, String text)
{
  if (index >= _listSize) {return;}
  if (!_valueList) {_valueList = new float[_listSize]();}
  if (!_textList) {_textList = new String[_listSize];}
  if (!_assigned) {_assigned = new bool[_listSize]();}
  if (!_valueList || !_textList || !_assigned) {return;}
  _valueList[index] = value;
  _textList[index] = text;
  _assigned[index] = true;
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
  if (_textForTrue.equals(text)) {return;}
  _textForTrue = text;
  _currentText = _value ? _textForTrue : _textForFalse;
  if (_value) {_isNeedRepaint = true;}
}

void FlprogOledBooleanListValueWidget::setFalseText(String text)
{
  if (_textForFalse.equals(text)) {return;}
  _textForFalse = text;
  _currentText = _value ? _textForTrue : _textForFalse;
  if (!_value) {_isNeedRepaint = true;}
}