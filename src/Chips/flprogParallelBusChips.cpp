#include "flprogParallelBusChips.h"

void FlprogParallelKS0108Chip::busInit()
{
  _mainBus.setPinCtrl(_pinRs, _pinEn, _pinCs1, _pinRst, _pinCs2, _pinCs3);
  _mainBus.setPinData(_pinD0, _pinD1, _pinD2, _pinD3, _pinD4, _pinD5, _pinD6, _pinD7);
  _mainBus.setChipMap(0, 1, 2);
  _mainBus.setParamPAR8(_device.num);
}

void FlprogParallelKS0108OnHC595Chip::busInit()
{
  _mainBus.setPinCtrl(_pinRs, _pinEn, _pinCs1, _pinRst, _pinCs2, _pinCs3);
  _mainBus.setSpiParam(_pinCs, _bus, 0);
  _mainBus.setChipMap(0, 1, 2);
  _mainBus.setParamPAR8(_device.num);
}

void FlprogParallelKS0108On2xHC595Chip::busInit()
{
  _mainBus.setChipMap(0, 1, 2);
  _mainBus.setSpiParam(_pinCs, _bus, 8000000);
  _mainBus.setParamSEQ16(_device.num);
}