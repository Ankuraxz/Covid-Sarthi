// permanently HIGH pins:
 // permanently LOW pins: 12
#include <LiquidCrystal.h> // includes the LiquidCrystal Library 
#include <DHT.h>
#define DHTPIN 52
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7) 
int Contrast = 50; //LCD CONTRAST
int ledPin = 13;                // choose the pin for the LED
int inputPin = 53;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;   
void setup() {
  // put your setup code here, to run once:
analogWrite(8,Contrast);
//lcd.begin(16,2);
//dht.begin();
//lcd.print("COVID SARTHI");
//float f = dht.readTemperature(true);
//if (isnan(f)){
//  lcd.print("ERROR");
//}
//lcd.setCursor(0,1);
//lcd.print("temp");
//lcd.print(f);
//delay(3000);

//lcd.setCursor(0,1);
//lcd.print("temp");
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
  pinMode(12,OUTPUT);
  digitalWrite(12,LOW);
 
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);


lcd.begin(16,2);
dht.begin();
lcd.print("COVID SARTHI");
float f = dht.readTemperature(true);
if (isnan(f)){
  lcd.print("ERROR");
}
lcd.setCursor(0,1);
lcd.print("temp");
lcd.print(f);
//delay(3000);
  

val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      
      delay(1000);
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");

      delay(1000);
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }

  


}
