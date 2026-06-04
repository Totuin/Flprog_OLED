#pragma once
#include "flprogUtilites.h"
#include "../../Chips/flprogOledAbstractChip.h"

class FlprogOledAbstractWidget : public AbstractFLProgClass
{
public:
  bool isNeedRepaint();
  void setIsNeedRepaint() { _isNeedRepaint = true; };

  void displayOn(FlprogOledAbstractChip *chip);

protected:
  uint8_t _id = 0;
  virtual void privateDisplayOn(FlprogOledAbstractChip *chip) = 0;
  uint32_t _lastRepaintTime = 0;
  bool _isNeedRepaint = true;

private:
};