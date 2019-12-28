#include <Servo.h>

//Definions
#define DEBUG 1
//#define WIN 1 // for input from windows terminal

//defining the pins
const int trigPin = 52;
const int echoPin = 53;

//Servo Objects
//Left Half
Servo servo_left_hip;
Servo servo_left_knee;
Servo servo_left_ankle;
Servo servo_left_shoulder;
Servo servo_left_elbow;
Servo servo_left_wrist;
//Rigth half
Servo servo_right_hip;
Servo servo_right_knee;
Servo servo_right_ankle;
Servo servo_right_shoulder;
Servo servo_right_elbow;
Servo servo_right_wrist;

int delay_time = 650;

//Debugging Vaules
const String POSITION = "Centeral";
//const String POSITION = "top";
const String FUNCTION = "move limbs";
//const String FUNCTION = "move neck";

//Bottom Baud Rate is 85 plus std rate of 9600
int bottom_baud_rate = 9685;

//Top Baud Rate is 36 plus std rate of 9600
//int top_baud_rate = 9636;

// defining variables
long duration;
int distance;

//movement variable
boolean movement = true;

//Threading Variables
unsigned long current_time = 0;
unsigned long previous_time = 0;
unsigned int button_blink_period = 1000;       // 1 second
unsigned long time_elapsed = button_blink_period;

void setup()
{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);
  Serial.begin(bottom_baud_rate);
  //Left
  servo_left_hip.attach(13);
  servo_left_knee.attach(12);
  servo_left_ankle.attach(11);
  servo_left_shoulder.attach(10);
  servo_left_elbow.attach(9);
  servo_left_wrist.attach(8);
  //Right
  //Serial.begin(right_baud_rate);
  servo_right_hip.attach(7);
  servo_right_knee.attach(6);
  servo_right_ankle.attach(5);
  servo_right_shoulder.attach(4);
  servo_right_elbow.attach(3);
  servo_right_wrist.attach(2);
  //Sleep for controller to sort out all internal connections and register vaules
  delay(200);
  //Move Servos to "Zero" position
  //Rigth
  servo_right_hip.write(90);
  servo_right_knee.write(90);
  servo_right_ankle.write(90);
  servo_right_shoulder.write(90);
  servo_right_elbow.write(90);
  servo_right_wrist.write(90);
  //Left
  servo_left_hip.write(90);
  servo_left_knee.write(90);
  servo_left_ankle.write(90);
  servo_left_shoulder.write(90);
  servo_left_elbow.write(90);
  servo_left_wrist.write(90);
}

void loop()
{
  current_time = millis();
  String input;
  //If any input is detected in arduino
  if (Serial.available() > 0)
  {
    //read the whole string until '\n' delimiter is read
#ifdef WIN
    input = Serial.readStringUntil('\r');
#else
    input = Serial.readStringUntil('\n');
#endif
    Serial.println(input);
    if (movement == true)
    {
      if (input.equals("walk backward"))
      {
        walk_legs();
        Serial.println("Legs is walking");
      }
      else if (input.equals("walk forward"))
      {
        walk_legs();
        Serial.println("Legs is walking");
      }
      else if (input.equals("stop"))
      {
        movement = false;
        stop_moving();
        Serial.println("stopping movement");
      }
      else if (input.equals("pos"))
      {
        Serial.println("Controller Position is " + POSITION + "Baud Rate is " + bottom_baud_rate);
      }
      else if (input.equals("function"))
      {
        Serial.println("Function is " + FUNCTION);
      }
    }
    else if (input.equals("resume"))
    {
      movement = true;
      Serial.println("resuming movement");
    }
  }
  else if (movement == false)
  {
    dist_check();
  }

  time_elapsed += (current_time - previous_time);
  previous_time = current_time;
}

void op_serial_checker()
{
  String input;
  //If any input is detected in arduino
  if (Serial.available() > 0)
  {
    //read the whole string until '\n' delimiter is read
#ifdef WIN
    input = Serial.readStringUntil('\r');
#else
    input = Serial.readStringUntil('\n');
#endif
    Serial.println(input);
    if (movement == true)
    {
      if (input.equals("turn left"))
      {
        Serial.println("turning left");
      }
      else if (input.equals("turn right"))
      {
        Serial.println("turning right");
      }
      else if (input.equals("stop"))
      {
        stop_moving();
        movement = false;
        Serial.println("stopping movement");
      }
      else if (input.equals("resume"))
      {
        movement = true;
        Serial.println("resuming movement");
      }
    }
  }
}

void walk_legs()
{
  while (movement)
  {
    servo_left_hip.write(90);
    servo_left_knee.write(90);
    servo_left_ankle.write(90);
    servo_left_shoulder.write(90);
    servo_left_elbow.write(90);
    servo_left_wrist.write(90);
    dist_check();
    op_serial_checker();
    delay(delay_time - 200);
    servo_left_hip.write(0);
    servo_left_knee.write(0);
    servo_left_ankle.write(0);
    servo_left_shoulder.write(0);
    servo_left_elbow.write(0);
    servo_left_wrist.write(0);
    dist_check();
    op_serial_checker();
    delay(delay_time - 200);
  }
}

void walk_arms()
{
  servo_left_hip.write(90);
  servo_left_knee.write(90);
  servo_left_ankle.write(90);
  servo_left_shoulder.write(90);
  servo_left_elbow.write(90);
  servo_left_wrist.write(90);
  delay(delay_time);
  servo_left_hip.write(0);
  servo_left_knee.write(0);
  servo_left_ankle.write(0);
  servo_left_shoulder.write(0);
  servo_left_elbow.write(0);
  servo_left_wrist.write(0);
  delay(delay_time);
  servo_left_hip.write(90);
  servo_left_knee.write(90);
  servo_left_ankle.write(90);
  servo_left_shoulder.write(90);
  servo_left_elbow.write(90);
  servo_left_wrist.write(90);
}

void stop_moving()
{
  //Rigth
  servo_right_hip.write(90);
  servo_right_knee.write(90);
  servo_right_ankle.write(90);
  servo_right_shoulder.write(90);
  servo_right_elbow.write(90);
  servo_right_wrist.write(90);
  //Left
  servo_left_hip.write(90);
  servo_left_knee.write(90);
  servo_left_ankle.write(90);
  servo_left_shoulder.write(90);
  servo_left_elbow.write(90);
  servo_left_wrist.write(90);
}

void dist_check()
{
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  if (DEBUG)
  {
    Serial.println(distance);
  }
  if (movement ==  true) {
    if (distance <= 10)
    {
      movement = false;
      Serial.println("frezzing all motor functions");
    }
  }
  else if (movement == false)
  {
    if (distance >= 10)
    {
      movement = true;
      Serial.println("resuming all motor functions");
    }
  }
}
