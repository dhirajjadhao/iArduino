//////////////////////////////////////////////////////////////////////////////////////////////////////

/////////    ////////   /////////    ////////     //      //  //////////   ////     //     ///////
   //       //     //   //      //   //      //   //      //      //       // //    //    //     \\
   //       /////////   ////////     //      //   //      //      //       //   //  //   //       \\
   //       //     //   //      //   //      //   //      //      //       //    // //   \\       //
/////////   //     //   //      //   ////////      ///////    //////////   //     ////     ///////

//////////////////////////////////////////////////////////////////////////////////////////////////////

/* Code by Dhiraj Jadhao

for more details on how to setup arduino board to control it wirelessly with iArduino App
and how to get started visit Official Website:

http://i-arduino.blogspot.com

This code is for use with iArduino App.

all rights reserved please contact on following mail id for details:

dhirajjadhao@gmail.com

*/


#include <SPI.h>             // for Arduino later than ver 0018
//#include <EthernetUdp.h>   // UDP library from bjoern@cs.stanford.edu
#include <Ethernet.h>
#include <IRremote.h>


IRsend irsend;

char str[10];

//////////////// Infrared Value Assignment For LG24 remote ///////////////////
///////////////////////////  For TV CONTROL  /////////////////////////////////
// First of all get the Values for your TV remote by using IRrecvDump example given in Infrared Library Examples. //
// For Protocol Other than RC5 and RC6 put same value in both places. //
// Every Two values correspond to the same TV remote button. //
// e.g channel0 and channel00 correspons to one button that is Channel 0 //

unsigned long channel0 = 0x800;  // UDP MSG R0H
unsigned long channel00 = 0x0;   // UDP MSG R0L
unsigned long channel1 = 0x801;  // UDP MSG R1H
unsigned long channel10 = 0x1;   // UDP MSG R1L
unsigned long channel2 = 0x802;  // UDP MSG R2H
unsigned long channel20 = 0x2;   // UDP MSG R2L
unsigned long channel3 = 0x803;  // UDP MSG R3H
unsigned long channel30 = 0x3;   // UDP MSG R3L
unsigned long channel4 = 0x804;  // UDP MSG R4H
unsigned long channel40 = 0x4;   // UDP MSG R4L
unsigned long channel5 = 0x805;  // UDP MSG R5H
unsigned long channel50 = 0x5;   // UDP MSG R5L
unsigned long channel6 = 0x806;  // UDP MSG R6H
unsigned long channel60 = 0x6;   // UDP MSG R6L
unsigned long channel7 = 0x807;  // UDP MSG R7H
unsigned long channel70 = 0x7;   // UDP MSG R7L
unsigned long channel8 = 0x808;  // UDP MSG R8H
unsigned long channel80 = 0x8;   // UDP MSG R8L
unsigned long channel9 = 0x809;  // UDP MSG R9H
unsigned long channel90 = 0x9;   // UDP MSG R9L
unsigned long power = 0x80C;     // UDP MSG RPH
unsigned long power0 = 0xC;      // UDP MSG RPL
unsigned long menu = 0x83B;      // UDP MSG RLH
unsigned long menu0 = 0x3B;      // UDP MSG RLL
unsigned long mute = 0x80D;      // UDP MSG RMH
unsigned long mute0 = 0xD;       // UDP MSG RML
unsigned long chup = 0x820;      // UDP MSG RUH
unsigned long chup0 = 0x20;      // UDP MSG RUL
unsigned long chdown = 0x821;    // UDP MSG RJH
unsigned long chdown0 = 0x21;    // UDP MSG RJL
unsigned long volup = 0x810;     // UDP MSG RXH
unsigned long volup0 = 0x10;     // UDP MSG RXL
unsigned long voldown = 0x811;   // UDP MSG RWH
unsigned long voldown0 = 0x11;   // UDP MSG RWL
unsigned long ok = 0x825;        // UDP MSG ROH
unsigned long ok0 = 0x25;        // UDP MSG ROL
unsigned long prech = 0x832;     // UDP MSG RRH
unsigned long prech0 = 0x32;     // UDP MSG RRL
unsigned long tvav = 0x838;      // UDP MSG RVH
unsigned long tvav0 = 0x38;      // UDP MSG RVL
unsigned long select = 0x838;    // UDP MSG RSH
unsigned long select0 = 0x38;    // UDP MSG RSL

// Number Of Bits For Diffrent Protocols. Uncomment For Respective Protocol //
// Get Type of Protocol for your TV remote by using IRrecvDump example code given in the Infrared Library Example. //

int bits= 12;  //           <----Infrared RC5 protocol Bits
//int bits= 32;  //           <----Infrared NEC protocol Bits
//int bits= 12;  //           <----Infrared Sony protocol Bits
//int bits= 20;  //           <----Infrared RC6 protocol Bits
//int bits= 16; //            <----Infrared JVC protocol Bits

