
#define buzzer 2
#define MOTOR1 8
#define MOTOR2 9
#define EN 10

int value = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(EN,OUTPUT);
  pinMode(MOTOR1,OUTPUT);
  pinMode(MOTOR2,OUTPUT);
  pinMode(buzzer, OUTPUT);
 
}
void loop() {
    tone(buzzer, 255, 1000);
    digitalWrite(MOTOR1,HIGH);
    digitalWrite(MOTOR2,LOW);
    if((200)<(512)){
    value = map(200, 0, 512, 0, 255);  
      Serial.println(value);
      analogWrite(EN,value);
      digitalWrite(MOTOR1,HIGH);
      digitalWrite(MOTOR2,LOW);
    }else{
      value = map(700, 512, 1023, 0, 255);
      Serial.println(value);
      analogWrite(EN,value);
      digitalWrite(MOTOR1,LOW);
      digitalWrite(MOTOR2,HIGH);
 
      }
 
  }
