#include <SoftwareSerial.h>

// Define the data transmit/receive pins in Arduino

#define TxD 2

#define RxD 3

SoftwareSerial mySerial(RxD, TxD); // RX, TX for Bluetooth
int counter;
int mins;

void setup() {

mySerial.begin(9600); // For Bluetooth

Serial.begin(9600); // For the IDE monitor Tools -> Serial Monitor

pinMode(9,OUTPUT);
pinMode(5,OUTPUT);
// Any code that you want to run once....
//const int runtime=10000;
counter=0;
mins=15;



}

void loop() {

// put your main code here, to run repeatedly:


digitalWrite(9, HIGH);
boolean isValidInput; do { byte c; // get the next character from the bluetooth serial port
while ( !mySerial.available() ){
        if(counter==1){
        digitalWrite(9, HIGH);
        digitalWrite(5, LOW);
//        digitalWrite(6, LOW);
        mySerial.println( "Motor Powered OFF" );
      }
      if(counter>0){
        counter=counter-1;
        delay(100);
      }else{
      
      }
  
  } ; // LOOP...

c = mySerial.read(); // Execute the option based on the character recieved

Serial.print(c); // Print the character received to the IDE serial monitor

switch ( c ) {

case 'a': // You've entered a

// Do the code you need when 'a' is received.....
  digitalWrite(9, LOW);
  digitalWrite(5, HIGH);
  mySerial.println( "Motor Powered ON for 15 mins" );
  counter=mins*10*60;




isValidInput = true;

break;

case 'b': // You've entered b
  digitalWrite(9, HIGH);
  digitalWrite(5, LOW);
  counter=0;

// Do the code you need when 'a' is received.....

mySerial.println( "Motor Powered OFF" );

isValidInput = true;

break;

case 'c': // You've entered c

// Do the code you need when 'a' is received.....
  digitalWrite(9, LOW);
  digitalWrite(5, HIGH);
  mySerial.println( "Motor Powered ON for 5 mins" );
  counter=5*10*60;




isValidInput = true;

break;
case 'd': // You've entered a

// Do the code you need when 'a' is received.....
  digitalWrite(9, LOW);
  digitalWrite(5, HIGH);
  mySerial.println( "Motor Powered ON for 10 mins" );
  counter=10*10*60;




isValidInput = true;

break;

case 'e': // You've entered a

// Do the code you need when 'a' is received.....
  digitalWrite(9, LOW);
  digitalWrite(5, HIGH);
  mySerial.println( "Motor Powered ON for 20 mins" );
  counter=20*10*60;




isValidInput = true;

break;

case 'f': // You've entered a

// Do the code you need when 'a' is received.....
  digitalWrite(9, LOW);
  digitalWrite(5, HIGH);
  mySerial.println( "Motor Powered ON for 25 mins" );
  counter=25*10*60;




isValidInput = true;

break;

case 'g': // You've entered a

// Do the code you need when 'a' is received.....
  digitalWrite(9, LOW);
  digitalWrite(5, HIGH);
  mySerial.println( "Motor Powered ON for 30 mins" );
  counter=30*10*60;




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
