//////////////////////////////////
////บทความที่เกี่ยวข้อง  https://sites.google.com/site/klsrobotcenter/lab-6-kar-kheiyn-kha-sangmenu-lotus-nano
// not found??????????????????
/////////////////////////////////
///////// ผนวกไลบรารี่ ////////////
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 OLED(-1);
///////////ตั้งค่าปุ่มกด///////////////////
int button =  2; /// กำหนดปุ่มกดสวิตซ์ขา 2
/////////////////////////////////////////////////////////////////////
void setup() {
  OLED.begin(SSD1306_SWITCHCAPVCC,0x3C); // กำหนดแอดเดรสของพอร์ตจอเป็น 0x3C (for the 128x64)
  pinMode(2, INPUT); // ตั้งค่าขา 2 เป็น INPUT
}
void loop(){
  
  int sw = digitalRead(button);     // ให้ sw อ่านค่า digital จากพอร์ต 2(button)
  int nob = analogRead(7);          // ให้ nob เทียบเท่าค่า A7
  int menu = map(nob,0,1023,0,12);  // เทียบอัตราส่วนของพอร์ต A7 จาก 0-1023 เพื่อทำเป็นเมนู 0-12 
  OLED.clearDisplay();              // ล้างค่าหน้าจอ
  OLED.setTextColor(WHITE,BLACK);   //สีอักษรเป็นสีขาว ,พื้นหลังดำ
  OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
  OLED.setTextSize(2);        // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.println("ROBOT MENU");     // พิมพ์คำว่า ROBOT MENU
  OLED.setTextSize(3);        // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.print("   ");         // วรรค
  OLED.println(menu);        // แสดงค่า Menu ที่ได้จากการ map nob ให้เหลือ 0-12
  OLED.setTextSize(1);        // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.println("Mikhail Akhsakov");     // พิมพ์คำว่า Mikhail Akhsakov
  OLED.print("  ");                      // วรรค
  OLED.print(nob);                     // แสดงค่าที่อ่านได้จาก nob หรือ Analog7
  OLED.println("Mikhail Akhsakov");     // พิมพ์คำว่า Mikhail Akhsakov
  OLED.display();
  if (sw !=0) // if sw is not 0 than back to loop()
    return;
  if (menu==0)  {
    OLED.clearDisplay();
    OLED.display();
    delay(100);
    return;
  }
  for (int i=0; i>menu;i++) 
    t();
  delay(100);
}
void t()    // ฟังก์ชันเสียงดังที่พอร์ต 3
{tone(3,1000,100);delay(300);  }
