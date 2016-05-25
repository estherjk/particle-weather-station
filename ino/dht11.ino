#include "Adafruit_DHT.h"
#include "Ubidots.h"

// DHT parameters
#define DHTPIN 5
#define DHTTYPE DHT11

// Ubidots parameters
#define UBIDOTS_TOKEN "YOUR_TOKEN_HERE"
#define UBIDOTS_DATASOURCE_NAME "Particle Weather Station"

int temperature;
int humidity;

DHT dht(DHTPIN, DHTTYPE);
Ubidots ubidots(UBIDOTS_TOKEN);

void setup() {
  ubidots.setDatasourceName(UBIDOTS_DATASOURCE_NAME);
  dht.begin();
}

void loop() {
  temperature = dht.getTempFarenheit();
  humidity = dht.getHumidity();

  Particle.publish("temperature", String(temperature), PRIVATE);
  Particle.publish("humidity", String(humidity), PRIVATE);

  ubidots.add("temperature", temperature);
  ubidots.add("humidity", humidity);
  ubidots.sendAll();

  delay(10000);
}
