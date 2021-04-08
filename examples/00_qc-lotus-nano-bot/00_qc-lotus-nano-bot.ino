//////////////////////////////////
////บทความที่เกี่ยวข้อง https://sites.google.com/site/klsrobotcenter/datasheet-lotus-nano
/////////////////////////////////
//////// ผนวกไลบรารี่ ////////////
#include <Wire.h>
#include <SPI.h>
#include <MechaQMC5883.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_ADS1015.h>
#include <Servo.h> 
Adafruit_SSD1306 OLED(-1);
MechaQMC5883 qmc;
Adafruit_ADS1115 ads1115;
/////////// ตั้งค่าเสียงในลำโพงบัซเซอร์///////////
  int snd=3;
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
int s6 ;
int s7 ;
void analogs()
{
  s0 = analogRead(0);
  s1 = analogRead(1);
  s2 = analogRead(2);
  s3 = analogRead(3);
  s6 = analogRead(6);
  s7 = analogRead(7);
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
  Wire.begin();
  qmc.init();
  ads1115.begin();
}

void loop() {
  int sw = digitalRead(button);     // ให้ sw อ่านค่า digital จากพอร์ต 2(button)
  int nob = analogRead(7);          // ให้ nob เทียบเท่าค่า A7
  int menu = map(nob, 0, 1023, 0, 12); // เทียบอัตราส่วนของพอร์ต A7 จาก 0-1023 เพื่อทำเป็นเมนู 0-12
  OLED.clearDisplay();              // ล้างค่าหน้าจอ
  OLED.setTextColor(WHITE, BLACK);  //สีอักษรเป็นสีขาว ,พื้นหลังดำ
  OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
  OLED.setTextSize(2);        // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.print("     ");         // วรรค
  OLED.println(menu);        // แสดงค่า Menu ที่ได้จากการ map nob ให้เหลือ 0-12
  OLED.setTextSize(1);        // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.println("    LOTUS ARDUIBOT");     // พิมพ์คำว่า  LOTUS ARDUIBOT
  OLED.print("      ");                      // วรรค
  OLED.print(nob);                     // แสดงค่าที่อ่านได้จาก nob หรือ Analog7
  OLED.println(" TEST");     // พิมพ์คำว่า TEST
   OLED.setTextSize(2);        // เซตขนาดอักษรมีขนาดเป็น 2
///////////////////////////////////////////////////////////////
if ((menu == 0))
  {OLED.println(" ANA&DIGI");
  }
  if ((menu == 1))
  {OLED.println(" SERVO123");

  }
  if((menu == 2))
  { OLED.println("   MOTOR");

  }
  if((menu == 3))
  {
   OLED.println("  COMPASS");
  }
  if ((menu == 4))
  {
   OLED.println("ANALOG I2C");
  }
  if ((menu == 5))
  {
   OLED.println("   SOUND");
  }
  if ((sw == 0) and (menu == 6))
  {
 
  }
  if ((sw == 0) and (menu == 7))
  {

  }
  if ((sw == 0) and (menu == 8))
  {

  }
  if ((sw == 0) and (menu == 9))
  {

  }
  if ((sw == 0) and (menu == 10))
  {

  }
  if ((sw == 0) and (menu == 11))
  {

  }
  if ((sw == 0) and (menu == 12))
  {

  }
//////////////////////////////////////////////////////////////

  OLED.display();
  if ((sw == 0) and (menu == 0))
  {tone(3,900,100); sensor();
  }
  if ((sw == 0) and (menu == 1))
  {
    tone(3,900,100);menu1();
  }
  if ((sw == 0) and (menu == 2))
  { 
    tone(3,900,100); menu2();
  }
  if ((sw == 0) and (menu == 3))
  {
    tone(3,900,100); menu3();
  }
  if ((sw == 0) and (menu == 4))
  {
   tone(3,900,100); menu4();
  }
  if ((sw == 0) and (menu == 5))
  {
   tone(3,900,100); menu5();
  }
  if ((sw == 0) and (menu == 6))
  {
  tone(3,900,100); menu6();
  }
  if ((sw == 0) and (menu == 7))
  {
  tone(3,900,100); menu7();
  }
  if ((sw == 0) and (menu == 8))
  {
  tone(3,900,100); menu8();
  }
  if ((sw == 0) and (menu == 9))
  {
  tone(3,900,100); menu9();
  }
  if ((sw == 0) and (menu == 10))
  {
  tone(3,900,100); menu10();
  }
  if ((sw == 0) and (menu == 11))
  {
  tone(3,900,100); menu11();
  }
  if ((sw == 0) and (menu == 12))
  {
 tone(3,900,100);  menu12();
  }
  delay(100);
}
void sensor()
{
  pinMode(0,INPUT);
  pinMode(1,INPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  while (true) {
      analogs();
      OLED.clearDisplay();
      OLED.setTextColor(WHITE, BLACK);  //สีอักษรเป็นสีขาว ,พื้นหลังดำ
      OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
      OLED.setTextSize(1);        // เซตขนาดอักษรมีขนาดเป็น 1

      OLED.println(" ANALOG TEST");
      OLED.print("  A0 = "); OLED.print(s0); OLED.print("  A1 = "); OLED.println(s1);  // แสดงค่าเซนเซอร์ S1 S2
      OLED.print("  A2 = "); OLED.print(s2); OLED.print("  A3 = "); OLED.println(s3);  // แสดงค่าเซนเซอร์ S3 S4
      OLED.print("  A6 = "); OLED.print(s6); OLED.print("  A7 = "); OLED.println(s7);  // แสดงค่าเซนเซอร์ S6 S7
      OLED.println(" DIGITAL TEST");
      OLED.print("  D0 = "); OLED.print(digitalRead(0));  OLED.print("  D1 = "); OLED.println(digitalRead(1)); 
      OLED.print("  D2 = "); OLED.println(digitalRead(2)); 
      OLED.display();
      delay(50);
    }
  }


  void ads()
{
  while (true) {
      int16_t adc0, adc1, adc2, adc3;
 adc0 = ads1115.readADC_SingleEnded(0);
 adc1 = ads1115.readADC_SingleEnded(1);
 adc2 = ads1115.readADC_SingleEnded(2);
 adc3 = ads1115.readADC_SingleEnded(3);
 
 int AA0 = map(adc0,700,25000,0,1023);
 int AA1 = map(adc1,700,25000,0,1023);
 int AA2 = map(adc2,700,25000,0,1023);
 int AA3 = map(adc3,700,25000,0,1023);
      OLED.clearDisplay();
      OLED.setTextColor(WHITE, BLACK);  //สีอักษรเป็นสีขาว ,พื้นหลังดำ
      OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
      OLED.setTextSize(1);        // เซตขนาดอักษรมีขนาดเป็น 1
      OLED.println(" ANALOG I2C TEST");
      OLED.print("    AA0 = "); OLED.println(AA0);
      OLED.print("    AA1 = "); OLED.println(AA1); 
      OLED.print("    AA2 = "); OLED.println(AA2); 
      OLED.print("    AA3 = "); OLED.println(AA3); 
      OLED.display();
      delay(50);
    }
  }
  void motor()
  {  //-------------------เดินหน้า-----------------------------// 
  OLED.clearDisplay();              // ล้างค่าหน้าจอ
  OLED.setTextColor(WHITE, BLACK);  //สีอักษรเป็นสีขาว ,พื้นหลังดำ
  OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
  OLED.setTextSize(2);        // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.println("  ML    MR");        // แสดงค่า Menu ที่ได้จากการ map nob ให้เหลือ 0-12
  OLED.println("  F     F");
  OLED.setTextSize(1); 
  OLED.println(" -------------------");
  OLED.setTextSize(2); 
  OLED.println("  FORWARD");
  OLED.display();
  run(100,100);delay(1000);tone(3,1000,500);

  //-------------------ถอยหลัง-----------------------------// 
  OLED.clearDisplay();              // ล้างค่าหน้าจอ
  OLED.setTextColor(WHITE, BLACK);  //สีอักษรเป็นสีขาว ,พื้นหลังดำ
  OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
  OLED.setTextSize(2);        // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.println("  ML    MR");        // แสดงค่า Menu ที่ได้จากการ map nob ให้เหลือ 0-12
  OLED.println("  B     B");
  OLED.setTextSize(1); 
  OLED.println(" -------------------");
  OLED.setTextSize(2); 
  OLED.println("   BACK");
  OLED.display();
  run(-100,-100);delay(2000);tone(3,1000,500);

  //-------------------เลี้ยวซ้าย-----------------------------// 
  OLED.clearDisplay();              // ล้างค่าหน้าจอ
  OLED.setTextColor(WHITE, BLACK);  //สีอักษรเป็นสีขาว ,พื้นหลังดำ
  OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
  OLED.setTextSize(2);        // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.println("  ML    MR");        // แสดงค่า Menu ที่ได้จากการ map nob ให้เหลือ 0-12
  OLED.println("  B     F");
  OLED.setTextSize(1); 
  OLED.println(" -------------------");
  OLED.setTextSize(2); 
  OLED.println("   LEFT");
    OLED.display();
  run(-100,100);delay(2000);tone(3,1000,500);

   //-------------------เลี้ยวขวา-----------------------------// 
  OLED.clearDisplay();              // ล้างค่าหน้าจอ
  OLED.setTextColor(WHITE, BLACK);  //สีอักษรเป็นสีขาว ,พื้นหลังดำ
  OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
  OLED.setTextSize(2);        // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.println("  ML    MR");        // แสดงค่า Menu ที่ได้จากการ map nob ให้เหลือ 0-12
  OLED.println("  F     B");
  OLED.setTextSize(1); 
  OLED.println(" -------------------");
  OLED.setTextSize(2); 
  OLED.println("   RIGHT");
    OLED.display();
  run(100,-100);delay(2000);tone(3,1000,500);

    //-------------------หยุด-----------------------------// 
  OLED.clearDisplay();              // ล้างค่าหน้าจอ
  OLED.setTextColor(WHITE, BLACK);  //สีอักษรเป็นสีขาว ,พื้นหลังดำ
  OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
  OLED.setTextSize(2);        // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.println("  ML    MR");        // แสดงค่า Menu ที่ได้จากการ map nob ให้เหลือ 0-12
  OLED.println("  0     0");
  OLED.setTextSize(1); 
  OLED.println(" -------------------");
  OLED.setTextSize(2); 
  OLED.println("    STOP");
    OLED.display();
  run(0,0);delay(2000);tone(3,1000,500);


    
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
  OLED.print("SV2 = ");  // พิมพ์คำว่า SV2 = 
  OLED.println(nob);     // นำค่า nob มาแสดงใน oled
  OLED.print("SV3 = ");  // พิมพ์คำว่า SV3 = 
  OLED.println(nob);     // นำค่า nob มาแสดงใน oled
  OLED.display();        // เปิดฟังก์ชันแสดงผล
  sv1.write(nob);        // สั่งเซอร์โวมอเตอร์ให้หมุนไปตามค่าองศาที่ทำการ nob ไว้
  sv2.write(nob);        // สั่งเซอร์โวมอเตอร์ให้หมุนไปตามค่าองศาที่ทำการ nob ไว้
  sv3.write(nob);        // สั่งเซอร์โวมอเตอร์ให้หมุนไปตามค่าองศาที่ทำการ nob ไว้
  delay(50);             // หน่วงเวลา 0.05 วินาที
}}
/////////////////////////////////////////////////////
void sv_set()   // เซตเซอร์โว
{sv1.write(40); // ค่าองศาเซอร์โวตอนเปิดบอร์ด
  }
