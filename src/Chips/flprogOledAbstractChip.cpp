#include "flprogOledAbstractChip.h"

void FlprogOledAbstractChip::abstractInit()
{
}

void FlprogOledAbstractChip::pool()
{
  if (!_isInit)
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
    _isInit = true;
  }
}

void FlprogOledSpiChip::spiInit()
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