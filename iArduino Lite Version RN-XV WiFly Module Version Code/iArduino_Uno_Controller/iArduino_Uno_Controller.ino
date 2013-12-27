
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


char str[10];


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



void setup() 
{

  Serial.begin(9600);    //Start Serial Communications with PC
  
  pinMode(relay2,OUTPUT);    
  pinMode(relay3,OUTPUT);    
  pinMode(relay4,OUTPUT);   
  pinMode(relay5,OUTPUT);    
  pinMode(relay6,OUTPUT);
  pinMode(relay7,OUTPUT);
  pinMode(relay8,OUTPUT);
  pinMode(relay9,OUTPUT);
 
  
}


void loop()
{
 // Integer that will hold our PWM values for later use // 
 
   
  int relay3pwmVal;    
  int relay5pwmVal;    
  int relay6pwmVal;    
  int relay9pwmVal; 

///////////////////////////////////////////////////////////  


    if(Serial.available() > 0)
  {
    int packetSize = Serial.available();
   

      for (byte i=0; i< packetSize; i++)
  {
    str[i] = Serial.read();
  }



    ///////////////////////// PWM Value Formatting //////////////////////////////////

    relay3pwmVal = (str[3] - '0')*100 + (str[4] - '0')*10 + (str[5] - '0'); 
    relay5pwmVal = (str[3] - '0')*100 + (str[4] - '0')*10 + (str[5] - '0'); 
    relay6pwmVal = (str[3] - '0')*100 + (str[4] - '0')*10 + (str[5] - '0'); 
    relay9pwmVal = (str[3] - '0')*100 + (str[4] - '0')*10 + (str[5] - '0'); 

    

   
  
   //////////////////////// Pin 2 (relay2) /////////////////////////////////////       
 if (str[0] = 'P' && str[1]=='2' && str[2]=='H')  // If we get the message "P2H", then set relay2 or Pin 2 HIGH
    {
      
      digitalWrite(relay2,HIGH);    //Turn on relay2
  
      Serial.println("Pin 2 ON");    //Write notification 

  
  

    }
    
     
    
    else if (str[0] = 'P' && str[1]=='2' && str[2]=='L')  // If we get the message "P2L", then set relay2 or Pin 2 LOW
    {
      
      digitalWrite(relay2,LOW);    //Turn off relay2
  
      Serial.println("Pin 2 OFF");    //Write notification 

      
    }
    
     //////////////////////// Pin 3 (relay3) /////////////////////////////////////       
      
       if (str[0] = 'P' && str[1]=='3' && str[2]=='M')  
    {

      
          
      analogWrite(relay3,relay3pwmVal);
      Serial.println(relay3pwmVal);    
    

    }
    
    
    
    if (str[0] = 'P' && str[1]=='3' && str[2]=='H') 
    {
      
      digitalWrite(relay3,HIGH);    
  
      Serial.println("Pin 3 ON");    
  
 
  
  

    }
    
     
    
    else if (str[0] = 'P' && str[1]=='3' && str[2]=='L')  
    {
      
      digitalWrite(relay3,LOW);    
  
      Serial.println("Pin 3 OFF");     
      
      

      
    }
    
    
    
     //////////////////////// Pin 4 (relay4) /////////////////////////////////////       
 
    if (str[0] = 'P' && str[1]=='4' && str[2]=='H')  
    {
      
      digitalWrite(relay4,HIGH);    
  
      Serial.println("Pin 4 ON");     
  
  
  

    }
    
     
    
    else if (str[0] = 'P' && str[1]=='4' && str[2]=='L')  
    {
      
      digitalWrite(relay4,LOW);    
  
      Serial.println("Pin 4 OFF");    
      
  
      
    }
    
    
     //////////////////////// Pin 5 (relay5) /////////////////////////////////////       
        
       if (str[0] = 'P' && str[1]=='5' && str[2]=='M')  
    {

      
          
      analogWrite(relay5,relay5pwmVal);
      Serial.println(relay5pwmVal);     
    

    }

    
    
    if (str[0] = 'P' && str[1]=='5' && str[2]=='H')  
    {
      
      digitalWrite(relay5,HIGH);    
  
      Serial.println("Pin 5 ON");   
  

  
  

    }
    
     
    
    else if (str[0] = 'P' && str[1]=='5' && str[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      
      digitalWrite(relay5,LOW);    
  
      Serial.println("Pin 5 OFF");    
      
 
      
    }
    
    
    
     //////////////////////// Pin 6 (relay6) /////////////////////////////////////       
        
       if (str[0] = 'P' && str[1]=='6' && str[2]=='M')  
    {

      
       
      analogWrite(relay6,relay6pwmVal);
      Serial.println(relay6pwmVal);     
    

    }

    
    
    if (str[0] = 'P' && str[1]=='6' && str[2]=='H')  // If we get the message "P6H", then set relay1 (6) HIGH
    {
      
      digitalWrite(relay6,HIGH);   
  
      Serial.println("Pin 6 ON");    
  


    }
    
     
    
    else if (str[0] = 'P' && str[1]=='6' && str[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      
      digitalWrite(relay6,LOW);    
  
      Serial.println("Pin 6 OFF");     
      
      
 
      
    }
    
    
     //////////////////////// Pin 7 (relay7) /////////////////////////////////////       
 
    
    if (str[0] = 'P' && str[1]=='7' && str[2]=='H') 
    {
      
      digitalWrite(relay7,HIGH);   
  
      Serial.println("Pin 7 ON");     
  
  

    }
    
     
    
    else if (str[0] = 'P' && str[1]=='7' && str[2]=='L') 
    {
      
      digitalWrite(relay7,LOW);   
  
      Serial.println("Pin 7 OFF");    
      
 
      
    }
    
    
     //////////////////////// Pin 8 (relay8) /////////////////////////////////////       
 
    
    if (str[0] = 'P' && str[1]=='8' && str[2]=='H')  
    {
      
      digitalWrite(relay8,HIGH);   
  
      Serial.println("Pin 8 ON");   

  

    }
    
     
    
    else if (str[0] = 'P' && str[1]=='8' && str[2]=='L')  
    {
      
      digitalWrite(relay8,LOW);    
  
      Serial.println("Pin 8 OFF");    
      
      

      
    }
    
     //////////////////////// Pin 9 (relay9) /////////////////////////////////////       
        
      if (str[0] = 'P' && str[1]=='9' && str[2]=='M')  
    {

      analogWrite(relay9,relay9pwmVal);
      Serial.println(relay9pwmVal);      
    

    }

   
   
    if (str[0] = 'P' && str[1]=='9' && str[2]=='H')  
    {
      
      digitalWrite(relay9,HIGH);   
  
      Serial.println("Pin 9 ON");   
  
 

    }
    
     
    
    else if (str[0] = 'P' && str[1]=='9' && str[2]=='L')  
    {
      
      digitalWrite(relay9,LOW);    
  
      Serial.println("Pin 9 OFF");    
      
      
    
      
    }
    
 
 }
 
 delay(20);
 
}  


