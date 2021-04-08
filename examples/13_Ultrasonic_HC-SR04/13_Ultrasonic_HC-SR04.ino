//////////////////////////////////
////บทความที่เกี่ยวข้อง https://sites.google.com/site/klsrobotcenter/lab-13-kar-chi-ngan-ultrasonic-module-hc-sr04
/////////////////////////////////
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 OLED(-1);
 ////////////////////////////////////////     
      int trig = A0;  // ให้ขา Trig ต่อเข้ากับพอร์ต A0
      int echo = A1;  // ให้ขา Echo ต่อเข้ากับพอร์ต A1
////////////////////////////////////////
    void setup() {
    OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C); // กำหนดแอดเดรสของพอร์ตจอเป็น 0x3C (for the 128x64)
    }  
    void loop()
    {
      long duration, cm; 
      pinMode(trig, OUTPUT);   
      digitalWrite(trig, LOW);
      delayMicroseconds(2);
      digitalWrite(trig, HIGH);
      delayMicroseconds(5);
      digitalWrite(trig, LOW);
      pinMode(echo, INPUT);
      duration = pulseIn(echo, HIGH);
      cm = microsecondsToCentimeters(duration);
      OLED.clearDisplay();
      OLED.setTextColor(WHITE, BLACK);  //สีอักษรเป็นสีขาว ,พื้นหลังดำ
      OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
      OLED.setTextSize(2);        // เซตขนาดอักษรมีขนาดเป็น 1
      OLED.println(" Distance");  // พิมพ์ตัวอักษรที่จอ OLED คำว่า Distance
      OLED.println("..........");  // พิมพ์ตัวอักษรที่จอ OLED คำว่า .............
      OLED.print("    "); // เว้นวรรคที่จอ OLED
      OLED.print(cm);   // พิมพ์ตัวอักษรที่จอ OLED อ่านค่าตัวแปร cm
      OLED.println("cm");// พิมพ์ตัวอักษรที่จอ OLED คำว่า cm
      OLED.println("..........");  // พิมพ์ตัวอักษรที่จอ OLED คำว่า .............
      OLED.display(); // แสดงผลการทำงานจอ OLED
      delay(50); // หน่วงเวลาการทำงานทุกๆ 50 มิลลิวินาที
    }
     
    long microsecondsToCentimeters(long microseconds)
    {
      // The speed of sound is 340 m/s or 29 microseconds per centimeter.
      // The ping travels out and back, so to find the distance of the
      // object we take half of the distance travelled.
      return microseconds / 29 / 2;
    }
