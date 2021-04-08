//////////////////////////////////
////บทความที่เกี่ยวข้อง  https://sites.google.com/site/klsrobotcenter/lab-3-kar-chi-ngan-cx-oled-i2c
/////////////////////////////////
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 OLED(-1);
void setup() {
  OLED.begin(SSD1306_SWITCHCAPVCC,0x3C); // กำหนดแอดเดรสของพอร์ตจอเป็น 0x3C (for the 128x64)
}
void loop(){
  OLED.clearDisplay();
  OLED.setTextColor(WHITE,BLACK);   //สีอักษรเป็นสีขาว ,พื้นหลังดำ
  OLED.setCursor(10,0);       // เซตตำแหน่ง 10,0
  OLED.setTextSize(2);        // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.println("KLS-ROBOT");     // พิมพ์คำว่า Robot
  OLED.println("   2018");    // พิมพ์บรรทัดใหม่หลังคำว่า 2018
  OLED.print("Robot club");      // พิมพ์คำว่า Robot club
  OLED.display();
}
