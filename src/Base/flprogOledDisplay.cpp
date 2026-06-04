#include "flprogOledDisplay.h"

FlprogOledDisplay::FlprogOledDisplay(uint16_t screensSize)
{
  _screensSize = screensSize;
  if (_screensSize == 0)
  {
    return;
  }
  _screens = new FlprogOledScreen *[_screensSize];
}

bool FlprogOledDisplay::isNeedRepaint()
{
  if (_screensSize == 0)
  {
    return false;
  }
  for (uint16_t i = 0; i < _screensSize; i++)
  {
    if (_screens[i] != 0)
    {
      if (_screens[i]->isNeedRepaint())
      {
        _isShow = true;
        return true;
      }
    }
  }
  if (_isShow)
  {
    _isShow = false;
    return true;
  }
  return false;
}

void FlprogOledDisplay::setIsNeedRepaint()
{
  if (_screensSize == 0)
  {
    return;
  }
  for (uint16_t i = 0; i < _screensSize; i++)
  {
    if (_screens[i] != 0)
    {
      _screens[i]->setIsNeedRepaint();
    }
  }
}

void FlprogOledDisplay::setEn(uint8_t value)
{
  if (_en == value)
  {
    return;
  }
  if (!_en)
  {
    setIsNeedRepaint();
  }
  _en = value;
}

void FlprogOledDisplay::displayOn(FlprogOledAbstractChip *chip)
{

  if (_screensSize == 0)
  {
    return;
  }
  if (!RT_HW_oled.checkDev(chip->getNum()))
  {
    return;
  }

  chip->_device.direct(_en);
  chip->_device.sendDevice();
  if (chip->_device.runDevice)
  {
    return;
  }
  if (!isNeedRepaint())
  {
    return;
  }
  chip->_device.clear(0, 0);
  for (uint16_t i = 0; i < _screensSize; i++)
  {
    if (_screens[i] != 0)
    {
      _screens[i]->displayOn(chip);
    }
  }
  chip->_device.runDevice = 1;
}

void FlprogOledDisplay::setScreen(uint16_t index, FlprogOledScreen *screen)
{
  if (_screensSize == 0)
  {
    return;
  }
  if (index >= _screensSize)
  {
    return;
  }
  if (screen == 0)
  {
    return;
  }
  _screens[index] = screen;
}