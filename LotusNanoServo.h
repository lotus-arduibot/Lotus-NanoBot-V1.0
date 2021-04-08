#ifndef LotusNanoServo_h
#define LotusNanoServo_h
////////////////////////////////////////////
//////  www.lotus-arduibot.com   //////////
///////////////////////////////////////////
#include "Servo.h"
// flags for function set
#define _lotus_servo1 10
#define _lotus_servo2 11
#define _lotus_servo3 12
Servo lotus_servo1;
Servo lotus_servo2;
Servo lotus_servo3;
#ifndef ALL
#define ALL 100
#endif

void servo(uint8_t servo,int16_t angle)
{
  if (servo==ALL)
  {
    if (angle==-1)
	{
	  lotus_servo1.detach();
	  lotus_servo2.detach();
	  lotus_servo3.detach();
	}
	else
	{
      if (!(lotus_servo1.attached()))
	  {
		lotus_servo1.attach(_lotus_servo1);
	  }
	  lotus_servo1.write(angle);

      if (!(lotus_servo2.attached()))
	  {
		lotus_servo2.attach(_lotus_servo2);
	  }
	 lotus_servo2.write(angle);

      if (!(lotus_servo3.attached()))
	  {
		lotus_servo3.attach(_lotus_servo3);
	  }
	  lotus_servo3.write(angle);
	}
  }
  if (servo==1)
  {
    if (angle==-1)
	{
	 lotus_servo1.detach();
	}
	else
	{
      if (!(lotus_servo1.attached()))
	  {
		lotus_servo1.attach(_lotus_servo1);
	  }
	  lotus_servo1.write(angle);
	}
  }
  if (servo==2)
  {
    if (angle==-1)
	{
	 lotus_servo2.detach();
	}
	else
	{
      if (!(lotus_servo2.attached()))
	  {
		lotus_servo2.attach(_lotus_servo2);
	  }
	 lotus_servo2.write(angle);
	}
  }
  if (servo==3)
  {
    if (angle==-1)
	{
	 lotus_servo3.detach();
	}
	else
	{
      if (!(lotus_servo3.attached()))
	  {
		lotus_servo3.attach(_lotus_servo3);
	  }
	  lotus_servo3.write(angle);
	}
  }
}

void sv1(int16_t angle){lotus_servo1.attach(_lotus_servo1);lotus_servo1.write(angle);}
void sv2(int16_t angle){lotus_servo2.attach(_lotus_servo2);lotus_servo2.write(angle);}
void sv3(int16_t angle){lotus_servo3.attach(_lotus_servo3);lotus_servo3.write(angle);}



//////////
#endif
