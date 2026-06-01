#pragma once
#include "flprogUtilites.h"
#include "flprogOledTextWidget.h"

#define FLPROG_OLED_INTX_VALUE_MODE 'I'              // -- mode:I-intx
#define FLPROG_OLED_UINTX_VALUE_MODE 'U'             // -- U-uintx
#define FLPROG_OLED_ZERO_HEX_VALUE_MODE 'H'          // -- H-HEX c добавлением впереди 0x
#define FLPROG_OLED_HEX_VALUE_MODE 'h'               // -- h-HEX без добавления впереди 0
#define FLPROG_OLED_LSB_BIN_VALUE_MODE 'B'           // -- B-BIN двоичная впереди младший бит
#define FLPROG_OLED_MSB_BIN_VALUE_MODE 'b'           // -- b-BIN впереди старший бит
#define FLPROG_OLED_CHAR_UPPERCASE_VALUE_MODE 'C'    // -- C-char заглавные буквы
#define FLPROG_OLED_CHAR_LOWERCASE_VALUE_MODE 'c'    // -- c-char прописные буквы
#define FLPROG_OLED_UINT8_PIN_VALUE_MODE 'D'         // -- D-pin  значение uint8_t
#define FLPROG_OLED_NAME_PIN_VALUE_MODE 'T'          // -- T-pin  наименование(PA0,D1)
#define FLPROG_OLED_UINT8_NAME_PIN_VALUE_MODE 'A'    // -- A-pin  наименование+значение uint8_t
#define FLPROG_OLED_UINT8_ADDRESS_VALUE_MODE 'd'     // -- d-addr значение uint8_t
#define FLPROG_OLED_HEX_ADDRESS_VALUE_MODE 't'       // -- t-addr значение HEX
#define FLPROG_OLED_HEX_UINT8_ADDRESS_VALUE_MODE 'a' // -- a-addr значение HEX/значение uint8_t
#define FLPROG_OLED_TIME_LEADING_ZERO_VALUE_MODE 'M' // -- M-формат времени с дополнением впереди '0';	m-формат времени с дополнением впереди '0'
#define FLPROG_OLED_IP_ADDRESS_VALUE_MODE 'E'        // -- E-IP адрес из uint32_t;
#define FLPROG_OLED_FLOAT_0_VALUE_MODE '0'           // -- 0 знаков после точки for float,uintx;
#define FLPROG_OLED_FLOAT_1_VALUE_MODE '1'           // -- 1  знаков после точки for float,uintx;
#define FLPROG_OLED_FLOAT_2_VALUE_MODE '2'           // -- 2  знаков после точки for float,uintx;
#define FLPROG_OLED_FLOAT_3_VALUE_MODE '3'           // -- 3  знаков после точки for float,uintx;
#define FLPROG_OLED_FLOAT_4_VALUE_MODE '4'           // -- 4  знаков после точки for float,uintx;
#define FLPROG_OLED_STRING_UPPERCASE_VALUE_MODE 'U'  // -- U-String заглавные буквы
#define FLPROG_OLED_STRING_LOWERCASE_VALUE_MODE 'L'  // -- L-String прописные буквы
#define FLPROG_OLED_NOT_CHANDGE_VALUE_MODE 'S'       // -- S-String строка без изменения

#define FLPROG_OLED_LEFT_ALIGN_VALUE_MODE 'L'   // -- Выравнивание влево
#define FLPROG_OLED_RIGHT_ALIGN_VALUE_MODE 'R'  // -- Выравнивание вправо
#define FLPROG_OLED_CENTER_ALIGN_VALUE_MODE 'C' // -- Выравнивание по центру
#define FLPROG_OLED_NONE_ALIGN_VALUE_MODE '~'   // -- Нет выравнивания

class FlprogOledAbstractValueWidget : public FlprogOledAbstractWidget
{
public:
  void setInsertPoint(int16_t x, int16_t y) { _textWidget.setInsertPoint(x, y); };
  void setScale(uint8_t scale) { _textWidget.setScale(scale); };
  void setStyle(uint8_t style) { _textWidget.setStyle(style); };
  void setColorFigure(uint32_t color) { _textWidget.setColorFigure(color); };
  void setColorBorders(uint32_t color) { _textWidget.setColorBorders(color); };

  void setLength(uint8_t value);
  void setPrefix(String prefix);
  void setSuffix(String suffix);
  void setAlign(char align);
  void setMode(char mode);

  bool isNeedRepaint();

protected:
  void privateDisplayOn(FlprogOledAbstractChip *chip);
 virtual  void setValue() = 0;
  uint8_t _length = 0;
  char _align = FLPROG_OLED_NONE_ALIGN_VALUE_MODE;
  char _mode = FLPROG_OLED_NOT_CHANDGE_VALUE_MODE;
  String _prefix = "";
  String _suffix = "";
  RT_HW_MESS_ID _message;
  FlprogOledTextWidget _textWidget;
};

/*
struct RT_HW_MESS_ID {
  String  str;			   		//--Формируемая строка;
  uint8_t dir=0;					//--Номер этапа в функции;
  char    suff;					//--Суффикс строки;
  uint8_t lenVar;					//--Длина сообщения в символах;
  uint8_t lenByte;				//--Длина сообщения в байтах (с учетом кодировки Unicode8);
  uint8_t lenBegin,lenEnd;		//--Длина заполнителей спереди и сзади сообщения;
  uint8_t lenSuff:1,lenCR:1;		//--Флаг наличия суффикса;
};

*/