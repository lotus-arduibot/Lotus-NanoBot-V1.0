#ifndef LotusOLED_h
#define LotusOLED_h
/////////////////////////
#include "arduino.h"
#include "Adafruit_SSD1306.h"
#include "ADAFRUIT_GFX.h"
#include "LotusIO.h"
#include "LotusCompass.h"


////////////////////////////////////////////
//////  www.lotus-arduibot.com   //////////
///////////////////////////////////////////
Adafruit_SSD1306 OLED(-1);

////////////////////////////คำสั่งทั่วไป////////////////////////////////////////
void oleddel ( ) 
{ 
  OLED.clearDisplay(); 
}
void oledset ( )  
{ OLED.begin(SSD1306_SWITCHCAPVCC,0x3C); 
  OLED.clearDisplay(); 
  OLED.setTextColor(WHITE,BLACK);
  OLED.setCursor(0,0); 
}
void oledcur (uint8_t x,uint8_t y )  
{
OLED.setCursor(x,y);    
}
void oledsize (uint8_t size )
{
OLED.setTextSize(size);
}
void oledplay ( )
{
OLED.display();    
}
////////////////////////////// OLED PRINT ////////////////////////////////////
////////////////////////////// OLED PRINT ////////////////////////////////////
////////////////////////////// OLED PRINT ////////////////////////////////////
/////////////////////////////Print input string //////////////////////////////  
void oled (uint8_t x,uint8_t y,uint8_t size,String text,int text2 )
{
OLED.setCursor(x,y); 
OLED.setTextSize(size);
OLED.print(text);  
OLED.print(text2);  
OLED.display();    
}

void oled (uint8_t x,uint8_t y,uint8_t size,String text )
{
OLED.setCursor(x,y); 
OLED.setTextSize(size);
OLED.print(text);  
OLED.display();    
}
void oled (String text )
{
OLED.print(text);  
OLED.display();    
}
/////////////////////////////Print input Int //////////////////////////////  
void oled (uint8_t x,uint8_t y,uint8_t size,int text )
{
OLED.setCursor(x,y); 
OLED.setTextSize(size);
OLED.print(text);  
OLED.display();    
}

void oled (String text,int text1 )
{

OLED.print(text);  
OLED.print(text1);  
OLED.display();    
} 

void oled (int text )
{ 
OLED.print(text);  
OLED.display();    
}
////////////////////////////// OLED PRINTln ////////////////////////////////
////////////////////////////// OLED PRINTln ////////////////////////////////
////////////////////////////// OLED PRINTln ////////////////////////////////
////////////////////////////// OLED PRINTln ////////////////////////////////
void oledln (uint8_t x,uint8_t y,uint8_t size,String text,int text2 )
{
OLED.setCursor(x,y); 
OLED.setTextSize(size);
OLED.print(text);  
OLED.println(text2);  
OLED.display();    
}

void oledln (uint8_t x,uint8_t y,uint8_t size,String text )
{
OLED.setCursor(x,y); 
OLED.setTextSize(size);
OLED.println(text);  
OLED.display();    
}

void oledln (String text )
{
OLED.println(text);  
OLED.display();    
}
/////////////////////////////Println input Int //////////////////////////////  
void oledln (uint8_t x,uint8_t y,uint8_t size,int text )
{
OLED.setCursor(x,y); 
OLED.setTextSize(size);
OLED.println(text);  
OLED.display();    
}
void oledln (String text,int text1 )
{

OLED.print(text);  
OLED.println(text1);  
OLED.display();    
} 
void oledln (int text )
{ 
OLED.println(text);  
OLED.display();    
}

