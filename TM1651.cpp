#include "TM1651.h"
#include <Arduino.h>

static int8_t NumTab[] = 
{ 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f,
  0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71,
  0x00, 0x63, 0x5c, 0x01, 0x40, 0x08
}; // Numbers 0-9, A-F, and special characters

TM1651::TM1651(uint8_t Clk, uint8_t Data)
{
  Clkpin = Clk;
  Datapin = Data;
  pinMode(Clkpin, OUTPUT);
  pinMode(Datapin, OUTPUT);
}

int TM1651::writeByte(int8_t wr_data)
{
  uint8_t i, ack;
  for (i = 0; i < 8; i++)  // Send 8 bits
  { 
    digitalWrite(Clkpin, LOW);
    digitalWrite(Datapin, (wr_data & 0x01) ? HIGH : LOW); // LSB first
    wr_data >>= 1;
    digitalWrite(Clkpin, HIGH);
  }
  
  digitalWrite(Clkpin, LOW); // Wait for ACK
  digitalWrite(Datapin, HIGH);
  digitalWrite(Clkpin, HIGH);
  pinMode(Datapin, INPUT);

  bitDelay(); 
  ack = digitalRead(Datapin);
  
  if (ack == 0)  
  {  
    pinMode(Datapin, OUTPUT);
    digitalWrite(Datapin, LOW);
  }
  
  bitDelay();
  pinMode(Datapin, OUTPUT);
  bitDelay();

  return ack;
}

void TM1651::start(void)
{
  digitalWrite(Clkpin, HIGH);
  digitalWrite(Datapin, HIGH);
  digitalWrite(Datapin, LOW);
  digitalWrite(Clkpin, LOW);
}

void TM1651::stop(void)
{
  digitalWrite(Clkpin, LOW);
  digitalWrite(Datapin, LOW);
  digitalWrite(Clkpin, HIGH);
  digitalWrite(Datapin, HIGH);
}

void TM1651::displayNum(uint8_t dig, uint8_t number)
{
  start();
  writeByte(ADDR_FIXED);
  stop();
  
  start();
  writeByte(STARTADDR + dig); // Digit position (0-2)
  writeByte(NumTab[number]);
  stop();
  
  start();
  writeByte(Cmd_DispCtrl); // 88 + brightness (0-7), 88=display ON
  stop();
}

void TM1651::displayInteger(uint16_t number)
{
  if (number > 999) number = 999;
  
  start();
  writeByte(ADDR_AUTO);
  stop();
  
  start();
  writeByte(STARTADDR);
  writeByte(NumTab[(number / 100) % 10]);
  writeByte(NumTab[(number / 10) % 10]);
  writeByte(NumTab[number % 10]);
  stop();
  
  start();
  writeByte(Cmd_DispCtrl);
  stop();
}

void TM1651::displayDP(uint8_t dp)
{
  start();
  writeByte(ADDR_FIXED);
  stop();
  
  start();
  writeByte(STARTADDR + 3); // Decimal position
  writeByte(dp);
  stop();
  
  start();
  writeByte(Cmd_DispCtrl);
  stop();
}

void TM1651::displayClear(void)
{
  displayDP(0);
  displayInteger(0);
}

void TM1651::displaySet(uint8_t brightness)
{
  Cmd_DispCtrl = 0x88 + brightness; // Set brightness and turn on
}

void TM1651::displayOff()
{
  Cmd_DispCtrl = 0x80;
  start();
  writeByte(Cmd_DispCtrl);
  stop();
}

void TM1651::bitDelay(void)
{
  delayMicroseconds(50); // The delay function is retained
}
