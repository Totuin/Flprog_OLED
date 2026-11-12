#pragma once
#include <cstdint>
#include <cstddef>
#include <string>
#include <sstream>
#include <cstring>
#include <climits>
#include "RT_HW_OLED.h"
class String {
public:
    std::string s;
    String() = default;
    String(const char* x): s(x ? x : "") {}
    String(const std::string& x):s(x){}
    String(const String&)=default;
    String& operator=(const String&)=default;
    bool equals(const String& other) const{return s == other.s;}
    unsigned int length() const{return static_cast<unsigned int>(s.size());}
    char operator[](unsigned int i) const{return s[i];}
    void remove(unsigned int idx){if(idx<s.size())s.erase(idx);}
};
struct RT_HW_MESS_ID { String str; char sign1=0;char sign0=0; };
class MockBase {
public:
    bool isTimer(uint32_t, uint32_t) {return false;}
    size_t getLenUTF8(const String &v) {
        size_t n=0;
        for (unsigned char ch :v.s) if ((ch & 0xC0)!=0x80)++n;
        return n;
    }
    template<typename T> void messSetVar(RT_HW_MESS_ID& out, T val, char) {
        std::ostringstream ss; ss << val; out.str = String(ss.str());
    }
    void messSetVar(RT_HW_MESS_ID& out, const String& val, char){out.str=val;}
};
extern MockBase RT_HW_Base;
inline uint32_t millis(){return 0;}
#define FLPROG_READY_STATUS 1
#define FLPROG_NOT_REDY_STATUS 0
class AbstractFLProgClass {
public: virtual void setFlags(){};
protected: uint8_t _status=FLPROG_NOT_REDY_STATUS;
};
