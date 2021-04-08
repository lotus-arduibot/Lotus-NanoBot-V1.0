//////////////////////////////////
////บทความที่เกี่ยวข้อง https://sites.google.com/site/klsrobotcenter/lab-15-kar-chi-khaen-kl-rwm-kab-kar-thaerk-sen-lotus-nano-bot
/////////////////////////////////
/*
1. เมนู 0 วัดความเข้มแสง
2. เมนู 1 sv_knob(); วัดองศาเซอร์โว
3.คำสั่งเซอร์โวยก up();
4.คำสั่งเซอร์โววาง down(); 
5.คำสั่งเซอร์โวยก up(); 
6. คำสั่งแทกเส้นหยุดตรงเส้นแยก P(); 
7. คำสั่งแทกเส้นตามจำนวนนับ P(จำนวนนับ); 
8. คำสั่งเลี้ยวขวา R();
9. คำสั่งเลี้ยวซ้าย L();
10. คำสั่งถอยหลังไม่ใช้เซนเซอร์ b();
*/
//////////////////ผนวกไลบรารี่จอแสดงผล//////////////////
//////// ผนวกไลบรารี่ ////////////
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h> 
Adafruit_SSD1306 OLED(-1);
///////////ตั้งค่าปุ่มกด///////////////////
int button =  2; /// กำหนดปุ่มกดสวิตซ์ขา 2
int ss1 = 10;  // เปิดใช้งาน s1 ที่พอร์ต 10
int ss2 = 11;  // เปิดใช้งาน s1 ที่พอร์ต 11
int ss3 = 12;  // เปิดใช้งาน s1 ที่พอร์ต 12
Servo sv1;     // ประกาศการใช้งาน sv1
Servo sv2;     // ประกาศการใช้งาน sv2
Servo sv3;     // ประกาศการใช้งาน sv3
//////////////////////////////////////////////
////////////ตั้งค่าพอร์ตมอเตอร์////////////////////
#define DR1  7  /// กำหนดสัญญาณดิจิตอลขวาที่ 1 พอร์ต 7
#define DR2  8  /// กำหนดสัญญาณดิจิตอลขวาที่ 2 พอร์ต 8
#define PWMR 6 /// กำหนดสัญญาณ PWM ขวาพอร์ต 6
/////////////////////////////////
#define DL1  9  // กำหนดสัญญาณดิจิตอลซ้ายที่ 1 พอร์ต 9
#define DL2  4  // กำหนดสัญญาณดิจิตอลซ้ายที่ 2 พอร์ต 4
#define PWML 5  /// กำหนดสัญญาณ PWM ซ้ายพอร์ต 5
/////////////////ตั้งค่าพอร์ต Analog//////////////
#define A0 500 // ค่ากลางเซนเซอร์ A0 (ซ้ายสุด)
#define A1 200// ค่ากลางเซนเซอร์ A1 (ซ้ายกลาง)
#define A2 700 // ค่ากลางเซนเซอร์ A2 (ขวากลาง)
#define A3 500// ค่ากลางเซนเซอร์ A3 (ขวาสุด)
///////////////////////////////////////////////
int s0 ; 
int s1 ;
int s2 ;
int s3 ;
void analogs()
{
  s0 = analogRead(0);
  s1 = analogRead(1);
  s2 = analogRead(2);
  s3 = analogRead(3);
}
//////////////////////////////////////////////
void setup() {
  OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C); // กำหนดแอดเดรสของพอร์ตจอเป็น 0x3C (for the 128x64)
  pinMode(2, INPUT); // ตั้งค่าขา 2 เป็น INPUT
  ////////กำหนดสัญญาณทุกขาเป็น OUTPUT /////////
  pinMode(DL1, OUTPUT);
  pinMode(DL2, OUTPUT);
  pinMode(PWML, OUTPUT);
  pinMode(DR1, OUTPUT);
  pinMode(DR2, OUTPUT);
  pinMode(PWMR, OUTPUT);
  sv1.attach(ss1); // เรียกใช้งานเตรียมตอบสนองเซอร์โว sv1
  sv2.attach(ss2); // เรียกใช้งานเตรียมตอบสนองเซอร์โว sv2
  sv3.attach(ss3); // เรียกใช้งานเตรียมตอบสนองเซอร์โว sv3
  sv_set();
}

