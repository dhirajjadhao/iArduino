
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



void setup() 
{
  
 
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

     
      analogWrite(relay2,relay2pwmVal);    //Set relay2 to PWM Value
      
      Serial.println(relay2pwmVal);    //Write notification  
    

    }
    
    
    else if (str[0] == 'P' && str[1]=='2' && str[2]=='H')  // If we get the message "P2H", then set relay2 or Pin 2 HIGH
    {
      
      digitalWrite(relay2,HIGH);    //Turn on relay2
  
      Serial.println("Pin 2 ON");    //Write notification 

  
  

    }
    
     
    
    else if (str[0] == 'P' && str[1]=='2' && str[2]=='L')  // If we get the message "P2L", then set relay2 or Pin 2 LOW
    {
      
      digitalWrite(relay2,LOW);    //Turn off relay2
  
      Serial.println("Pin 2 OFF");    //Write notification 

      
    }
    
     //////////////////////// Pin 3 (relay3) /////////////////////////////////////       
      
       if (str[0] == 'P' && str[1]=='3' && str[2]=='M')  
    {

      
          
      analogWrite(relay3,relay3pwmVal);
      Serial.println(relay3pwmVal);    
    

    }
    
    
    
    if (str[0] == 'P' && str[1]=='3' && str[2]=='H') 
    {
      
      digitalWrite(relay3,HIGH);    
  
      Serial.println("Pin 3 ON");    
  
 
  
  

    }
    
     
    
    else if (str[0] == 'P' && str[1]=='3' && str[2]=='L')  
    {
      
      digitalWrite(relay3,LOW);    
  
      Serial.println("Pin 3 OFF");     
      
      

      
    }
    
    
    
     //////////////////////// Pin 4 (relay4) /////////////////////////////////////       
        
       if (str[0] == 'P' && str[1]=='4' && str[2]=='M') 
    {

      
      analogWrite(relay4,relay4pwmVal);    
      
      Serial.println(relay4pwmVal);     
    

    }

    
    if (str[0] == 'P' && str[1]=='4' && str[2]=='H')  
    {
      
      digitalWrite(relay4,HIGH);    
  
      Serial.println("Pin 4 ON");     
  
  
  

    }
    
     
    
    else if (str[0] == 'P' && str[1]=='4' && str[2]=='L')  
    {
      
      digitalWrite(relay4,LOW);    
  
      Serial.println("Pin 4 OFF");    
      
  
      
    }
    
    
     //////////////////////// Pin 5 (relay5) /////////////////////////////////////       
        
       if (str[0] == 'P' && str[1]=='5' && str[2]=='M')  
    {

      
          
      analogWrite(relay5,relay5pwmVal);
      Serial.println(relay5pwmVal);     
    

    }

    
    
    if (str[0] == 'P' && str[1]=='5' && str[2]=='H')  
    {
      
      digitalWrite(relay5,HIGH);    
  
      Serial.println("Pin 5 ON");   
  

  
  

    }
    
     
    
    else if (str[0] == 'P' && str[1]=='5' && str[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      
      digitalWrite(relay5,LOW);    
  
      Serial.println("Pin 5 OFF");    
      
 
      
    }
    
    
    
     //////////////////////// Pin 6 (relay6) /////////////////////////////////////       
        
       if (str[0] == 'P' && str[1]=='6' && str[2]=='M')  
    {

      
       
      analogWrite(relay6,relay6pwmVal);
      Serial.println(relay6pwmVal);     
    

    }

    
    
    if (str[0] == 'P' && str[1]=='6' && str[2]=='H')  // If we get the message "P6H", then set relay1 (6) HIGH
    {
      
      digitalWrite(relay6,HIGH);   
  
      Serial.println("Pin 6 ON");    
  


    }
    
     
    
    else if (str[0] == 'P' && str[1]=='6' && str[2]=='L')  // If we get the message "P6L", then set relay1 (6) LOW
    {
      
      digitalWrite(relay6,LOW);    
  
      Serial.println("Pin 6 OFF");     
      
      
 
      
    }
    
    
     //////////////////////// Pin 7 (relay7) /////////////////////////////////////       
    
       if (str[0] == 'P' && str[1]=='7' && str[2]=='M')
    {

      
      analogWrite(relay7,relay7pwmVal);    
      
      Serial.println(relay7pwmVal);     
    

    }
    
    
    if (str[0] == 'P' && str[1]=='7' && str[2]=='H') 
    {
      
      digitalWrite(relay7,HIGH);   
  
      Serial.println("Pin 7 ON");     
  
  

    }
    
     
    
    else if (str[0] == 'P' && str[1]=='7' && str[2]=='L') 
    {
      
      digitalWrite(relay7,LOW);   
  
      Serial.println("Pin 7 OFF");    
      
 
      
    }
    
    
     //////////////////////// Pin 8 (relay8) /////////////////////////////////////       
        
       if (str[0] == 'P' && str[1]=='8' && str[2]=='M')  
    {

      
      analogWrite(relay8,relay8pwmVal);    
      
      Serial.println(relay8pwmVal);     
    

    }

    
    if (str[0] == 'P' && str[1]=='8' && str[2]=='H')  
    {
      
      digitalWrite(relay8,HIGH);   
  
      Serial.println("Pin 8 ON");   

  

    }
    
     
    
    else if (str[0] == 'P' && str[1]=='8' && str[2]=='L')  
    {
      
      digitalWrite(relay8,LOW);    
  
      Serial.println("Pin 8 OFF");    
      
      

      
    }
    
     //////////////////////// Pin 9 (relay9) /////////////////////////////////////       
        
      if (str[0] == 'P' && str[1]=='9' && str[2]=='M')  
    {

      analogWrite(relay9,relay9pwmVal);
      Serial.println(relay9pwmVal);      
    

    }

   
   
    if (str[0] == 'P' && str[1]=='9' && str[2]=='H')  
    {
      
      digitalWrite(relay9,HIGH);   
  
      Serial.println("Pin 9 ON");   
  
 

    }
    
     
    
    else if (str[0] == 'P' && str[1]=='9' && str[2]=='L')  
    {
      
      digitalWrite(relay9,LOW);    
  
      Serial.println("Pin 9 OFF");    
      
      
    
      
    }
    
    
         //////////////////////// Pin 22 (relay22) /////////////////////////////////////       
   

   
    if (str[0] == 'P' && str[1]=='2' && str[2]=='2' && str[3]=='H')  
    {
      
      digitalWrite(relay22,HIGH);   
  
      Serial.println("Pin 22 ON");   
  
  
  

    }
    
     
    
    else if (str[0] == 'P' && str[1]=='2' && str[2]=='2' && str[3]=='L')  
    {
      
      digitalWrite(relay22,LOW);    
  
      Serial.println("Pin 22 OFF");    
      
   
      
    }
    
    
     //////////////////////// Pin 24 (relay24) /////////////////////////////////////       
   

   
    if (str[0] == 'P' && str[1]=='2' && str[2]=='4' && str[3]=='H')  
    {
      
      digitalWrite(relay24,HIGH);   
  
      Serial.println("Pin 24 ON");   
 
  
  

    }
    
     
    
    else if (str[0] == 'P' && str[1]=='2' && str[2]=='4' && str[3]=='L')  
    {
      
      digitalWrite(relay24,LOW);    
  
      Serial.println("Pin 24 OFF");    
      
   
      
    }
    
    
    //////////////////////// Pin 26 (relay26) /////////////////////////////////////       
   

   
    if (str[0] == 'P' && str[1]=='2' && str[2]=='6' && str[3]=='H')  
    {
      
      digitalWrite(relay26,HIGH);   
  
      Serial.println("Pin 26 ON");   
  

  

    }
    
     
    
    else if (str[0] == 'P' && str[1]=='2' && str[2]=='6' && str[3]=='L')  
    {
      
      digitalWrite(relay26,LOW);    
  
      Serial.println("Pin 26 OFF");    
      
   
    } 
    
    
     //////////////////////// Pin 28 (relay28) /////////////////////////////////////       
   

   
    if (str[0] == 'P' && str[1]=='2' && str[2]=='8' && str[3]=='H')  
    {
      
      digitalWrite(relay28,HIGH);   
  
      Serial.println("Pin 28 ON");   
  

    }
    
     
    
    else if (str[0] == 'P' && str[1]=='2' && str[2]=='8' && str[3]=='L')  
    {
      
      digitalWrite(relay28,LOW);    
  
      Serial.println("Pin 28 OFF");    
      
 
    }
    
    
     //////////////////////// Pin 30 (relay30) /////////////////////////////////////       
   

   
    if (str[0] == 'P' && str[1]=='3' && str[2]=='0' && str[3]=='H')  
    {
      
      digitalWrite(relay30,HIGH);   
  
      Serial.println("Pin 30 ON");   
  


    }
    
     
    
    else if (str[0] == 'P' && str[1]=='3' && str[2]=='0' && str[3]=='L')  
    {
      
      digitalWrite(relay30,LOW);    
  
      Serial.println("Pin 30 OFF");    
      

    }
    
    
     //////////////////////// Pin 31 (relay31) /////////////////////////////////////       
   

   
    if (str[0] == 'P' && str[1]=='3' && str[2]=='1' && str[3]=='H')  
    {
      
      digitalWrite(relay31,HIGH);   
  
      Serial.println("Pin 31 ON");   
  

    }
    
     
    
    else if (str[0] == 'P' && str[1]=='3' && str[2]=='1' && str[3]=='L')  
    {
      
      digitalWrite(relay31,LOW);    
  
      Serial.println("Pin 31 OFF");    
   
    }


 //////////////////////// Pin 32 (relay32) /////////////////////////////////////       
   

   
    if (str[0] == 'P' && str[1]=='3' && str[2]=='2' && str[3]=='H')  
    {
      
      digitalWrite(relay32,HIGH);   
  
      Serial.println("Pin 32 ON");   
 
    }
    
     
    
    else if (str[0] == 'P' && str[1]=='3' && str[2]=='2' && str[3]=='L')  
    {
      
      digitalWrite(relay32,LOW);    
  
      Serial.println("Pin 32 OFF");    
      
 
    }


 //////////////////////// Pin 33 (relay33) /////////////////////////////////////       
   

   
    if (str[0] == 'P' && str[1]=='3' && str[2]=='3' && str[3]=='H')  
    {
      
      digitalWrite(relay33,HIGH);   
  
      Serial.println("Pin 33 ON");   
  
  
    }
    
     
    
    else if (str[0] == 'P' && str[1]=='3' && str[2]=='3' && str[3]=='L')  
    {
      
      digitalWrite(relay33,LOW);    
  
      Serial.println("Pin 33 OFF");    
   
    }


 //////////////////////// Pin 34 (relay34) /////////////////////////////////////       
   

   
    if (str[0] == 'P' && str[1]=='3' && str[2]=='4' && str[3]=='H')  
    {
      
      digitalWrite(relay34,HIGH);   
  
      Serial.println("Pin 34 ON");   
  
    }
    
     
    
    else if (str[0] == 'P' && str[1]=='3' && str[2]=='4' && str[3]=='L')  
    {
      
      digitalWrite(relay34,LOW);    
  
      Serial.println("Pin 34 OFF");    
  
    }


//////////////////////// Pin 35 (relay35) /////////////////////////////////////       
   

   
    if (str[0] == 'P' && str[1]=='3' && str[2]=='5' && str[3]=='H')  
    {
      
      digitalWrite(relay35,HIGH);   
  
      Serial.println("Pin 35 ON");   
  
  
    }
    
     
    
    else if (str[0] == 'P' && str[1]=='3' && str[2]=='5' && str[3]=='L')  
    {
      
      digitalWrite(relay35,LOW);    
  
      Serial.println("Pin 35 OFF");    
      

    }
    
    
     //////////////////////// Pin 36 (relay36) /////////////////////////////////////       
   

   
    if (str[0] == 'P' && str[1]=='3' && str[2]=='6' && str[3]=='H')  
    {
      
      digitalWrite(relay36,HIGH);   
  
      Serial.println("Pin 36 ON");   
  
 
    }
    
     
    
    else if (str[0] == 'P' && str[1]=='3' && str[2]=='6' && str[3]=='L')  
    {
      
      digitalWrite(relay36,LOW);    
  
      Serial.println("Pin 36 OFF");    

    }


 //////////////////////// Pin 37 (relay37) /////////////////////////////////////       
   

   
    if (str[0] == 'P' && str[1]=='3' && str[2]=='7' && str[3]=='H')  
    {
      
      digitalWrite(relay37,HIGH);   
  
      Serial.println("Pin 37 ON");   
  

    }
    
     
    
    else if (str[0] == 'P' && str[1]=='3' && str[2]=='7' && str[3]=='L')  
    {
      
      digitalWrite(relay37,LOW);    
  
      Serial.println("Pin 37 OFF");    
      
   
    }


 //////////////////////// Pin 38 (relay38) /////////////////////////////////////       
   

   
    if (str[0] == 'P' && str[1]=='3' && str[2]=='8' && str[3]=='H')  
    {
      
      digitalWrite(relay38,HIGH);   
  
      Serial.println("Pin 38 ON");   


    }
    
     
    
    else if (str[0] == 'P' && str[1]=='3' && str[2]=='8' && str[3]=='L')  
    {
      
      digitalWrite(relay38,LOW);    
  
      Serial.println("Pin 38 OFF");    
  
    }


 //////////////////////// Pin 39 (relay39) /////////////////////////////////////       
   

   
    if (str[0] == 'P' && str[1]=='3' && str[2]=='9' && str[3]=='H')  
    {
      
      digitalWrite(relay39,HIGH);   
  
      Serial.println("Pin 39 ON");   
  
  

    }
    
     
    
    else if (str[0] == 'P' && str[1]=='3' && str[2]=='9' && str[3]=='L')  
    {
      
      digitalWrite(relay39,LOW);    
  
      Serial.println("Pin 39 OFF");    
  
      
    }


 //////////////////////// Pin 40 (relay40) /////////////////////////////////////       
   

   
    if (str[0] == 'P' && str[1]=='4' && str[2]=='0' && str[3]=='H')  
    {
      
      digitalWrite(relay40,HIGH);   
  
      Serial.println("Pin 40 ON");   
  
 

    }
    
     
    
    else if (str[0] == 'P' && str[1]=='4' && str[2]=='0' && str[3]=='L')  
    {
      
      digitalWrite(relay40,LOW);    
  
      Serial.println("Pin 40 OFF");    
      

    }
    
    
    //////////////////////// Pin 41 (relay41) /////////////////////////////////////       
   

   
    if (str[0] == 'P' && str[1]=='4' && str[2]=='1' && str[3]=='H')  
    {
      
      digitalWrite(relay41,HIGH);   
  
      Serial.println("Pin 41 ON");   
  


    }
    
     
    
    else if (str[0] == 'P' && str[1]=='4' && str[2]=='1' && str[3]=='L')  
    {
      
      digitalWrite(relay41,LOW);    
  
      Serial.println("Pin 41 OFF");    
      
  
    }


//////////////////////// Pin 42 (relay42) /////////////////////////////////////       
   

   
    if (str[0] == 'P' && str[1]=='4' && str[2]=='2' && str[3]=='H')  
    {
      
      digitalWrite(relay42,HIGH);   
  
      Serial.println("Pin 42 ON");   
  
   
    }
    
     
    
    else if (str[0] == 'P' && str[1]=='4' && str[2]=='2' && str[3]=='L')  
    {
      
      digitalWrite(relay42,LOW);    
  
      Serial.println("Pin 42 OFF");    
      
    
    }


//////////////////////// Pin 43 (relay43) /////////////////////////////////////       
   

   
    if (str[0] == 'P' && str[1]=='4' && str[2]=='3' && str[3]=='H')  
    {
      
      digitalWrite(relay43,HIGH);   
  
      Serial.println("Pin 43 ON");   
  

    }
    
     
    
    else if (str[0] == 'P' && str[1]=='4' && str[2]=='3' && str[3]=='L')  
    {
      
      digitalWrite(relay43,LOW);    
  
      Serial.println("Pin 43 OFF");    
    
    }


//////////////////////// Pin 44 (relay44) /////////////////////////////////////       
   
       if (str[0] == 'P' && str[1]=='4' && str[2]=='4' && str[3]=='M')  
    {

     
      analogWrite(relay44,relay44pwmVal);  
      
      Serial.println(relay44pwmVal);    //Write notification  
    

    }

   
    else if (str[0] == 'P' && str[1]=='4' && str[2]=='4' && str[3]=='H')  
    {
      
      digitalWrite(relay44,HIGH);   
  
      Serial.println("Pin 44 ON");   
  
  
  

    }
    
     
    
    else if (str[0] == 'P' && str[1]=='4' && str[2]=='4' && str[3]=='L')  
    {
      
      digitalWrite(relay44,LOW);    
  
      Serial.println("Pin 44 OFF");    
 
    }


//////////////////////// Pin 45 (relay45) /////////////////////////////////////       
       
       if (str[0] == 'P' && str[1]=='4' && str[2]=='5' && str[3]=='M')  
    {

      
      analogWrite(relay45,relay45pwmVal);  
      
      Serial.println(relay45pwmVal);    //Write notification  
    

    }

   
    else if (str[0] == 'P' && str[1]=='4' && str[2]=='5' && str[3]=='H')  
    {
      
      digitalWrite(relay45,HIGH);   
  
      Serial.println("Pin 45 ON");   
  
 
    }
    
     
    
    else if (str[0] == 'P' && str[1]=='4' && str[2]=='5' && str[3]=='L')  
    {
      
      digitalWrite(relay45,LOW);    
  
      Serial.println("Pin 45 OFF");    
 
    }
    
    
    //////////////////////// Pin 46 (relay46) /////////////////////////////////////       
      
       if (str[0] == 'P' && str[1]=='4' && str[2]=='6' && str[3]=='M')  
    {

      
      analogWrite(relay46,relay46pwmVal);
      
      Serial.println(relay46pwmVal);    //Write notification  
    

    }

   
    else if (str[0] == 'P' && str[1]=='4' && str[2]=='6' && str[3]=='H')  
    {
      
      digitalWrite(relay46,HIGH);   
  
      Serial.println("Pin 46 ON");   
  
  

    }
    
     
    
    else if (str[0] == 'P' && str[1]=='4' && str[2]=='6' && str[3]=='L')  
    {
      
      digitalWrite(relay46,LOW);    
  
      Serial.println("Pin 46 OFF");    
  
      
    }


//////////////////////// Pin 47 (relay47) /////////////////////////////////////       
   

   
    if (str[0] == 'P' && str[1]=='4' && str[2]=='7' && str[3]=='H')  
    {
      
      digitalWrite(relay47,HIGH);   
  
      Serial.println("Pin 47 ON");   

  

    }
    
     
    
    else if (str[0] == 'P' && str[1]=='4' && str[2]=='7' && str[3]=='L')  
    {
      
      digitalWrite(relay47,LOW);    
  
      Serial.println("Pin 47 OFF");    
     
      
    }


//////////////////////// Pin 48 (relay48) /////////////////////////////////////       
   

   
    if (str[0] == 'P' && str[1]=='4' && str[2]=='8' && str[3]=='H')  
    {
      
      digitalWrite(relay48,HIGH);   
  
      Serial.println("Pin 48 ON");   

     
  
  

    }
    
     
    
    else if (str[0] == 'P' && str[1]=='4' && str[2]=='8' && str[3]=='L')  
    {
      
      digitalWrite(relay48,LOW);    
  
      Serial.println("Pin 48 OFF");    
      
      
    }


//////////////////////// Pin 49 (relay49) /////////////////////////////////////       
   

   
    if (str[0] == 'P' && str[1]=='4' && str[2]=='9' && str[3]=='H')  
    {
      
      digitalWrite(relay49,HIGH);   
  
      Serial.println("Pin 49 ON");   

   

    }
    
     
    
    else if (str[0] == 'P' && str[1]=='4' && str[2]=='9' && str[3]=='L')  
    {
      
      digitalWrite(relay49,LOW);    
  
      Serial.println("Pin 49 OFF");    
     
    }

/*

//////////////////////// Pin 50 (relay50) /////////////////////////////////////       
   

   
    if (str[0] = 'P' && str[1]=='5' && str[2]=='0' && str[3]=='H')  
    {
      
      digitalWrite(relay50,HIGH);   
  
      Serial.println("Pin 50 ON");   

      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 50 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (str[0] = 'P' && str[1]=='5' && str[2]=='0' && str[3]=='L')  
    {
      
      digitalWrite(relay50,LOW);    
  
      Serial.println("Pin 50 OFF");    
      
      
      Udp.write("Pin 50 is OFF");    
      Udp.endPacket();
      
    }


//////////////////////// Pin 51 (relay51) /////////////////////////////////////       
   

   
    if (str[0] = 'P' && str[1]=='5' && str[2]=='1' && str[3]=='H')  
    {
      
      digitalWrite(relay51,HIGH);   
  
      Serial.println("Pin 51 ON");   

      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 51 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (str[0] = 'P' && str[1]=='5' && str[2]=='1' && str[3]=='L')  
    {
      
      digitalWrite(relay51,LOW);    
  
      Serial.println("Pin 51 OFF");    
      
      
      Udp.write("Pin 51 is OFF");    
      Udp.endPacket();
      
    }


//////////////////////// Pin 52 (relay52) /////////////////////////////////////       
   

   
    if (str[0] = 'P' && str[1]=='5' && str[2]=='2' && str[3]=='H')  
    {
      
      digitalWrite(relay52,HIGH);   
  
      Serial.println("Pin 52 ON");   

      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 52 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (str[0] = 'P' && str[1]=='5' && str[2]=='2' && str[3]=='L')  
    {
      
      digitalWrite(relay52,LOW);    
  
      Serial.println("Pin 52 OFF");    
      
      
      Udp.write("Pin 52 is OFF");    
      Udp.endPacket();
      
    }


//////////////////////// Pin 53 (relay53) /////////////////////////////////////       
   

   
    if (str[0] = 'P' && str[1]=='5' && str[2]=='3' && str[3]=='H')  
    {
      
      digitalWrite(relay53,HIGH);   
  
      Serial.println("Pin 53 ON");   

      Udp.beginPacket(iPhoneIP,iPhonePort);
      Udp.write("Pin 53 is ON");    
      Udp.endPacket();
  
  

    }
    
     
    
    else if (str[0] = 'P' && str[1]=='5' && str[2]=='3' && str[3]=='L')  
    {
      
      digitalWrite(relay53,LOW);    
  
      Serial.println("Pin 53 OFF");    
      
      
      Udp.write("Pin 53 is OFF");    
      Udp.endPacket();
      
    }
  
 */   

 }
 
 delay(20);
 
}  


