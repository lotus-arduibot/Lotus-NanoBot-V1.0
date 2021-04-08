#ifndef LotusNanoMotor_h
#define LotusNanoMotor_h
////////////////////////////////////////////
//////  www.lotus-arduibot.com   //////////
///////////////////////////////////////////
#include "arduino.h"
#include "wiring_private.h"
////////////////////////////////////////////
#define _LotusNano_DR1  7
#define _LotusNano_DR2  8
#define _LotusNano_PWMR 6

#define _LotusNano_DL1  9
#define _LotusNano_DL2  4
#define _LotusNano_PWML 5
////////////////////////////////////////////

void run(int spl, int spr)   
{ 
  pinMode(_LotusNano_DL1,OUTPUT);
  pinMode(_LotusNano_DL2,OUTPUT);
  pinMode(_LotusNano_PWML,OUTPUT);
  
  pinMode(_LotusNano_DR1,OUTPUT);
  pinMode(_LotusNano_DR2,OUTPUT);
  pinMode(_LotusNano_PWMR,OUTPUT);

    
  if (spl > 0)
  {
    digitalWrite(_LotusNano_DL1, LOW);
    digitalWrite(_LotusNano_DL2, HIGH);
    analogWrite(_LotusNano_PWML, spl);
  }
  else if (spl < 0)
  {
    digitalWrite(_LotusNano_DL1, HIGH);
    digitalWrite(_LotusNano_DL2, LOW);
    analogWrite(_LotusNano_PWML, -spl);
  }
  else
  {
    digitalWrite(_LotusNano_DL1, HIGH);
    digitalWrite(_LotusNano_DL2, HIGH);
  }
  ////////////////////////////////////////
  if (spr > 0)
  {
    digitalWrite(_LotusNano_DR1, LOW);
    digitalWrite(_LotusNano_DR2, HIGH);
    analogWrite(_LotusNano_PWMR, spr);
  }
  else if (spr < 0)
  {
    digitalWrite(_LotusNano_DR1, HIGH);
    digitalWrite(_LotusNano_DR2, LOW);
    analogWrite(_LotusNano_PWMR, -spr);
  }
  else
  {
    digitalWrite(_LotusNano_DR1, HIGH);
    digitalWrite(_LotusNano_DR2, HIGH);
  }
}

void fd(int a){run(a,a);}
void bk(int a){run(-a,-a);}
void sr(int a){run(a,-a);}
void sl(int a){run(-a,a);}
void tr(int a){run(a,0);}
void tl(int a){run(0,a);}
void ao(){run(0,0);}
void fd2(int a,int b){run(a,b);}
///////////////////////////////////////////
#endif
