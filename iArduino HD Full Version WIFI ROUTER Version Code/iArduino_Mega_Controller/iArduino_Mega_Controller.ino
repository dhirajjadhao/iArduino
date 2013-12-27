
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

This code is for use with iArduino HD Full Version App.

all rights reserved please contact on following mail id for details:

dhirajjadhao@gmail.com

*/


#include <SPI.h>             // for Arduino later than ver 0018
//#include <EthernetUdp.h>   
#include <Ethernet.h>



//////////  NETWORK INFO  ////////////////

byte mac[] = { 0x90, 0xA2, 0xDA, 0x0D, 0x78, 0xE0 };  //Set your Ethernet Shield's MAC address here - make sure you replace the MAC Address with your shield's values!
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
int relay22 = 22;
int relay24 = 24;
int relay26 = 26;
int relay28 = 28;
int relay30 = 30;
int relay31 = 31;
int relay32 = 32;
int relay33 = 33;
int relay34 = 34;
int relay35 = 35;
int relay36 = 36;
int relay37 = 37;
int relay38 = 38;
int relay39 = 39;
int relay40 = 40;
int relay41 = 41;
int relay42 = 42;
int relay43 = 43;
int relay44 = 44;
int relay45 = 45;
int relay46 = 46;
int relay47 = 47;
int relay48 = 48;
int relay49 = 49;
int relay50 = 50;
int relay51 = 51;
int relay52 = 52;
int relay53 = 53;

/*
int ana0= A0;
int ana1= A1;
int ana2= A2;
int ana3= A3;
int ana4= A4;
int ana5= A5;
int ana6= A6;
int ana7= A7;
int ana8= A8;
int ana9= A9;
int ana10= A10;
int ana11= A11;
int ana12= A12;
int ana13= A13;
int ana14= A14;
int ana15= A15;


///////////////////////////////////////////

*/

///////////////// UDP Variables  ////////////////// 



// buffers for receiving and sending data
char packBuff[UDP_TX_PACKET_MAX_SIZE]; //buffer to hold incoming packet,

/////////////////////////////////////////////////

EthernetUDP Udp;


