#pragma once
#include "flprogUtilites.h"
#include "RT_HW_OLED.h"

typedef void (*FlprogOledDebugCallback)();

class FlprogOledAbstractChip : public AbstractFLProgClass
{

public:
  void setColStart(uint8_t value) { _colStart = value; };
  void setRowStart(uint8_t value) { _rowStart = value; };
  void setColorBGRt(uint8_t value) { _colorBGR = value; };
  void setOffSetX(int16_t offSetX) { _offSetX = offSetX; };
  void setOffSetY(int16_t offSetY) { _offSetY = offSetY; };
  void setMirrorX(uint8_t en) { _mirrorX = en; };
  void setMirrorY(uint8_t en) { _mirrorY = en; };

  void setWidth(uint16_t value) { _width = value; };
  void setHeight(uint16_t value) { _height = value; };
  void setPeriodLimit(uint16_t period) { _periodLimit = period; };
  void setRotation(uint16_t value) { _rotate = value; };
  void setContrast(uint8_t value) { _contrast = value; };

  void setExtNum(uint8_t value) { _extNum = value; };

  uint8_t getColStart() { return _colStart; };
  uint16_t getRowStart() { return _rowStart; };
  uint8_t getColorBGR() { return _colorBGR; };
  int16_t getOffSetX() { return _offSetX; };
  int16_t getOffSetY() { return _offSetY; };
  uint8_t getMirrorX() { return _mirrorX; };
  uint8_t getMirrorY() { return _mirrorY; };

  uint16_t getWidth() { return _width; };
  uint16_t getHeight() { return _height; };
  uint16_t getPeriodLimit() { return _periodLimit; };
  uint16_t getRotation() { return _rotate; };
  uint8_t getContrast() { return _contrast; };

  uint8_t getExtNum() { return _extNum; };
  uint8_t getNum() { return _num; };

  void sendSizePacket(int32_t value) { _sendSizePacket = value; };

  void pool(bool en);

  void debugCallback(FlprogOledDebugCallback callback) { _debugCallback = callback; };

  RT_HW_OLED_Device _device;

protected:
  virtual void init() {};
  virtual void busInit() {};
  virtual RT_HW_OLED_Bus *mainBus() { return nullptr; };
  FlprogOledDebugCallback _debugCallback = 0;
  uint8_t _colStart = 0;
  uint16_t _rowStart = 0;
  uint8_t _colorBGR = 0;
  uint16_t _width = 0;
  uint16_t _height = 0;
  uint8_t _num = 0;
  uint8_t _extNum = 100;

  uint16_t _periodLimit = 0;
  uint16_t _rotate = 0;
  uint8_t _contrast = 100;
  int16_t _offSetX = 0;
  int16_t _offSetY = 0;
  uint8_t _mirrorX = 0;
  uint8_t _mirrorY = 0;
  int32_t _sendSizePacket = 0;
};
