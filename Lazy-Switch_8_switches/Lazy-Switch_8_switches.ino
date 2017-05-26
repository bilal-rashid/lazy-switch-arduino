#include <SoftwareSerial.h>

// Define the data transmit/receive pins in Arduino

#define TxD 2

#define RxD 3

SoftwareSerial mySerial(RxD, TxD); // RX, TX for Bluetooth


void setup() {

mySerial.begin(9600); // For Bluetooth

Serial.begin(9600); // For the IDE monitor Tools -> Serial Monitor

pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);



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

// Do the code you need when 'a' is received.....
  digitalWrite(4, HIGH);

isValidInput = true;

break;

case 'a': // You've entered b
  digitalWrite(4, LOW);


isValidInput = true;

break;

case 'B': // You've entered a

// Do the code you need when 'a' is received.....
  digitalWrite(5, HIGH);

isValidInput = true;

break;

case 'b': // You've entered b
  digitalWrite(5, LOW);


isValidInput = true;

break;

case 'C': // You've entered a

// Do the code you need when 'a' is received.....
  digitalWrite(6, HIGH);

isValidInput = true;

break;

case 'c': // You've entered b
  digitalWrite(6, LOW);


isValidInput = true;

break;

case 'D': // You've entered a

// Do the code you need when 'a' is received.....
  digitalWrite(7, HIGH);

isValidInput = true;

break;

case 'd': // You've entered b
  digitalWrite(7, LOW);


isValidInput = true;

break;

case 'E': // You've entered a

// Do the code you need when 'a' is received.....
  digitalWrite(8, HIGH);

isValidInput = true;

break;

case 'e': // You've entered b
  digitalWrite(8, LOW);


isValidInput = true;

break;

case 'F': // You've entered a

// Do the code you need when 'a' is received.....
  digitalWrite(9, HIGH);

isValidInput = true;

break;

case 'f': // You've entered b
  digitalWrite(9, LOW);


isValidInput = true;

break;

case 'G': // You've entered a

// Do the code you need when 'a' is received.....
  digitalWrite(10, HIGH);

isValidInput = true;

break;

case 'g': // You've entered b
  digitalWrite(10, LOW);


isValidInput = true;

break;

case 'H': // You've entered a

// Do the code you need when 'a' is received.....
  digitalWrite(11, HIGH);

isValidInput = true;

break;

case 'h': // You've entered b
  digitalWrite(11, LOW);


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