void setup() 
{
  
 
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
  pinMode(relay22,OUTPUT);
  pinMode(relay24,OUTPUT);
  pinMode(relay26,OUTPUT);
  pinMode(relay28,OUTPUT);
  pinMode(relay30,OUTPUT);
  pinMode(relay31,OUTPUT);
  pinMode(relay32,OUTPUT);
  pinMode(relay33,OUTPUT);
  pinMode(relay34,OUTPUT);
  pinMode(relay35,OUTPUT);
  pinMode(relay36,OUTPUT);
  pinMode(relay37,OUTPUT);
  pinMode(relay38,OUTPUT);
  pinMode(relay39,OUTPUT);
  pinMode(relay40,OUTPUT);
  pinMode(relay41,OUTPUT);
  pinMode(relay42,OUTPUT);
  pinMode(relay43,OUTPUT);
  pinMode(relay44,OUTPUT);
  pinMode(relay45,OUTPUT);
  pinMode(relay46,OUTPUT);
  pinMode(relay47,OUTPUT);
  pinMode(relay48,OUTPUT);
  pinMode(relay49,OUTPUT);

  
 /*
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  pinMode(A6,INPUT);
  pinMode(A7,INPUT);
  pinMode(A8,INPUT);
  pinMode(A9,INPUT);
  pinMode(A10,INPUT);
  pinMode(A11,INPUT);
  pinMode(A12,INPUT);
  pinMode(A13,INPUT);
  pinMode(A14,INPUT);
  pinMode(A15,INPUT);
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
  int relay44pwmVal;
  int relay45pwmVal;
  int relay46pwmVal;
 
/*

 // Intergers that will hold analog input Vales //

int ana0Val;
int ana1Val;
int ana2Val;
int ana3Val;
int ana4Val;
int ana5Val;
int ana6Val;
int ana7Val;
int ana8Val;
int ana9Val;
int ana10Val;
int ana11Val;
int ana12Val;
int ana13Val;
int ana14Val;
int ana15Val;

///////////////////////////////////////////////////////////  

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
   
    ///////////////////////// PWM Value Formatting //////////////////////////////////
    relay2pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    relay3pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    relay4pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    relay5pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    relay6pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    relay7pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    relay8pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    relay9pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    relay44pwmVal = (packBuff[4] - '0')*100 + (packBuff[5] - '0')*10 + (packBuff[6] - '0'); 
    relay45pwmVal = (packBuff[4] - '0')*100 + (packBuff[5] - '0')*10 + (packBuff[6] - '0'); 
    relay46pwmVal = (packBuff[4] - '0')*100 + (packBuff[5] - '0')*10 + (packBuff[6] - '0'); 
    
    

/*

   
   //////////////////////// Analog Inputs Formatting /////////////////////////////////////
   ana0Val = (packBuff[2] - '0')*100 + (packBuff[3] - '0')*10 + (packBuff[4] - '0');
   ana1Val = (packBuff[2] - '0')*100 + (packBuff[3] - '0')*10 + (packBuff[4] - '0');
   ana2Val = (packBuff[2] - '0')*100 + (packBuff[3] - '0')*10 + (packBuff[4] - '0');
   ana3Val = (packBuff[2] - '0')*100 + (packBuff[3] - '0')*10 + (packBuff[4] - '0');
   ana4Val = (packBuff[2] - '0')*100 + (packBuff[3] - '0')*10 + (packBuff[4] - '0');
   ana5Val = (packBuff[2] - '0')*100 + (packBuff[3] - '0')*10 + (packBuff[4] - '0');
   ana6Val = (packBuff[2] - '0')*100 + (packBuff[3] - '0')*10 + (packBuff[4] - '0');
   ana7Val = (packBuff[2] - '0')*100 + (packBuff[3] - '0')*10 + (packBuff[4] - '0');
   ana8Val = (packBuff[2] - '0')*100 + (packBuff[3] - '0')*10 + (packBuff[4] - '0');
   ana9Val = (packBuff[2] - '0')*100 + (packBuff[3] - '0')*10 + (packBuff[4] - '0');
   ana10Val = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0');
   ana11Val = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0');
   ana12Val = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0');
   ana13Val = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0');
   ana14Val = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0');
   ana15Val = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0');
   
   
    //////////////////////// Analog 0 (ana0) ///////////////////////////////////// 
   
   if (packBuff[0] = 'A' && packBuff[1]=='0')  
    {

      analogWrite(ana0,ana0Val);    
      Serial.println("Analog0 Pin Value:");
      Serial.println(ana0Val);
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Analog0 Pin Value:");
      Udp.write(ana0Val);
      Udp.endPacket();   
    }
    
     //////////////////////// Analog 1 (ana1) ///////////////////////////////////// 
   
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
    
     //////////////////////// Analog 2 (ana2) ///////////////////////////////////// 
   
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
    
     //////////////////////// Analog 3 (ana3) ///////////////////////////////////// 
   
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
    
     //////////////////////// Analog 4 (ana4) ///////////////////////////////////// 
   
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
    
     //////////////////////// Analog 5 (ana5) ///////////////////////////////////// 
   
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
    
     //////////////////////// Analog 6 (ana6) ///////////////////////////////////// 
   
   if (packBuff[0] = 'A' && packBuff[1]=='6')  
    {
      analogWrite(ana6,ana6Val);    
      Serial.println("Analog6 Pin Value:");
      Serial.println(ana6Val);
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Analog6 Pin Value:");
      Udp.write(ana6Val);
      Udp.endPacket();   
    }
    
     //////////////////////// Analog 7 (ana7) ///////////////////////////////////// 
   
   if (packBuff[0] = 'A' && packBuff[1]=='7')  
    {
      analogWrite(ana7,ana7Val);    
      Serial.println("Analog7 Pin Value:");
      Serial.println(ana7Val);
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Analog7 Pin Value:");
      Udp.write(ana7Val);
      Udp.endPacket();   
    }
    
     //////////////////////// Analog 8 (ana8) ///////////////////////////////////// 
   
   if (packBuff[0] = 'A' && packBuff[1]=='8')  
    {
      analogWrite(ana8,ana8Val);    
      Serial.println("Analog8 Pin Value:");
      Serial.println(ana8Val);
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Analog8 Pin Value:");
      Udp.write(ana8Val);
      Udp.endPacket();  
    }
    
     //////////////////////// Analog 9 (ana9) ///////////////////////////////////// 
   
   if (packBuff[0] = 'A' && packBuff[1]=='9')  
    {
      analogWrite(ana9,ana9Val);    
      Serial.println("Analog9 Pin Value:");
      Serial.println(ana9Val);
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Analog9 Pin Value:");
      Udp.write(ana9Val);
      Udp.endPacket();  
    }
   
    //////////////////////// Analog 10 (ana10) ///////////////////////////////////// 
   
   if (packBuff[0] = 'A' && packBuff[1]=='1' && packBuff[2]=='0')  
    {
      analogWrite(ana10,ana10Val);    
      Serial.println("Analog10 Pin Value:");
      Serial.println(ana10Val);
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Analog10 Pin Value:");
      Udp.write(ana10Val);
      Udp.endPacket();  
    }
    
        //////////////////////// Analog 11 (ana11) ///////////////////////////////////// 
   
   if (packBuff[0] = 'A' && packBuff[1]=='1' && packBuff[2]=='1')  
    {
      analogWrite(ana11,ana11Val);    
      Serial.println("Analog11 Pin Value:");
      Serial.println(ana11Val);
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Analog11 Pin Value:");
      Udp.write(ana11Val);
      Udp.endPacket();   
    }
    
        //////////////////////// Analog 12 (ana12) ///////////////////////////////////// 
   
   if (packBuff[0] = 'A' && packBuff[1]=='1' && packBuff[2]=='2')  
    {
      analogWrite(ana12,ana12Val);    
      Serial.println("Analog12 Pin Value:");
      Serial.println(ana12Val);
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Analog12 Pin Value:");
      Udp.write(ana12Val);
      Udp.endPacket();  
    }
    
        //////////////////////// Analog 13 (ana13) ///////////////////////////////////// 
   
   if (packBuff[0] = 'A' && packBuff[1]=='1' && packBuff[2]=='3')  
    {
      analogWrite(ana13,ana13Val);    
      Serial.println("Analog13 Pin Value:");
      Serial.println(ana13Val);
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Analog13 Pin Value:");
      Udp.write(ana13Val);
      Udp.endPacket();   
    }
    
        //////////////////////// Analog 14 (ana14) ///////////////////////////////////// 
   
   if (packBuff[0] = 'A' && packBuff[1]=='1' && packBuff[2]=='4')  
    {
      analogWrite(ana14,ana14Val);    
      Serial.println("Analog14 Pin Value:");
      Serial.println(ana14Val);
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Analog14 Pin Value:");
      Udp.write(ana14Val);
      Udp.endPacket();   
    }
    
        //////////////////////// Analog 15 (ana15) ///////////////////////////////////// 
   
   if (packBuff[0] = 'A' && packBuff[1]=='1' && packBuff[2]=='5')  
    {
      analogWrite(ana15,ana15Val);    
      Serial.println("Analog15 Pin Value:");
      Serial.println(ana15Val);
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Analog15 Pin Value:");
      Udp.write(ana15Val);
      Udp.endPacket();  
    }
    
    
 */   
   
  
   //////////////////////// Pin 2 (relay2) /////////////////////////////////////       
       if (packBuff[0] = 'P' && packBuff[1]=='2' && packBuff[2]=='M')  
    {

     
      analogWrite(relay2,relay2pwmVal);    //Set relay2 to PWM Value
      
      Serial.println(relay2pwmVal);    //Write notification  
    

    }
    
    
    else if (packBuff[0] = 'P' && packBuff[1]=='2' && packBuff[2]=='H')  // If we get the message "P2H", then set relay2 or Pin 2 HIGH
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
        
       if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='M') 
    {

      
      analogWrite(relay4,relay4pwmVal);    
      
      Serial.println(relay4pwmVal);     
    

    }

    
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
    
       if (packBuff[0] = 'P' && packBuff[1]=='7' && packBuff[2]=='M')
    {

      
      analogWrite(relay7,relay7pwmVal);    
      
      Serial.println(relay7pwmVal);     
    

    }
    
    
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
        
       if (packBuff[0] = 'P' && packBuff[1]=='8' && packBuff[2]=='M')  
    {

      
      analogWrite(relay8,relay8pwmVal);    
      
      Serial.println(relay8pwmVal);     
    

    }

    
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
    
    
         //////////////////////// Pin 22 (relay22) /////////////////////////////////////       
   

   
    if (packBuff[0] = 'P' && packBuff[1]=='2' && packBuff[2]=='2' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay22,HIGH);   
  
      Serial.println("Pin 22 ON");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 22 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='2' && packBuff[2]=='2' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay22,LOW);    
  
      Serial.println("Pin 22 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 22 is OFF");    
      Udp.endPacket();
      
    }
    
    
     //////////////////////// Pin 24 (relay24) /////////////////////////////////////       
   

   
    if (packBuff[0] = 'P' && packBuff[1]=='2' && packBuff[2]=='4' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay24,HIGH);   
  
      Serial.println("Pin 24 ON");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 24 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='2' && packBuff[2]=='4' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay24,LOW);    
  
      Serial.println("Pin 24 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 24 is OFF");    
      Udp.endPacket();
      
    }
    
    
    //////////////////////// Pin 26 (relay26) /////////////////////////////////////       
   

   
    if (packBuff[0] = 'P' && packBuff[1]=='2' && packBuff[2]=='6' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay26,HIGH);   
  
      Serial.println("Pin 26 ON");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 26 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='2' && packBuff[2]=='6' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay26,LOW);    
  
      Serial.println("Pin 26 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 26 is OFF");    
      Udp.endPacket();
      
    } 
    
    
     //////////////////////// Pin 28 (relay28) /////////////////////////////////////       
   

   
    if (packBuff[0] = 'P' && packBuff[1]=='2' && packBuff[2]=='8' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay28,HIGH);   
  
      Serial.println("Pin 28 ON");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 28 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='2' && packBuff[2]=='8' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay28,LOW);    
  
      Serial.println("Pin 28 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 28 is OFF");    
      Udp.endPacket();
      
    }
    
    
     //////////////////////// Pin 30 (relay30) /////////////////////////////////////       
   

   
    if (packBuff[0] = 'P' && packBuff[1]=='3' && packBuff[2]=='0' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay30,HIGH);   
  
      Serial.println("Pin 30 ON");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 30 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='3' && packBuff[2]=='0' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay30,LOW);    
  
      Serial.println("Pin 30 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 30 is OFF");    
      Udp.endPacket();
      
    }
    
    
     //////////////////////// Pin 31 (relay31) /////////////////////////////////////       
   

   
    if (packBuff[0] = 'P' && packBuff[1]=='3' && packBuff[2]=='1' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay31,HIGH);   
  
      Serial.println("Pin 31 ON");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 31 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='3' && packBuff[2]=='1' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay31,LOW);    
  
      Serial.println("Pin 31 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 31 is OFF");    
      Udp.endPacket();
      
    }


 //////////////////////// Pin 32 (relay32) /////////////////////////////////////       
   

   
    if (packBuff[0] = 'P' && packBuff[1]=='3' && packBuff[2]=='2' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay32,HIGH);   
  
      Serial.println("Pin 32 ON");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 32 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='3' && packBuff[2]=='2' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay32,LOW);    
  
      Serial.println("Pin 32 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 32 is OFF");    
      Udp.endPacket();
      
    }


 //////////////////////// Pin 33 (relay33) /////////////////////////////////////       
   

   
    if (packBuff[0] = 'P' && packBuff[1]=='3' && packBuff[2]=='3' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay33,HIGH);   
  
      Serial.println("Pin 33 ON");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 33 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='3' && packBuff[2]=='3' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay33,LOW);    
  
      Serial.println("Pin 33 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 33 is OFF");    
      Udp.endPacket();
      
    }


 //////////////////////// Pin 34 (relay34) /////////////////////////////////////       
   

   
    if (packBuff[0] = 'P' && packBuff[1]=='3' && packBuff[2]=='4' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay34,HIGH);   
  
      Serial.println("Pin 34 ON");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 34 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='3' && packBuff[2]=='4' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay34,LOW);    
  
      Serial.println("Pin 34 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 34 is OFF");    
      Udp.endPacket();
      
    }


