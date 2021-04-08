//------------------------------------------------------------------------------------------------//
// Program	: Library for gennerate sound   
// Description 	: Library for gennerate easy sound
// Frequency	: Crytal 12 MHz at PLL 5x(CCLK = 60 MHz),PCLK = 30 MHz 
// Filename	: sound.h
// C compiler	: Keil CARM Compiler
//------------------------------------------------------------------------------------------------//
#ifndef LotusNanoSound_h
#define LotusNanoSound_h

#include "pins_arduino.h"
#include "wiring_private.h"
#define Lotus_snd_PIN 3
void __delay_sound(uint16_t ms) // private
{
	unsigned int i;
	for(i=0;i<ms;i++)
    delayMicroseconds(10);
}

void snd(uint16_t freq,uint32_t time)
{
	uint32_t dt=0,m=0;	// Keep value and 
	uint32_t tempTime;
	digitalWrite(Lotus_snd_PIN,LOW);
    pinMode(Lotus_snd_PIN,OUTPUT);
    tempTime=time*50;
    dt = 50000/freq;   	// Keep active logic delay
	time = (tempTime)/dt;	// Keep counter for generate sound
	for(m=0;m<time;m++) // Loop for generate sound(Toggle logic P0.12)   
	{
	  digitalWrite(Lotus_snd_PIN,HIGH);
	  __delay_sound(dt);
	  digitalWrite(Lotus_snd_PIN,LOW);
	  __delay_sound(dt);
	}		
}
void sound(uint16_t freq,uint32_t time)
{
	uint32_t dt=0,m=0;	// Keep value and 
	uint32_t tempTime;
	digitalWrite(Lotus_snd_PIN,LOW);
    pinMode(Lotus_snd_PIN,OUTPUT);
    tempTime=time*50;
    dt = 50000/freq;   	// Keep active logic delay
	time = (tempTime)/dt;	// Keep counter for generate sound
	for(m=0;m<time;m++) // Loop for generate sound(Toggle logic P0.12)   
	{
	  digitalWrite(Lotus_snd_PIN,HIGH);
	  __delay_sound(dt);
	  digitalWrite(Lotus_snd_PIN,LOW);
	  __delay_sound(dt);
	}		
}
void beep(){snd(900,100);}
#endif



