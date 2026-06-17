#pragma once
#include "flprogUtilites.h"
#include "RT_HW_OLED.h"
#include "flprogOledAbstractChip.h"

class FlprogOledI2cChip : public FlprogOledAbstractChip
{
public:
  FlprogOledI2cChip() : _mainBus(&_busDev) {};

  void setSpeed(uint32_t value) { _speed = value; };
  void setAdress(uint8_t value) { _address = value; };
  void setBus(uint8_t value) { _bus = value; };

  void setExtensionAddress(uint8_t value) { _exAddress = value; };
  void setExtensionChanel(uint8_t value) { _exChanel = value; };

  RT_HW_OLED_Bus *mainBus() { return &_mainBus; };

  RT_HW_STRUCT_I2C_DEV _busDev;
  RT_HW_OLED_I2C_Bus _mainBus;

protected:
  void busInit();

  uint8_t _address = 255;
  uint32_t _speed = 400000;
  uint8_t _exAddress = 0;
  uint8_t _exChanel = 0;
  uint8_t _bus = 0;
};

// --------------------- Чип CH1107 -----------------
class FlprogOledI2cChip_CH1107 : public FlprogOledI2cChip
{
public:
  using FlprogOledI2cChip::FlprogOledI2cChip;

protected:
  void init() { _device.setParamDev_CH1107(_device.num, _extNum); };
};

// --------------------- Чип CH1115 -----------------
class FlprogI2cCH1115Chip : public FlprogOledI2cChip
{
public:
  using FlprogOledI2cChip::FlprogOledI2cChip;

protected:
  void init() { _device.setParamDev_CH1115(_device.num, _extNum); };
};

// --------------------- Чип SH1106 -----------------
class FlprogI2cSH1106Chip : public FlprogOledI2cChip
{
public:
  using FlprogOledI2cChip::FlprogOledI2cChip;

protected:
  void init() { _device.setParamDev_SH1106(_device.num, _extNum); };
};

// --------------------- Чип SH1107 -----------------
class FlprogI2cSH1107Chip : public FlprogOledI2cChip
{
public:
  using FlprogOledI2cChip::FlprogOledI2cChip;

protected:
  void init() { _device.setParamDev_SH1107(_device.num, _extNum); };
};

// --------------------- Чип SSD1306 -----------------
class FlprogI2cSSD1306Chip : public FlprogOledI2cChip
{
public:
  using FlprogOledI2cChip::FlprogOledI2cChip;

protected:
  void init() { _device.setParamDev_SSD1306(_device.num, _extNum); };
};

// --------------------- Чип SSD1309 -----------------
class FlprogI2cSSD1309Chip : public FlprogOledI2cChip
{
public:
  using FlprogOledI2cChip::FlprogOledI2cChip;

protected:
  void init() { _device.setParamDev_SSD1309(_device.num, _extNum); };
};

// --------------------- Чип SSD1312 -----------------
class FlprogI2cSSD1312Chip : public FlprogOledI2cChip
{
public:
  using FlprogOledI2cChip::FlprogOledI2cChip;

protected:
  void init() { _device.setParamDev_SSD1312(_device.num, _extNum); };
};

// --------------------- Чип SSD1315 -----------------
class FlprogI2cSSD1315Chip : public FlprogOledI2cChip
{
public:
  using FlprogOledI2cChip::FlprogOledI2cChip;

protected:
  void init() { _device.setParamDev_SSD1315(_device.num, _extNum); };
};

// --------------------- Чип ST7567S -----------------
class FlprogI2cST7567SChip : public FlprogOledI2cChip
{
public:
  using FlprogOledI2cChip::FlprogOledI2cChip;

protected:
  void init() { _device.setParamDev_ST7567S(_device.num, _extNum); };
};
