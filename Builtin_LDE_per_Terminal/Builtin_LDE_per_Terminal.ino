#include <SoftwareSerial.h>
SoftwareSerial BTserial(10, 9); // RX, TX
 
char c=' '; 
boolean NL = true; 
 
void setup() 
{ 
 Serial.begin(9600); 
 Serial.print("Sketch: "); Serial.println(__FILE__); 
 Serial.print("Uploaded: "); Serial.println(__DATE__); 
 Serial.println(" "); 
 
 BTserial.begin(38400); 
 Serial.println("BTserial started at 38400"); 
 Serial.println(" "); 
} 
 
void loop() 
{ 
 if (BTserial.available()) 
 { 
 c = BTserial.read(); 
  Serial.write(c); 
 } 
 if (Serial.available()) 
 { 
 c = Serial.read(); 
 BTserial.write(c); 
 
 if (NL) { Serial.print(">"); NL = false; } 
 Serial.write(c); 
 if (c==10) { NL = true; } 
 } 
} 
