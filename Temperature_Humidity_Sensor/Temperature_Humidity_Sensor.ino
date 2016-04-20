

#include <DHT.h>

#define TEMPBREAKPOINT 37

#define DHTPIN 2 //The digital pin that the thermometer is connected to
#define FANPIN1 3
#define FANPIN2 4
#define LEDPIN 5
#define RELAYPIN 6
#define HUMIDIFIERPIN 7
#define POWERPIN 9
#define POWERPIN2 10


#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);


void setup() {
  
  Serial.begin(9600);
  Serial.println("DHT Test!");

  dht.begin();

  pinMode(RELAYPIN, OUTPUT);
  pinMode(FANPIN1, OUTPUT);
  pinMode(FANPIN2, OUTPUT);
  pinMode(LEDPIN, OUTPUT);
  pinMode(HUMIDIFIERPIN, OUTPUT);
  pinMode(POWERPIN, OUTPUT);
  pinMode(POWERPIN2, OUTPUT);  
}

void loop() {

  delay(1000);

  float t = dht.readTemperature();
  float h = dht.readHumidity();
  //float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t))
  {
    Serial.println("Failed to read from DHT sensor!");
  }


  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print("*C\t");
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println("%");

  //Heater Switch
  if (t <= 37)
  {
    Serial.println("+Heater");
    digitalWrite(RELAYPIN, LOW);
  }
  else
  {
    Serial.println("-Heater");
    digitalWrite(RELAYPIN, HIGH);
  }

  if (h <= 50)
  {
    Serial.println("+Humidifier");
    digitalWrite(HUMIDIFIERPIN, LOW);
  }

  else
  {
    Serial.println("-Humidifier");
    digitalWrite(HUMIDIFIERPIN, HIGH);
  }

  digitalWrite(LEDPIN, HIGH);
  Serial.println("+LED");
  digitalWrite(FANPIN1, HIGH);
  digitalWrite(FANPIN2, HIGH);
  digitalWrite(POWERPIN, HIGH);
  digitalWrite(POWERPIN2, HIGH);
  



  
}
