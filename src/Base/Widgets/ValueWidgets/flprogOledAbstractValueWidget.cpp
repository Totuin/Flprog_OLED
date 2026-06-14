#include "flprogOledAbstractValueWidget.h"

bool FlprogOledAbstractValueWidget::isNeedRepaint()
{
  if (_isNeedRepaint)
  {
    return true;
  }
  return _textWidget.isNeedRepaint();
}

void FlprogOledAbstractValueWidget::setPrefix(String prefix)
{
  if (_prefix.equals(prefix))
  {
    return;
  }
  _isNeedRepaint = true;
  _prefix = prefix;
}

void FlprogOledAbstractValueWidget::setSuffix(String suffix)
{
  if (_suffix.equals(suffix))
  {
    return;
  }
  _isNeedRepaint = true;
  _suffix = suffix;
}

void FlprogOledAbstractValueWidget::setLength(uint8_t value)
{
  if (_length == value)
  {
    return;
  }
  _isNeedRepaint = true;
  _length = value;
}

void FlprogOledAbstractValueWidget::setAlign(char align)
{
  if (_align == align)
  {
    return;
  }
  _isNeedRepaint = true;
  _align = align;
}

void FlprogOledAbstractValueWidget::setMode(char mode)
{
  if (_mode == mode)
  {
    return;
  }
  _isNeedRepaint = true;
  _mode = mode;
}

void FlprogOledAbstractValueWidget::privateDisplayOn(FlprogOledAbstractChip *chip)
{
  if (_isNeedRepaint)
  {
    privateSetValue();
    calculatePositions();
  }

  _textWidget.setStartPoint(_x, _y);
  _textWidget.setText(_prefix);
  _textWidget.displayOn(chip);

  _textWidget.setStartPoint(_valueX, _y);
  _textWidget.setText(_message.str);
  _textWidget.displayOn(chip);

  _textWidget.setStartPoint(_suffixX, _y);
  _textWidget.setText(_suffix);
  _textWidget.displayOn(chip);
}

void FlprogOledAbstractValueWidget::calculatePositions()
{

  if (_message.str.length() > _length)
  {
    _message.str.remove(_length); //--Усечение ссобщения сзади до заданной длины size;
  }
  uint8_t sumbolWidth = 6;
  if (_textWidget.getStyle() & RT_HW_OLED_TEXT_BOLD)
  {
    sumbolWidth = sumbolWidth + 1;
  }
  if (_textWidget.getStyle() & RT_HW_OLED_TEXT_ITALIC_R)
  {
    sumbolWidth = sumbolWidth + 2;
  }
  sumbolWidth = sumbolWidth * _textWidget.getScale();
  int16_t valueWidth = _length * sumbolWidth;
  int16_t prefixWidth = _prefix.length() * sumbolWidth;
  _suffixX = valueWidth + prefixWidth + _x;
  if (_align == FLPROG_OLED_CENTER_ALIGN_VALUE_MODE)
  {
    int16_t offset = ((_length - _message.str.length()) * sumbolWidth) / 2;
    _valueX = prefixWidth + _x + offset;
    return;
  }
  if (_align == FLPROG_OLED_RIGHT_ALIGN_VALUE_MODE)
  {
    _valueX = _suffixX - (_message.str.length() * sumbolWidth);
    return;
  }
  _valueX = _x + prefixWidth;
}

void FlprogOledAbstractValueWidget::setStartPoint(int16_t x, int16_t y)
{
  if ((_x == x) && (_y == y))
  {
    return;
  }
  _isNeedRepaint = true;
  _x = x;
  _y = y;
}

void FlprogOledAbstractValueWidget::initTextWidget(uint8_t id, int16_t x0, int16_t y0, uint8_t scale, uint8_t style, uint32_t colorFigure, uint32_t colorBorders)
{
  _id = id;
  _x = x0;
  _y = y0;
  _textWidget.setStartPoint(0, 0);
  _textWidget.setScale(scale);
  _textWidget.setStyle(style);
  _textWidget.setColorFigure(colorFigure);
  _textWidget.setColorBorders(colorBorders);
}