//////////////////////// Pin 35 (relay35) /////////////////////////////////////       
   

   
    if (packBuff[0] = 'P' && packBuff[1]=='3' && packBuff[2]=='5' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay35,HIGH);   
  
      Serial.println("Pin 35 ON");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 35 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='3' && packBuff[2]=='5' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay35,LOW);    
  
      Serial.println("Pin 35 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 35 is OFF");    
      Udp.endPacket();
      
    }
    
    
     //////////////////////// Pin 36 (relay36) /////////////////////////////////////       
   

   
    if (packBuff[0] = 'P' && packBuff[1]=='3' && packBuff[2]=='6' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay36,HIGH);   
  
      Serial.println("Pin 36 ON");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 36 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='3' && packBuff[2]=='6' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay36,LOW);    
  
      Serial.println("Pin 36 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 36 is OFF");    
      Udp.endPacket();
      
    }


 //////////////////////// Pin 37 (relay37) /////////////////////////////////////       
   

   
    if (packBuff[0] = 'P' && packBuff[1]=='3' && packBuff[2]=='7' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay37,HIGH);   
  
      Serial.println("Pin 37 ON");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 37 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='3' && packBuff[2]=='7' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay37,LOW);    
  
      Serial.println("Pin 37 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 37 is OFF");    
      Udp.endPacket();
      
    }


 //////////////////////// Pin 38 (relay38) /////////////////////////////////////       
   

   
    if (packBuff[0] = 'P' && packBuff[1]=='3' && packBuff[2]=='8' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay38,HIGH);   
  
      Serial.println("Pin 38 ON");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 38 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='3' && packBuff[2]=='8' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay38,LOW);    
  
      Serial.println("Pin 38 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 38 is OFF");    
      Udp.endPacket();
      
    }


 //////////////////////// Pin 39 (relay39) /////////////////////////////////////       
   

   
    if (packBuff[0] = 'P' && packBuff[1]=='3' && packBuff[2]=='9' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay39,HIGH);   
  
      Serial.println("Pin 39 ON");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 39 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='3' && packBuff[2]=='9' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay39,LOW);    
  
      Serial.println("Pin 39 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 39 is OFF");    
      Udp.endPacket();
      
    }


 //////////////////////// Pin 40 (relay40) /////////////////////////////////////       
   

   
    if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='0' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay40,HIGH);   
  
      Serial.println("Pin 40 ON");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 40 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='0' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay40,LOW);    
  
      Serial.println("Pin 40 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 40 is OFF");    
      Udp.endPacket();
      
    }
    
    
    //////////////////////// Pin 41 (relay41) /////////////////////////////////////       
   

   
    if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='1' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay41,HIGH);   
  
      Serial.println("Pin 41 ON");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 41 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='1' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay41,LOW);    
  
      Serial.println("Pin 41 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 41 is OFF");    
      Udp.endPacket();
      
    }


