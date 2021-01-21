#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <Servo.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
Servo myservo; //echo Servo
/*
 * SET PORT
 */
int ledPin = 13;    // LED connected to digital pin 13 ON BOARD
int pumpPin = 8;    // pin 8
int irPin = 7;      // OUTPUT * Black line * pin 7
int irS1 = 9;
int irS2 = 10;
myservo.attach(15);
/*
 * Global variable
 */
int valueIR = 0;
int valueS1 = 0;
int valueS2 = 0;
int ambient = 0;
int object = 0;
/*
 * Triger variable
 */
int count = 0;                  // count on/off pump
int trigPump = 0;
int trigGate = 0;

void setup() {
  pinMode(ledPin, OUTPUT);    // set the digital pin 13 as output
  pinMode(irPin, INPUT);      // set the digital pin 7 as input
  
  pinMode(pumpPin, OUTPUT);      // set the digital pin 8 as output
  digitalWrite(pumpPin, LOW);    // off
  
  mlx.begin();
  Serial.begin(9600);
}

void loop() {
  func_sensor();
  func_pump();
  func_gate();
}

void func_sensor(){
    static unsigned long last_time = millis();
    static unsigned long period = 500;
    if(millis() - last_time >= period){
      last_time = millis();
      /*
       * READ SENSOR FOR HAND
       */
      valueIR = digitalRead(irPin);
      if(valueIR == 0){
        digitalWrite(ledPin, HIGH);
        ambient = mlx.readAmbientTempC();
        object = mlx.readObjectTempC();
        Serial.print("Ambient = "); Serial.print(ambient); 
        Serial.print("*C\tObject = "); Serial.print(object); Serial.println("*C");
        trigPump = 1;
      }
    }
}

void func_pump(){
  static unsigned long last_time = (millis()-2500);   //delay before work 500 ms. (realtime - 2500) mean period 3000 - 500
  static unsigned long period = 3000;                 // set Time for work pump ms. /1000 = s. -* 3 sec. *-
  if(trigPump == 1){
    if(millis() - last_time >= period){
      last_time = millis();
      /*
       * Every 3 sec.
       */
      if(count == 0){
        digitalWrite(pumpPin, HIGH);
        count++;
      }else{
        digitalWrite(pumpPin, LOW);
        count = 0;
        trigPump = 0;
        while(digitalRead(irPin) == 0){
          // stop work until your hand out area
        }
        trigGate = 1;
      }
    }
  }
}

void func_gate(){
  if(trigGate == 1){
    static unsigned long last_time = millis()           // (millis()-4500);   // Delay Before Work 500 ms.
    static unsigned long period = 5000;                 // Time work 5 s.
    if(millis() - last_time >= period){
      last_time = millis();
      /*
       * After Time.  5 sec. Close and Reset
       */
      trigGate = 0;
    }
    valueS1 = digitalRead(irS1);
    valueS2 = digitalRead(irS2);
    if(valueS1 == 0 and valueS2 == 1){          // sw1 = on , sw2 = off
      //--------- OPEN GATE ------------//
      myservo.write(90);
    }else if(valueS1 == 0 and valueS2 == 0){
      //--------- HOLD OPEN GATE ------------//
      myservo.write(90);
    }else if(valueS1 == 1 and valueS2 == 0){
      //--------- CLOSE AND RESET ------//
      trigGate = 0;
    }
  }else{
    //--------- CLOSE GATE -----------//
    myservo.write(0);
  }
}
