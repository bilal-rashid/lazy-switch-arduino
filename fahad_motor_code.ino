#include <SoftwareSerial.h>
#include <EEPROM.h>

// Define the data transmit/receive pins in Arduino

#define TxD 2

#define RxD 3
#include <RH_ASK.h>
#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h> // Not actually used but needed to compile
#endif

RH_ASK driver(2000,  4, 7, 5); // ESP8266 or ESP32: do not use pin 11 or 2
SoftwareSerial mySerial(RxD, TxD); // RX, TX for Bluetooth
long counter;
long counter_value;
int counterValueAddress = 9; 
int buttonState = 0; 
const int RED = 6;
const int BLUE = 7;
const int GREEN = 8;
const int SIGNAL = 9;
bool isOn;
void setup()
{
  #ifdef RH_HAVE_SERIAL
//     Serial.begin(115200);    // Debugging only
#endif
     (driver.init());
//#ifdef RH_HAVE_SERIAL
////         Serial.println("init failed");
//#else
//  ;
//#endif

    mySerial.begin(9600); // For Bluetooth

    Serial.begin(9600); // For the IDE monitor Tools -> Serial Monitor

    pinMode(9, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(11, INPUT);
    // Any code that you want to run once....
    counter = 0;
    isOn = false;
    EEPROM.get(counterValueAddress, counter_value);
}

void loop()
{

    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);
    // put your main code here, to run repeatedly:

    digitalWrite(9, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    boolean isValidInput;
    do {
        byte c; // get the next character from the bluetooth serial port
        
        while (!mySerial.available()) {
          if (driver.recv(buf, &buflen)) // Non-blocking
            { 
              String rcv;
              for(int i=0;i<buflen;i++){
                rcv += (char)buf[i];
              }
              if(rcv == "12ON"){
                digitalWrite(9, LOW);
                digitalWrite(5, LOW);
                digitalWrite(6, HIGH);
                counter = counter_value;
                isOn = true;
                Serial.println("ON");
              }else if (rcv == "12OF"){
                counter = 2;
                isOn = false;
                Serial.println("OFF");
              }
            }
            if (counter == 1) {
                digitalWrite(9, HIGH);
                digitalWrite(5, HIGH);
                digitalWrite(6, HIGH);
                //        digitalWrite(6, LOW);
                mySerial.println("Motor Powered OFF");
                isOn = false;
                counter = counter - 1;
            }
            else if(counter>1) {
              counter = counter - 1;
              delay(100);
              if(counter < (60L*10L*60L) ) {
                digitalWrite(5, HIGH);
                digitalWrite(6, LOW);
              }
            }
            buttonState = digitalRead(11);
            if (buttonState == HIGH) {
              // turn LED on:
              if(!isOn){
                digitalWrite(9, LOW);
                digitalWrite(5, LOW);
                digitalWrite(6, HIGH);
                counter = counter_value;
                isOn = true;
                delay(1000);
              }else{
                counter = 2;
                delay(100);
              }
            } else {
            }

        }; // LOOP...

       
        c = mySerial.read(); // Execute the option based on the character recieved

        Serial.print(c); // Print the character received to the IDE serial monitor

        switch (c) {

        case 'a': // You've entered a

            // Do the code you need when 'a' is received.....
            digitalWrite(9, LOW);
            digitalWrite(5, LOW);
            digitalWrite(6, HIGH);
            mySerial.println("Motor Powered ON for 30 mins");
            counter = 30L * 10L * 60L;

            isValidInput = true;
            isOn = true;

            break;

        case 'b': // You've entered b
            digitalWrite(9, HIGH);
            digitalWrite(5, HIGH);
            digitalWrite(6, HIGH);
            counter = 0;

            // Do the code you need when 'a' is received.....

            mySerial.println("Motor Powered OFF");

            isValidInput = true;
            isOn = false;

            break;

        case 'c': // You've entered c

            // Do the code you need when 'a' is received.....
            digitalWrite(9, LOW);
            digitalWrite(5, LOW);
            digitalWrite(6, HIGH);
            mySerial.println("Motor Powered ON for 1 hour");
            counter = 60L * 10L * 60L;

            isValidInput = true;
            isOn = true;

            break;
        case 'd': // You've entered a

            // Do the code you need when 'a' is received.....
            digitalWrite(9, LOW);
            digitalWrite(5, LOW);
            digitalWrite(6, HIGH);
            mySerial.println("Motor Powered ON for 1 hour, 30 mins");
            counter = 90L * 10L * 60L;

            isValidInput = true;
            isOn = true;

            break;

        case 'e': // You've entered a

            // Do the code you need when 'a' is received.....
            digitalWrite(9, LOW);
            digitalWrite(5, LOW);
            digitalWrite(6, HIGH);
            mySerial.println("Motor Powered ON for 2 hours");
            counter = 120L * 10L * 60L;

            isValidInput = true;
            isOn = true;

            break;

        case 'f': // You've entered a

            // Do the code you need when 'a' is received.....
            digitalWrite(9, LOW);
            digitalWrite(5, LOW);
            digitalWrite(6, HIGH);
            mySerial.println("Motor Powered ON for 2 hours, 30 mins");
            counter = 150L * 10L * 60L;

            isValidInput = true;
            isOn = true;

            break;

        case 'g': // You've entered a

            // Do the code you need when 'a' is received.....
            digitalWrite(9, LOW);
            digitalWrite(5, LOW);
            digitalWrite(6, HIGH);
            mySerial.println("Motor Powered ON for 3 hours");
            counter = 180L * 10L * 60L;

            isValidInput = true;
            isOn = true;

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
