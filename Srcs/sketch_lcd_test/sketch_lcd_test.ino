// No external AREF

// RS - D53
// E  - D51
// D4, D5, D6, D7 - D30, D32, D34, D36

// DHT11 - D41

// Voltage input - A0

#include <LiquidCrystal.h>
#include <DHT.h>

const int rs = 53, en = 51, d4 = 30, d5 = 32, d6 = 34, d7 = 36;

const int dhtPin = 41;

const int voltagePin = A0;
const int voltageGain = 4.0, voltageRef = 5.0;

int stage = 0;

#define DHTTYPE DHT11

LiquidCrystal lcd (rs, en, d4, d5, d6, d7);
DHT           dht (dhtPin, DHTTYPE);

void setup() {
  lcd.begin (16, 2);
  dht.begin ();
  Serial1.begin (9600);
  
  Serial1.println ("Hi from here");
  lcd.clear ();
  lcd.setCursor (0, 0);
  lcd.print ("Welcome");
}

void loop() {
  delay (1000); // per 2 sec
  
  float h = dht.readHumidity ();
  float t = dht.readTemperature ();
  lcd.clear ();
  lcd.setCursor (0, 0);
  lcd.print(String ("Temp: ") + String (t) + String (" C"));
  lcd.setCursor (0, 1);
  lcd.print(String ("Humid: ") + String (h) + String (" %"));

  delay (1000);
  
  int   aVal = analogRead (voltagePin);
  float voltage = voltageGain * aVal * (voltageRef / 1023.0);
  lcd.clear ();
  lcd.setCursor (0, 0);
  lcd.print (String ("Volt: ") + String (voltage));
  lcd.setCursor (0, 1);
  lcd.print (String ("DVal: ") + String(aVal));

  Serial1.println (String ("Temp: ") + String (t) + String (" C"));
  Serial1.println (String ("Humid: ") + String (h) + String (" %"));
  Serial1.println (String ("Volt: ") + String (voltage));
}