////////////////////////////////////////////////////////
////////////////กลุ่มใช้งานร่วมกับ oledplay////////////////////////////
////////////////กลุ่มใช้งานร่วมกับ oledplay////////////////////////////
////////////////กลุ่มใช้งานร่วมกับ oledplay////////////////////////////
////////////////กลุ่มใช้งานร่วมกับ oledplay////////////////////////////
////////////////กลุ่มใช้งานร่วมกับ oledplay////////////////////////////
////////////////กลุ่มใช้งานร่วมกับ oledplay////////////////////////////
////////////////กลุ่มใช้งานร่วมกับ oledplay////////////////////////////
////////////////กลุ่มใช้งานร่วมกับ oledplay////////////////////////////
////////////////กลุ่มใช้งานร่วมกับ oledplay////////////////////////////

void oledp (uint8_t x,uint8_t y,uint8_t size,String text,int text2 )
{
OLED.setCursor(x,y); 
OLED.setTextSize(size);
OLED.print(text);  
OLED.print(text2);      
}

void oledp (uint8_t x,uint8_t y,uint8_t size,String text )
{
OLED.setCursor(x,y); 
OLED.setTextSize(size);
OLED.print(text);      
}
void oledp (String text )
{
OLED.print(text);     
}
/////////////////////////////Print input Int //////////////////////////////  
void oledp (uint8_t x,uint8_t y,uint8_t size,int text )
{
OLED.setCursor(x,y); 
OLED.setTextSize(size);
OLED.print(text);    
}

void oledp (String text,int text1 )
{

OLED.print(text);  
OLED.print(text1);      
} 

void oledp (int text )
{ 
OLED.print(text);    
}
////////////////////////////// OLED PRINTln ////////////////////////////////
////////////////////////////// OLED PRINTln ////////////////////////////////
////////////////////////////// OLED PRINTln ////////////////////////////////
////////////////////////////// OLED PRINTln ////////////////////////////////
void oledlnp (uint8_t x,uint8_t y,uint8_t size,String text,int text2 )
{
OLED.setCursor(x,y); 
OLED.setTextSize(size);
OLED.print(text);  
OLED.println(text2);      
}

void oledlnp (uint8_t x,uint8_t y,uint8_t size,String text )
{
OLED.setCursor(x,y); 
OLED.setTextSize(size);
OLED.println(text);      
}

void oledlnp (String text )
{
OLED.println(text);     
}
/////////////////////////////Println input Int //////////////////////////////  
void oledlnp (uint8_t x,uint8_t y,uint8_t size,int text )
{
OLED.setCursor(x,y); 
OLED.setTextSize(size);
OLED.println(text);    
}
void oledlnp (String text,int text1 )
{
OLED.print(text);  
OLED.println(text1);  
} 
void oledlnp (int text )
{ 
OLED.println(text);  
   
}
////////////////////////oled size //////////////////////////////
void oledp (uint8_t size,int num)
{
OLED.setTextSize(size);
OLED.print(num);    
}
void oledp (uint8_t size,String text )
{
OLED.setTextSize(size);
OLED.print(text);    
}

void oledp (uint8_t size,int num,String text)
{OLED.setTextSize(size);
OLED.print(num);  
OLED.print(text);  
}

////////////////////////
void oledlnp (uint8_t size,int num)
{
OLED.setTextSize(size);
OLED.println(num);    
}
void oledlnp (uint8_t size,String text )
{
OLED.setTextSize(size);
OLED.println(text);    
}

void oledlnp (uint8_t size,int num,String text)
{OLED.setTextSize(size);
OLED.print(num);  
OLED.println(text);  
}


//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

void lotext(){
  OLED.clearDisplay();
  OLED.setTextColor(WHITE,BLACK);   
  OLED.setCursor(10,0);      
  OLED.setTextSize(2);        
  OLED.println("  Lotus");    
  OLED.println(" Arduibot");   
  OLED.setTextSize(1);   
//  OLED.println("    LotusNanoBot"); 
  OLED.println("  lotus-arduibot.com");
  OLED.setTextSize(2); 
   OLED.print("  D2 Press");   
  OLED.display();
}
void lotextdel(){
  OLED.clearDisplay();OLED.display();
}
#endif