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
  setValue();
  RT_HW_Base.messFormat(_message, _length, '~', _align);
  _textWidget.setText(_prefix + _message.str + _suffix);
  _textWidget.displayOn(chip);
}