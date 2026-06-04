#include "flprogSpiChips.h"

void FlprogOledSpiChip::busInit()
{
  _mainBus.setParamSPI(_device.num, _bus, _pinCs, _pinDc, _pinRst, _pinBlk, _speed);
  if (_dmaMode)
  {
    _device.setModeDMA();
  }
  else
  {
    _device.setModeCPU();
  }
}
