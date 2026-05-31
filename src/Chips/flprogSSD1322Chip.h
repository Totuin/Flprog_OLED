#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "RT_HW_OLED.h"
#include "./Buses/flprogSpiOledBus.h"

class FlprogSSD1322Chip : public FlprogOledSpiChip
{
public:
  FlprogSSD1322Chip() {};

protected:
  void init();
};