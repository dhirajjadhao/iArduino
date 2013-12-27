
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


IPAddress iPhoneIP(192, 168, 1, 100);               //Leave it as its is  //Set the iPhone/iPod/iPad's IP address to send messages back to iArduino...
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

/*
int ana0 = A0;
int ana1 = A1;
int ana2 = A2;
int ana3 = A3;
int ana4 = A4;
int ana5 = A5;

///////////////////////////////////////////
*/

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
  Udp.begin(localPort);    //Setup UDP socket on port defined earlier
  Serial.begin(9600);    //Start Serial Communications with PC
  
 
  pinMode(relay2,OUTPUT);    
  pinMode(relay3,OUTPUT);    
  pinMode(relay4,OUTPUT);   
  pinMode(relay5,OUTPUT);    
  pinMode(relay6,OUTPUT);
  pinMode(relay7,OUTPUT);
  pinMode(relay8,OUTPUT);
  pinMode(relay9,OUTPUT);
/*
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT); 
*/ 
  
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

/*
// Intergers for Holding Analog Input Values //

int ana0Val;
int ana1Val;
int ana2Val;
int ana3Val;
int ana4Val;
int ana5Val;


///////////////////////////////////////////////
*/  
  
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
    
   
   // PWM Pin Format Declaration //
   
    relay2pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    relay3pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    relay4pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    relay5pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    relay6pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    relay7pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    relay8pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    relay9pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
 
 
 ///////////////////////////////////////////////////////////////////////////////////////////// 
   
  /*
  
   // Analog Pin Format Declaration //
   
   ana0Val = (packBuff[2] - '0')*100 + (packBuff[3] - '0')*10 + (packBuff[4] - '0');
   ana1Val = (packBuff[2] - '0')*100 + (packBuff[3] - '0')*10 + (packBuff[4] - '0');
   ana2Val = (packBuff[2] - '0')*100 + (packBuff[3] - '0')*10 + (packBuff[4] - '0');
   ana3Val = (packBuff[2] - '0')*100 + (packBuff[3] - '0')*10 + (packBuff[4] - '0');
   ana4Val = (packBuff[2] - '0')*100 + (packBuff[3] - '0')*10 + (packBuff[4] - '0');
   ana5Val = (packBuff[2] - '0')*100 + (packBuff[3] - '0')*10 + (packBuff[4] - '0');
   
/////////////////////////////////////////////////////////////////////////////////////////////

 //////////////////////// Analog Pin 0 /////////////////////////////////////       
       if (packBuff[0] = 'A' && packBuff[1]=='0')  
    {

      
      analogWrite(A0,ana0Val);    
      
      Serial.println("Analog0 Pin Value:");  
      Serial.println(ana0Val);
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Analog0 Pin Value:");
      Udp.write(ana0Val);
      Udp.endPacket();

    }
    
    
 //////////////////////// Analog Pin 1 /////////////////////////////////////       
       if (packBuff[0] = 'A' && packBuff[1]=='1')  
    {
      analogWrite(ana1,ana1Val);    
      Serial.println("Analog1 Pin Value:");
      Serial.println(ana1Val);
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Analog1 Pin Value:");
      Udp.write(ana1Val);
      Udp.endPacket(); 

    }    
    
    
     //////////////////////// Analog Pin 2 /////////////////////////////////////       
       if (packBuff[0] = 'A' && packBuff[1]=='2')  
    {
      analogWrite(ana2,ana2Val);    
      Serial.println("Analog2 Pin Value:");
      Serial.println(ana2Val);
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Analog2 Pin Value:");
      Udp.write(ana2Val);
      Udp.endPacket();

    } 
    
    
     //////////////////////// Analog Pin 3 /////////////////////////////////////       
       if (packBuff[0] = 'A' && packBuff[1]=='3')  
    {

      analogWrite(ana3,ana3Val);    
      Serial.println("Analog3 Pin Value:");
      Serial.println(ana3Val);
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Analog3 Pin Value:");
      Udp.write(ana3Val);
      Udp.endPacket();

    } 
    
    
     //////////////////////// Analog Pin 4 /////////////////////////////////////       
       if (packBuff[0] = 'A' && packBuff[1]=='4')  
    {
      analogWrite(ana4,ana4Val);    
      Serial.println("Analog4 Pin Value:");
      Serial.println(ana4Val);
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Analog4 Pin Value:");
      Udp.write(ana4Val);
      Udp.endPacket(); 

    } 
    
    
     //////////////////////// Analog Pin 5 /////////////////////////////////////       
       if (packBuff[0] = 'A' && packBuff[1]=='5')  
    {
      analogWrite(ana5,ana5Val);    
      Serial.println("Analog5 Pin Value:");
      Serial.println(ana5Val);
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Analog5 Pin Value:");
      Udp.write(ana5Val);
      Udp.endPacket();

    } 
    
 */   



