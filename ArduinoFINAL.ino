#include <Adafruit_MotorShield.h>

const int trigPin=9;
const int echoPin=10;
const int trigPin2=12;
const int echoPin2=11;
const int DISTANCE=200;

long duration;
int distance;
long duration2;
int distance2;
int stop;

Adafruit_MotorShield AFMS = Adafruit_MotorShield();//

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *backLeft = AFMS.getMotor(1);
Adafruit_DCMotor *backRight = AFMS.getMotor(2);
Adafruit_DCMotor *frontRight = AFMS.getMotor(3);
Adafruit_DCMotor *frontLeft = AFMS.getMotor(4);


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  Serial.begin(9600);           // set up Serial library at 9600 bps

  if (!AFMS.begin(1000)) {         // create with the default frequency 1KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }

  // Set the speed to start, from 0 (off) to 255 (max speed)
  backLeft->setSpeed(255);
  backRight->setSpeed(255);
  frontLeft->setSpeed(255);
  frontRight->setSpeed(255);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.34/2;

  Serial.print("1:");
  Serial.println(distance);

  delay(50);


  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2*0.34/2;

  Serial.print("2:");
  Serial.println(distance2);
  

  if (Serial.available()>0){
    char key = Serial.read();
  
    if (distance < DISTANCE && key=='w'){
      backLeft->run(RELEASE);
      backRight->run(RELEASE);
      frontLeft->run(RELEASE);
      frontRight->run(RELEASE);
    }
    else if (distance2 < DISTANCE && key=='s'){
      backLeft->run(RELEASE);
      backRight->run(RELEASE);
      frontLeft->run(RELEASE);
      frontRight->run(RELEASE);
    }
    else{
    //DRIVE FORWARD
      if(key=='w'){
        backLeft->run(BACKWARD);
        backRight->run(FORWARD);
        frontLeft->run(BACKWARD);
        frontRight->run(FORWARD);
      }
      
      //DRIVE BACKWARD
      else if(key=='s'){
        backLeft->run(FORWARD);
        backRight->run(BACKWARD);
        frontLeft->run(FORWARD);
        frontRight->run(BACKWARD);     
      }
    
      //TURN LEFT
      else if(key=='a'){
        frontRight->run(FORWARD);
        backRight->run(FORWARD);
        frontLeft->run(FORWARD);
        backLeft->run(FORWARD);
      }

      //TURN RIGHT
      else if(key=='d'){
        frontLeft->run(BACKWARD);
        backLeft->run(BACKWARD);
        frontRight->run(BACKWARD);
        backRight->run(BACKWARD);
      }

      else if(key=='x'){
        backLeft->run(RELEASE);
        backRight->run(RELEASE);
        frontLeft->run(RELEASE);
        frontRight->run(RELEASE);
      }
      else if (key != 'D'){
        backLeft->run(RELEASE);
        backRight->run(RELEASE);
        frontLeft->run(RELEASE);
        frontRight->run(RELEASE);
      }   
    }
  }


 
}