
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


#include <SPI.h>             // for Arduino later than ver 0018
#include <Servo.h> 

char str[10];

// Define Servo pins
Servo relay2,relay3,relay4,relay5,relay6,relay7,relay8,relay9,relay44,relay45,relay46; 
////


void setup()
{
Serial.begin(9600);

//Define servo pins to attach

  relay2.attach(2);
  relay3.attach(3);
  relay4.attach(4);
  relay5.attach(5);
  relay6.attach(6);
  relay7.attach(7);
  relay8.attach(8);
  relay9.attach(9);
  relay44.attach(44);
  relay45.attach(45);
  relay46.attach(46);


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
  
  
  if(Serial.available() > 0)
  {
  
   int packetSize = Serial.available();
   

   for (byte i=0; i< packetSize; i++)
  {
    str[i] = Serial.read();
  } 
   
  
  
      ///////////////////////// PWM Value Formatting //////////////////////////////////
    relay2pwmVal = (str[3] - '0')*100 + (str[4] - '0')*10 + (str[5] - '0');  
    relay3pwmVal = (str[3] - '0')*100 + (str[4] - '0')*10 + (str[5] - '0'); 
    relay4pwmVal = (str[3] - '0')*100 + (str[4] - '0')*10 + (str[5] - '0'); 
    relay5pwmVal = (str[3] - '0')*100 + (str[4] - '0')*10 + (str[5] - '0'); 
    relay6pwmVal = (str[3] - '0')*100 + (str[4] - '0')*10 + (str[5] - '0'); 
    relay7pwmVal = (str[3] - '0')*100 + (str[4] - '0')*10 + (str[5] - '0'); 
    relay8pwmVal = (str[3] - '0')*100 + (str[4] - '0')*10 + (str[5] - '0'); 
    relay9pwmVal = (str[3] - '0')*100 + (str[4] - '0')*10 + (str[5] - '0'); 
    relay44pwmVal = (str[4] - '0')*100 + (str[5] - '0')*10 + (str[6] - '0'); 
    relay45pwmVal = (str[4] - '0')*100 + (str[5] - '0')*10 + (str[6] - '0'); 
    relay46pwmVal = (str[4] - '0')*100 + (str[5] - '0')*10 + (str[6] - '0');   
    
    
     //////////////////////// Pin 2 (relay2) /////////////////////////////////////       
       if (str[0] == 'P' && str[1]=='2' && str[2]=='M')  
    {

     
      relay2.write(relay2pwmVal);    //Set relay2 to PWM Value
      
      Serial.println(relay2pwmVal);    //Write notification  
    

    }
    
    
         //////////////////////// Pin 3 (relay3) /////////////////////////////////////       
      else if (str[0] == 'P' && str[1]=='3' && str[2]=='M')  
    {

     
      relay3.write(relay3pwmVal);    //Set relay3 to PWM Value
      
      Serial.println(relay3pwmVal);    //Write notification  
    

    }
    
    
             //////////////////////// Pin 4 (relay4) /////////////////////////////////////       
      else if (str[0] == 'P' && str[1]=='4' && str[2]=='M')  
    {

     
      relay4.write(relay4pwmVal);    //Set relay4 to PWM Value
      
      Serial.println(relay4pwmVal);    //Write notification  
    

    }
    
    
                 //////////////////////// Pin 5 (relay5) /////////////////////////////////////       
      else if (str[0] == 'P' && str[1]=='5' && str[2]=='M')  
    {

     
      relay5.write(relay5pwmVal);    //Set relay5 to PWM Value
      
      Serial.println(relay5pwmVal);    //Write notification  
    

    }
    
    
                     //////////////////////// Pin 6 (relay6) /////////////////////////////////////       
      else if (str[0] == 'P' && str[1]=='6' && str[2]=='M')  
    {

     
      relay6.write(relay6pwmVal);    //Set relay6 to PWM Value
      
      Serial.println(relay6pwmVal);    //Write notification  
    

    }
    
    
    
                         //////////////////////// Pin 7 (relay7) /////////////////////////////////////       
      else if (str[0] == 'P' && str[1]=='7' && str[2]=='M')  
    {

     
      relay7.write(relay7pwmVal);    //Set relay7 to PWM Value
      
      Serial.println(relay7pwmVal);    //Write notification  
    

    }
    
    
    
                             //////////////////////// Pin 8 (relay8) /////////////////////////////////////       
      else if (str[0] == 'P' && str[1]=='8' && str[2]=='M')  
    {

     
      relay8.write(relay8pwmVal);    //Set relay8 to PWM Value
      
      Serial.println(relay8pwmVal);    //Write notification  
    

    }
    
 
 
 
                              //////////////////////// Pin 9 (relay9) /////////////////////////////////////       
      else if (str[0] == 'P' && str[1]=='9' && str[2]=='M')  
    {

     
      relay9.write(relay9pwmVal);    //Set relay9 to PWM Value
      
      Serial.println(relay9pwmVal);    //Write notification  
    

    }   
    
    
    
                                  //////////////////////// Pin 44 (relay44) /////////////////////////////////////       
      else if (str[0] == 'P' && str[1]=='4' && str[2]=='4' && str[2]=='M')  
    {

     
      relay44.write(relay44pwmVal);    //Set relay44 to PWM Value
      
      Serial.println(relay44pwmVal);    //Write notification  
    

    } 
    
    
    
                                      //////////////////////// Pin 45 (relay45) /////////////////////////////////////       
      else if (str[0] == 'P' && str[1]=='4' && str[2]=='5' && str[2]=='M')  
    {

     
      relay45.write(relay45pwmVal);    //Set relay45 to PWM Value
      
      Serial.println(relay45pwmVal);    //Write notification  
    

    } 
    
    
    
                                          //////////////////////// Pin 46 (relay46) /////////////////////////////////////       
      else if (str[0] == 'P' && str[1]=='4' && str[2]=='6' && str[2]=='M')  
    {

     
      relay46.write(relay46pwmVal);    //Set relay45 to PWM Value
      
      Serial.println(relay46pwmVal);    //Write notification  
    

    } 
  
  
  }
  
   delay(20);
   Serial.flush();

}
