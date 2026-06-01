#include "flprogOledAbstractWidget.h"

void FlprogOledAbstractWidget::displayOn(FlprogOledAbstractChip *chip)
{
  if (chip == 0)
  {
    return;
  }
  privateDisplayOn(chip);
  _isNeedRepaint = false;
}