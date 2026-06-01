#pragma once
#include "flprogUtilites.h"
#include "flprogOledScreen.h"

class FlprogOledDisplay : public AbstractFLProgClass
{
public:
  FlprogOledDisplay(uint16_t screensSize);

  void setEn(uint8_t value);
  bool isNeedRepaint();
  void setIsNeedRepaint();

  void displayOn(FlprogOledAbstractChip *chip);

protected:
  uint8_t _en = 1;
  FlprogOledScreen **_screens = 0;
  uint16_t _screensSize = 0;
}