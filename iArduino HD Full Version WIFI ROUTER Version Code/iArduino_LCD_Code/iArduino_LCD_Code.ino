#include <LiquidCrystal.h>
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


LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

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
  
   // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  
 
  
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
    Udp.flush();
    Serial.flush();
    lcd.clear();
  } 
  
  
  
  lcd.setCursor(1,0);
  lcd.write(packBuff);
  lcd.scrollDisplayLeft(); 
  delay(300);
  
  for (int pos=0; pos < packetSize ; pos++)
  {
  lcd.scrollDisplayLeft(); 
  delay(300);
  }


}
