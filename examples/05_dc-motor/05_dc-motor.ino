//////////////////////////////////
////บทความที่เกี่ยวข้อง  https://sites.google.com/site/klsrobotcenter/lab-4-motor-nano-bot
/////////////////////////////////
///////////ตั้งค่าปุ่มกด///////////////////
int button =  2; /// กำหนดปุ่มกดสวิตซ์ขา 2

////////////ตั้งค่าพอร์ตมอเตอร์////////////////////
#define DR1  7  /// กำหนดสัญญาณดิจิตอลขวาที่ 1 พอร์ต 7
#define DR2  8  /// กำหนดสัญญาณดิจิตอลขวาที่ 2 พอร์ต 8
#define PWMR 6 /// กำหนดสัญญาณ PWM ขวาพอร์ต 6
/////////////////////////////////
#define DL1  9  // กำหนดสัญญาณดิจิตอลซ้ายที่ 1 พอร์ต 9
#define DL2  4  // กำหนดสัญญาณดิจิตอลซ้ายที่ 2 พอร์ต 4
#define PWML 5  /// กำหนดสัญญาณ PWM ซ้ายพอร์ต 5

void setup() {
  Serial.begin(9600);
  //////////////////////////////////////////////////
  pinMode(2, INPUT); // ตั้งค่าขา 2 เป็น INPUT

  ////////กำหนดสัญญาณทุกขาเป็น OUTPUT ///////////////
  pinMode(DL1, OUTPUT);
  pinMode(DL2, OUTPUT);
  pinMode(PWML, OUTPUT);
  pinMode(DR1, OUTPUT);
  pinMode(DR2, OUTPUT);
  pinMode(PWMR, OUTPUT);
  ////////////////////////////
}

void loop() {
  int sw = digitalRead(button);
  if (sw == 0) {
    tone(3, 1000, 500);
    ///////////////// เขียน Code ทดสอบที่นี่ /////////////
    run(100, 100); delay(1000); run(0, 0);tone(3,1200,100);
    run(100, 0); delay(1000); run(0, 0);tone(3,1200,100);
    run(-100, -100); delay(1000); run(0, 0);tone(3,1200,100);
    run(0, 100); delay(1000); run(0, 0);tone(3,1200,100);
   
  }
  ///////////////////////////////////////////////
  else {
    run(0, 0);
  }
  Serial.println(sw);
}
////////////////////////////////////////
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
    analogWrite(PWML, -255);
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
    analogWrite(PWMR, -255);
  }
}
