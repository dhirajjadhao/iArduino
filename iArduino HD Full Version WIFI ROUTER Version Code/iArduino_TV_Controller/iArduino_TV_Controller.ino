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


//////////  NETWORK INFO  ////////////////

byte mac[] = { 0x90, 0xA2, 0xDA, 0x0D, 0x78, 0xE0 };  //Set your Ethernet Shield's MAC address here - make sure you replace the ZZs with your shield's values!
byte ip[] = { 192,168,1,102 };                        // Set your shield's desired IP address here - check your network for configuration details
//byte gateway[] = { 192,168,1,1 };                   //if you need to set a gateway IP
//byte subnet[] = { 255,255,255,0 };                  // Change this to your subnet address
  
unsigned int localPort = 7777;                        // local port to listen on (set this the same as Port # on Ardumote Params Screen)


IPAddress iPhoneIP(192, 168, 1, 101);                 //Set the iPhone/iPod/iPad's IP address to send messages back to Ardumote...
unsigned int iPhonePort = 7777;                       //Set the Port # of the message table you configured in Ardumote (default is 7777)...


///////////////////////////////////////////


///////////////// UDP Variables  ////////////////// 

// the next two variables are set when a packet is received
//byte remoteIp[4];          // holds received packet's originating IP
//unsigned int  remotePort;   // holds received packet's originating port

// buffers for receiving and sending data
char packBuff[UDP_TX_PACKET_MAX_SIZE]; //buffer to hold incoming packet,

/////////////////////////////////////////////////

EthernetUDP Udp;


void setup() {
  
  // More info on Ethernet on Arduino's website:  http://arduino.cc/en/Reference/EthernetBegin
  // start the Ethernet and UDP:
  Ethernet.begin(mac,ip);   // If you don't need to set your default gateway or subnet manually, use this
//  Ethernet.begin(mac,ip,gateway,subnet);  // Use this line instead if you've manually set all the parameters
  
  
  Udp.begin(localPort);    //Setup UDP socket on port defined earlier

  Serial.begin(9600);    //Start Serial Communications with PC
  


 
}

