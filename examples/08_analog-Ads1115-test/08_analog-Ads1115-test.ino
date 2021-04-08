
//////////////////////////////////
////บทความที่เกี่ยวข้อง   https://sites.google.com/site/klsrobotcenter/lab-8-analog-i2c-ads1115
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
void setup() {
  OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C); // กำหนดแอดเดรสของพอร์ตจอเป็น 0x3C (for the 128x64)
    ads1115.begin(); // เปิดการใช้งาน ADS1115
}
void loop(){
int16_t adc0, adc1, adc2, adc3;
 adc0 = ads1115.readADC_SingleEnded(0);
 adc1 = ads1115.readADC_SingleEnded(1);
 adc2 = ads1115.readADC_SingleEnded(2);
 adc3 = ads1115.readADC_SingleEnded(3);
 /////////// ทำการ Map ค่าเซนเซอร์ Analog ที่ได้ค่าเหมาะสมกับเซนเซอร์ Lotus T3 /////
 int AA0 = map(adc0,0,27000,0,1023);
 int AA1 = map(adc1,0,27000,0,1023);
 int AA2 = map(adc2,0,27000,0,1023);
 int AA3 = map(adc3,0,27000,0,1023);
//////////////////////////////////////////////////////////////////////////////
      OLED.clearDisplay();
      OLED.setTextColor(WHITE, BLACK);  //สีอักษรเป็นสีขาว ,พื้นหลังดำ
      OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
      OLED.setTextSize(1);        // เซตขนาดอักษรมีขนาดเป็น 1
      OLED.println(" ANALOG I2C TEST");
      OLED.print("    AA0 = "); OLED.println(AA0); /// แสดงผลค่าอะนาล็อกMapที่พอร์ต AA0
      OLED.print("    AA1 = "); OLED.println(AA1); /// แสดงผลค่าอะนาล็อกMapที่พอร์ต AA1
      OLED.print("    AA2 = "); OLED.println(AA2); /// แสดงผลค่าอะนาล็อกMapที่พอร์ต AA2
      OLED.print("    AA3 = "); OLED.println(AA3); /// แสดงผลค่าอะนาล็อกMapที่พอร์ต AA3
      OLED.display();
      delay(50);
  
  }