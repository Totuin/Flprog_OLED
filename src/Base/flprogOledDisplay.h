#pragma once
#include "flprogUtilites.h"
#include "flprogOledScreen.h"

// Контейнер экранов одного дисплея; рисование происходит после завершения предыдущей передачи.
class FlprogOledDisplay : public AbstractFLProgClass
{
public:
  // Экраны принадлежат вызывающему коду; этот объект владеет только массивом указателей.
  FlprogOledDisplay(uint16_t screensSize);
  ~FlprogOledDisplay();
  FlprogOledDisplay(const FlprogOledDisplay &) = delete;
  FlprogOledDisplay &operator=(const FlprogOledDisplay &) = delete;

  void setEn(bool value);
  bool getEn() { return _en; };

  bool isNeedRepaint();
  void setIsNeedRepaint();
  void setScreen(uint16_t index, FlprogOledScreen *screen);

  // Вызывается из loop(): обслуживает передачу и рисует новый кадр лишь при изменении.
  void displayOn(FlprogOledAbstractChip *chip);

protected:
  bool _en = true;
  FlprogOledScreen **_screens = 0;
  uint16_t _screensSize = 0;
  bool _isShow = false;
  bool _needsRepaint = false; // Замена/удаление экрана требует очистить прошлый кадр.
};