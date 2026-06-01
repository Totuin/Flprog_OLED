#pragma once
#include "flprogUtilites.h"
#include "RT_HW_OLED.h"
#include "flprogOledAbstractChip.cpp"



class FlprogSSD1322_27Chip : public FlprogOledSpiChip
{
public:
  FlprogSSD1322_27Chip() {};

protected:
  void init();
};