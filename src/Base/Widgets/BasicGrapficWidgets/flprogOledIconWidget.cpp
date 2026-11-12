#include "flprogOledIconWidget.h"

FlprogOledIconWidget::FlprogOledIconWidget(uint8_t id, int16_t x, int16_t y, int16_t w, int16_t h, int16_t index, uint8_t scale, uint8_t colorFigure, uint8_t colorBorders)
{
  _id = id;
  _x0 = x;
  _y0 = y;
  _w = w;
  _index = index;
  _h = h;
  _scale = scale;
  _colorFigure = colorFigure;
  _colorBorders = colorBorders;
}



void FlprogOledIconWidget::setSize(int16_t w, int16_t h)
{
  if ((_w == w) && (_h == h))
  {
    return;
  }
  _isNeedRepaint = true;
  _w = w;
  _h = h;
}

void FlprogOledIconWidget::setScale(int8_t scale)
{
  // Подпись метода оставлена int8_t для совместимости с генерируемым кодом.
  // Отрицательный масштаб не приводим к огромному uint8_t (например, -1 -> 255).
  if (scale < 0 || _scale == static_cast<uint8_t>(scale)) {return;}
  _isNeedRepaint = true;
  _scale = static_cast<uint8_t>(scale);
}

void FlprogOledIconWidget::setIndex(int16_t index)
{
  if (_index == index)
  {
    return;
  }
  _isNeedRepaint = true;
  _index = index;
}

void FlprogOledIconWidget::privateDisplayOn(FlprogOledAbstractChip *chip)
{
  // Индекс поступает из генерируемой схемы и может быть -1 до выбора иконки.
  // Размер таблицы получаем из заголовка RT_HW_OLED, без жёсткой константы.
  const size_t iconCount = sizeof(icons_8x8) / sizeof(icons_8x8[0]);
  if (_index < 0 || static_cast<size_t>(_index) >= iconCount) {return;}
  // Таблица в RT_HW_OLED хранит только 8x8 (8 байт на иконку).
  // Передача произвольных w/h из setSize() приводила к чтению за границей 8-байтной записи.
  if (_w <= 0 || _h <= 0) {return;}
  const int16_t width = _w > 8 ? 8 : _w;
  const int16_t height = _h > 8 ? 8 : _h;
  chip->_device.iconEx(_id, _x0, _y0, width, height, icons_8x8[_index], _scale, _colorFigure, _colorBorders);
}