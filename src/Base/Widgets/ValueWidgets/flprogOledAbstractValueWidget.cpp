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

// Обрезает String по количеству UTF-8 символов, а не байтов.
// Для некорректной UTF-8 строки оставляет максимум length исходных начальных байтов.
static void flprogOledTruncateUtf8(String &text, uint8_t maxChars)
{
  const unsigned int bytes = text.length();
  unsigned int chars = 0;
  for (unsigned int i = 0; i < bytes; ++i)
  {
    const uint8_t ch = static_cast<uint8_t>(text[i]);
    if ((ch & 0xC0) != 0x80)
    {
      if (chars == maxChars)
      {
        text.remove(i);
        return;
      }
      ++chars;
    }
  }
}

static int16_t flprogOledClampCoordinate(int32_t position)
{
  if (position > 32767) {return 32767;}
  if (position < -32768) {return -32768;}
  return static_cast<int16_t>(position);
}

void FlprogOledAbstractValueWidget::calculatePositions()
{
  // Форматтер RT_HW_BASE возвращает Arduino String; важно не обрезать UTF-8 посередине.
  flprogOledTruncateUtf8(_message.str, _length);

  int32_t charWidth = 6;
  if (_textWidget.getStyle() & RT_HW_OLED_TEXT_BOLD) {++charWidth;}
  if (_textWidget.getStyle() & RT_HW_OLED_TEXT_ITALIC_R) {charWidth += 2;}
  charWidth *= _textWidget.getScale();
  const int32_t valueWidth = static_cast<int32_t>(_length) * charWidth;
  const int32_t prefixWidth = static_cast<int32_t>(RT_HW_Base.getLenUTF8(_prefix)) * charWidth;
  const int32_t actualWidth = static_cast<int32_t>(RT_HW_Base.getLenUTF8(_message.str)) * charWidth;

  const int32_t suffixX = static_cast<int32_t>(_x) + prefixWidth + valueWidth;
  _suffixX = flprogOledClampCoordinate(suffixX);

  int32_t valueX = static_cast<int32_t>(_x) + prefixWidth;
  if (_align == FLPROG_OLED_CENTER_ALIGN_VALUE_MODE)
  {
    valueX += (valueWidth - actualWidth) / 2;
  }
  else if (_align == FLPROG_OLED_RIGHT_ALIGN_VALUE_MODE)
  {
    valueX += valueWidth - actualWidth;
  }
  _valueX = flprogOledClampCoordinate(valueX);
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

