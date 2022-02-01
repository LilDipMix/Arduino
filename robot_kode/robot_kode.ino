// made by philip amadeus


#include "MeMegaPi.h"

float distance;

MeUltrasonicSensor ultraSensor(PORT_7); /* Ultrasonic module can ONLY be connected to port 3, 4, 6, 7, 8 of base shield. */

MeLineFollower lineFinder(PORT_5);

MeMegaPiDCMotor motor1(PORT1B);

MeMegaPiDCMotor motor2(PORT3B);


int8_t motorSpeed = 255;
int sensorState;  //IR sensor
int distance1;
int distance2;
MePort port(PORT_6);
Servo myservo1;  // create servo object to control a servo 
Servo myservo2;  // create servo object to control another servo
int16_t servo1pin =  port.pin1();//attaches the servo on PORT_3 SLOT1 to the servo object
int16_t servo2pin =  port.pin2();//attaches the servo on PORT_3 SLOT2 to the servo object

void setup()
{
  Serial.begin(9600);

}
void fast(){
  //motor PORT1B
  digitalWrite(35, LOW);
  digitalWrite(34, HIGH);

  analogWrite(12, motorSpeed);
  
  //motor PORT3B
  digitalWrite(43, LOW);
  digitalWrite(42, HIGH);

  analogWrite(9, motorSpeed);
}
void left(){
  //motor PORT1B
  digitalWrite(35, LOW);
  digitalWrite(34, HIGH);
  analogWrite(12, 100);
  
  //motor PORT3B
  digitalWrite(43, HIGH);
  digitalWrite(42, LOW);

  analogWrite(9, 100);
}

void right(){
  //motor PORT1B
  digitalWrite(35, HIGH);
  digitalWrite(34, LOW);

  analogWrite(12, 100);
  
  //motor PORT3B
  digitalWrite(43, LOW);
  digitalWrite(42, HIGH);

  analogWrite(9, 100);
}
  
void stopper(){
  //motor PORT1B
  digitalWrite(35, LOW);
  digitalWrite(34, LOW);

  analogWrite(12, motorSpeed);
  
  //motor PORT3B
  digitalWrite(43, LOW);
  digitalWrite(42, LOW);

  analogWrite(9, 0);


  myservo1.attach(servo1pin);  // attaches the servo on servopin1
  myservo2.attach(servo2pin);  // attaches the servo on servopin2
} 

void loop(){

  distance = ultraSensor.distanceCm();
  sensorState = lineFinder.readSensors();
  myservo1.write(90);                  // sets the servo position according to the scaled value 
  myservo2.write(90);
   
  if (sensorState == S1_OUT_S2_OUT){
    
     if(distance < 15){
      stopper();
      delay(1500);
      myservo1.write(0);                  // sets the servo position according to the scaled value 
      myservo2.write(0);
      delay(2000);   
      distance1 = ultraSensor.distanceCm();
      myservo1.write(180);                  // sets the servo position according to the scaled value 
      myservo2.write(180);
      delay(2000);   
      distance2 = ultraSensor.distanceCm();
         if(distance1 > distance2){
          right();
          delay(1500);
          
         }
         
         else if(distance2 < distance1){
          left();
          delay(1500);
          
         
         }
    
  }     


     
  
    else if(sensorState == S1_IN_S2_IN){
     stopper();
    }