void loop() {
  int sw = digitalRead(button);     // ให้ sw อ่านค่า digital จากพอร์ต 2(button)
  int nob = analogRead(7);          // ให้ nob เทียบเท่าค่า A7
  int menu = map(nob, 0, 1023, 0, 12); // เทียบอัตราส่วนของพอร์ต A7 จาก 0-1023 เพื่อทำเป็นเมนู 0-12
  OLED.clearDisplay();              // ล้างค่าหน้าจอ
  OLED.setTextColor(WHITE, BLACK);  //สีอักษรเป็นสีขาว ,พื้นหลังดำ
  OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
  OLED.setTextSize(2);        // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.print("   ");         // วรรค
  OLED.println(menu);        // แสดงค่า Menu ที่ได้จากการ map nob ให้เหลือ 0-12
  OLED.setTextSize(1);        // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.println("  KLS ROBOT CENTER");     // พิมพ์คำว่า KLS ROBOT CENTER
  OLED.print("  ");                      // วรรค
  OLED.print(nob);                     // แสดงค่าที่อ่านได้จาก nob หรือ Analog7
  OLED.println(" www.kls.ac.th");     // พิมพ์คำว่า www.kls.ac.th
  OLED.display();
  if ((sw == 0) and (menu == 0))
  { sensor();
  }
  if ((sw == 0) and (menu == 1))
  {
    menu1();
  }
  if ((sw == 0) and (menu == 2))
  { 
    menu2();
  }
  if ((sw == 0) and (menu == 3))
  {
    menu3();
  }
  if ((sw == 0) and (menu == 4))
  {
   menu4();
  }
  if ((sw == 0) and (menu == 5))
  {
   menu5();
  }
  if ((sw == 0) and (menu == 6))
  {
  menu6();
  }
  if ((sw == 0) and (menu == 7))
  {
  menu7();
  }
  if ((sw == 0) and (menu == 8))
  {
  menu8();
  }
  if ((sw == 0) and (menu == 9))
  {
  menu9();
  }
  if ((sw == 0) and (menu == 10))
  {
  menu10();
  }
  if ((sw == 0) and (menu == 11))
  {
  menu11();
  }
  if ((sw == 0) and (menu == 12))
  {
  menu12();
  }
  delay(100);
}
void sensor()
{
  while (true) {
      analogs();
      OLED.clearDisplay();
      OLED.setTextColor(WHITE, BLACK);  //สีอักษรเป็นสีขาว ,พื้นหลังดำ
      OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
      OLED.setTextSize(1);        // เซตขนาดอักษรมีขนาดเป็น 1
      OLED.print("       S0 = "); OLED.println(s0);  // แสดงค่าเซนเซอร์ S0
      OLED.print("       S1 = "); OLED.println(s1);  // แสดงค่าเซนเซอร์ S1
      OLED.print("       S2 = "); OLED.println(s2);  // แสดงค่าเซนเซอร์ S2
      OLED.print("       S3 = "); OLED.println(s3);  // แสดงค่าเซนเซอร์ S3
      OLED.display();
      delay(50);
    }
  }
  /////////////////////// ฟังก์ชันเซฮร์โว //////////////////////////
  void up(){sv1.write(0);delay(1000); } // เซอร์โวยก
  void down() {sv1.write(30);delay(1000); }// เซอร์โววาง

///////////////////////เจอดำหยุด////////////////////////////////////////////
/////////////////////////เลี้ยวซ้าย///////////////////////////////////////////
void L0(){while (1){analogs();run(-130,130);if(s0<A0){run(0,0);break;}}} //S0
void L1(){while (1){analogs();run(-100,100);if(s1<A1){run(0,0);break;}}} //S1
void L2(){while (1){analogs();run(-130,130);if(s2<A2){run(0,0);break;}}} //S2
void L3(){while (1){analogs();run(-130,130);if(s3<A3){run(0,0);break;}}} //S3
//////////////////////เลี้ยวขวา//////////////////////////////////////////
void R0(){while (1){analogs();run(130,-130);if(s0<A0){run(0,0);break;}}} //S0
void R1(){while (1){analogs();run(130,-130);if(s1<A1){run(0,0);break;}}} //S1
void R2(){while (1){analogs();run(100,-100);if(s2<A2){run(0,0);break;}}} //S2
void R3(){while (1){analogs();run(130,-130);if(s3<A3){run(0,0);break;}}} //S3

