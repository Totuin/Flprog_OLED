#pragma once
#include "flprogUtilites.h"
#include "RT_HW_OLED.h"
#include "flprogOledAbstractChip.h"

// --------------------- Чип KS0108 -----------------
class FlprogParallelKS0108Chip : public FlprogOledAbstractChip
{
public:
  void setPinRs(uint8_t pin) { _pinRs = pin; };
  void setPinEn(uint8_t pin) { _pinEn = pin; };
  void setPinRst(uint8_t pin) { _pinRst = pin; };
  void setPinCs1(uint8_t pin) { _pinCs1 = pin; };
  void setPinCs2(uint8_t pin) { _pinCs2 = pin; };
  void setPinCs3(uint8_t pin) { _pinCs3 = pin; };

  void setPinD0(uint8_t pin) { _pinD0 = pin; };
  void setPinD1(uint8_t pin) { _pinD1 = pin; };
  void setPinD2(uint8_t pin) { _pinD2 = pin; };
  void setPinD3(uint8_t pin) { _pinD3 = pin; };
  void setPinD4(uint8_t pin) { _pinD4 = pin; };
  void setPinD5(uint8_t pin) { _pinD5 = pin; };
  void setPinD6(uint8_t pin) { _pinD6 = pin; };
  void setPinD7(uint8_t pin) { _pinD7 = pin; };

  uint8_t getPinRs() { return _pinRs; };
  uint8_t getPinEn() { return _pinEn; };
  uint8_t getPinRst() { return _pinRst; };
  uint8_t getPinCs1() { return _pinCs1; };
  uint8_t getPinCs2() { return _pinCs2; };
  uint8_t getPinCs3() { return _pinCs3; };

  uint8_t getPinD0() { return _pinD0; };
  uint8_t getPinD1() { return _pinD1; };
  uint8_t getPinD2() { return _pinD2; };
  uint8_t getPinD3() { return _pinD3; };
  uint8_t getPinD4() { return _pinD4; };
  uint8_t getPinD5() { return _pinD5; };
  uint8_t getPinD6() { return _pinD6; };
  uint8_t getPinD7() { return _pinD7; };

  RT_HW_OLED_Bus *mainBus() { return &_mainBus; };

  RT_HW_OLED_PAR8_Bus _mainBus;

protected:
  void busInit();
  void init() { _device.setParamDev_KS0108(_device.num, _extNum); };

  uint8_t _pinRs = 255;
  uint8_t _pinEn = 255;
  uint8_t _pinRst = 255;
  uint8_t _pinCs1 = 255;
  uint8_t _pinCs2 = 255;
  uint8_t _pinCs3 = 255;
  uint8_t _pinD0 = 255;
  uint8_t _pinD1 = 255;
  uint8_t _pinD2 = 255;
  uint8_t _pinD3 = 255;
  uint8_t _pinD4 = 255;
  uint8_t _pinD5 = 255;
  uint8_t _pinD6 = 255;
  uint8_t _pinD7 = 255;
};

// --------------------- Чип KS0108<->74HC595 -----------------
class FlprogParallelKS0108OnHC595Chip : public FlprogOledAbstractChip
{
public:
  void setPinRs(uint8_t pin) { _pinRs = pin; };
  void setPinEn(uint8_t pin) { _pinEn = pin; };
  void setPinRst(uint8_t pin) { _pinRst = pin; };
  void setPinCs1(uint8_t pin) { _pinCs1 = pin; };
  void setPinCs2(uint8_t pin) { _pinCs2 = pin; };
  void setPinCs3(uint8_t pin) { _pinCs3 = pin; };

  void setPinCs(uint8_t pin) { _pinCs = pin; };
  void setBus(uint8_t bus) { _bus = bus; };

  uint8_t getPinRs() { return _pinRs; };
  uint8_t getPinEn() { return _pinEn; };
  uint8_t getPinRst() { return _pinRst; };
  uint8_t getPinCs1() { return _pinCs1; };
  uint8_t getPinCs2() { return _pinCs2; };
  uint8_t getPinCs3() { return _pinCs3; };

  uint8_t getPinCs() { return _pinCs; };
  uint8_t getBus() { return _bus; };

  RT_HW_OLED_Bus *mainBus() { return &_mainBus; };

  RT_HW_OLED_SEQ8_Bus _mainBus;

protected:
  void busInit();
  void init() { _device.setParamDev_KS0108(_device.num, _extNum); };

  uint8_t _pinRs = 255;
  uint8_t _pinEn = 255;
  uint8_t _pinRst = 255;
  uint8_t _pinCs1 = 255;
  uint8_t _pinCs2 = 255;
  uint8_t _pinCs3 = 255;
  uint8_t _pinCs = 255;
  uint8_t _bus = 0;
};

// --------------------- Чип KS0108<->2x74HC595 -----------------
class FlprogParallelKS0108On2xHC595Chip : public FlprogOledAbstractChip
{
public:
  void setPinCs(uint8_t pin) { _pinCs = pin; };
  void setBus(uint8_t bus) { _bus = bus; };

  uint8_t getPinCs() { return _pinCs; };
  uint8_t getBus() { return _bus; };

  RT_HW_OLED_Bus *mainBus() { return &_mainBus; };

  RT_HW_OLED_SEQ16_Bus _mainBus;

protected:
  void busInit();
  void init() { _device.setParamDev_KS0108(_device.num, _extNum); };

  uint8_t _pinCs = 255;
  uint8_t _bus = 0;
};