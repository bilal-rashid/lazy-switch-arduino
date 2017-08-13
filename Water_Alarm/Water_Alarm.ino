#include <SoftwareSerial.h>

// Define the data transmit/receive pins in Arduino

#define TxD 2

#define RxD 3

SoftwareSerial mySerial(RxD, TxD); // RX, TX for Bluetooth

int ledPin = 5;
int relayPin = 9; 
void setup() {

mySerial.begin(9600); // For Bluetooth

Serial.begin(9600); // For the IDE monitor Tools -> Serial Monitor

pinMode(ledPin,OUTPUT);
pinMode(relayPin,OUTPUT);



}

void loop() {

// put your main code here, to run repeatedly:
digitalWrite(relayPin, HIGH);


boolean isValidInput; do { byte c; // get the next character from the bluetooth serial port
while ( !mySerial.available() ){
  
  } ; // LOOP...

c = mySerial.read(); // Execute the option based on the character recieved

Serial.print(c); // Print the character received to the IDE serial monitor

switch ( c ) {

case 'A': // You've entered a

  digitalWrite(relayPin, LOW);
  digitalWrite(ledPin, HIGH);
  delay(4000);
  digitalWrite(relayPin, HIGH);
  digitalWrite(ledPin, LOW);
  delay(10000);
  digitalWrite(relayPin, LOW);
  digitalWrite(ledPin, HIGH);
  delay(4000);
  digitalWrite(relayPin, HIGH);
  digitalWrite(ledPin, LOW);
  

isValidInput = true;

break;

case 'B': // You've entered a

  digitalWrite(relayPin, LOW);
  digitalWrite(ledPin, HIGH);
  delay(5000);
  digitalWrite(relayPin, HIGH);
  digitalWrite(ledPin, LOW);
  delay(10000);
  digitalWrite(relayPin, LOW);
  digitalWrite(ledPin, HIGH);
  delay(4000);
  digitalWrite(relayPin, HIGH);
  digitalWrite(ledPin, LOW);
  

  isValidInput = true;

break;

case 'C': // You've entered a

  digitalWrite(relayPin, LOW);
  digitalWrite(ledPin, HIGH);
  delay(6000);
  digitalWrite(relayPin, HIGH);
  digitalWrite(ledPin, LOW);
  delay(10000);
  digitalWrite(relayPin, LOW);
  digitalWrite(ledPin, HIGH);
  delay(4000);
  digitalWrite(relayPin, HIGH);
  digitalWrite(ledPin, LOW);
  

  isValidInput = true;

break;

case 'D': // You've entered a

  digitalWrite(relayPin, LOW);
  digitalWrite(ledPin, HIGH);
  delay(7000);
  digitalWrite(relayPin, HIGH);
  digitalWrite(ledPin, LOW);
  delay(10000);
  digitalWrite(relayPin, LOW);
  digitalWrite(ledPin, HIGH);
  delay(5000);
  digitalWrite(relayPin, HIGH);
  digitalWrite(ledPin, LOW);
  

  isValidInput = true;

break;

case 'E': // You've entered a

  digitalWrite(relayPin, LOW);
  digitalWrite(ledPin, HIGH);
  delay(8000);
  digitalWrite(relayPin, HIGH);
  digitalWrite(ledPin, LOW);
  delay(10000);
  digitalWrite(relayPin, LOW);
  digitalWrite(ledPin, HIGH);
  delay(5000);
  digitalWrite(relayPin, HIGH);
  digitalWrite(ledPin, LOW);
  

  isValidInput = true;

break;


case 'F': // You've entered b
  digitalWrite(relayPin, LOW);
  digitalWrite(ledPin, HIGH);

  isValidInput = true;

break;

case 'f': // You've entered b
  digitalWrite(relayPin, HIGH);
  digitalWrite(ledPin, LOW);


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
