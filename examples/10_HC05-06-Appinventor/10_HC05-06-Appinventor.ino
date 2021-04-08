//////////////////////////////////
////บทความที่เกี่ยวข้อง https://sites.google.com/site/klsrobotcenter/lab-10-kar-chi-ngan-modul-bluthuth-tha-cxy-bangkhab-hun-ynt-lotus-nano-bot
/////////////////////////////////

#define DL1  7
#define DL2  8
#define PWML 6
#define DR1  9
#define DR2  4
#define PWMR 5
/////////////////////////////////////////////////////////////////
void setup()
{
  Serial.begin(9600); ///////// อ่านซีเรียลมอนิเตอร์ ที่ 9600
  pinMode(DL1, OUTPUT);
  pinMode(DL2, OUTPUT);
  pinMode(PWML, OUTPUT);
  pinMode(DR1, OUTPUT);
  pinMode(DR2, OUTPUT);
  pinMode(PWMR, OUTPUT);  
}  
/////////////////////////////////////////////////////////////////////////////////
void loop()
 {
   if(Serial.available()>0);
{       char x = Serial.read();
        if (x == 'F') {run(100,100);}    /// รับค่าคำสั่ง F เดินหน้า
        if (x == 'B'){run(-100,-100);}   /// รับค่าคำสั่ง B ถอยหลัง
        if (x == 'R') {run(100,-100);}   /// รับค่าคำสั่ง R เลี้ยวขวา
        if (x == 'L') {run(-100,100);}   /// รับค่าคำสั่ง L เลี้ยวซ้าย
         if (x == 'S') {run(0,0);}      /// รับค่าคำสั่ง S หยุด
    }}
/////////////////////////////////////////////
void run(int spl,int spr)
{
if(spl>0)
  {
  digitalWrite(DL1, LOW);
  digitalWrite(DL2, HIGH);
  analogWrite(PWML, spl);
  }
else if(spl<0)
      {
      digitalWrite(DL1, HIGH);
      digitalWrite(DL2, LOW);
      analogWrite(PWML, -spl);
      }
     else
      {
      digitalWrite(DL1, HIGH);
      digitalWrite(DL2, HIGH);
      analogWrite(PWMR, -255);
      }
///////////////////
if(spr>0)
  {
  digitalWrite(DR1, LOW);
  digitalWrite(DR2, HIGH);
  analogWrite(PWMR, spr);
  }
else if(spr<0)
      {
      digitalWrite(DR1, HIGH);
      digitalWrite(DR2, LOW);
      analogWrite(PWMR, -spr);
      }
     else
      {
      digitalWrite(DR1, HIGH);
      digitalWrite(DR2, HIGH);
      analogWrite(PWMR, -255);
      }             
}      
