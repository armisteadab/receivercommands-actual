// ask_receiver.pde
// -*- mode: C++ -*-
// Simple example of how to use RadioHead to receive messages
// with a simple ASK transmitter in a very simple way.
// Implements a simplex (one-way) receiver with an Rx-B1 module
// Tested on Arduino Mega, Duemilanova, Uno, Due, Teensy, ESP-12

#include <RH_ASK.h>
#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h> // Not actually used but needed to compile
#endif

 const int radioRCV = 3;
//RH_ASK driver(2000, 3, 4, 0); // ATTiny, RX on D3 (pin 2 on attiny85) TX on D4 (pin 3 on attiny85), 
// RH_ASK driver(2000, PD14, PD13, 0); STM32F4 Discovery: see tx and rx on Orange and Red LEDS
 RH_ASK driver(2000, radioRCV, 50, 51); // ESP8266 or ESP32: do not use pin 11 or 2


const int RelayOFF = HIGH;
const int RelayON = LOW;
const int milliwait = 300;
const int Relay1 =  23;
const int Relay2 =  24;
const int Relay3 =  25;
const int Relay4 =  26;
const int Relay5 =  27;
const int Relay6 =  30;
const int Relay7 =  29;
const int Relay8 =  28;
const int Relay9 =  31;

const int Relay10 =  38;
const int Relay11 =  33;
const int Relay12 =  34;
const int Relay13 =  35;
const int Relay14 =  32;
const int Relay15 =  36;
const int Relay16 =  37;

String Cmd_Recieved;
String rcv;

void setup()
{
#ifdef RH_HAVE_SERIAL
    Serial.begin(9600);   // Debugging only
#endif
    if (!driver.init())
#ifdef RH_HAVE_SERIAL
         Serial.println("init failed");
#else
        ;
#endif

pinMode(Relay1, OUTPUT) ; //23;
pinMode(Relay2, OUTPUT) ; //24;
pinMode(Relay3, OUTPUT) ; //25;
pinMode(Relay4, OUTPUT) ; //26;
pinMode(Relay5, OUTPUT) ; //27;
pinMode(Relay6, OUTPUT) ; //28;
pinMode(Relay7, OUTPUT) ; //29;
pinMode(Relay8, OUTPUT) ; //30;
pinMode(Relay9, OUTPUT) ; //31;
pinMode(Relay10, OUTPUT) ; //32;
pinMode(Relay11, OUTPUT) ; //33;
pinMode(Relay12, OUTPUT) ; //34;
pinMode(Relay13, OUTPUT) ; //35;
pinMode(Relay14, OUTPUT) ; //36;
pinMode(Relay15, OUTPUT) ; //37;
pinMode(Relay16, OUTPUT) ; //38;


}

  void ALLRelaysOFF(){


// set all to relay off
digitalWrite(Relay1, RelayOFF) ;           
digitalWrite(Relay2, RelayOFF) ;           
digitalWrite(Relay3, RelayOFF) ;           
digitalWrite(Relay4, RelayOFF) ;           
digitalWrite(Relay5, RelayOFF) ;           
digitalWrite(Relay6, RelayOFF) ;           
digitalWrite(Relay7, RelayOFF) ;           
digitalWrite(Relay8, RelayOFF) ;           
digitalWrite(Relay9, RelayOFF) ;           
digitalWrite(Relay10, RelayOFF) ;           
digitalWrite(Relay11, RelayOFF) ;           
digitalWrite(Relay12, RelayOFF) ;           
digitalWrite(Relay13, RelayOFF) ;           
digitalWrite(Relay14, RelayOFF) ;           
digitalWrite(Relay15, RelayOFF) ;           
digitalWrite(Relay16, RelayOFF) ;           


}
 
