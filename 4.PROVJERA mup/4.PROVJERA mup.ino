

#include "DHT.h"
#define DHTPIN 11     
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);
const int pinA = 2;
const int pinB = 3;
const int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;
int pinDP = 9;
void setup() {
  pinMode(pinA,OUTPUT);
  pinMode(pinB,OUTPUT);
  pinMode(pinC,OUTPUT);
  pinMode(pinD,OUTPUT);
  pinMode(pinE,OUTPUT);
  pinMode(pinF,OUTPUT);
  pinMode(pinG,OUTPUT);
  pinMode(pinDP,OUTPUT);
  digitalWrite(pinA,HIGH);
  digitalWrite(pinB,HIGH);
  digitalWrite(pinC,HIGH);
  digitalWrite(pinD,HIGH);
  digitalWrite(pinE,HIGH);
  digitalWrite(pinF,HIGH);
  digitalWrite(pinG,HIGH);
  digitalWrite(pinDP,HIGH);
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {

  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
 float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
  if (t<20){
    digitalWrite(pinA,LOW);
  }
  if (t>21 && t<24){
    digitalWrite(pinA,LOW);
    digitalWrite(pinB,LOW);
  }
  if (t>25 && t<27){
    digitalWrite(pinA,LOW);
    digitalWrite(pinB,LOW);
    digitalWrite(pinC,LOW);
  }
  if (t>27){
    digitalWrite(pinDP,LOW);
    delay(500);
    digitalWrite(pinDP,HIGH);
    delay(500);
  }
  if (h<25){
    digitalWrite(pinF,LOW);
  }
  if (h>25 && h<40){
    digitalWrite(pinF,LOW);
    digitalWrite(pinG,LOW);
  }
  if (t>40 && t<61){
    digitalWrite(pinF,LOW);
    digitalWrite(pinG,LOW);
    digitalWrite(pinE,LOW);
  }
  if (t>61){
    digitalWrite(pinD,LOW);
    delay(500);
    digitalWrite(pinD,HIGH);
    delay(500);
  }
  
  
}
