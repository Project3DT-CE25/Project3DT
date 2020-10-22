#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

int ledPin = 13;    // LED connected to digital pin 13 ON BOARD
int pumpPin = 8;    // pin 8
int irPin = 7;      // OUTPUT * Black line * pin 7
int valueIR = 0;

int ambient = 0;
int object = 0;
int trigPump = 0;
unsigned long last_time = (millis()-2500);  //delay before work 500 ms. (realtime - 1500) mean period 3000 - 500
unsigned long period = 3000;    // set Time for work pump ms. /1000 = s. - 2 sec. -
int count = 0;                  // count on/off pump

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
}

void func_sensor(){
    static unsigned long last_time = millis();
    static unsigned long period = 500;
    if(millis() - last_time >= period){
      last_time = millis();
      /*
       * Enter Code
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
  if(trigPump == 1){ 
    if(millis() - last_time >= period){
      last_time = millis();
      /*
       * Enter Code
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
      }
    }
  }
}
