#include <SoftwareSerial.h>
#include <EEPROM.h>

// Define the data transmit/receive pins in Arduino

#define TxD 2

#define RxD 3

SoftwareSerial mySerial(RxD, TxD); // RX, TX for Bluetooth
int counter;
int mins;

long runTime;
long delayTime;
long runTimeHolder, delayTimeHolder;
int delayTimeAddress = 9;   //Location we want the data to be put.
int delayTimeHolderAddress = 18;   //Location we want the data to be put.
int runTimeAddress = 0;   //Location we want the data to be put.

String inputString;

void setup() {

  mySerial.begin(9600); // For Bluetooth

  Serial.begin(9600); // For the IDE monitor Tools -> Serial Monitor

  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  // Any code that you want to run once....
  //const int runtime=10000;
  counter = 0;
  mins = 4;

  
  
  EEPROM.get(runTimeAddress, runTime);
  EEPROM.get(delayTimeAddress, delayTime);
  EEPROM.get(delayTimeHolderAddress, delayTimeHolder);
  
  mySerial.println( "Run time set to" );
  mySerial.println( runTime );

  mins = runTime;
  
  mySerial.println( "delay time set to" );
  mySerial.println( delayTime );
  
   mySerial.println( "delay time holder set to" );
   mySerial.println( delayTimeHolder );
  
  runTimeHolder = 0;

  


}
// http://stackoverflow.com/questions/9072320/split-string-into-string-array
String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }

  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
void loop() {
  digitalWrite(9, HIGH);

  // put your main code here, to run repeatedly:

  boolean isValidInput; do {

    while ( !mySerial.available() ) {
      if (counter == 1) {
        digitalWrite(9, HIGH);
        digitalWrite(6, LOW);
        delayTimeHolder = delayTime;        
      EEPROM.put(delayTimeHolderAddress, delayTimeHolder);
        //        digitalWrite(6, LOW);
        mySerial.println( "Motor Powered OFF" );
      }
      if (counter > 0) {
        counter = counter - 1;
        delay(100);
      } else {
        if (delayTimeHolder == 1) {
          digitalWrite(9, LOW);
          digitalWrite(6, HIGH);
          runTimeHolder = runTime;
        }
        if (delayTimeHolder > 0) {
          delayTimeHolder = delayTimeHolder - 1;
          if (delayTimeHolder % 300 == 0)
          {
            EEPROM.put(delayTimeHolderAddress, delayTimeHolder);
            mySerial.println( "Motor will START after" );
            mySerial.println( delayTimeHolder / 600 );
          }
          delay(100);
        }
        if (runTimeHolder == 1) {
          digitalWrite(9, HIGH);
          digitalWrite(6, LOW);
          delayTimeHolder = delayTime;
          EEPROM.put(delayTimeHolderAddress, delayTimeHolder);
        }
        if (runTimeHolder > 0) {
          if(runTimeHolder == runTime){//first time
            EEPROM.put(delayTimeHolderAddress, delayTime);// reset delaytimeholder
            
          }
          runTimeHolder = runTimeHolder - 1;
          if (runTimeHolder % 300 == 0)
          {
            mySerial.println( "Motor will STOP after" );
            mySerial.println( runTimeHolder / 600 );
          }
          delay(100);
        }

      }

    } ; // LOOP...



    //byte c; // get the next character from the bluetooth serial port
    delay(10); // short dely to get buffer full
    inputString = mySerial.readString(); // Execute the option based on the character recieved


    Serial.println(inputString); // Print the character received to the IDE serial monitor
    String keyWord = getValue(inputString, ',' , 0);
    if (keyWord == "on")
    {
      digitalWrite(9, LOW);
      digitalWrite(6, HIGH);
      mySerial.println( "Motor Powered ON" );
      counter = mins * 10 * 60;
      isValidInput = true;
    }
    else if (keyWord == "off")
    {
      digitalWrite(9, HIGH);
      digitalWrite(6, LOW);
      counter = 0;
      delayTimeHolder = delayTime;
      EEPROM.put(delayTimeHolderAddress, delayTimeHolder);
      runTimeHolder = 0;
      mySerial.println( "Motor Powered OFF" );
      isValidInput = true;
    }
    else if (keyWord == "runtime")
    {
      runTimeHolder = 0;
      int runTimeTemp = getValue(inputString, ',' , 1).toInt();
      runTime = runTimeTemp * 600;
      EEPROM.put(runTimeAddress, runTime);
      runTimeHolder = runTime;
      // Do the code you need when 'a' is received.....
      mySerial.println( "Run time set to" );
      mySerial.println( runTime );
      isValidInput = true;
    }
    else if (keyWord == "delaytime")
    {
      runTimeHolder = 0;
      long delayTimeTemp = getValue(inputString, ',' , 1).toInt();
      delayTime = delayTimeTemp * 600;
      EEPROM.put(delayTimeAddress, delayTime);
      delayTimeHolder = delayTime;
      EEPROM.put(delayTimeHolderAddress, delayTimeHolder);
      runTimeHolder = runTime;
      // Do the code you need when 'a' is received.....
      
      mySerial.println( "delaytime recieved is " );
      mySerial.println( delayTimeTemp );
      mySerial.println( "delay time set to" );
      mySerial.println( delayTime );
      isValidInput = true;
    }
    else
    {
      mySerial.println( "Invalid Input" );
      isValidInput = false;
    }
    inputString = "";
  } while ( isValidInput == true );

}
