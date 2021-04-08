//////////////////////////////////
////บทความที่เกี่ยวข้อง  https://sites.google.com/site/klsrobotcenter/lab-6-kar-kheiyn-kha-sangmenu-lotus-nano
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
  OLED.println("  KLS ROBOT CENTER");     // พิมพ์คำว่า KLS ROBOT CENTER
  OLED.print("  ");                      // วรรค
  OLED.print(nob);                     // แสดงค่าที่อ่านได้จาก nob หรือ Analog7
  OLED.println(" www.kls.ac.th");     // พิมพ์คำว่า www.kls.ac.th
  OLED.display();
  if ((sw == 0)and(menu==0)) { OLED.clearDisplay();OLED.display();}
  if ((sw == 0)and(menu==1)) {t();}  //เมนู 1 เสียงดัง 1 ครั้ง 
  if ((sw == 0)and(menu==2)) {t();t();}  //เมนู 2 เสียงดัง 2 ครั้ง 
  if ((sw == 0)and(menu==3)) {t();t();t();}  //เมนู 3 เสียงดัง 3 ครั้ง 
  if ((sw == 0)and(menu==4)) {t();t();t();t();}  //เมนู 4 เสียงดัง 4 ครั้ง 
  if ((sw == 0)and(menu==5)) {t();t();t();t();t();}  //เมนู 5 เสียงดัง 5 ครั้ง 
  if ((sw == 0)and(menu==6)) {t();t();t();t();t();t();}  //เมนู 6 เสียงดัง 6 ครั้ง 
  if ((sw == 0)and(menu==7)) {t();t();t();t();t();t();t();}  //เมนู 7 เสียงดัง 7 ครั้ง 
  if ((sw == 0)and(menu==8)) {t();t();t();t();t();t();t();t();}  //เมนู 8 เสียงดัง 8 ครั้ง 
  if ((sw == 0)and(menu==9)) {t();t();t();t();t();t();t();t();t();}  //เมนู 9 เสียงดัง 9 ครั้ง 
  if ((sw == 0)and(menu==10)) {t();t();t();t();t();t();t();t();t();t();}  //เมนู 10 เสียงดัง 10 ครั้ง 
  if ((sw == 0)and(menu==11)) {t();t();t();t();t();t();t();t();t();t();t();}  //เมนู 11 เสียงดัง 11 ครั้ง 
  if ((sw == 0)and(menu==12)) {t();t();t();t();t();t();t();t();t();t();t();t();}  //เมนู 12 เสียงดัง 12 ครั้ง 
  delay(100);
}
void t()    // ฟังก์ชันเสียงดังที่พอร์ต 3
{tone(3,1000,100);delay(300);  }
