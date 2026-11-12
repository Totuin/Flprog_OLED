#pragma once
#include "flprogUtilites.h"
#include "Widgets/flprogOledAbstractWidget.h"

// Логический экран: набор указателей на виджеты, отрисовываемых в общий framebuffer.
class FlprogOledScreen : public AbstractFLProgClass
{
public:
  // Виджеты не принадлежат экрану; освобождается лишь таблица указателей.
  FlprogOledScreen() {};
  FlprogOledScreen(uint16_t widgetsSize);
  ~FlprogOledScreen();
  FlprogOledScreen(const FlprogOledScreen &) = delete;
  FlprogOledScreen &operator=(const FlprogOledScreen &) = delete;

  // При изменении размера сохраняет уже назначенные виджеты в доступных слотах.
  void setWidgetsSize(uint16_t widgetsSize);
  void setWidget(uint16_t index, FlprogOledAbstractWidget *widget);

  bool isNeedRepaint();
  void setIsNeedRepaint();

  void isActive(bool value);
  bool getIsActive() { return _isActive; };
  void displayOn(FlprogOledAbstractChip *chip);

protected:
  FlprogOledAbstractWidget **_widgets = 0;
  uint16_t _widgetsSize = 0;
  bool _isActive = true;
  bool _needsRepaint = false; // Смена состояния/набора виджетов меняет весь кадр.
};