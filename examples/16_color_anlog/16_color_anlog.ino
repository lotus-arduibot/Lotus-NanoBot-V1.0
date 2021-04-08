//////////////////////////////////
////บทความที่เกี่ยวข้อง https://sites.google.com/site/klsrobotcenter/lab-16-kar-xan-kha-si-cak-sayyananalog-doy-chi-sensexrlotus-t3-rgb
/////////////////////////////////
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 OLED(-1);
/////////ค่าสี S1R ใช้เซนเซอร์ T3 สีแดงวัด////////
#define Y01 10000     // กรอกค่าพื้นเหลือง
#define G01 10000     // กรอกค่าพื้นเขียว
#define R01 10000     // กรอกค่าพื้นแดง
#define B01 10000     // กรอกค่าพื้นน้ำเงิน
/////////ค่าสี S2B ใช้เซนเซอร์ T3 สีน้ำเงินวัด/////////////////////
#define Y02 10000     // กรอกค่าพื้นเหลือง
#define G02 10000     // กรอกค่าพื้นเขียว
#define R02 10000     // กรอกค่าพื้นแดง
#define B02 10000     // กรอกค่าพื้นน้ำเงิน
/////////ค่าสี S6G ใช้เซนเซอร์ T3 สีเขียววัด/////////////////////
#define Y06 10000     // กรอกค่าพื้นเหลือง
#define G06 10000     // กรอกค่าพื้นเขียว
#define R06 10000     // กรอกค่าพื้นแดง
#define B06 10000     // กรอกค่าพื้นน้ำเงิน
///////////////////////////////////////////////////////
void setup() {
  // put your setup code here, to run once:
 OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C); // กำหนดแอดเดรสของพอร์ตจอเป็น 0x3C (for the 128x64)
 
}
void loop() {
  // put your main code here, to run repeatedly:
  int  s0 = analogRead(0);
  int  s1 = analogRead(1);
  int  s2 = analogRead(2);
  int  s3 = analogRead(3);
  int  s6 = analogRead(6);
OLED.clearDisplay();
    OLED.setTextColor(WHITE, BLACK);  //สีอักษรเป็นสีขาว ,พื้นหลังดำ
    OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
    OLED.setTextSize(1);        // เซตขนาดอักษรมีขนาดเป็น 1
    OLED.print("      S1R = "); OLED.println(s1);  // แสดงค่าเซนเซอร์ S1
    OLED.print("      S2B = "); OLED.println(s2);  // แสดงค่าเซนเซอร์ S2
    OLED.print("      S6G = "); OLED.println(s6);  // แสดงค่าเซนเซอร์ S3
    if (  ( s1>=(Y01 - 100) ) and (s1 < (Y01 + 100))and( s2>=(Y02 - 100) ) and (s2 < (Y02 + 100))and( s6>=(Y06 - 70) ) and (s6 < (Y06 + 70))      ){OLED.println("         Yelow");}
    if (  ( s1>=(G01 - 100) ) and (s1 < (G01 + 100))and( s2>=(G02 - 100) ) and (s2 < (G02 + 100))and( s6>=(G06 - 70) ) and (s6 < (G06 + 70))        ){OLED.println("         Green");}
    if (  ( s1>=(R01 - 100) ) and (s1 < (R01 + 100))and( s2>=(R02 - 100) ) and (s2 < (R02 + 100))and( s6>=(R06 - 70) ) and (s6 < (R06 + 70))        ) {OLED.println("          Red");}
    if (  ( s1>=(B01 - 100) ) and (s1 < (B01 + 100))and( s2>=(B02 - 100) ) and (s2 < (B02 + 100))and( s6>=(B06 - 70) ) and (s6 < (B06 + 70))        ) {OLED.println("          Blue");}           
    else { OLED.println("        -------");}
    OLED.display();
    delay(50);
}
