#pragma once
#include "flprogUtilites.h"
#include "RT_HW_OLED.h"
#include "flprogOledAbstractChip.h"

class FlprogOledSpiChip : public FlprogOledAbstractChip
{
public:
  FlprogOledSpiChip() : _mainBus(&_busDev) {};

  void setPinCs(uint8_t pin) { _pinCs = pin; };
  void setPinBlk(uint8_t pin) { _pinBlk = pin; };
  void setPinDc(uint8_t pin) { _pinDc = pin; };
  void setPinRst(uint8_t pin) { _pinRst = pin; };
  void setSpeed(uint32_t value) { _speed = value; };
  void setBus(uint8_t value) { _bus = value; };

  uint8_t getPinCs() { return _pinCs; };
  uint8_t getPinBlk() { return _pinBlk; };
  uint8_t getPinDc() { return _pinDc; };
  uint8_t getPinRst() { return _pinRst; };
  uint32_t getSpeed() { return _speed; };
  uint8_t getBus() { return _bus; };

  void setDmaMode(bool value) { _dmaMode = value; };
  bool getDmaMode() { return _dmaMode; };

  RT_HW_OLED_Bus *mainBus() { return &_mainBus; };

  RT_HW_OLED_SPI_Bus _mainBus;
  RT_HW_STRUCT_SPI_DEV _busDev;

protected:
  void busInit();

  uint8_t _pinCs = 255;
  uint8_t _pinBlk = 255;
  uint8_t _pinDc = 255;
  uint8_t _pinRst = 255;
  uint32_t _speed = 8000000;
  uint8_t _bus = 0;

  bool _dmaMode = false;
};

// --------------------- Чип CH1107 -----------------
class FlprogSpiCH1107Chip : public FlprogOledSpiChip
{
public:
  using FlprogOledSpiChip::FlprogOledSpiChip;

protected:
  void init() { _device.setParamDev_CH1107(_device.num, _extNum); };
};

// --------------------- Чип SSD1322_27 -----------------
class FlprogSSD1322_27Chip : public FlprogOledSpiChip
{
public:
  using FlprogOledSpiChip::FlprogOledSpiChip;

protected:
  void init() { _device.setParamDev_SSD1322_27(_device.num, _extNum); };
};

// --------------------- Чип SSD1322_31 -----------------
class FlprogSSD1322_31Chip : public FlprogOledSpiChip
{
public:
  using FlprogOledSpiChip::FlprogOledSpiChip;

protected:
  void init() { _device.setParamDev_SSD1322_31(_device.num, _extNum); };
};

// --------------------- Чип CH1115 -----------------
class FlprogSpiCH1115Chip : public FlprogOledSpiChip
{
public:
  using FlprogOledSpiChip::FlprogOledSpiChip;

protected:
  void init() { _device.setParamDev_CH1115(_device.num, _extNum); };
};

// --------------------- Чип SH1106 -----------------
class FlprogSpiSH1106Chip : public FlprogOledSpiChip
{
public:
  using FlprogOledSpiChip::FlprogOledSpiChip;

protected:
  void init() { _device.setParamDev_SH1106(_device.num, _extNum); };
};

// --------------------- Чип SSD1306 -----------------
class FlprogSpiSSD1306Chip : public FlprogOledSpiChip
{
public:
  using FlprogOledSpiChip::FlprogOledSpiChip;

protected:
  void init() { _device.setParamDev_SSD1306(_device.num, _extNum); };
};

// --------------------- Чип SSD1309 -----------------
class FlprogSpiSSD1309Chip : public FlprogOledSpiChip
{
public:
  using FlprogOledSpiChip::FlprogOledSpiChip;

protected:
  void init() { _device.setParamDev_SSD1309(_device.num, _extNum); };
};

// --------------------- Чип SSD1312 -----------------
class FlprogSpiSSD1312Chip : public FlprogOledSpiChip
{
public:
  using FlprogOledSpiChip::FlprogOledSpiChip;

protected:
  void init() { _device.setParamDev_SSD1312(_device.num, _extNum); };
};

// --------------------- Чип SSD1315 -----------------
class FlprogSpiSSD1315Chip : public FlprogOledSpiChip
{
public:
  using FlprogOledSpiChip::FlprogOledSpiChip;

protected:
  void init() { _device.setParamDev_SSD1315(_device.num, _extNum); };
};

// --------------------- Чип ST7565 -----------------
class FlprogSpiST7565Chip : public FlprogOledSpiChip
{
protected:
  void init() { _device.setParamDev_ST7565(_device.num, _extNum); };
};


// --------------------- Чип ST7920 -----------------
class FlprogSpiST7920Chip : public FlprogOledSpiChip
{
protected:
  void init() { _device.setParamDev_ST7920(_device.num, _extNum); };
};

// --------------------- Чип ILI9163 -----------------
class FlprogSpiILI9163Chip : public FlprogOledSpiChip
{
public:
  using FlprogOledSpiChip::FlprogOledSpiChip;

protected:
  void init() { _device.setParamDev_ILI9163(_device.num, _extNum); };
};

// --------------------- Чип ILI9225 -----------------
class FlprogSpiILI9225Chip : public FlprogOledSpiChip
{
public:
  using FlprogOledSpiChip::FlprogOledSpiChip;

protected:
  void init() { _device.setParamDev_ILI9225(_device.num, _extNum); };
};

// --------------------- Чип ILI9341 -----------------
class FlprogSpiILI9341Chip : public FlprogOledSpiChip
{
public:
  using FlprogOledSpiChip::FlprogOledSpiChip;

protected:
  void init() { _device.setParamDev_ILI9341(_device.num, _extNum); };
};

// --------------------- Чип ILI9486 -----------------
class FlprogSpiILI9486Chip : public FlprogOledSpiChip
{
public:
  using FlprogOledSpiChip::FlprogOledSpiChip;

protected:
  void init() { _device.setParamDev_ILI9486(_device.num, _extNum); };
};

// --------------------- Чип ST7735 -----------------
class FlprogSpiST7735Chip : public FlprogOledSpiChip
{
public:
  using FlprogOledSpiChip::FlprogOledSpiChip;

protected:
  void init() { _device.setParamDev_ST7735(_device.num, _extNum); };
};

// --------------------- Чип ST7789 -----------------
class FlprogSpiST7789Chip : public FlprogOledSpiChip
{
public:
  using FlprogOledSpiChip::FlprogOledSpiChip;

protected:
  void init() { _device.setParamDev_ST7789(_device.num, _extNum); };
};