#include "flprogI2CChips.h"

void FlprogOledI2cChip::busInit()
{
  _mainBus.setParamI2C(_device.num, _address, _bus, _exAddress, _exChanel, _speed);
  _device.setModeCPU(_sendSizePacket);
}