////////// เข็มทิศ ////////////////////////////////
void compass()
{
  while (true) {
    int x, y, z;
    int azimuth;
    qmc.read(&x, &y, &z, &azimuth);
    analogs();
    OLED.clearDisplay();
    OLED.setTextColor(WHITE, BLACK);  //สีอักษรเป็นสีขาว ,พื้นหลังดำ
    OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
    OLED.setTextSize(2);        // เซตขนาดอักษรมีขนาดเป็น 1
    OLED.print(" Azi = "); OLED.println(azimuth);
    OLED.display();
    delay(50);
  }
}
void sound(){
tone(snd, 660, 100);
  delay(150);
  tone(snd, 660, 100);
  delay(300);
  tone(snd, 660, 100);
  delay(300);
  tone(snd, 510, 100);
  delay(100);
  tone(snd, 660, 100);
  delay(300);
  tone(snd, 770, 100);
  delay(550);
  tone(snd, 380, 100);
  delay(575);

  tone(snd, 510, 100);
  delay(450);
  tone(snd, 380, 100);
  delay(400);
  tone(snd, 320, 100);
  delay(500);
  tone(snd, 440, 100);
  delay(300);
  tone(snd, 480, 80);
  delay(330);
  tone(snd, 450, 100);
  delay(150);
  tone(snd, 430, 100);
  delay(300);
  tone(snd, 380, 100);
  delay(200);
  tone(snd, 660, 80);
  delay(200);
  tone(snd, 760, 50);
  delay(150);
  tone(snd, 860, 100);
  delay(300);
  tone(snd, 700, 80);
  delay(150);
  tone(snd, 760, 50);
  delay(350);
  tone(snd, 660, 80);
  delay(300);
  tone(snd, 520, 80);
  delay(150);
  tone(snd, 580, 80);
  delay(150);
  tone(snd, 480, 80);
  delay(500);

  tone(snd, 510, 100);
  delay(450);
  tone(snd, 380, 100);
  delay(400);
  tone(snd, 320, 100);
  delay(500);
  tone(snd, 440, 100);
  delay(300);
  tone(snd, 480, 80);
  delay(330);
  tone(snd, 450, 100);
  delay(150);
  tone(snd, 430, 100);
  delay(300);
  tone(snd, 380, 100);
  delay(200);
  tone(snd, 660, 80);
  delay(200);
  tone(snd, 760, 50);
  delay(150);
  tone(snd, 860, 100);
  delay(300);
  tone(snd, 700, 80);
  delay(150);
  tone(snd, 760, 50);
  delay(350);
  tone(snd, 660, 80);
  delay(300);
  tone(snd, 520, 80);
  delay(150);
  tone(snd, 580, 80);
  delay(150);
  tone(snd, 480, 80);
  delay(500);

  tone(snd, 500, 100);
  delay(300);

  tone(snd, 760, 100);
  delay(100);
  tone(snd, 720, 100);
  delay(150);
  tone(snd, 680, 100);
  delay(150);
  tone(snd, 620, 150);
  delay(300);

  tone(snd, 650, 150);
  delay(300);
  tone(snd, 380, 100);
  delay(150);
  tone(snd, 430, 100);
  delay(150);

  tone(snd, 500, 100);
  delay(300);
  tone(snd, 430, 100);
  delay(150);
  tone(snd, 500, 100);
  delay(100);
  tone(snd, 570, 100);
  delay(220);

  tone(snd, 500, 100);
  delay(300);

  tone(snd, 760, 100);
  delay(100);
  tone(snd, 720, 100);
  delay(150);
  tone(snd, 680, 100);
  delay(150);
  tone(snd, 620, 150);
  delay(300);

  tone(snd, 650, 200);
  delay(300);

  tone(snd, 1020, 80);
  delay(300);
  tone(snd, 1020, 80);
  delay(150);
  tone(snd, 1020, 80);
  delay(300);

  tone(snd, 380, 100);
  delay(300);
  tone(snd, 500, 100);
  delay(300);

  tone(snd, 760, 100);
  delay(100);
  tone(snd, 720, 100);
  delay(150);
  tone(snd, 680, 100);
  delay(150);
  tone(snd, 620, 150);
  delay(300);

  tone(snd, 650, 150);
  delay(300);
  tone(snd, 380, 100);
  delay(150);
  tone(snd, 430, 100);
  delay(150);

  tone(snd, 500, 100);
  delay(300);
  tone(snd, 430, 100);
  delay(150);
  tone(snd, 500, 100);
  delay(100);
  tone(snd, 570, 100);
  delay(420);

  tone(snd, 585, 100);
  delay(450);

  tone(snd, 550, 100);
  delay(420);

  tone(snd, 500, 100);
  delay(360);

  tone(snd, 380, 100);
  delay(300);
  tone(snd, 500, 100);
  delay(300);
  tone(snd, 500, 100);
  delay(150);
  tone(snd, 500, 100);
  delay(300);

  tone(snd, 500, 100);
  delay(300);

  tone(snd, 760, 100);
  delay(100);
  tone(snd, 720, 100);
  delay(150);
  tone(snd, 680, 100);
  delay(150);
  tone(snd, 620, 150);
  delay(300);

  tone(snd, 650, 150);
  delay(300);
  tone(snd, 380, 100);
  delay(150);
  tone(snd, 430, 100);
  delay(150);

  tone(snd, 500, 100);
  delay(300);
  tone(snd, 430, 100);
  delay(150);
  tone(snd, 500, 100);
  delay(100);
  tone(snd, 570, 100);
  delay(220);

  tone(snd, 500, 100);
  delay(300);

  tone(snd, 760, 100);
  delay(100);
  tone(snd, 720, 100);
  delay(150);
  tone(snd, 680, 100);
  delay(150);
  tone(snd, 620, 150);
  delay(300);

  tone(snd, 650, 200);
  delay(300);

  tone(snd, 1020, 80);
  delay(300);
  tone(snd, 1020, 80);
  delay(150);
  tone(snd, 1020, 80);
  delay(300);

  tone(snd, 380, 100);
  delay(300);
  tone(snd, 500, 100);
  delay(300);

  tone(snd, 760, 100);
  delay(100);
  tone(snd, 720, 100);
  delay(150);
  tone(snd, 680, 100);
  delay(150);
  tone(snd, 620, 150);
  delay(300);

  tone(snd, 650, 150);
  delay(300);
  tone(snd, 380, 100);
  delay(150);
  tone(snd, 430, 100);
  delay(150);

  tone(snd, 500, 100);
  delay(300);
  tone(snd, 430, 100);
  delay(150);
  tone(snd, 500, 100);
  delay(100);
  tone(snd, 570, 100);
  delay(420);

  tone(snd, 585, 100);
  delay(450);

  tone(snd, 550, 100);
  delay(420);

  tone(9, 500, 100);
  delay(360);

  tone(snd, 380, 100);
  delay(300);
  tone(snd, 500, 100);
  delay(300);
  tone(snd, 500, 100);
  delay(150);
  tone(snd, 500, 100);
  delay(300);

  tone(snd, 500, 60);
  delay(150);
  tone(snd, 500, 80);
  delay(300);
  tone(snd, 500, 60);
  delay(350);
  tone(snd, 500, 80);
  delay(150);
  tone(snd, 580, 80);
  delay(350);
  tone(snd, 660, 80);
  delay(150);
  tone(snd, 500, 80);
  delay(300);
  tone(snd, 430, 80);
  delay(150);
  tone(snd, 380, 80);
  delay(600);

  tone(snd, 500, 60);
  delay(150);
  tone(snd, 500, 80);
  delay(300);
  tone(snd, 500, 60);
  delay(350);
  tone(snd, 500, 80);
  delay(150);
  tone(snd, 580, 80);
  delay(150);
  tone(snd, 660, 80);
  delay(550);

  tone(snd, 870, 80);
  delay(325);
  tone(snd, 760, 80);
  delay(600);

  tone(snd, 500, 60);
  delay(150);
  tone(snd, 500, 80);
  delay(300);
  tone(snd, 500, 60);
  delay(350);
  tone(snd, 500, 80);
  delay(150);
  tone(snd, 580, 80);
  delay(350);
  tone(snd, 660, 80);
  delay(150);
  tone(snd, 500, 80);
  delay(300);
  tone(snd, 430, 80);
  delay(150);
  tone(snd, 380, 80);
  delay(600);

  tone(snd, 660, 100);
  delay(150);
  tone(snd, 660, 100);
  delay(300);
  tone(snd, 660, 100);
  delay(300);
  tone(snd, 510, 100);
  delay(100);
  tone(snd, 660, 100);
  delay(300);
  tone(snd, 770, 100);
  delay(550);
  tone(snd, 380, 100);
  delay(575);  
  
  
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
  sv_knob(); // ทดสอบเซอร์โว
}
void menu2()   /// code 2 ที่นี่
{ motor(); // ทดสอบมอเตอร์

}
void menu3()   /// code 3 ที่นี่
{compass(); // ทดสอบเข็มทิศ
}
void menu4()   /// code 4 ที่นี่
{ads(); // ทดสอบอนาล็อก I2C
}
void menu5()   /// code 5 ที่นี่
{sound(); // ทดสอบเสียงดนตรี
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
{
  
}
