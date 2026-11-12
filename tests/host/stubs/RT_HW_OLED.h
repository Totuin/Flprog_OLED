#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <cassert>
// This host-only stub is not shipped as a replacement for RT_HW_OLED.
constexpr uint32_t RT_HW_OLED_FILL_NO=0xFFFFFFFFu;
constexpr uint32_t RT_HW_OLED_FILL_WHITE=0xFFFFFFu;
constexpr uint32_t RT_HW_OLED_FILL_BLACK=0;
constexpr uint8_t RT_HW_OLED_TEXT_BOLD=1;
constexpr uint8_t RT_HW_OLED_TEXT_ITALIC_R=2;
const static uint8_t icons_8x8[][8] = {{1,2,3,4,5,6,7,8}, {1,2,3,4,5,6,7,8}, {1,2,3,4,5,6,7,8}};
struct RT_HW_STRUCT_I2C_DEV {};
struct RT_HW_STRUCT_SPI_DEV {};
struct RT_HW_OLED_Bus {virtual ~RT_HW_OLED_Bus()=default;};
struct RT_HW_OLED_I2C_Bus:RT_HW_OLED_Bus {explicit RT_HW_OLED_I2C_Bus(RT_HW_STRUCT_I2C_DEV*){}; void setParamI2C(uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint32_t){};};
struct RT_HW_OLED_SPI_Bus:RT_HW_OLED_Bus {explicit RT_HW_OLED_SPI_Bus(RT_HW_STRUCT_SPI_DEV*){};void setParamSPI(uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint32_t){};};
struct RT_HW_OLED_PAR8_Bus:RT_HW_OLED_Bus {void setPinCtrl(uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t){}; void setPinData(uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t){};void setChipMap(uint8_t,uint8_t,uint8_t){};void setParamPAR8(uint8_t){};};
struct RT_HW_OLED_SEQ8_Bus:RT_HW_OLED_PAR8_Bus {void setSpiParam(uint8_t,uint8_t,uint32_t){};void setParamSEQ8(uint8_t){};};
struct RT_HW_OLED_SEQ16_Bus:RT_HW_OLED_SEQ8_Bus {void setParamSEQ16(uint8_t){};};
class String;
struct RT_HW_OLED_Device {
    uint8_t num=0; bool runDevice=false;bool sendInProgress=false;uint8_t modeScreen=0;
    RT_HW_OLED_Bus*bus=nullptr;
    int iconCount=0, rectCount=0, drawCount=0, clearCount=0;
    std::vector<std::string> text;
    std::vector<int> positions;
    void direct(uint8_t){};
    void sendDevice(){runDevice=false;};
    void clear(uint8_t,uint32_t){++clearCount;};
    void setPeriodLimit(uint16_t){};
    void setScreenSize(uint16_t,uint16_t){};
    void setRotation(uint16_t){};
    void setContrast(uint8_t){};
    void setOffSetX(int16_t){};
    void setOffSetY(int16_t){};
    void setMirrorX(uint8_t){};
    void setMirrorY(uint8_t){};
    void setModeCPU(int32_t=0){};
    void setModeDMA(int32_t=0){};
    void line(uint8_t,int16_t,int16_t,int16_t,int16_t,uint32_t,uint8_t){};
    void circle(uint8_t,int16_t,int16_t,int16_t,uint32_t,uint32_t,uint8_t){};
    void rect(uint8_t,int16_t,int16_t,int16_t,int16_t,uint32_t,uint32_t,uint8_t){++rectCount;};
    void iconEx(uint8_t,int16_t,int16_t,int16_t w,int16_t h,const uint8_t*,uint8_t,uint32_t,uint32_t){assert(w>0&&w<=8&&h>0&&h<=8);++iconCount;};
    void drawString(uint8_t,int16_t,int16_t,const String&,uint8_t,uint8_t,uint32_t,uint32_t);
#define PARAM(X) void setParamDev_##X(uint8_t,uint8_t){}
    PARAM(CH1107) PARAM(CH1115) PARAM(SH1106) PARAM(SH1107) PARAM(SSD1306) PARAM(SSD1309)
    PARAM(SSD1312) PARAM(SSD1315) PARAM(ST7567S) PARAM(SSD1322_27) PARAM(SSD1322_31)
    PARAM(ST7565) PARAM(ST7920) PARAM(ILI9163) PARAM(ILI9225) PARAM(ILI9341) PARAM(ILI9486)
    PARAM(ST7735) PARAM(ST7789) PARAM(ST7796) PARAM(KS0108)
#undef PARAM
};
struct RT_HW_OLED {
    uint8_t addDevice(RT_HW_OLED_Device* d){d->num=1;return 1;}
    bool checkDev(uint8_t n){return n!=0;}
};
extern RT_HW_OLED RT_HW_oled;
