//////////////////////////////////
////บทความที่เกี่ยวข้อง https://sites.google.com/site/klsrobotcenter/lab-12-kar-chi-ngan-rwm-kab-cxy-sti-ks-ps2-uart
/////////////////////////////////
//////// ผนวกไลบรารี่ ////////////
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h> 
#include <SoftwareSerial.h>
Adafruit_SSD1306 OLED(-1);
///////////////////////////////////////////////////////////////////////////////
SoftwareSerial mySerial(A0, A1); // RX, TX ซึ่งต้องต่อต่อ A0 ใส่กับ Tx และ A1 กับ Rx
///////////////////////////////////////////////////////////////////////////////
///////////ตั้งค่าปุ่มกด///////////////////
int button =  2; /// กำหนดปุ่มกดสวิตซ์ขา 2
int ss1 = 10;  // เปิดใช้งาน s1 ที่พอร์ต 10
int ss2 = 11;  // เปิดใช้งาน s1 ที่พอร์ต 11
int ss3 = 12;  // เปิดใช้งาน s1 ที่พอร์ต 12
Servo sv1;     // ประกาศการใช้งาน sv1
Servo sv2;     // ประกาศการใช้งาน sv2
Servo sv3;     // ประกาศการใช้งาน sv3
//////////////////////////////////////////////
int servo_x = 90;   // ตัวแปรสำหรับเก็บองศาของเซอร์โวที่ใช้หนีบวัตถุ
int servo_y = 90;   // ตัวแปรสำหรับเก็บองศาของเซอร์โวที่ใช้ยกแขนจับ
////////////ตั้งค่าพอร์ตมอเตอร์////////////////////
#define DR1  7  /// กำหนดสัญญาณดิจิตอลขวาที่ 1 พอร์ต 7
#define DR2  8  /// กำหนดสัญญาณดิจิตอลขวาที่ 2 พอร์ต 8
#define PWMR 6 /// กำหนดสัญญาณ PWM ขวาพอร์ต 6
/////////////////////////////////
#define DL1  9  // กำหนดสัญญาณดิจิตอลซ้ายที่ 1 พอร์ต 9
#define DL2  4  // กำหนดสัญญาณดิจิตอลซ้ายที่ 2 พอร์ต 4
#define PWML 5  /// กำหนดสัญญาณ PWM ซ้ายพอร์ต 5
//////////////////////////////////////////////////////////
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
/////////////////แสดงโลโก้โลตัส อาดุยบอท/////////////////////////
const unsigned char logo [] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 
0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 
0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 
0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 
0x62, 0x40, 0x01, 0x00, 0x24, 0x82, 0x08, 0x0a, 0x18, 
0x6f, 0xc0, 0x07, 0x80, 0x7f, 0xef, 0xdf, 0x3f, 0xd8, 
0x63, 0x80, 0x3f, 0xf8, 0xee, 0x67, 0x06, 0x70, 0xc8, 
0x63, 0x00, 0x1f, 0xf0, 0xce, 0x63, 0x04, 0x70, 0xd8, 
0x63, 0x80, 0x3e, 0xf8, 0x06, 0x07, 0x86, 0x3e, 0x18, 
0x63, 0x80, 0x78, 0x78, 0x0e, 0x07, 0x0c, 0x1f, 0xd8, 
0x63, 0x00, 0xfc, 0x3e, 0x0e, 0x03, 0x06, 0x0b, 0xe8, 
0x63, 0x86, 0x38, 0x78, 0x0e, 0x07, 0x04, 0x60, 0xf8, 
0x63, 0x8c, 0x3f, 0xf8, 0x06, 0x03, 0x8c, 0x70, 0xe8, 
0x67, 0xfc, 0x3f, 0xf0, 0x0f, 0x03, 0xdc, 0x7d, 0xd8, 
0x6f, 0xb8, 0x3f, 0xf8, 0x1f, 0x01, 0xf0, 0x2f, 0x98, 
0x60, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x08, 
0x60, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 
0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 
0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 
0x60, 0x87, 0xe7, 0xc7, 0x37, 0x7e, 0x1e, 0x3f, 0x18, 
0x61, 0x86, 0x67, 0x73, 0x33, 0x33, 0x33, 0x6d, 0x18, 
0x63, 0xc6, 0x32, 0x33, 0x23, 0x13, 0x61, 0x8c, 0x88, 
0x63, 0xc7, 0xe6, 0x33, 0x32, 0x3e, 0x61, 0x8c, 0x18, 
0x63, 0xe6, 0xc3, 0x32, 0x13, 0x33, 0x63, 0x8c, 0x18, 
0x66, 0x66, 0x66, 0x33, 0x23, 0x33, 0x31, 0x8c, 0x08, 
0x66, 0x77, 0x77, 0xe3, 0xe7, 0x3f, 0x3f, 0x1c, 0x18, 
0x64, 0x40, 0x11, 0x00, 0x04, 0x48, 0x04, 0x02, 0x18, 
0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 
0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 
0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

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
  OLED.begin(SSD1306_SWITCHCAPVCC,0x3C); // initialize with the I2C addr 0x3C (for the 128x64)
  OLED.clearDisplay();
  OLED.drawBitmap(40,20,logo,70,32,1);  //40,20 is x,y coordinates and 70,32 พิกเซล is image size
  OLED.display();
  Serial.begin(9600);  // ช่องอ่านค่าหลักใน Serail Monitor
  while (!Serial) {
  }
  Serial.println("LOTUS ARDUIBOT");
  mySerial.begin(115200);
  mySerial.println("www.LOTUS-ARDUIBOT.COM");
}
void loop() { // รับการอ่านค่าจากพอร์ต UART
  if (mySerial.available()) {
    char x = mySerial.read();
     if (x == 'A') {run(100,100);delay(50);}  // กดปุ่มเดินหน้า
     if (x == 'B') {run(-100,-100);delay(50);} // กดปุ่มถอยหลัง
     if (x == 'C') {run(-100,100);delay(50);}  // กดปุ่มเลี้ยวซ้าย
     if (x == 'D') {run(100,-100);delay(50);} // กดปุ่มเลี้ยวขวา
     if (x == 'K') {tone(3,1200,200);} // กดปุ่มสี่เหลี่ยม
     if (x == 'L') {tone(3,1300,200);} // กดปุ่มวงกลม
     if (x == 'I') {tone(3,1400,200);} // กดปุ่มสามเหลี่ยม
     if (x == 'J') {tone(3,1500,200);} // กดปุ่มกากบาท

     if (x == 'M') {// กดปุ่มR1
       servo_x += 5;                                // เพิ่มขึ้นทีละ 5 องศา
      servo_x = (servo_x > 180) ? 180 : servo_x;     // เซอร์โวสูงสุดแค่ 90 องศา
      sv1.write(servo_x);                          // ค่าในการทำงานของเซอร์โวเท่ากับ Servo_x ปัจจุบัน  
      } 
     if (x == 'N') {// กดปุ่มR2
        servo_x -= 5;                                // องศาของเซอร์โวลดลง 2 องศา
        servo_x = (servo_x < 0) ? 0 : servo_x;       // ให้ค่าองศาของเซอร์โวต่ำสุดแค่ 40 องศา
        sv1.write(servo_x);                          // ค่าในการทำงานของเซอร์โวเท่ากับ Servo_x ปัจจุบัน      
            } 

     if (x == 'E') {// กดปุ่มL1
        servo_y += 5;                               // เพิ่มขึ้นทีละ 5 องศา
        servo_y = (servo_y > 180) ? 180 : servo_y;    // เซอร์โวสูงสุดแค่ 90 องศา
        sv2.write(servo_y);                         // ค่าในการทำงานของเซอร์โวเท่ากับ Servo_y ปัจจุบัน
      } 
      if (x == 'F') {// กดปุ่มL2
        servo_y -= 5;                              // ลดทีละ 5 องศา
        servo_y = (servo_y < 0) ? 0 : servo_y;     // เซอร์โวต่ำสุดได้แค่ 0 องศา
        sv2.write(servo_y);                        // ค่าในการทำงานของเซอร์โวเท่ากับ Servo_y ปัจจุบัน
        } 
     else{run(0,0);}  // นอกเหนือจากนั้นมอเตอร์หยุด
 //   Serial.write(mySerial.read());
    
}}
