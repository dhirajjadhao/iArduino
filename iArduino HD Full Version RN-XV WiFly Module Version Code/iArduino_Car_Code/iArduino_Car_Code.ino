
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

///////////////////////////////////////////





void setup() {
  

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

  
  if(Serial.available()==4)
  {

      for (byte i=0; i<4; i++)
  {
    str[i] = Serial.read();
  }
   
    
      //////////////////////// Forward /////////////////////////////////////       
      

     if (str[0] == 'F' && str[1]=='O' && str[2]=='R' && str[3]=='H') 
    {
      
    // YOU CAN ALSO MENTION YOUR OWN ACTION FOR FORWARD COMMAND HERE.
    // JUST REPLACE THE CODE GIVEN BELOW WITH YOUR OWN
      
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
  
   
       Serial.flush();

  
  }
  
   else if (str[0] == 'F' && str[1]=='O' && str[2]=='R' && str[3]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
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
      Serial.flush();
      
    }
  
  
   
   
    //////////////////////// Backward /////////////////////////////////////       
      

     if (str[0] == 'B' && str[1]=='A' && str[2]=='C' && str[3]=='H') 
    {
      
     // YOU CAN ALSO MENTION YOUR OWN ACTION FOR FORWARD COMMAND HERE.
    // JUST REPLACE THE CODE GIVEN BELOW WITH YOUR OWN
      
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
     Serial.flush();
  
  }
  
   else if (str[0] == 'B' && str[1]=='A' && str[2]=='C' && str[3]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
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
      Serial.flush();
      
    }
 
 
     //////////////////////// Right /////////////////////////////////////       
      

     if (str[0] == 'R' && str[1]=='I' && str[2]=='G' && str[3]=='H') 
    {
      
     // YOU CAN ALSO MENTION YOUR OWN ACTION FOR FORWARD COMMAND HERE.
    // JUST REPLACE THE CODE GIVEN BELOW WITH YOUR OWN    
      
      
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
  
      Serial.flush();
  
  }
  
   else if (str[0] == 'R' && str[1]=='I' && str[2]=='G' && str[3]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
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
      
      Serial.flush();
      
    }
    
    
         //////////////////////// Left /////////////////////////////////////       
      

     if (str[0] == 'L' && str[1]=='E' && str[2]=='F' && str[3]=='H') 
    {
      
      
    // YOU CAN ALSO MENTION YOUR OWN ACTION FOR FORWARD COMMAND HERE.
    // JUST REPLACE THE CODE GIVEN BELOW WITH YOUR OWN      
      
      
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
  
   Serial.flush();
  

  
  }
  
   else if (str[0] == 'L' && str[1]=='E' && str[2]=='F' && str[3]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
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
      
      Serial.flush();
      
    }
     
    
  
    
    
 }
 

 
}  




