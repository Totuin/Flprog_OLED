#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "RT_HW_OLED.h"
#include "flprogAbstractOledBuse.h"

class FlprogSpiOledBus : public FlprogOledAbstractBus
{
public:
  FlprogSpiOledBus() {};

  void setPinCs(uint8_t pin) { _pinCs = pin; };
  void setPinBlk(uint8_t pin) { _pinBlk = pin; };
  void setPinDc(uint8_t pin) { _pinDc = pin; };
  void setPinRst(uint8_t pin) { _pinRst = pin; };
  void setSpeed(uint32_t value) { _speed = value; };
  void setBus(uint8_t value) { _bus = value; };

  void init(uint8_t num);

protected:
  uint8_t _pinCs = 255;
  uint8_t _pinBlk = 255;
  uint8_t _pinDc = 255;
  uint8_t _pinRst = 255;
  uint32_t _speed = 8000000;
  uint8_t _bus = 0;

  RT_HW_STRUCT_SPI_DEV _spiDev;
  RT_HW_OLED_SPI_Bus *_mainBus;
};