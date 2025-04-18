#ifndef TM1651_H
#define TM1651_H

#include <Arduino.h>
#include <inttypes.h>

//************ Definitions for TM1651 *********************
#define ADDR_AUTO  0x40
#define ADDR_FIXED 0x44
#define STARTADDR  0xC0 

// Definitions for the decimal point
#define DP_ON   1
#define DP_OFF  0

//************** Definitions for brightness ***********************/
#define BRIGHT_DARKEST 0
#define BRIGHT_TYPICAL 2
#define BRIGHTEST      7

class TM1651 {
public:
    TM1651(uint8_t clk, uint8_t data);
    int writeByte(int8_t wr_data);
    void start(void);
    void stop(void);
    void displayNum(uint8_t pos, uint8_t num);
    void displayInteger(uint16_t num);
    void displayDP(uint8_t pos);
    void displayClear(void);
    void displaySet(uint8_t brightness = BRIGHT_TYPICAL);
    void displayOff();

private:
    uint8_t Clkpin;
    uint8_t Datapin;
    uint8_t Cmd_DispCtrl;
    void bitDelay(void);
};

#endif
