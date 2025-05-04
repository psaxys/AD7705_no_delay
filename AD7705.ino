#include <SPI.h>
#include <AD7705.h>
AD7705 ad(2, 3);// DRDY pin, RESET pin

// SS    7 // CS
// MOSI  6 // DIN
// MISO  5 // DOUT
// SCK   4 // SCLK

long data;
unsigned long previousMillis = 0;
const long interval = 1000; // интервал между измерениями (мс)

void setup() {
  Serial.begin(115200);
  ad.conf();
  delay(500);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // CH1 = 1/CH2 = 2
    // GAIN = 1,2,4,8,16,32,64,128
    // RATE = 20,25,100,200 Hz
    // UNIPOLAR = 0/BIPOLAR = 1 

    ad.setSetup(1,1,25,0);
    data = ad.read_unipolar();
    Serial.print("Сhannel 1 >> ");Serial.println(data);

   /* ad.setSetup(2,1,25,0);
    data = ad.read_unipolar();
    Serial.print("  Сhannel 2 >>  ");Serial.println(data); */
  }
}
