//////////////////////////////////
////บทความที่เกี่ยวข้อง https://sites.google.com/site/klsrobotcenter/lab-8-line-tracking-lotus-nano-bot
/////////////////////////////////
//////////////////ผนวกไลบรารี่จอแสดงผล//////////////////
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 OLED(-1);
///////////ตั้งค่าปุ่มกด///////////////////
int button =  2; /// กำหนดปุ่มกดสวิตซ์ขา 2
////////////ตั้งค่าพอร์ตมอเตอร์////////////////////
#define DR1  7  /// กำหนดสัญญาณดิจิตอลขวาที่ 1 พอร์ต 7
#define DR2  8  /// กำหนดสัญญาณดิจิตอลขวาที่ 2 พอร์ต 8
#define PWMR 6 /// กำหนดสัญญาณ PWM ขวาพอร์ต 6
/////////////////////////////////
#define DL1  9  // กำหนดสัญญาณดิจิตอลซ้ายที่ 1 พอร์ต 9
#define DL2  4  // กำหนดสัญญาณดิจิตอลซ้ายที่ 2 พอร์ต 4
#define PWML 5  /// กำหนดสัญญาณ PWM ซ้ายพอร์ต 5
/////////////////ตั้งค่าพอร์ต Analog//////////////
#define A0 200  // ค่ากลางเซนเซอร์ A0 (ซ้ายสุด)
#define A1 200  // ค่ากลางเซนเซอร์ A1 (ซ้ายกลาง)
#define A2 200  // ค่ากลางเซนเซอร์ A2 (ขวากลาง)
#define A3 200  // ค่ากลางเซนเซอร์ A3 (ขวาสุด)
/////////////////////////////////////////////////////
void setup() {
  OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C); // กำหนดแอดเดรสของพอร์ตจอเป็น 0x3C
   //////////////////////////////////////////////////
  pinMode(2, INPUT); // ตั้งค่าขา 2 เป็น INPUT
   ////////กำหนดสัญญาณทุกขาเป็น OUTPUT ///////////////
  pinMode(DL1, OUTPUT);
  pinMode(DL2, OUTPUT);
  pinMode(PWML, OUTPUT);
  pinMode(DR1, OUTPUT);
  pinMode(DR2, OUTPUT);
  pinMode(PWMR, OUTPUT);
  ////////////////////////////
}
void loop() {
  int sw = digitalRead(button);
if (sw==0){while(true){
  /////////// ตั้งค่าเซนเซอร์ตามการอ่านพอร์ตอนาล็อก S0,S1,S2,S3
  int s0 = analogRead(0);
  int s1 = analogRead(1);
  int s2 = analogRead(2);
  int s3 = analogRead(3);
 ////////////////////////////////////////////////////////
/*
  OLED.clearDisplay();
  OLED.setTextColor(WHITE, BLACK);  //สีอักษรเป็นสีขาว ,พื้นหลังดำ
  OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
  OLED.setTextSize(1);        // เซตขนาดอักษรมีขนาดเป็น 1
  OLED.print("       S0 = "); OLED.println(s0);  // แสดงค่าเซนเซอร์ S0
  OLED.print("       S1 = "); OLED.println(s1);  // แสดงค่าเซนเซอร์ S1
  OLED.print("       S2 = "); OLED.println(s2);  // แสดงค่าเซนเซอร์ S2
  OLED.print("       S3 = "); OLED.println(s3);  // แสดงค่าเซนเซอร์ S3
  OLED.display();
*/
  ///////////////////เงื่อนไขการแทกเส้นที่นี่ หาอัตราที่เหมาะสมเอง///////////////
if (s0 < A0){run(-75, 75);delay(120);}
if (s1 < A1){run(0, 75);delay(120);}
if (s2 < A2){run(75, 0);delay(60);}
if (s3 < A3){run(75, -75);delay(60);}
  else {run(50,50);delay(20);}
  //////////////////////////////////////////////////////////////////
  //delay(50);  // เปลี่ยนค่าเซนเซอร์ทุก 0.1 วินาที
}
}
}
/////////////////////////////////////////////////////////////////
void run(int spl, int spr)   // ประกาศฟังก์ชัน run(กำลังมอเตอร์ซ้าาย,กำลังมอเตอร์ขวา);
{
  if (spl > 0)
  {
    digitalWrite(DL1, LOW);
    digitalWrite(DL2, HIGH);
    analogWrite(PWML, spl);
  }
  else if (spl < 0)
  {
    digitalWrite(DL1, HIGH);
    digitalWrite(DL2, LOW);
    analogWrite(PWML, -spl);
  }
  else
  {
    digitalWrite(DL1, LOW);
    digitalWrite(DL2, LOW);
  }
  //////////////////////////////////////
  if (spr > 0)
  {
    digitalWrite(DR1, LOW);
    digitalWrite(DR2, HIGH);
    analogWrite(PWMR, spr);
  }
  else if (spr < 0)
  {
    digitalWrite(DR1, HIGH);
    digitalWrite(DR2, LOW);
    analogWrite(PWMR, -spr);
  }
  else
  {
    digitalWrite(DR1, LOW);
    digitalWrite(DR2, LOW);
  }
}
