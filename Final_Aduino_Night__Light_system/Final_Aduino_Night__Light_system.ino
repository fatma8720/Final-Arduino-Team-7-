
#include <Servo.h>  
       
       Servo myservo;  

#define LDR A0
#define LED1 12
#define LED2 13
#define LED3 2
#define LED4 4
#define LED5 7
#define echoPin 10
#define trigPin 8
const int LDR_Min=700;
const int DISTANCE_THRESHOLD = 50;
int LDRValue = 0;
long duration; 
int distance;
int val;  
int pos = 0;

void setup() {
  
  Serial.begin(9600);
   myservo.attach(9); 
   
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);

  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); 
  Serial.println("with Arduino UNO R3");
  
  
}

void loop() { 
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance < DISTANCE_THRESHOLD){
     myservo.write(180); 
 if(analogRead(LDR)<LDR_Min) {
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, HIGH); 
  delay(500);
  }
  }
 
   
  if (distance > DISTANCE_THRESHOLD){
    myservo.write(0);
  }
   
}
