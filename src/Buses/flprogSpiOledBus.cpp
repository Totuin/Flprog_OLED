#include "flprogSpiOledBus.h"

void FlprogSpiOledBus::init(uint8_t num)
{
  _mainBus = new RT_HW_OLED_SPI_Bus(&_spiDev);
  _mainBus->setParamSPI(num, _bus, _pinCs, _pinDc, _pinRst, _pinBlk, _speed);
}
