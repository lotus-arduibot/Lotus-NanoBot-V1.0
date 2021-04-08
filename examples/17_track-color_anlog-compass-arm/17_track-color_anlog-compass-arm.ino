int a =14;
int b =12;
int c =23;
int d =19;

void setup() {
 pinMode(a,OUTPUT); 
 pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
    pinMode(d,OUTPUT);
 }

void loop() {
 digitalWrite(a,HIGH); 
 delay(100);            
 digitalWrite(a,LOW);  
 delay(100);            
  digitalWrite(b,HIGH); 
 delay(100);            
 digitalWrite(b,LOW);  
 delay(100);            
  digitalWrite(c,HIGH); 
 delay(100);           
 digitalWrite(c,LOW);  
 delay(100);    
    digitalWrite(d,HIGH); 
 delay(100);           
 digitalWrite(d,LOW);  
 delay(100);    
}
