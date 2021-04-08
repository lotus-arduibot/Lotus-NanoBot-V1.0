//////////////////////////////////
////บทความที่เกี่ยวข้อง https://sites.google.com/site/klsrobotcenter/lab-4-kar-chi-ngan-servo-motor
/////////////////////////////////
#include <Servo.h> // ผนวกไลบรารี่
int s1 = 10;  // เปิดใช้งาน s1 ที่พอร์ต 10
Servo sv1;     // ประกาศการใช้งาน sv1
void setup() { 
   sv1.attach(s1); // เรียกใช้งานเตรียมตอบสนอง sv1
}
void loop(){ 
   sv1.write(0);  // sv1 ทำงานที่ 0 องศา
   delay(1000);    //หน่วงเวลา 1 วินาที
   sv1.write(30);  // sv1 ทำงานที่ 30 องศา
   delay(1000);    //หน่วงเวลา 1 วินาที
   sv1.write(60); // sv1 ทำงานที่ 60 องศา
   delay(1000);    //หน่วงเวลา 1 วินาที
}