void loop()
{
         //command relay as folHIGHs
         // 9-16 are POWER, related one directly across 
         //1-8  are direction, set first
         Cmd_Recieved = "";
         GetRadioMessage();

        if(Cmd_Recieved.equals("~RR1L~")){
           digitalWrite(Relay1, RelayON) ;           
           delay(milliwait);
           digitalWrite(Relay16, RelayON) ;           
           delay(milliwait);
           digitalWrite(Relay16, RelayOFF) ;           
           digitalWrite(Relay1, RelayOFF) ;           
           
           }           
           
        if(Cmd_Recieved.equals("~RR2L~")){
           digitalWrite(Relay2, RelayON) ;           
           delay(milliwait);
           digitalWrite(Relay15, RelayON) ;           
           delay(milliwait);
           digitalWrite(Relay15, RelayOFF) ;           
           digitalWrite(Relay2, RelayOFF) ;           
           
           }           
           
        if(Cmd_Recieved.equals("~RR3L~")){
           digitalWrite(Relay3, RelayON) ;           
           delay(milliwait);
           digitalWrite(Relay14, RelayON) ;           
           delay(milliwait);
           digitalWrite(Relay14, RelayOFF) ;           
           digitalWrite(Relay3, RelayOFF) ;           
           
           }           
           
        if(Cmd_Recieved.equals("~RR4L~")){
           digitalWrite(Relay4, RelayON) ;           
           delay(milliwait);
           digitalWrite(Relay13, RelayON) ;           
           delay(milliwait);
           digitalWrite(Relay13, RelayOFF) ;           
           digitalWrite(Relay4, RelayOFF) ;           
           
           }           
           
        if(Cmd_Recieved.equals("~RR5L~")){
           digitalWrite(Relay5, RelayON) ;           
           delay(milliwait);
           digitalWrite(Relay12, RelayON) ;           
           delay(milliwait);
           digitalWrite(Relay12, RelayOFF) ;           
           digitalWrite(Relay5, RelayOFF) ;           
           
           }           
           
        if(Cmd_Recieved.equals("~RR6L~")){
           digitalWrite(Relay6, RelayON) ;           
           delay(milliwait);
           digitalWrite(Relay11, RelayON) ;           
           delay(milliwait);
           digitalWrite(Relay11, RelayOFF) ;           
           digitalWrite(Relay6, RelayOFF) ;           
           
           }           
           
        if(Cmd_Recieved.equals("~RR7L~")){
           digitalWrite(Relay7, RelayON) ;           
           delay(milliwait);
           digitalWrite(Relay10, RelayON) ;           
           delay(milliwait);
           digitalWrite(Relay10, RelayOFF) ;           
           digitalWrite(Relay7, RelayOFF) ;           
           
           }           
           
        if(Cmd_Recieved.equals("~RR8L~")){
           digitalWrite(Relay8, RelayON) ;           
           delay(milliwait);
           digitalWrite(Relay9, RelayON) ;           
           delay(milliwait);
           digitalWrite(Relay9, RelayOFF) ;           
           digitalWrite(Relay8, RelayOFF) ;                      
           }           
           
        if(Cmd_Recieved.equals("~RR1R~")){
           digitalWrite(Relay1, RelayOFF) ;           
           delay(milliwait);
           digitalWrite(Relay16, RelayON) ;           
           delay(milliwait);
           digitalWrite(Relay16, RelayOFF) ;           
           digitalWrite(Relay1, RelayOFF) ;           
           }           
           
        if(Cmd_Recieved.equals("~RR2R~")){
           digitalWrite(Relay2, RelayOFF) ;           
           delay(milliwait);
           digitalWrite(Relay15, RelayON) ;           
           delay(milliwait);
           digitalWrite(Relay15, RelayOFF) ;           
           digitalWrite(Relay2, RelayOFF) ;           
           }           
           
        if(Cmd_Recieved.equals("~RR3R~")){
           digitalWrite(Relay3, RelayOFF) ;           
           delay(milliwait);
           digitalWrite(Relay14, RelayON) ;           
           delay(milliwait);
           digitalWrite(Relay14, RelayOFF) ;           
           digitalWrite(Relay3, RelayOFF) ;           
           }           
           
        if(Cmd_Recieved.equals("~RR4R~")){
           digitalWrite(Relay4, RelayOFF) ;           
           delay(milliwait);
           digitalWrite(Relay13, RelayON) ;           
           delay(milliwait);
           digitalWrite(Relay13, RelayOFF) ;           
           digitalWrite(Relay4, RelayOFF) ;           
           }           
           
        if(Cmd_Recieved.equals("~RR5R~")){
           digitalWrite(Relay5, RelayOFF) ;           
           delay(milliwait);
           digitalWrite(Relay12, RelayON) ;           
           delay(milliwait);
           digitalWrite(Relay12, RelayOFF) ;           
           digitalWrite(Relay5, RelayOFF) ;           
        }  

        if(Cmd_Recieved.equals("~RR6R~")){
           digitalWrite(Relay6, RelayOFF) ;           
           delay(milliwait);
           digitalWrite(Relay11, RelayON) ;           
           delay(milliwait);
           digitalWrite(Relay11, RelayOFF) ;           
           digitalWrite(Relay6, RelayOFF) ;           
        }  
        
        if(Cmd_Recieved.equals("~RR7R~")){
           digitalWrite(Relay7, RelayOFF) ;           
           delay(milliwait);
           digitalWrite(Relay10, RelayON) ;           
           delay(milliwait);
           digitalWrite(Relay10, RelayOFF) ;           
           digitalWrite(Relay7, RelayOFF) ;           
        }
           
        if(Cmd_Recieved.equals("~RR8R~")){
           digitalWrite(Relay8, RelayOFF) ;           
           delay(milliwait);
           digitalWrite(Relay9, RelayON) ;           
           delay(milliwait);
           digitalWrite(Relay9, RelayOFF) ;           
           digitalWrite(Relay8, RelayOFF) ;           
        }                 


         if(Cmd_Recieved != ""){          
         Serial.print(Cmd_Recieved);
         }
         
         Cmd_Recieved = "";   // clear it
         ALLRelaysOFF();

    }


  void GetRadioMessage() {
       //listen for temp broadcast

    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);
    
          rcv = "";
       if (driver.recv(buf, &buflen)) // Non-blocking
        {


          // Message with a good checksum received, dump it.
          //driver.printBuffer('Got:', buf, buflen);

          for (int i = 0; i < buflen; i++) {
            rcv +=  (char)buf[i];
          }

        }
                   Cmd_Recieved = (rcv);

    }
