

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

This code is for use with iArduino App and is based on RN171XVW WiFly Module.

all rights reserved please contact on following mail id for details:

dhirajjadhao@gmail.com

*/




#include <LiquidCrystal.h>
#include <SPI.h>             // for Arduino later than ver 0018


char str[100];


LiquidCrystal lcd(7, 6, 5, 4, 3, 2);




void setup() 

{

  Serial.begin(9600);    //Start Serial Communications with PC
  
   // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  
 
  
}

void loop()
{
  int packetSize = Serial.available();

  if(Serial.available() == packetSize)
  {
    
   for (byte i=0; i< packetSize; i++)
  {
    str[i] = Serial.read();
  }

    lcd.clear();
  } 
  
  
  
  lcd.setCursor(1,0);
  lcd.write(str);

  lcd.scrollDisplayLeft(); 
  delay(300);
  
  for (int pos=0; pos < packetSize ; pos++)
  {
  lcd.scrollDisplayLeft(); 
  delay(300);
  }
Serial.flush();

}
