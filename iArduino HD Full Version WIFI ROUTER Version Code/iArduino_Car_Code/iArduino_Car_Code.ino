
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
//#include <EthernetUdp.h>   
#include <Ethernet.h>


//////////  NETWORK INFO  ////////////////

byte mac[] = { 0x90, 0xA2, 0xDA, 0x0D, 0x59, 0x82 };  //Set your Ethernet Shield's MAC address here - make sure you replace the MAC Address with your shield's values!
byte ip[] = { 192,168,1,102 };                        // Set your shield's desired IP address here - check your network for configuration details
//byte gateway[] = { 192,168,1,1 };                   //if you need to set a gateway (Optional)
//byte subnet[] = { 255,255,255,0 };                  // Change this to your subnet address (Optional)
  
unsigned int localPort = 7777;                        // local port to listen on (set this the same as Port # on iArduino Port Field)


IPAddress iPhoneIP(192, 168, 1, 101);               //Leave it as its is  //Set the iPhone/iPod/iPad's IP address to send messages back to iArduino...
unsigned int iPhonePort = 7777;                     //Leave it as its is  //Set the Port # of the message table you configured in iArduino 


///////////////////////////////////////////

///////// Pin Assignments /////////////////

//Do not change anything unless you understand what this part of the code do.

int relay2 = 2;
int relay3 = 3;
int relay4 = 4;
int relay5 = 5;
int relay6 = 6;
int relay7 = 7;
int relay8 = 8;
int relay9 = 9;

///////////////////////////////////////////


///////////////// UDP Variables  ////////////////// 



// buffers for receiving and sending data
char packBuff[UDP_TX_PACKET_MAX_SIZE]; //buffer to hold incoming packet,

/////////////////////////////////////////////////

EthernetUDP Udp;


void setup() {
  
  // More info on Ethernet on Arduino's website:  http://arduino.cc/en/Reference/EthernetBegin
  // start the Ethernet and UDP:
  Ethernet.begin(mac,ip);   // If you don't need to set your default gateway or subnet manually, use this

  Udp.begin(localPort);    //Setup UDP socket on port defined earlier
  Serial.begin(9600);    //Start Serial Communications with PC
  
          
  pinMode(relay2,OUTPUT);   //Designate pin 2 as Output Pin
  pinMode(relay3,OUTPUT);   //Designate pin 3 as Output Pin
  pinMode(relay4,OUTPUT);   //Designate pin 4 as Output Pin
  pinMode(relay5,OUTPUT);   //Designate pin 5 as Output Pin
  pinMode(relay6,OUTPUT);   //Designate pin 6 as Output Pin
  pinMode(relay7,OUTPUT);   //Designate pin 7 as Output Pin
  pinMode(relay8,OUTPUT);   //Designate pin 8 as Output Pin
  pinMode(relay9,OUTPUT);   //Designate pin 9 as Output Pin
 
  
 }