//////////////////////// Pin 42 (relay42) /////////////////////////////////////       
   

   
    if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='2' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay42,HIGH);   
  
      Serial.println("Pin 42 ON");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 42 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='2' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay42,LOW);    
  
      Serial.println("Pin 42 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 42 is OFF");    
      Udp.endPacket();
      
    }


//////////////////////// Pin 43 (relay43) /////////////////////////////////////       
   

   
    if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='3' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay43,HIGH);   
  
      Serial.println("Pin 43 ON");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 43 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='3' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay43,LOW);    
  
      Serial.println("Pin 43 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 43 is OFF");    
      Udp.endPacket();
      
    }


//////////////////////// Pin 44 (relay44) /////////////////////////////////////       
   
       if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='4' && packBuff[3]=='M')  
    {

     
      analogWrite(relay44,relay44pwmVal);  
      
      Serial.println(relay44pwmVal);    //Write notification  
    

    }

   
    else if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='4' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay44,HIGH);   
  
      Serial.println("Pin 44 ON");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 44 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='4' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay44,LOW);    
  
      Serial.println("Pin 44 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 44 is OFF");    
      Udp.endPacket();
      
    }


//////////////////////// Pin 45 (relay45) /////////////////////////////////////       
       
       if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='5' && packBuff[3]=='M')  
    {

      
      analogWrite(relay45,relay45pwmVal);  
      
      Serial.println(relay45pwmVal);    //Write notification  
    

    }

   
    else if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='5' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay45,HIGH);   
  
      Serial.println("Pin 45 ON");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 45 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='5' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay45,LOW);    
  
      Serial.println("Pin 45 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 45 is OFF");    
      Udp.endPacket();
      
    }
    
    
    //////////////////////// Pin 46 (relay46) /////////////////////////////////////       
      
       if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='6' && packBuff[3]=='M')  
    {

      
      analogWrite(relay46,relay46pwmVal);
      
      Serial.println(relay46pwmVal);    //Write notification  
    

    }

   
    else if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='6' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay46,HIGH);   
  
      Serial.println("Pin 46 ON");   
  
      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 46 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='6' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay46,LOW);    
  
      Serial.println("Pin 46 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 46 is OFF");    
      Udp.endPacket();
      
    }


