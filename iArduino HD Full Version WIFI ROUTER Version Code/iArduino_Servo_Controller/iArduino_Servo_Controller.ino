
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
#include <EthernetUdp.h>   
#include <Ethernet.h>
#include <Servo.h> 

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
 
Servo servo2;  // create servo object to control a servo 
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;
Servo servo9;
Servo servo44;
Servo servo45;
Servo servo46;
 
///////////////////////////////////////////

///////////////// UDP Variables  ////////////////// 

// the next two variables are set when a packet is received
//byte remoteIp[4];          // holds received packet's originating IP
//unsigned int  remotePort;   // holds received packet's originating port

// buffers for receiving and sending data
char packBuff[UDP_TX_PACKET_MAX_SIZE]; //buffer to hold incoming packet,

/////////////////////////////////////////////////

EthernetUDP Udp;

 
void setup() 
{ 
  servo2.attach(2);  // attaches the servo on pin 9 to the servo object 
  servo3.attach(3);
  servo4.attach(4);
  servo5.attach(5);
  servo6.attach(6);
  servo7.attach(7);
  servo8.attach(8);
  servo9.attach(9);
  servo44.attach(44);
  servo45.attach(45);
  servo46.attach(46);
  
  
  
  
  
  
  
 // More info on Ethernet on Arduino's website:  http://arduino.cc/en/Reference/EthernetBegin
 // start the Ethernet and UDP:
  Ethernet.begin(mac,ip);   // If you don't need to set your default gateway or subnet manually, use this
  Udp.begin(localPort);    //Setup UDP socket on port defined earlier
  Serial.begin(9600);    //Start Serial Communications with PC 
  
} 
 
void loop() 
{ 
 
 // Integer that will hold our PWM values for later use // 
 
  int servo2pwmVal;    
  int servo3pwmVal;    
  int servo4pwmVal;    
  int servo5pwmVal;    
  int servo6pwmVal;    
  int servo7pwmVal; 
  int servo8pwmVal; 
  int servo9pwmVal;
  int servo44pwmVal;
  int servo45pwmVal;
  int servo46pwmVal;

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
    
   
   // PWM Pin Format Declaration //
   
    servo2pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    servo3pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    servo4pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    servo5pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    servo6pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    servo7pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    servo8pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0'); 
    servo9pwmVal = (packBuff[3] - '0')*100 + (packBuff[4] - '0')*10 + (packBuff[5] - '0');
    servo44pwmVal = (packBuff[4] - '0')*100 + (packBuff[5] - '0')*10 + (packBuff[6] - '0');
    servo45pwmVal = (packBuff[4] - '0')*100 + (packBuff[5] - '0')*10 + (packBuff[6] - '0');
    servo46pwmVal = (packBuff[4] - '0')*100 + (packBuff[5] - '0')*10 + (packBuff[6] - '0'); 
 
 
 ///////////////////////////////////////////////////////////////////////////////////////////// 
   

//////////////////////// Pin 2 (Servo 2) /////////////////////////////////////       
      
       if (packBuff[0] = 'P' && packBuff[1]=='2' && packBuff[2]=='M')  
    {

      
      servo2.write(servo2pwmVal);   
      
      Serial.println(servo2pwmVal);    
    
    }
    
    
//////////////////////// Pin 3 (Servo 3) /////////////////////////////////////       
      
      else if (packBuff[0] = 'P' && packBuff[1]=='3' && packBuff[2]=='M')  
    {

      
      servo3.write(servo3pwmVal);   
      
      Serial.println(servo3pwmVal);    
    
    }    
    
//////////////////////// Pin 4 (Servo 4) /////////////////////////////////////       
      
      else if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='M')  
    {

      
      servo4.write(servo4pwmVal);   
      
      Serial.println(servo4pwmVal);    
    
    }

//////////////////////// Pin 5 (Servo 5) /////////////////////////////////////       
      
      else if (packBuff[0] = 'P' && packBuff[1]=='5' && packBuff[2]=='M')  
    {

      
      servo5.write(servo5pwmVal);   
      
      Serial.println(servo5pwmVal);    
    
    } 
   
//////////////////////// Pin 6 (Servo 6) /////////////////////////////////////       
      
      else if (packBuff[0] = 'P' && packBuff[1]=='6' && packBuff[2]=='M')  
    {

      
      servo6.write(servo6pwmVal);   
      
      Serial.println(servo6pwmVal);    
    
    } 
 
//////////////////////// Pin 7 (Servo 7) /////////////////////////////////////       
      
      else if (packBuff[0] = 'P' && packBuff[1]=='7' && packBuff[2]=='M')  
    {

      
      servo7.write(servo7pwmVal);   
      
      Serial.println(servo7pwmVal);    
    
    }
  
//////////////////////// Pin 8 (Servo 8) /////////////////////////////////////       
      
      else if (packBuff[0] = 'P' && packBuff[1]=='8' && packBuff[2]=='M')  
    {

      
      servo8.write(servo8pwmVal);   
      
      Serial.println(servo8pwmVal);    
    
    }    
    
//////////////////////// Pin 9 (Servo 9) /////////////////////////////////////       
      
      else if (packBuff[0] = 'P' && packBuff[1]=='9' && packBuff[2]=='M')  
    {

      
      servo9.write(servo9pwmVal);   
      
      Serial.println(servo9pwmVal);    
    
    }
   
//////////////////////// Pin 44 (Servo 44) /////////////////////////////////////       
      
      else if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='4' && packBuff[3]=='M')  
    {

      
      servo44.write(servo44pwmVal);   
      
      Serial.println(servo44pwmVal);    
    
    }
    
//////////////////////// Pin 45 (Servo 45) /////////////////////////////////////       
      
      else if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='5' && packBuff[3]=='M')  
    {

      
      servo45.write(servo45pwmVal);   
      
      Serial.println(servo45pwmVal);    
    
    }

//////////////////////// Pin 46 (Servo 46) /////////////////////////////////////       
      
      else if (packBuff[0] = 'P' && packBuff[1]=='4' && packBuff[2]=='6' && packBuff[3]=='M')  
    {

      
      servo46.write(servo46pwmVal);   
      
      Serial.println(servo46pwmVal);    
    
    }    
    
 
 
 
 }
 
 delay(5);
 
}  
