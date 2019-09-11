#include <Servo.h>. 
 
// Ultrasonik Sinyal pinleri
const int trigPin = 10;
const int echoPin = 11;
const int LEDdizisi[] = {2,3,4,5,6,7};

long duration;
int distance;
 
Servo myServo; 

void setup() {
  for(int i=0; i<6 ;i++)    
  { /* For dongusuyle LEDdizisi elemanlarina ulasiyoruz */
    pinMode(LEDdizisi[i], OUTPUT); /* LED pinleri cikis olarak ayarlandi */
  }
  
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  myServo.attach(12); // Servo motor sinyal pini
}

void loop() {
  

   
  // 15 derece ile 165 derece arasında dön
  for(int i=15;i<=165;i++){ myServo.write(i); delay(30); distance = calculateDistance(); Serial.print(i); Serial.print(","); Serial.print(distance); Serial.print("."); } for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
  
  for(int i=0; i<6; i++){ /* Tum LEDleri sirayla 50 milisaniye yakip sonduruyoruz */
    digitalWrite(LEDdizisi[i],HIGH);      
    delay(150);                           
    digitalWrite(LEDdizisi[i],LOW);         
  }
 
  for(int j=5;j>-1; j--)
  { /* LEDleri geri yonde 50 milisaniye yakip sonduruyoruz */
    digitalWrite(LEDdizisi[j],HIGH);     
    delay(150);
    digitalWrite(LEDdizisi[j], LOW);
  }
 
}

  

 
int calculateDistance(){ 
   
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  return distance;
}
