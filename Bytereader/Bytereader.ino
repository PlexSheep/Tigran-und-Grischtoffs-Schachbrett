#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(10, 9); // RX, TX

const int MESSAGE_SIZE = 5;

byte Data; // the data received
byte DataArr[MESSAGE_SIZE];

void setup() {
  Bluetooth.begin(9600);
  Serial.begin(9600);
  Serial.println("Waiting for five bytes...");
  Bluetooth.println("Send 5 bytes");
  for ( int i = 0; i < MESSAGE_SIZE; i++) {
    DataArr[i] = 0;
  }
}

byte readFromBT() {
  if (Bluetooth.available()) { //wait for data received
    return Bluetooth.read();
  }
    return 0;
}

void fillArray() {
  
  for ( int i = 0; i < MESSAGE_SIZE; i++) {
    DataArr[i] = readFromBT();
  }
}

void loop() {

  if (Bluetooth.available()) { //wait for data received
    fillArray();
    for ( int i = 0; i < 5; i++) {
      Serial.println(DataArr[i], HEX);
    }
    Serial.println("#######");
  }

  delay(100);
}