/////////////////////////////ฟังก์ชันเซอร์โว////////////////////////////////////////
void sv_knob() {
  while(true){
  int vr = analogRead(A7);  // กำหนดตัวแปรจำนวนเต็มอ่านค่าอนาล็อกที่พอร์ต 7
  int nob = map(vr, 0, 1023, 0, 180); // ทำการ map อัตราส่วนจากสัญญาณ analog 0-1023 เป็น 0-180
  OLED.clearDisplay();    // เคลียร์หน้าจอ oled
  OLED.setTextColor(WHITE, BLACK);  //สีอักษรเป็นสีขาว ,พื้นหลังดำ
  OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
  OLED.setTextSize(2);        // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.print("SV1 = ");     // พิมพ์คำว่า SV1 = 
  OLED.println(nob);     // นำค่า nob มาแสดงใน oled
  OLED.display();        // เปิดฟังก์ชันแสดงผล
  sv1.write(nob);        // สั่งเซอร์โวมอเตอร์ให้หมุนไปตามค่าองศาที่ทำการ nob ไว้
  delay(50);             // หน่วงเวลา 0.05 วินาที
}}
/////////////////////////////////////////////////////
void sv_set()   // เซตเซอร์โว
{sv1.write(40); // ค่าองศาเซอร์โวตอนเปิดบอร์ด
  }
/////////////////////////ฟังก์ชันเส้นทาง////////////////////////////////////////
/////////////////////////ฟังก์ชันเส้นทาง////////////////////////////////////////

void P()     ///////////// ฟังก์ชันแทกเส้นเจอคู่ดำหยุด/////////////////////////////
{while (1){ 
  s0 = analogRead(0);
  s1 = analogRead(1);
  s2 = analogRead(2);
  s3 = analogRead(3);
if ((s1 > A1) and (s2 > A2)){run(130, 130);}
if (s1 < A1){run(-170, 180);delay(5);}
if (s2 < A2){run(180, -170);delay(5);}
if ((s1 < A1) and (s2 < A2))
    {run(130, 130);delay(150);run(0, 0);delay(100);tone(3,1000,100);break;}}}

void P(int t)     ///////////// ฟังก์ชันแทกเส้น/////////////////////////////
{ int j = 0;
  while (1){ 
  s0 = analogRead(0);
  s1 = analogRead(1);
  s2 = analogRead(2);
  s3 = analogRead(3);
if ((s1 > A1) and (s2 > A2)){run(75, 75);}
if (s1 < A1){run(-30, 75);}
if (s2 < A2){run(75, -30);}
//if (s0 < A0){run(-40, 75);}
//if (s3 < A3){run(75, -40);}
if (((s1 < A1) and (s2 < A2)) or ((s1 < A1) and (s0 < A0)) or ((s2 < A2) and (s3 < A3))){run(75, 75);}
if (j>t){run(0, 0);tone(3,900,500);break;}
j++;}}
//////////////////////////////////////////////////////////////////////////////////

void L(){L0();L1();delay(100);tone(3,1000,50);} /////// เลี้ยวซ้าย
void R(){R3();R2();delay(100);tone(3,1000,50);} ///////// เลี้ยว
void b(){run(-75,-70);delay(1000);run(0,0);delay(600);} // ถอยหลัง
//////////////////////////////////////////////////////////////////////////

/////////////////////////////ฟังก์ชันมอเตอร์///////////////////////////////////
/////////////////////////////ฟังก์ชันมอเตอร์///////////////////////////////////
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
//////////////////////////////// เรียกใช้ code menu ////////////
void menu1()  /// code 1 ที่นี่
{
  sv_knob();
}
void menu2()   /// code 2 ที่นี่
{
  P();
}
void menu3()   /// code 3 ที่นี่
{
  
}
void menu4()   /// code 4 ที่นี่
{
}
void menu5()   /// code 5 ที่นี่
{
  }
void menu6()   /// code 6 ที่นี่
{
}
void menu7()   /// code 7 ที่นี่
{
}
void menu8()   /// code 8 ที่นี่
{
}
void menu9()   /// code 9 ที่นี่
{
}
void menu10()   /// code 10 ที่นี่
{
}
void menu11()   /// code 11 ที่นี่
{
}
void menu12()   /// code 12 ที่นี่
{down();P();P();P();P();up();R();P();R();P();P();P();down();b();
 }
