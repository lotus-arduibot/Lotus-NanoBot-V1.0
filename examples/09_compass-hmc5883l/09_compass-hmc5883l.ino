//////////////////////////////////
////บทความที่เกี่ยวข้อง   https://sites.google.com/site/klsrobotcenter/lab-9-kar-chi-ngan-khem-thisdigital-i2c-hmc5883l
/////////////////////////////////
#include <Wire.h>
#include <MechaQMC5883.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 OLED(-1);

MechaQMC5883 qmc;

void setup() {
  OLED.begin(SSD1306_SWITCHCAPVCC,0x3C); // กำหนดแอดเดรสของพอร์ตจอเป็น 0x3C (for the 128x64)
  Wire.begin();
  Serial.begin(9600);
  qmc.init();    //qmc.setMode(Mode_Continuous,ODR_200Hz,RNG_2G,OSR_256);
}

void loop() {
  int x, y, z;
  int azimuth;
  //float azimuth; //is supporting float too
  qmc.read(&x, &y, &z,&azimuth);
  //azimuth = qmc.azimuth(&y,&x);//you can get custom azimuth
  //////////////////////แสดงคำสั่งแต่ละแกนที่จอ OLED //////////////////
   OLED.clearDisplay();
  OLED.setTextColor(WHITE,BLACK);   //สีอักษรเป็นสีขาว ,พื้นหลังดำ
  OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
  OLED.setTextSize(2);        // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.print("x = ");  
  OLED.println(x);
    OLED.print("y = ");  
  OLED.println(y);  
    OLED.print("z = ");  
  OLED.println(z);     
    OLED.print("a = ");  
  OLED.println(azimuth);  
  OLED.display();

  /*//////////////////// โชว์คำสั่งแต่ละแกนที่ Serial monitor ///////////
  Serial.print("x: ");
  Serial.print(x);
  Serial.print(" y: ");
  Serial.print(y);
  Serial.print(" z: ");
  Serial.print(z);
  Serial.print(" a: ");
  Serial.print(azimuth);
  Serial.println();
  delay(100);
  */
}
