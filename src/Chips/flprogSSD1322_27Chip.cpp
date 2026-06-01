#include "flprogSSD1322_27Chip.h"

void FlprogSSD1322_27Chip::init()
{
  busInit();
  _device.setParamDev_SSD1322_27(_num, _extNum);
}