void loop()
{
 // Integer that will hold our PWM values for later use // 
 
  int relay2pwmVal;    
  int relay3pwmVal;    
  int relay4pwmVal;    
  int relay5pwmVal;    
  int relay6pwmVal;    
  int relay7pwmVal; 
  int relay8pwmVal; 
  int relay9pwmVal; 

///////////////////////////////////////////////////////////  
  
  
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
    
   
    
      //////////////////////// Forward /////////////////////////////////////       
      

     if (packBuff[0] = 'F' && packBuff[1]=='O' && packBuff[2]=='R' && packBuff[3]=='H') 
    {
      // Front Right Motor
      digitalWrite(relay2,HIGH);
      digitalWrite(relay3,LOW);
     
     // Front Left Motor
      digitalWrite(relay4,HIGH);
      digitalWrite(relay5,LOW); 
      
      
     // Rear Right Motor
      digitalWrite(relay6,HIGH);
      digitalWrite(relay7,LOW);
     
     // Rear Left Motor
      digitalWrite(relay8,HIGH);
      digitalWrite(relay9,LOW);
  
      Serial.println("Forward");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Forward");    
      Udp.endPacket();
  
  }
  
   else if (packBuff[0] = 'F' && packBuff[1]=='O' && packBuff[2]=='R' && packBuff[3]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      // Front Right Motor
      digitalWrite(relay2,LOW);
      digitalWrite(relay3,LOW);
     
     // Front Left Motor
      digitalWrite(relay4,LOW);
      digitalWrite(relay5,LOW); 
      
      
     // Rear Right Motor
      digitalWrite(relay6,LOW);
      digitalWrite(relay7,LOW);
     
     // Rear Left Motor
      digitalWrite(relay8,LOW);
      digitalWrite(relay9,LOW);
      
      
    }
  
  
   
   
    //////////////////////// Backward /////////////////////////////////////       
      

     if (packBuff[0] = 'B' && packBuff[1]=='A' && packBuff[2]=='C' && packBuff[3]=='H') 
    {
      // Front Right Motor
      digitalWrite(relay3,HIGH);
      digitalWrite(relay2,LOW);
     
     // Front Left Motor
      digitalWrite(relay5,HIGH);
      digitalWrite(relay4,LOW); 
      
      
     // Rear Right Motor
      digitalWrite(relay7,HIGH);
      digitalWrite(relay6,LOW);
     
     // Rear Left Motor
      digitalWrite(relay9,HIGH);
      digitalWrite(relay8,LOW);
  
      Serial.println("Forward");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Backward");    
      Udp.endPacket();
  
  }
  
   else if (packBuff[0] = 'B' && packBuff[1]=='A' && packBuff[2]=='C' && packBuff[3]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      // Front Right Motor
      digitalWrite(relay2,LOW);
      digitalWrite(relay3,LOW);
     
     // Front Left Motor
      digitalWrite(relay4,LOW);
      digitalWrite(relay5,LOW); 
      
      
     // Rear Right Motor
      digitalWrite(relay6,LOW);
      digitalWrite(relay7,LOW);
     
     // Rear Left Motor
      digitalWrite(relay8,LOW);
      digitalWrite(relay9,LOW);
      
      
    }
 
 
     //////////////////////// Right /////////////////////////////////////       
      

     if (packBuff[0] = 'R' && packBuff[1]=='I' && packBuff[2]=='G' && packBuff[3]=='H') 
    {
      // Front Right Motor
      digitalWrite(relay3,HIGH);
      digitalWrite(relay2,LOW);
     
     // Front Left Motor
      digitalWrite(relay4,HIGH);
      digitalWrite(relay5,LOW); 
      
      
     // Rear Right Motor
      digitalWrite(relay7,HIGH);
      digitalWrite(relay6,LOW);
     
     // Rear Left Motor
      digitalWrite(relay8,HIGH);
      digitalWrite(relay9,LOW);
  
      Serial.println("Forward");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Right");    
      Udp.endPacket();
  
  }
  
   else if (packBuff[0] = 'R' && packBuff[1]=='I' && packBuff[2]=='G' && packBuff[3]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      // Front Right Motor
      digitalWrite(relay2,LOW);
      digitalWrite(relay3,LOW);
     
     // Front Left Motor
      digitalWrite(relay4,LOW);
      digitalWrite(relay5,LOW); 
      
      
     // Rear Right Motor
      digitalWrite(relay6,LOW);
      digitalWrite(relay7,LOW);
     
     // Rear Left Motor
      digitalWrite(relay8,LOW);
      digitalWrite(relay9,LOW);
      
      
    }
    
    
         //////////////////////// Left /////////////////////////////////////       
      

     if (packBuff[0] = 'L' && packBuff[1]=='E' && packBuff[2]=='F' && packBuff[3]=='H') 
    {
      // Front Right Motor
      digitalWrite(relay2,HIGH);
      digitalWrite(relay3,LOW);
     
     // Front Left Motor
      digitalWrite(relay5,HIGH);
      digitalWrite(relay4,LOW); 
      
      
     // Rear Right Motor
      digitalWrite(relay6,HIGH);
      digitalWrite(relay7,LOW);
     
     // Rear Left Motor
      digitalWrite(relay9,HIGH);
      digitalWrite(relay8,LOW);
  
      Serial.println("Forward");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Left");    
      Udp.endPacket();
  
  }
  
   else if (packBuff[0] = 'L' && packBuff[1]=='E' && packBuff[2]=='F' && packBuff[3]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      // Front Right Motor
      digitalWrite(relay2,LOW);
      digitalWrite(relay3,LOW);
     
     // Front Left Motor
      digitalWrite(relay4,LOW);
      digitalWrite(relay5,LOW); 
      
      
     // Rear Right Motor
      digitalWrite(relay6,LOW);
      digitalWrite(relay7,LOW);
     
     // Rear Left Motor
      digitalWrite(relay8,LOW);
      digitalWrite(relay9,LOW);
      
      
    }
     
    
  
    
    
 }
 
 delay(20);
 
}  




