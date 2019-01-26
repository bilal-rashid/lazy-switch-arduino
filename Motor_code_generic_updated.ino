#include <SoftwareSerial.h>
#include <EEPROM.h>

// Define the data transmit/receive pins in Arduino

#define TxD 2

#define RxD 3

SoftwareSerial mySerial(RxD, TxD); // RX, TX for Bluetooth
long counter;
long counter_value;
int counterValueAddress = 9; 
int buttonState = 0; 
const int RED = 6;
const int BLUE = 7;
const int GREEN = 8;
const int SIGNAL = 9;
void setup()
{

    mySerial.begin(9600); // For Bluetooth

    Serial.begin(9600); // For the IDE monitor Tools -> Serial Monitor

    pinMode(RED, OUTPUT);
    pinMode(BLUE, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(SIGNAL, OUTPUT);
    pinMode(11, INPUT);
    // Any code that you want to run once....
    counter = 0;
    EEPROM.get(counterValueAddress, counter_value);
}

void turn_on(){
  digitalWrite(SIGNAL, LOW);
  digitalWrite(RED, LOW);
  digitalWrite(BLUE, LOW);
  digitalWrite(GREEN, HIGH);
}

void turn_off(){
  digitalWrite(SIGNAL, HIGH);
  digitalWrite(RED, HIGH);
  digitalWrite(BLUE, LOW);
  digitalWrite(GREEN, LOW);
}

void turnBlue() {
  digitalWrite(RED, LOW);
  digitalWrite(BLUE, HIGH);
  digitalWrite(GREEN, LOW);
}

void turnGreen() {
  digitalWrite(RED, LOW);
  digitalWrite(BLUE, LOW);
  digitalWrite(GREEN, HIGH);
}

void turnGreenBlue() {
  digitalWrite(RED, LOW);
  digitalWrite(BLUE, HIGH);
  digitalWrite(GREEN, HIGH);
}

void turnRED() {
  digitalWrite(RED, HIGH);
  digitalWrite(BLUE, LOW);
  digitalWrite(GREEN, LOW);
}

void loop()
{

    // put your main code here, to run repeatedly:

    turn_off();
    boolean isValidInput;
    do {
        byte c; // get the next character from the bluetooth serial port
        while (!mySerial.available()) {
            if (counter == 1) {
              turn_off();
              mySerial.println("Motor Powered OFF");
              counter = counter - 1;
            }
            else if(counter>1) {
              counter = counter - 1;
              delay(100);
              if(counter < (60L*10L*60L) ) {
                if(counter%2==0){
                  turnBlue();
                }else{
                  turnGreen();
                }
              }else{
                if(counter%10==0){
                  turnBlue();
                }else{
                  turnGreen();
                }
              }
            }
            buttonState = digitalRead(11);
            if (buttonState == HIGH) {
              // turn LED on:
              turn_on();
              counter = counter_value;
            } else {
            }

        }; // LOOP...

        c = mySerial.read(); // Execute the option based on the character recieved

        Serial.print(c); // Print the character received to the IDE serial monitor

        switch (c) {

        case 'a': // You've entered a

            // Do the code you need when 'a' is received.....
            turn_on();
            mySerial.println("Motor Powered ON for 30 mins");
            counter = 30L * 10L * 60L;

            isValidInput = true;

            break;

        case 'b': // You've entered b
            turn_off();
            counter = 0;

            // Do the code you need when 'a' is received.....

            mySerial.println("Motor Powered OFF");

            isValidInput = true;

            break;

        case 'c': // You've entered c

            // Do the code you need when 'a' is received.....
            turn_on();
            mySerial.println("Motor Powered ON for 1 hour");
            counter = 60L * 10L * 60L;

            isValidInput = true;

            break;
        case 'd': // You've entered a

            // Do the code you need when 'a' is received.....
            turn_on();
            mySerial.println("Motor Powered ON for 1 hour, 30 mins");
            counter = 90L * 10L * 60L;

            isValidInput = true;

            break;

        case 'e': // You've entered a

            // Do the code you need when 'a' is received.....
            turn_on();
            mySerial.println("Motor Powered ON for 2 hours");
            counter = 120L * 10L * 60L;

            isValidInput = true;

            break;

        case 'f': // You've entered a

            // Do the code you need when 'a' is received.....
            turn_on();
            mySerial.println("Motor Powered ON for 2 hours, 30 mins");
            counter = 150L * 10L * 60L;

            isValidInput = true;

            break;

        case 'g': // You've entered a

            // Do the code you need when 'a' is received.....
            turn_on();
            mySerial.println("Motor Powered ON for 3 hours");
            counter = 180L * 10L * 60L;

            isValidInput = true;

            break;
        case 'A': // You've entered a

            // Do the code you need when 'A' is received.....
            mySerial.println("Default time set to 30 mins");
            EEPROM.put(counterValueAddress, 30L * 10L * 60L);
            counter_value=30L * 10L * 60L;
            isValidInput = true;

            break;
        case 'B': // You've entered a

            // Do the code you need when 'A' is received.....
            mySerial.println("Default time set to 1 hour");
            EEPROM.put(counterValueAddress, 60L * 10L * 60L);
            counter_value=60L * 10L * 60L;
            isValidInput = true;

            break;
        case 'C': // You've entered a

            // Do the code you need when 'A' is received.....
            mySerial.println("Default time set to 1 hour, 30 mins");
            EEPROM.put(counterValueAddress, 90L * 10L * 60L);
            counter_value=90L * 10L * 60L;
            isValidInput = true;

            break;
        case 'D': // You've entered a

            // Do the code you need when 'A' is received.....
            mySerial.println("Default time set to 2 hours");
            EEPROM.put(counterValueAddress, 120L * 10L * 60L);
            counter_value=120L * 10L * 60L;
            isValidInput = true;

            break;

        default:

            // Do the code you need when any other character is received.....

//            mySerial.println("Please enter 'a' or 'b'");
//
//            isValidInput = false;

            break;
        }

    } while (isValidInput == true);
}
