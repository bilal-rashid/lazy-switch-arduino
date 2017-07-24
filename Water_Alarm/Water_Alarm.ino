#include <SoftwareSerial.h>

// Define the data transmit/receive pins in Arduino

#define TxD 2

#define RxD 3

SoftwareSerial mySerial(RxD, TxD); // RX, TX for Bluetooth


void setup() {

mySerial.begin(9600); // For Bluetooth

Serial.begin(9600); // For the IDE monitor Tools -> Serial Monitor

pinMode(4,OUTPUT);



}

void loop() {

// put your main code here, to run repeatedly:



boolean isValidInput; do { byte c; // get the next character from the bluetooth serial port
while ( !mySerial.available() ){
  
  } ; // LOOP...

c = mySerial.read(); // Execute the option based on the character recieved

Serial.print(c); // Print the character received to the IDE serial monitor

switch ( c ) {

case 'A': // You've entered a

  digitalWrite(4, HIGH);
  delay(4000);
  digitalWrite(4, LOW);
  delay(10000);
  digitalWrite(4, HIGH);
  delay(4000);
  digitalWrite(4, LOW);
  

isValidInput = true;

break;

case 'B': // You've entered a

  digitalWrite(4, HIGH);
  delay(5000);
  digitalWrite(4, LOW);
  delay(10000);
  digitalWrite(4, HIGH);
  delay(4000);
  digitalWrite(4, LOW);
  

  isValidInput = true;

break;

case 'C': // You've entered a

  digitalWrite(4, HIGH);
  delay(6000);
  digitalWrite(4, LOW);
  delay(10000);
  digitalWrite(4, HIGH);
  delay(4000);
  digitalWrite(4, LOW);
  

  isValidInput = true;

break;

case 'D': // You've entered a

  digitalWrite(4, HIGH);
  delay(7000);
  digitalWrite(4, LOW);
  delay(10000);
  digitalWrite(4, HIGH);
  delay(5000);
  digitalWrite(4, LOW);
  

  isValidInput = true;

break;

case 'E': // You've entered a

  digitalWrite(4, HIGH);
  delay(8000);
  digitalWrite(4, LOW);
  delay(10000);
  digitalWrite(4, HIGH);
  delay(5000);
  digitalWrite(4, LOW);
  

  isValidInput = true;

break;


case 'F': // You've entered b
  digitalWrite(4, HIGH);


  isValidInput = true;

break;

case 'f': // You've entered b
  digitalWrite(4, LOW);


  isValidInput = true;

break;


default:

// Do the code you need when any other character is received.....

  mySerial.println( "Please enter 'a' or 'b'" );

  isValidInput = false;

break;

}

} while ( isValidInput == true );

}