//////////////////////// Pin 2 (relay2) /////////////////////////////////////       

    if (packBuff[0] = 'P' && packBuff[1]=='2' && packBuff[2]=='H' )  // If we get the message "P2H", then set relay2 or Pin 2 HIGH
    {
      
      digitalWrite(relay2,HIGH);    //Turn on relay2
  
      Serial.println("Pin 2 ON");    //Write notification 
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 2 is ON");    // Send Message back to iPhone
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='2' && packBuff[2]=='L')  // If we get the message "P2L", then set relay2 or Pin 2 LOW
    {
      
      digitalWrite(relay2,LOW);    //Turn off relay2
  
      Serial.println("Pin 2 OFF");    //Write notification 
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 2 is OFF");    // Send Message back to iPhone
      Udp.endPacket();
      
    }
    
     //////////////////////// Pin 3 (relay3) /////////////////////////////////////       
      
       if (packBuff[0] = 'P' && packBuff[1]=='3' && packBuff[2]=='M')  
    {

      
      analogWrite(relay3,relay3pwmVal);    
      
      Serial.println(relay3pwmVal);    
    

    }
    
    
    
    if (packBuff[0] = 'P' && packBuff[1]=='3' && packBuff[2]=='H') 
    {
      
      digitalWrite(relay3,HIGH);    
  
      Serial.println("Pin 3 ON");    
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 3 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='3' && packBuff[2]=='L')  
    {
      
      digitalWrite(relay3,LOW);    
  
      Serial.println("Pin 3 OFF");     
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 3 is OFF");    
      Udp.endPacket();
      
    }
    
    
    
     //////////////////////// Pin 4 (relay4) /////////////////////////////////////       

   if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='H')  
    {
      
      digitalWrite(relay4,HIGH);    
  
      Serial.println("Pin 4 ON");     
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 4 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='L')  
    {
      
      digitalWrite(relay4,LOW);    
  
      Serial.println("Pin 4 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 4 is OFF");   
      Udp.endPacket();
      
    }
    
    
     //////////////////////// Pin 5 (relay5) /////////////////////////////////////       
        
       if (packBuff[0] = 'P' && packBuff[1]=='5' && packBuff[2]=='M')  
    {

      
      analogWrite(relay5,relay5pwmVal);    
      
      Serial.println(relay5pwmVal);     
    

    }

    
    
    if (packBuff[0] = 'P' && packBuff[1]=='5' && packBuff[2]=='H')  
    {
      
      digitalWrite(relay5,HIGH);    
  
      Serial.println("Pin 5 ON");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 5 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='5' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      
      digitalWrite(relay5,LOW);    
  
      Serial.println("Pin 5 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 5 is OFF");   
      Udp.endPacket();
      
    }
    
    
    
     //////////////////////// Pin 6 (relay6) /////////////////////////////////////       
        
       if (packBuff[0] = 'P' && packBuff[1]=='6' && packBuff[2]=='M')  
    {

      
      analogWrite(relay6,relay6pwmVal);    
      
      Serial.println(relay6pwmVal);     
    

    }

    
    
    if (packBuff[0] = 'P' && packBuff[1]=='6' && packBuff[2]=='H')  // If we get the message "P6H", then set relay1 (6) HIGH
    {
      
      digitalWrite(relay6,HIGH);   
  
      Serial.println("Pin 6 ON");    
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 6 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='6' && packBuff[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      
      digitalWrite(relay6,LOW);    
  
      Serial.println("Pin 6 OFF");     
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 6 is OFF");    
      Udp.endPacket();
      
    }
    
    
     //////////////////////// Pin 7 (relay7) /////////////////////////////////////       

    if (packBuff[0] = 'P' && packBuff[1]=='7' && packBuff[2]=='H') 
    {
      
      digitalWrite(relay7,HIGH);   
  
      Serial.println("Pin 7 ON");     
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 7 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='7' && packBuff[2]=='L') 
    {
      
      digitalWrite(relay7,LOW);   
  
      Serial.println("Pin 7 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 7 is OFF");    
      Udp.endPacket();
      
    }
    
    
     //////////////////////// Pin 8 (relay8) /////////////////////////////////////       

    if (packBuff[0] = 'P' && packBuff[1]=='8' && packBuff[2]=='H')  
    {
      
      digitalWrite(relay8,HIGH);   
  
      Serial.println("Pin 8 ON");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 8 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='8' && packBuff[2]=='L')  
    {
      
      digitalWrite(relay8,LOW);    
  
      Serial.println("Pin 8 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 8 is OFF");    
      Udp.endPacket();
      
    }
    
     //////////////////////// Pin 9 (relay9) /////////////////////////////////////       
        
      if (packBuff[0] = 'P' && packBuff[1]=='9' && packBuff[2]=='M')  
    {

      
      analogWrite(relay9,relay9pwmVal);    
      
      Serial.println(relay9pwmVal);      
    

    }

   
   
    if (packBuff[0] = 'P' && packBuff[1]=='9' && packBuff[2]=='H')  
    {
      
      digitalWrite(relay9,HIGH);   
  
      Serial.println("Pin 9 ON");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 9 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='9' && packBuff[2]=='L')  
    {
      
      digitalWrite(relay9,LOW);    
  
      Serial.println("Pin 9 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 9 is OFF");    
      Udp.endPacket();
      
    }
    
 }
 
 delay(20);
 
}  