void loop() 
{
  
   // if there's data available, read a packet
  int packetSize = Udp.parsePacket(); // note that this includes the UDP header
  if(packetSize)
  {
    packetSize = packetSize - 8;      // subtract the 8 byte header
    Serial.print("Packet size: ");
    Serial.println(packetSize);

    // read the packet into packetBuffer and get the senders IP addr and port number
    Udp.read(packBuff,UDP_TX_PACKET_MAX_SIZE);
    Serial.println("Message: ");
    Serial.println(packBuff);
    
    
    //////////////////////// channel 0 /////////////////////////////////////       
        
     if (packBuff[0] = 'R' && packBuff[1]=='0'&& packBuff[2]=='H')  
    {

      irsend.sendRC5(channel0, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 0");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("channel 0");    // Send Message back to iPhone
      Udp.endPacket();

    }
     else if (packBuff[0] = 'R' && packBuff[1]=='0' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(channel00, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 0");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("channel 0");    // Send Message back to iPhone
      Udp.endPacket(); 
      
      
    }
    
       //////////////////////// channel 1 /////////////////////////////////////       
        
     if (packBuff[0] = 'R' && packBuff[1]=='1'&& packBuff[2]=='H')  
    {

      irsend.sendRC5(channel1, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 1");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("channel 1");    // Send Message back to iPhone
      Udp.endPacket();

    }
     else if (packBuff[0] = 'R' && packBuff[1]=='1' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(channel10, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 1");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("channel 1");    // Send Message back to iPhone
      Udp.endPacket(); 
      
      
    }


//////////////////////// channel 2 ////////////////////////////// 


     if (packBuff[0] = 'R' && packBuff[1]=='2'&& packBuff[2]=='H')  
    {

      irsend.sendRC5(channel2, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 2");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("channel 2");    // Send Message back to iPhone
      Udp.endPacket();

    }
     else if (packBuff[0] = 'R' && packBuff[1]=='2' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(channel20, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 2");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("channel 2");    // Send Message back to iPhone
      Udp.endPacket(); 
      
      
    }



//////////////////////// channel 3 ////////////////////////////// 
 if (packBuff[0] = 'R' && packBuff[1]=='3'&& packBuff[2]=='H')  
    {

      irsend.sendRC5(channel3, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 3");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("channel 3");    // Send Message back to iPhone
      Udp.endPacket();

    }
     else if (packBuff[0] = 'R' && packBuff[1]=='3' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(channel30, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 3");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("channel 3");    // Send Message back to iPhone
      Udp.endPacket(); 
      
      
    }





//////////////////////// channel 4 ////////////////////////////// 

 if (packBuff[0] = 'R' && packBuff[1]=='4'&& packBuff[2]=='H')  
    {

      irsend.sendRC5(channel4, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 4");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("channel 4");    // Send Message back to iPhone
      Udp.endPacket();

    }
     else if (packBuff[0] = 'R' && packBuff[1]=='4' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(channel40, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 4");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("channel 4");    // Send Message back to iPhone
      Udp.endPacket(); 
      
      
    }




//////////////////////// channel 5 ////////////////////////////// 

 if (packBuff[0] = 'R' && packBuff[1]=='5'&& packBuff[2]=='H')  
    {

      irsend.sendRC5(channel5, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 5");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("channel 5");    // Send Message back to iPhone
      Udp.endPacket();

    }
     else if (packBuff[0] = 'R' && packBuff[1]=='5' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(channel50, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 5");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("channel 5");    // Send Message back to iPhone
      Udp.endPacket(); 
      
      
    }



//////////////////////// channel 6 ////////////////////////////// 

 if (packBuff[0] = 'R' && packBuff[1]=='6'&& packBuff[2]=='H')  
    {

      irsend.sendRC5(channel6, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 6");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("channel 6");    // Send Message back to iPhone
      Udp.endPacket();

    }
     else if (packBuff[0] = 'R' && packBuff[1]=='6' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(channel60, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 6");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("channel 6");    // Send Message back to iPhone
      Udp.endPacket(); 
      
      
    }


//////////////////////// channel 7 ////////////////////////////// 

 if (packBuff[0] = 'R' && packBuff[1]=='7'&& packBuff[2]=='H')  
    {

      irsend.sendRC5(channel7, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 7");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("channel 7");    // Send Message back to iPhone
      Udp.endPacket();

    }
     else if (packBuff[0] = 'R' && packBuff[1]=='7' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(channel70, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 7");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("channel 7");    // Send Message back to iPhone
      Udp.endPacket(); 
      
      
    }

//////////////////////// channel 8 ////////////////////////////// 

 if (packBuff[0] = 'R' && packBuff[1]=='8'&& packBuff[2]=='H')  
    {

      irsend.sendRC5(channel8, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 8");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("channel 8");    // Send Message back to iPhone
      Udp.endPacket();

    }
     else if (packBuff[0] = 'R' && packBuff[1]=='8' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(channel80, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 8");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("channel 8");    // Send Message back to iPhone
      Udp.endPacket(); 
      
      
    }




//////////////////////// channel 9 ////////////////////////////// 

 if (packBuff[0] = 'R' && packBuff[1]=='9'&& packBuff[2]=='H')  
    {

      irsend.sendRC5(channel9, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 9");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("channel 9");    // Send Message back to iPhone
      Udp.endPacket();

    }
     else if (packBuff[0] = 'R' && packBuff[1]=='9' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(channel90, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV channel 9");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("channel 9");    // Send Message back to iPhone
      Udp.endPacket(); 
      
      
    }




//////////////////////// TV power ////////////////////////////// 

 if (packBuff[0] = 'R' && packBuff[1]=='P'&& packBuff[2]=='H')  
    {

      irsend.sendRC5(power, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV On/Off");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("TV On/Off");    // Send Message back to iPhone
      Udp.endPacket();

    }
     else if (packBuff[0] = 'R' && packBuff[1]=='P' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(power0, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV On/Off");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("TV On/Off");    // Send Message back to iPhone
      Udp.endPacket(); 
      
      
    }




//////////////////////// tv menu ////////////////////////////// 


if (packBuff[0] = 'R' && packBuff[1]=='L'&& packBuff[2]=='H')  
    {

      irsend.sendRC5(menu, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV menu");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("TV menu");    // Send Message back to iPhone
      Udp.endPacket();

    }
     else if (packBuff[0] = 'R' && packBuff[1]=='L' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(menu0, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV menu");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("TV menu");    // Send Message back to iPhone
      Udp.endPacket(); 
      
      
    }


////////////////////////  Mute  ////////////////////////////// 

if (packBuff[0] = 'R' && packBuff[1]=='M'&& packBuff[2]=='H')  
    {

      irsend.sendRC5(mute, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV mute");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("TV mute");    // Send Message back to iPhone
      Udp.endPacket();

    }
     else if (packBuff[0] = 'R' && packBuff[1]=='M' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(mute0, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV mute");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("TV mute");    // Send Message back to iPhone
      Udp.endPacket(); 
      
      
    }



//////////////////////// channel Up ////////////////////////////// 

if (packBuff[0] = 'R' && packBuff[1]=='U'&& packBuff[2]=='H')  
    {

      irsend.sendRC5(chup, bits); // LG TV code
      delay(100);
       
      
      Serial.println("channel up");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("channel up");    // Send Message back to iPhone
      Udp.endPacket();

    }
     else if (packBuff[0] = 'R' && packBuff[1]=='U' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(chup0, bits); // LG TV code
      delay(100);
       
      
      Serial.println("channel up");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("channel up");    // Send Message back to iPhone
      Udp.endPacket(); 
      
      
    }





//////////////////////// channel Down ////////////////////////////// 

if (packBuff[0] = 'R' && packBuff[1]=='J'&& packBuff[2]=='H')  
    {

      irsend.sendRC5(chdown, bits); // LG TV code
      delay(100);
       
      
      Serial.println("channel down");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("channel down");    // Send Message back to iPhone
      Udp.endPacket();

    }
     else if (packBuff[0] = 'R' && packBuff[1]=='J' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(chdown0, bits); // LG TV code
      delay(100);
       
      
      Serial.println("channel down");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("channel down");    // Send Message back to iPhone
      Udp.endPacket(); 
      
      
    }



//////////////////////// vol up ////////////////////////////// 

if (packBuff[0] = 'R' && packBuff[1]=='X'&& packBuff[2]=='H')  
    {

      irsend.sendRC5(volup, bits); // LG TV code
      delay(100);
       
      
      Serial.println("vol up");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("vol up");    // Send Message back to iPhone
      Udp.endPacket();

    }
     else if (packBuff[0] = 'R' && packBuff[1]=='X' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(volup0, bits); // LG TV code
      delay(100);
       
      
      Serial.println("vol up");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("vol up");    // Send Message back to iPhone
      Udp.endPacket(); 
      
      
    }





//////////////////////// vol down ////////////////////////////// 

if (packBuff[0] = 'R' && packBuff[1]=='W'&& packBuff[2]=='H')  
    {

      irsend.sendRC5(voldown, bits); // LG TV code
      delay(100);
       
      
      Serial.println("vol down");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("vol down");    // Send Message back to iPhone
      Udp.endPacket();

    }
     else if (packBuff[0] = 'R' && packBuff[1]=='W' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(voldown0, bits); // LG TV code
      delay(100);
       
      
      Serial.println("vol down");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("vol down");    // Send Message back to iPhone
      Udp.endPacket(); 
      
      
    }





//////////////////////// ok button ////////////////////////////// 

if (packBuff[0] = 'R' && packBuff[1]=='O'&& packBuff[2]=='H')  
    {

      irsend.sendRC5(ok, bits); // LG TV code
      delay(100);
       
      
      Serial.println("ok");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("ok");    // Send Message back to iPhone
      Udp.endPacket();

    }
     else if (packBuff[0] = 'R' && packBuff[1]=='O' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(ok0, bits); // LG TV code
      delay(100);
       
      
      Serial.println("ok");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("ok");    // Send Message back to iPhone
      Udp.endPacket(); 
      
      
    }




//////////////////////// Previous Channel ////////////////////////////// 

if (packBuff[0] = 'R' && packBuff[1]=='R'&& packBuff[2]=='H')  
    {

      irsend.sendRC5(prech, bits); // LG TV code
      delay(100);
       
      
      Serial.println("previous channel");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("previous channel");    // Send Message back to iPhone
      Udp.endPacket();

    }
     else if (packBuff[0] = 'R' && packBuff[1]=='R' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(prech0, bits); // LG TV code
      delay(100);
       
      
      Serial.println("previous channel");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("previous channel");    // Send Message back to iPhone
      Udp.endPacket(); 
      
      
    }




//////////////////////// TV AV ////////////////////////////// 

if (packBuff[0] = 'R' && packBuff[1]=='V'&& packBuff[2]=='H')  
    {

      irsend.sendRC5(tvav, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV/AV");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("TV/AV");    // Send Message back to iPhone
      Udp.endPacket();

    }
     else if (packBuff[0] = 'R' && packBuff[1]=='V' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(tvav0, bits); // LG TV code
      delay(100);
       
      
      Serial.println("TV/AV");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("TV/AV");    // Send Message back to iPhone
      Udp.endPacket(); 
      
      
    }



//////////////////////// Select ////////////////////////////// 

if (packBuff[0] = 'R' && packBuff[1]=='S'&& packBuff[2]=='H')  
    {

      irsend.sendRC5(select, bits); // LG TV code
      delay(100);
       
      
      Serial.println("Select");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Select");    // Send Message back to iPhone
      Udp.endPacket();

    }
     else if (packBuff[0] = 'R' && packBuff[1]=='S' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      irsend.sendRC5(select0, bits); // LG TV code
      delay(100);
       
      
      Serial.println("Select");    //Write notification  
    
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Select");    // Send Message back to iPhone
      Udp.endPacket(); 
      
      
    }


 }
  
  delay(20);
}
