#include <NewPing.h>

#define SONAR_NUM 1   
#define MAX_DISTANCE 150 

#define Front 0

#define TRIG 2 
#define ECHO 3  

NewPing sonar(TRIG, ECHO, MAX_DISTANCE);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); 
  Serial.begin(115200);
}

long sonar_front(void) {
  long duration, distance;

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = ((float)(340 * duration) / 1000) / 2;
  
  return distance;
}

void loop() {
  float front_sonar = 0.0;

  front_sonar = sonar.ping_cm()*10; 
  if(front_sonar == 0.0)  front_sonar = MAX_DISTANCE;
   
  Serial.print("Distance: ");
  Serial.print(front_sonar);  
  Serial.println("mm");

  if((front_sonar > 0) && (front_sonar <= 250.0))
  {
    digitalWrite(LED_BUILTIN, HIGH);   
    delay(500);  //  1초동안 켜짐
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);    
    delay(500);  //  1초동안 꺼짐
  }
}
