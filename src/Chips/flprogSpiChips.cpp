#include "flprogSpiChips.h"

void FlprogOledSpiChip::busInit()
{
  _mainBus.setParamSPI(_device.num, _bus, _pinCs, _pinRs, _pinRst, _pinBlk, _speed);
  if (_dmaMode)
  {
    _device.setModeDMA(_sendSizePacket);
  }
  else
  {
    _device.setModeCPU(_sendSizePacket);
  }
}
