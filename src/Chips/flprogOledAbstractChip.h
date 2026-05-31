#pragma once
#include <Arduino.h>
#include "flprogUtilites.h"
#include "RT_HW_OLED.h"

class FlprogOledAbstractChip
{
public:
  void setColStart(uint8_t value) { _colStart = value; };
  void setRowStartt(uint8_t value) { _rowStart = value; };
  void setColorBGRt(uint8_t value) { colorBGR = value; };
  void setOffSetX(int16_t offSetX) {};
  void setOffSetY(int16_t offSetY) {};
  void setMirrorX(uint8_t en) {};
  void setMirrorY(uint8_t en) {};

  void setWidth(uint8_t value) { _width = value; };
  void setHeight(uint8_t value) { _height = value; };
  void setPeriodLimit(uint16_t period) { _periodLimit = period; };
  void setRotation(uint16_t value) { _rotate = value; };
  void setContrast(uint8_t value) { _contrast = value; };

  uint8_t getNum() { return _num; };

  void pool();

protected:
  virtual void init() = 0;
  uint8_t _colStart = 0;
  uint16_t _rowStart = 0;
  uint8_t _colorBGR = 0;
  uint16_t _width = 0;
  uint16_t _height = 0;
  bool _isInit = false;
  uint8_t _num = 0;
  uint16_t _periodLimit = 0;
  uint16_t _rotate = 0;
  uint8_t _contrast = 100;
  int16_t _offSetX = 0;
  int16_t _offSetY = 0;
  uint8_t _mirrorX = 0;
  uint8_t _mirrorY = 0;

  RT_HW_OLED_Device _device;
};

class FlprogOledSpiChip : public FlprogOledAbstractChip
{
public:
  void setPinCs(uint8_t pin) { _bus.setPinCs(pin); };
  void setPinBlk(uint8_t pin) { _bus.setPinBlk(pin); };
  void setPinDc(uint8_t pin) { _bus.setPinDc(pin); };
  void setPinRst(uint8_t pin) { _bus.setPinRst(pin); };
  void setSpeed(uint32_t value) { _bus.setSpeed(value); };
  void setDmaMode(bool value) { _dmaMode = value; };
  void setBus(uint8_t value) { _bus.setBus(value); };
  void sendSizePacket(int32_t value) { _sendSizePacket = value; };

protected:
  void
  spiInit();
  bool _dmaMode = false;
  int32_t _sendSizePacket = 0;
  FlprogSpiOledBus _bus;
};