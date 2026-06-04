#pragma once
#include "flprogUtilites.h"
#include "Widgets\flprogOledAbstractWidget.h"

class FlprogOledScreen : public AbstractFLProgClass
{
public:
  FlprogOledScreen() {};
  FlprogOledScreen(uint16_t widgetsSize);

  void setWidgetsSize(uint16_t widgetsSize);
  void setWidget(uint16_t index, FlprogOledAbstractWidget *widget);

  bool isNeedRepaint();
  void setIsNeedRepaint();

  void isActive(bool value);
  bool getIsActive() { return _isActive; };
  void displayOn(FlprogOledAbstractChip *chip);

protected:
  FlprogOledAbstractWidget **_widgets = 0;
  uint16_t _widgetsSize = 0;
  bool _isActive = true;
};