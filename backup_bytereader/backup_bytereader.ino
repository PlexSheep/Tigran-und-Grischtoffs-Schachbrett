/*
 *  Send Bytes using Bluetooth.
 *  Bytes will be filled into a Array of the size MESSAGE_SIZE.
 *  If less than MESSAGE_SIZE bytes are sent, the array will be filled with empty bytes.
 *  If more than MESSAGE_SIZE bytes are sent, full arrays before will be discarded and only the ones that didnt fit will be left
 *  Only one array is saved.
 */

#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(10, 9); // RX, TX

const int MESSAGE_SIZE = 3;

byte Data; // the data received
byte DataArr[MESSAGE_SIZE];

void setup() {
  Bluetooth.begin(9600);
  Serial.begin(9600);
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
    for ( int i = 0; i < MESSAGE_SIZE; i++) {
      Serial.println(DataArr[i], HEX);
    }
    Serial.println("#######");
  }

  delay(100);
}
