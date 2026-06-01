#pragma once
#include "flprogUtilites.h"
#include "../../Chips/flprogOledAbstractChip.h"

class FlprogOledAbstractWidget : public AbstractFLProgClass
{
public:
  FlprogOledAbstractWidget() {};

  virtual bool isNeedRepaint() { return _isNeedRepaint; };
  void setIsNeedRepaint() { _isNeedRepaint = true; };


  void displayOn(FlprogOledAbstractChip *chip);

protected:
  bool _isNeedRepaint = true;
  uint8_t _id = 0;
  virtual void privateDisplayOn(FlprogOledAbstractChip *chip) = 0;
};