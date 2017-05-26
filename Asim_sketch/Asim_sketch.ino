#include <SoftwareSerial.h>

// Define the data transmit/receive pins in Arduino

#define TxD 2

#define RxD 3

SoftwareSerial mySerial(RxD, TxD); // RX, TX for Bluetooth
int counter;
int mins;

int runTime;
int delayTime;
int runTimeHolder,delayTimeHolder;

void setup() {

mySerial.begin(9600); // For Bluetooth

Serial.begin(9600); // For the IDE monitor Tools -> Serial Monitor

pinMode(9,OUTPUT);
pinMode(6,OUTPUT);
// Any code that you want to run once....
//const int runtime=10000;
counter=0;
mins=4;

runTime=3*60*10;
delayTime=120*60*10;

runTimeHolder=0;
delayTimeHolder=delayTime;



}

void loop() {

// put your main code here, to run repeatedly:

boolean isValidInput; do { byte c; // get the next character from the bluetooth serial port
while ( !mySerial.available() ){
        if(counter==1){
        digitalWrite(9, LOW);
        digitalWrite(6, LOW);
        delayTimeHolder=delayTime;
//        digitalWrite(6, LOW);
        mySerial.println( "Motor Powered OFF" );
      }
      if(counter>0){
        counter=counter-1;
        delay(100);
      }else{
          if(delayTimeHolder==1){
            digitalWrite(9, HIGH);
            digitalWrite(6, HIGH);
            runTimeHolder=runTime;
          }
          if(delayTimeHolder>0){
            delayTimeHolder=delayTimeHolder-1;
            delay(100);
          }
          if(runTimeHolder==1){
            digitalWrite(9, LOW);
            digitalWrite(6, LOW);
            delayTimeHolder=delayTime;
          }
          if(runTimeHolder>0){
            runTimeHolder=runTimeHolder-1;
            delay(100);
          }
      
    }
  
  } ; // LOOP...

c = mySerial.read(); // Execute the option based on the character recieved

Serial.print(c); // Print the character received to the IDE serial monitor

switch ( c ) {

case 'a': // You've entered a

// Do the code you need when 'a' is received.....
  digitalWrite(9, HIGH);
  digitalWrite(6, HIGH);
  mySerial.println( "Motor Powered ON" );
  counter=mins*10*60;




isValidInput = true;

break;

case 'b': // You've entered b
  digitalWrite(9, LOW);
  digitalWrite(6, LOW);
  counter=0;
  delayTimeHolder=delayTime;
  runTimeHolder=0;

// Do the code you need when 'a' is received.....

mySerial.println( "Motor Powered OFF" );

isValidInput = true;

break;

default:

// Do the code you need when any other character is received.....

mySerial.println( "Invalid Input" );

isValidInput = false;

break;

}

} while ( isValidInput == true );

}