//////////////////////// Pin 47 (relay47) /////////////////////////////////////       
   

   
    if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='7' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay47,HIGH);   
  
      Serial.println("Pin 47 ON");   

      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 47 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='7' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay47,LOW);    
  
      Serial.println("Pin 47 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 47 is OFF");    
      Udp.endPacket();
      
    }


//////////////////////// Pin 48 (relay48) /////////////////////////////////////       
   

   
    if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='8' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay48,HIGH);   
  
      Serial.println("Pin 48 ON");   

      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 48 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='8' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay48,LOW);    
  
      Serial.println("Pin 48 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 48 is OFF");    
      Udp.endPacket();
      
    }


//////////////////////// Pin 49 (relay49) /////////////////////////////////////       
   

   
    if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='9' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay49,HIGH);   
  
      Serial.println("Pin 49 ON");   

      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 49 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='9' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay49,LOW);    
  
      Serial.println("Pin 49 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 49 is OFF");    
      Udp.endPacket();
      
    }

/*

//////////////////////// Pin 50 (relay50) /////////////////////////////////////       
   

   
    if (packBuff[0] = 'P' && packBuff[1]=='5' && packBuff[2]=='0' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay50,HIGH);   
  
      Serial.println("Pin 50 ON");   

      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 50 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='5' && packBuff[2]=='0' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay50,LOW);    
  
      Serial.println("Pin 50 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 50 is OFF");    
      Udp.endPacket();
      
    }


//////////////////////// Pin 51 (relay51) /////////////////////////////////////       
   

   
    if (packBuff[0] = 'P' && packBuff[1]=='5' && packBuff[2]=='1' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay51,HIGH);   
  
      Serial.println("Pin 51 ON");   

      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 51 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='5' && packBuff[2]=='1' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay51,LOW);    
  
      Serial.println("Pin 51 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 51 is OFF");    
      Udp.endPacket();
      
    }


//////////////////////// Pin 52 (relay52) /////////////////////////////////////       
   

   
    if (packBuff[0] = 'P' && packBuff[1]=='5' && packBuff[2]=='2' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay52,HIGH);   
  
      Serial.println("Pin 52 ON");   

      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 52 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='5' && packBuff[2]=='2' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay52,LOW);    
  
      Serial.println("Pin 52 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 52 is OFF");    
      Udp.endPacket();
      
    }


//////////////////////// Pin 53 (relay53) /////////////////////////////////////       
   

   
    if (packBuff[0] = 'P' && packBuff[1]=='5' && packBuff[2]=='3' && packBuff[3]=='H')  
    {
      
      digitalWrite(relay53,HIGH);   
  
      Serial.println("Pin 53 ON");   

      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 53 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (packBuff[0] = 'P' && packBuff[1]=='5' && packBuff[2]=='3' && packBuff[3]=='L')  
    {
      
      digitalWrite(relay53,LOW);    
  
      Serial.println("Pin 53 OFF");    
      
      Udp.beginPacket(iPhoneIP, iPhonePort);
      Udp.write("Pin 53 is OFF");    
      Udp.endPacket();
      
    }
  
 */   

 }
 
 delay(20);
 
}  


