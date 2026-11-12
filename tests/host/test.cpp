#include <cassert>
#include <iostream>
#include <limits>
#include "flprogOled.h"
MockBase RT_HW_Base;
RT_HW_OLED RT_HW_oled;
void RT_HW_OLED_Device::drawString(uint8_t, int16_t x,int16_t y,const String& s,uint8_t,uint8_t,uint32_t,uint32_t){++drawCount;text.push_back(s.s);positions.push_back(x);positions.push_back(y);}

struct TestGauge:FlprogOledGaudeWidget {
    using FlprogOledGaudeWidget::levelPoint;
    using FlprogOledGaudeWidget::FlprogOledGaudeWidget;
};

int main(){
    // Unassigned slots must be null and never dereferenced.
    FlprogOledDisplay display(3);
    assert(!display.isNeedRepaint());
    FlprogOledScreen screen(3);
    assert(screen.isNeedRepaint()); // создание пустых слотов тоже требует очистки/перерисовки
    FlprogOledTextWidget label(1,0,0,String("a"),1,0,0,0);
    screen.setWidget(1,&label);
    assert(screen.isNeedRepaint());
    screen.setWidgetsSize(5);
    assert(screen.isNeedRepaint());
    screen.setWidgetsSize(2);
    assert(screen.isNeedRepaint());
    screen.setWidget(0,&label);
    display.setScreen(1,&screen);
    assert(display.isNeedRepaint());

    FlprogOledI2cChip chip;
    chip.pool(true);
    assert(chip.getNum()==1);
    chip._device.sendInProgress=true;
    display.displayOn(&chip);
    assert(chip._device.clearCount==0);
    chip._device.sendInProgress=false;
    display.displayOn(&chip);
    assert(chip._device.clearCount==1);
    assert(chip._device.runDevice);
    // Deactivating one of multiple screens must trigger a full redraw.
    FlprogOledScreen second(1);
    FlprogOledTextWidget secondLabel(2,4,4,String("B"),1,0,0,0);
    second.setWidget(0,&secondLabel);
    display.setScreen(2,&second);
    chip._device.runDevice=false;
    display.displayOn(&chip);
    const int clearBefore = chip._device.clearCount;
    screen.isActive(false);
    chip._device.runDevice=false;
    display.displayOn(&chip);
    assert(chip._device.clearCount == clearBefore+1);
    screen.isActive(true);
    chip._device.runDevice=false;
    display.displayOn(&chip);
    screen.setWidgetsSize(0);
    chip._device.runDevice=false;
    const int clearBeforeEmpty = chip._device.clearCount;
    display.displayOn(&chip);
    assert(chip._device.clearCount==clearBeforeEmpty+1);
    display.setScreen(2,nullptr);
    chip._device.runDevice=false;
    const int clearBeforeDetach=chip._device.clearCount;
    display.displayOn(&chip);
    assert(chip._device.clearCount==clearBeforeDetach+1);

    // Icon out-of-range must not access either side of the driver's icon table.
    FlprogOledIconWidget icon(1,0,0,8,8,-1,1,1,0);
    icon.displayOn(&chip);
    assert(chip._device.iconCount==0);
    icon.setIndex(3);icon.displayOn(&chip);assert(chip._device.iconCount==0);
    icon.setIndex(2);icon.displayOn(&chip);assert(chip._device.iconCount==1);
    icon.setSize(256,256);icon.displayOn(&chip);assert(chip._device.iconCount==2);
    icon.setScale(-1); // Недопустимое значение не превращается в 255.

    // List mapping: updating a label with unchanged numeric value must repaint.
    FlprogOledNumberListValueWidget values(1,0,0,1,0,1,0,2);
    values.setLength(12);
    values.setDefaultText("unknown");
    values.setTextItem(0,5,"five");
    values.setValue(5);
    values.displayOn(&chip);
    assert(chip._device.text[chip._device.text.size()-2]=="five");
    values.setTextItem(0,5,"FIVE");
    assert(values.isNeedRepaint());
    values.displayOn(&chip);
    assert(chip._device.text[chip._device.text.size()-2]=="FIVE");
    values.setValue(6);values.displayOn(&chip);
    assert(chip._device.text[chip._device.text.size()-2]=="unknown");

    FlprogOledFloatListValueWidget floats(1,0,0,1,0,1,0,2);
    floats.setLength(8);floats.setDefaultText("none");floats.setTextItem(0,0.5f,"half");floats.setValue(0.5f);
    floats.displayOn(&chip);assert(chip._device.text[chip._device.text.size()-2]=="half");
    floats.setTextItem(0,0.5f,"HALF");floats.displayOn(&chip);
    assert(chip._device.text[chip._device.text.size()-2]=="HALF");

    FlprogOledBooleanListValueWidget flags(1,0,0,1,0,1,0);
    flags.setLength(10);flags.setFalseText("OFF");flags.setTrueText("ON");
    flags.displayOn(&chip);assert(chip._device.text[chip._device.text.size()-2]=="OFF");
    flags.setFalseText("NO");flags.displayOn(&chip);
    assert(chip._device.text[chip._device.text.size()-2]=="NO");

    // UTF-8 code point boundary and negative coordinates.
    FlprogOledStringValueWidget str(1,-15,-3,1,0,1,0);
    str.setLength(3);str.setValue(String(u8"Привет"));str.displayOn(&chip);
    assert(chip._device.text[chip._device.text.size()-2]==u8"При");
    assert(chip._device.positions[chip._device.positions.size()-4]<0);

    // 32-bit extremes and interpolation of gauge (no signed overflow).
    TestGauge gauge(1,0,0,120,30,1,0,1);
    gauge.setMinValue(std::numeric_limits<int32_t>::min());
    gauge.setMaxValue(std::numeric_limits<int32_t>::max());
    gauge.setValue(0);
    assert(gauge.levelPoint(120,0)==60);
    gauge.displayOn(&chip);
    std::cout << "OLED_HOST_TEST_PASS\n";
}
