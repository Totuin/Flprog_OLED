#include "flprogOledAbstractWidget.h"

bool FlprogOledAbstractWidget::isNeedRepaint()
{
  if (_isNeedRepaint)
  {
    return true;
  }
  if (RT_HW_Base.isTimer(_lastRepaintTime, 1000))
  {
    _isNeedRepaint = true;
    return true;
  }
  return false;
}

void FlprogOledAbstractWidget::displayOn(FlprogOledAbstractChip *chip)
{
  if (chip == 0)
  {
    return;
  }
  privateDisplayOn(chip);
  _isNeedRepaint = false;
  _lastRepaintTime = millis();
}