// #include <Arduino.h>
 #include <Wire.h>
#include <SPI.h> // thư viện chuẩn SPI
#include <nRF24L01.h> 
#include <RF24.h>  // Thu viện RF24L01
RF24 radio(8,9); // CE, CSN
const byte address[6] = "00001";// địa chỉ
char xyData[32] = "";
String x, y;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  x = analogRead(A1); // đọc giá trị analoag trục x của joystick
  y = analogRead(A0); // đọc giá trị analoag trục y của joystick
  // gửi giá trị analog của trục x
  x.toCharArray(xyData, 5); 
  radio.write(&xyData, sizeof(xyData)); 
  // gửi giá trị analog của trục y
  y.toCharArray(xyData, 5);
  radio.write(&xyData, sizeof(xyData));
  delay(20);
}