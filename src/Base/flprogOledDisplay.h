#pragma once
#include "flprogUtilites.h"
#include "flprogOledScreen.h"

class FlprogOledDisplay : public AbstractFLProgClass
{
public:
  FlprogOledDisplay(uint16_t screensSize);

  void setEn(bool value);
  bool getEn() { return _en; };

  bool isNeedRepaint();
  void setIsNeedRepaint();
  void setScreen(uint16_t index, FlprogOledScreen *screen);

  void displayOn(FlprogOledAbstractChip *chip);

protected:
  bool _en = true;
  FlprogOledScreen **_screens = 0;
  uint16_t _screensSize = 0;
  bool _isShow = false;
};