#include <LiquidCrystal_I2C.h>

int motionPin = 10;
int motion = 0;

#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET     4
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

int dataServo1 = 270; // Servo 1 rotation range(dataServo1=0~180)
int dataServo2 = 0; // Servo 2 rotation range(dataServo2=0~180) 
int dataServo3 = 0; // Servo 3 rotation range(dataServo3=0~180)
int dataServo4 = 180; // Servo 4 rotation range(dataServo4=0~180)
int dataServo5 = 135; // Servo 5 rotation range(dataServo5=35~90)

float dirServo1ffset = 0;    // define a variable for deviation(degree) of the servo
float dirServo2ffset = 0;    // define a variable for deviation(degree) of the servo
float dirServo3ffset = 0;    // define a variable for deviation(degree) of the servo
float dirServo4ffset = 0;    // define a variable for deviation(degree) of the servo
float dirServo5ffset = 0;    // define a variable for deviation(degree) of the servo

int motionServo1 = 90;
int motionServo2 = 113;
int motionServo3 = 90;
int motionServo4 = 90;
int motionServo5 = 135;


void setup() {
  // put your setup code here, to run once:
  pinMode(motionPin, INPUT);
  Serial.begin(9600);

  servo1.attach(9);
  servo2.attach(6);
  servo3.attach(5);
  servo4.attach(3);
  servo5.attach(11);
  
  servo1.write(dataServo1+dirServo1ffset);
  servo2.write(dataServo2+dirServo2ffset);
  servo3.write(dataServo3+dirServo3ffset); 
  servo4.write(dataServo4+dirServo4ffset);
  servo5.write(dataServo5+dirServo5ffset);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextColor(WHITE);//Sets the font display color
  display.clearDisplay();//cls
  //Set the font size
  display.setTextSize(2);
  //Set the display location
  display.setCursor(0, 0);
  //String displayed
  display.println(F("OLED OK"));
  //Began to show
  display.display();

  delay(1000);

  delay(30000);
  display.clearDisplay();;
  display.setCursor(0, 0);
  display.println(F("Motion Sensor Calibrated"));
  delay(3000);

  

}

void loop() {
  // put your main code here, to run repeatedly:
  motion = digitalRead(motionPin);
  
  if(motion == HIGH){
    servo1.write(motionServo1);
    servo2.write(motionServo2);
    servo3.write(motionServo3);
    servo4.write(motionServo4);
    servo5.write(motionServo5);

    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Happy     Father's  Day Appa!");
    display.display();

    delay(30000);
  }
  else{
    servo1.write(dataServo1+dirServo1ffset);
    servo2.write(dataServo2+dirServo2ffset);
    servo3.write(dataServo3+dirServo3ffset); 
    servo4.write(dataServo4+dirServo4ffset);
    servo5.write(dataServo5+dirServo5ffset);

    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("No Motion Detected");
    display.display();
  }
  
}
