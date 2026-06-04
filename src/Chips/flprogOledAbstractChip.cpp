#include "flprogOledAbstractChip.h"

void FlprogOledAbstractChip::pool(bool en)
{
  if(! en)
  {
    return;
  }
  if (_status != FLPROG_READY_STATUS)
  {
    _device.bus = mainBus();
    if (!_num)
    {
      _num = RT_HW_oled.addDevice(&_device);
      if (!_num)
      {
        return;
      }
    }
    busInit();
    _device.setPeriodLimit(_periodLimit);
    _device.setScreenSize(_width, _height);
    init();
    _device.setRotation(_rotate);
    _device.setContrast(_contrast);
    _device.setOffSetX(_offSetX);
    _device.setOffSetY(_offSetY);
    _device.setMirrorX(_mirrorX);
    _device.setMirrorY(_mirrorY);
    _device.sendSizePacket = _sendSizePacket;
    _status = FLPROG_READY_STATUS;
  }
}
