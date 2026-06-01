#include "flprogOledAbstractChip.h"

void FlprogOledAbstractChip::abstractInit()
{
}

void FlprogOledAbstractChip::pool()
{
  if (_status != FLPROG_READY_STATUS)
  {
    _num = RT_HW_oled.addDevice(&_device);
    if (!_num)
    {
      return;
    }
    _device.setPeriodLimit(_periodLimit);
    _device.setScreenSize(_width, _height);
    _device.setRotation(_rotate);
    _device.setContrast(_contrast);
    _device.setOffSetX(_offSetX);
    _device.setOffSetY(_offSetY);
    _device.setMirrorX(_mirrorX);
    _device.setMirrorY(_mirrorY);
    init();
    _status = FLPROG_READY_STATUS;
  }
}

void FlprogOledSpiChip::busInit()
{
  _bus.init(_num);
  _device.sendSizePacket = _sendSizePacket;
  if (_dmaMode)
  {
    _device.setModeDMA();
  }
  else
  {
    _device.setModeCPU();
  }
}