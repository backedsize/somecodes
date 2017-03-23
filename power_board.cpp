#include <Servo.h>
#include <ros.h>
#include <power_board/PwrBrd.h>

ros::NodeHandle nh;

//PWM: 3, 5, 6, 9, 10, and 11. Provide 8-bit PWM
Servo ESC1;
Servo ESC2;
Servo ESC3;
Servo ESC4;
Servo ESC5;
Servo ESC6;

const int ESC1PIN = 3;
const int ESC2PIN = 5;
const int ESC3PIN = 6;
const int ESC4PIN = 9;
const int ESC5PIN = 10;
const int ESC6PIN = 11;
const int BUTTON = 4;
const int SWITCH = 7;

power_board::PwrBrd PwrBrd; //Objeto
ros::Subscriber sub("PwrBrd", &PwrBrd); //Subscribe no topico PwrBrd

void setup()
{
  nh.initNode();
  nh.subscribe(sub); //Subscribe na funcao do ROS

  ESC1.attach(ESC1PIN);
  ESC1.writeMicroseconds(1500);  // Set to NeutralPoint
  ESC2.attach(ESC2PIN);
  ESC2.writeMicroseconds(1500);
  ESC3.attach(ESC3PIN);
  ESC3.writeMicroseconds(1500);
  ESC4.attach(ESC4PIN);
  ESC4.writeMicroseconds(1500);
  ESC5.attach(ESC5PIN);
  ESC5.writeMicroseconds(1500);
  ESC6.attach(ESC6PIN);
  ESC6.writeMicroseconds(1500);

  pinMode(BUTTON, OUTPUT);
  pinMode(SWITCH, OUTPUT);
  Serial.begin(9600); //check se precisa dar serial begin
}

void loop(){
  ESC1.writeMicroseconds = PwrBrd.ESC1;
  ESC2.writeMicroseconds = PwrBrd.ESC2;
  ESC3.writeMicroseconds = PwrBrd.ESC3;
  ESC4.writeMicroseconds = PwrBrd.ESC4;
  ESC5.writeMicroseconds = PwrBrd.ESC5;
  ESC6.writeMicroseconds = PwrBrd.ESC6;
  nh.spinOnce();
  delay(1);
}





