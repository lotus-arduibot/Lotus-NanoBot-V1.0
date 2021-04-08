//////////////////////////////////
////บทความที่เกี่ยวข้อง https://sites.google.com/site/klsrobotcenter/lab1-digital-output
/////////////////////////////////
void setup() {   // ทำงานครั้งเดียว
pinMode(2,OUTPUT); // พอร์ต 2 ทำหน้าที่เป็น OUTPUT
}

void loop() {    // ทำงานต่อเนื่อง
digitalWrite(2,HIGH);  // ไฟติดที่พอร์ต 2
delay(1000);   // เวลา 1000 มิลลิวินาที
digitalWrite(2,LOW); // ไฟดับที่พอร์ต 2
delay(1000);   // เวลา 1000 มิลลิวินาที
}