////////////////////////////////////////////////////////////////////////////                        



void setup() \
{


  Serial.begin(9600);    //Start Serial Communications with PC
  


 
}

void loop() 
{

 
    if(Serial.available() > 0)
  {
    int packetSize = Serial.available();
   

      for (byte i=0; i< packetSize; i++)
  {
    str[i] = Serial.read();
  } 
  
 

    //////////////////////// channel 0 /////////////////////////////////////       
        
     if (str[0] == 'R' && str[1]=='0'&& str[2]=='H')  
    {

      irsend.sendRC5(channel0, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 0");    //Write notification  
    
      

    }
     else if (str[0] == 'R' && str[1]=='0' && str[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(channel00, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 0");    //Write notification  
    
      
    
       
      
      
    }
    
       //////////////////////// channel 1 /////////////////////////////////////       
        
     if (str[0] == 'R' && str[1]=='1'&& str[2]=='H')  
    {

      irsend.sendRC5(channel1, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 1");    //Write notification  
    
      
      
      

    }
     else if (str[0] == 'R' && str[1]=='1' && str[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(channel10, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 1");    //Write notification  
    
      
      
       
      
      
    }


//////////////////////// channel 2 ////////////////////////////// 


     if (str[0] == 'R' && str[1]=='2'&& str[2]=='H')  
    {

      irsend.sendRC5(channel2, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 2");    //Write notification  
    
      
     
      

    }
     else if (str[0] == 'R' && str[1]=='2' && str[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(channel20, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 2");    //Write notification  
    
      
     
       
      
      
    }



//////////////////////// channel 3 ////////////////////////////// 
 if (str[0] == 'R' && str[1]=='3'&& str[2]=='H')  
    {

      irsend.sendRC5(channel3, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 3");    //Write notification  
    
      
      
      

    }
     else if (str[0] == 'R' && str[1]=='3' && str[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(channel30, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 3");    //Write notification  
    
      
     
       
      
      
    }





//////////////////////// channel 4 ////////////////////////////// 

 if (str[0] == 'R' && str[1]=='4'&& str[2]=='H')  
    {

      irsend.sendRC5(channel4, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 4");    //Write notification  
    
      
      
      

    }
     else if (str[0] == 'R' && str[1]=='4' && str[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(channel40, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 4");    //Write notification  
    
      
     
       
      
      
    }




//////////////////////// channel 5 ////////////////////////////// 

 if (str[0] == 'R' && str[1]=='5'&& str[2]=='H')  
    {

      irsend.sendRC5(channel5, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 5");    //Write notification  
    
      
     
      

    }
     else if (str[0] == 'R' && str[1]=='5' && str[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(channel50, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 5");    //Write notification  
    
      
     
       
      
      
    }



//////////////////////// channel 6 ////////////////////////////// 

 if (str[0] == 'R' && str[1]=='6'&& str[2]=='H')  
    {

      irsend.sendRC5(channel6, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 6");    //Write notification  
    
      
      
      

    }
     else if (str[0] == 'R' && str[1]=='6' && str[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(channel60, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 6");    //Write notification  
    
      
      
       
      
      
    }


//////////////////////// channel 7 ////////////////////////////// 

 if (str[0] == 'R' && str[1]=='7'&& str[2]=='H')  
    {

      irsend.sendRC5(channel7, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 7");    //Write notification  
    
      
      
      

    }
     else if (str[0] == 'R' && str[1]=='7' && str[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(channel70, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 7");    //Write notification  
    
      
     
       
      
      
    }

//////////////////////// channel 8 ////////////////////////////// 

 if (str[0] == 'R' && str[1]=='8'&& str[2]=='H')  
    {

      irsend.sendRC5(channel8, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 8");    //Write notification  
    
      
     
      

    }
     else if (str[0] == 'R' && str[1]=='8' && str[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(channel80, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 8");    //Write notification  
    
      
     
       
      
      
    }




//////////////////////// channel 9 ////////////////////////////// 

 if (str[0] == 'R' && str[1]=='9'&& str[2]=='H')  
    {

      irsend.sendRC5(channel9, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 9");    //Write notification  
    
      
      

    }
     else if (str[0] == 'R' && str[1]=='9' && str[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(channel90, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 9");    //Write notification  
    
   
       
      
      
    }




//////////////////////// TV power ////////////////////////////// 

 if (str[0] == 'R' && str[1]=='P'&& str[2]=='H')  
    {

      irsend.sendRC5(power, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV On/Off");    //Write notification  
    
      
      

    }
     else if (str[0] == 'R' && str[1]=='P' && str[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(power0, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV On/Off");    //Write notification  
    
      

       
      
      
    }




//////////////////////// tv menu ////////////////////////////// 


if (str[0] == 'R' && str[1]=='L'&& str[2]=='H')  
    {

      irsend.sendRC5(menu, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV menu");    //Write notification  
    
      
     
      

    }
     else if (str[0] == 'R' && str[1]=='L' && str[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(menu0, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV menu");    //Write notification  
    
      
    
       
      
      
    }


////////////////////////  Mute  ////////////////////////////// 

if (str[0] == 'R' && str[1]=='M'&& str[2]=='H')  
    {

      irsend.sendRC5(mute, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV mute");    //Write notification  
    
      
      
      

    }
     else if (str[0] == 'R' && str[1]=='M' && str[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(mute0, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV mute");    //Write notification  
    
      
    
       
      
      
    }



//////////////////////// channel Up ////////////////////////////// 

if (str[0] == 'R' && str[1]=='U'&& str[2]=='H')  
    {

      irsend.sendRC5(chup, bits); // LG TV code
      delay(100);
       
      
      Serial.println("channel up");    //Write notification  
    
      
      
      

    }
     else if (str[0] == 'R' && str[1]=='U' && str[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(chup0, bits); // LG TV code
      delay(100);
       
      
      Serial.println("channel up");    //Write notification  
    
      
    
       
      
      
    }





//////////////////////// channel Down ////////////////////////////// 

if (str[0] == 'R' && str[1]=='J'&& str[2]=='H')  
    {

      irsend.sendRC5(chdown, bits); // LG TV code
      delay(100);
       
      
      Serial.println("channel down");    //Write notification  
    
      
     
      

    }
     else if (str[0] == 'R' && str[1]=='J' && str[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(chdown0, bits); // LG TV code
      delay(100);
       
      
      Serial.println("channel down");    //Write notification  
    
      
   
       
      
      
    }



//////////////////////// vol up ////////////////////////////// 

if (str[0] == 'R' && str[1]=='X'&& str[2]=='H')  
    {

      irsend.sendRC5(volup, bits); // LG TV code
      delay(100);
       
      
      Serial.println("vol up");    //Write notification  
    
      
   
      

    }
     else if (str[0] == 'R' && str[1]=='X' && str[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(volup0, bits); // LG TV code
      delay(100);
       
      
      Serial.println("vol up");    //Write notification  
    
      
       
      
      
    }





//////////////////////// vol down ////////////////////////////// 

if (str[0] == 'R' && str[1]=='W'&& str[2]=='H')  
    {

      irsend.sendRC5(voldown, bits); // LG TV code
      delay(100);
       
      
      Serial.println("vol down");    //Write notification  
    
      
   
      

    }
     else if (str[0] == 'R' && str[1]=='W' && str[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(voldown0, bits); // LG TV code
      delay(100);
       
      
      Serial.println("vol down");    //Write notification  
    
      
  
       
      
      
    }





//////////////////////// ok button ////////////////////////////// 

if (str[0] == 'R' && str[1]=='O'&& str[2]=='H')  
    {

      irsend.sendRC5(ok, bits); // LG TV code
      delay(100);
       
      
      Serial.println("ok");    //Write notification  
    
      
    
      

    }
     else if (str[0] == 'R' && str[1]=='O' && str[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(ok0, bits); // LG TV code
      delay(100);
       
      
      Serial.println("ok");    //Write notification  
    
      
       
      
      
    }




//////////////////////// Previous Channel ////////////////////////////// 

if (str[0] == 'R' && str[1]=='R'&& str[2]=='H')  
    {

      irsend.sendRC5(prech, bits); // LG TV code
      delay(100);
       
      
      Serial.println("previous channel");    //Write notification  
    
      

      

    }
     else if (str[0] == 'R' && str[1]=='R' && str[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(prech0, bits); // LG TV code
      delay(100);
       
      
      Serial.println("previous channel");    //Write notification  
    
      

       
      
      
    }




//////////////////////// TV AV ////////////////////////////// 

if (str[0] == 'R' && str[1]=='V'&& str[2]=='H')  
    {

      irsend.sendRC5(tvav, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV/AV");    //Write notification  
    
 
      

    }
     else if (str[0] == 'R' && str[1]=='V' && str[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(tvav0, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV/AV");    //Write notification  
    
      

       
      
      
    }



//////////////////////// Select ////////////////////////////// 

if (str[0] == 'R' && str[1]=='S'&& str[2]=='H')  
    {

      irsend.sendRC5(select, bits); // LG TV code
      delay(100);
       
      
      Serial.println("Select");    //Write notification  
    
      

    }
     else if (str[0] == 'R' && str[1]=='S' && str[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(select0, bits); // LG TV code
      delay(100);
       
      
      Serial.println("Select");    //Write notification  
    
      

       
      
      
    }


 }
  
  delay(20);
}
