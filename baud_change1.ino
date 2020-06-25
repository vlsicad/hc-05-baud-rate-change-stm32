/*
  Analog input, serial output

  Reads an analog input pin, prints the results to the serial monitor.

  The circuit:

  * Potentiometer connected to analog pin 15.
  * Center pin of the potentiometer goes to the analog pin.
  * Side pins of the potentiometer go to +3.3V (VCC) and ground

  created over and over again
  by Tom Igoe and everyone who's ever used Arduino

  Ported to Maple 27 May, 2010 by Bryan Newbold
*/

// Analog input pin.  You may need to change this number if your board
// can't do analog input on pin 15.
 const int analogInputPin0 = 0;
 const int analogInputPin1 = 1;
 const int analogInputPin2 = 2;

 byte inCmdByte = 0;    // for incoming serial data (command) from PC
 byte SmplFlag = 0;     // flag for sampling (1 = go, 0 = stop)
 int Sample[3];         // define 3x integer array for sample readings


void setup() {
  // Declare analogInputPin as INPUT_ANALOG:
    pinMode(analogInputPin0, INPUT_ANALOG);
    pinMode(analogInputPin1, INPUT_ANALOG);
    pinMode(analogInputPin1, INPUT_ANALOG);
    pinMode(PC13, OUTPUT);
  	Serial.begin(38400); // Ignored by Maple. But needed by boards using Hardware serial via a USB to Serial Adaptor
       SmplFlag = 1 ;
}

unsigned long cur_time, last_time,i;
char buffer[25];


void loop()
{



 if (SmplFlag == 0 )     // now if sample flag is raised,
  { 
    digitalWrite(PC13, HIGH);  // and turn on LED2.
    delay(100);          // Wait for 10 milliseconds)
    digitalWrite(PC13, LOW);  // and turn on LED2 
    delay(100);          // Wait for 10 milliseconds)
   
  }
  delay(1000);          // Wait for 10 milliseconds)
  delay(1000);          // Wait for 10 milliseconds)
  delay(1000);          // Wait for 10 milliseconds)
  delay(1000);          // Wait for 10 milliseconds)
  

  cur_time = millis();
  if (SmplFlag == 1 )     // now if sample flag is raised,
  {         
    delay(1000);          // Wait for 10 milliseconds)
    sprintf( buffer, "AT+NAME=EEG_BOARD\r\n" );
    Serial.write(buffer);
    delay(1000);          // Wait for 10 milliseconds)  
    delay(1000);          // Wait for 10 milliseconds) 
    sprintf( buffer, "AT+UART=115200,1,0\r\n" );
    Serial.write(buffer);
    delay(1000);          // Wait for 10 milliseconds)
    delay(1000);          // Wait for 10 milliseconds)
    sprintf( buffer, "AT+PSWD=1122\r\n" );
    delay(1000);          // Wait for 10 milliseconds)
    Serial.write(buffer);
    SmplFlag = 0;               // finally clear sample flag
  }      
  
}   // end of loop() code and sketch
     
