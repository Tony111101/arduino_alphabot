#include <IRremote.h>
#include "AlphaBot.h"
AlphaBot Car1 = AlphaBot();

const int RECV_PIN =4;
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  Car1.SetSpeed(90);
}

void loop(){
  if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);
        irrecv.resume();
  } 
  if (results.value==0xA55A01FE)
     {Car1.Forward(1000);
      Car1.Brake();
  } 

  else if (results.value==0xA55A817E)
    {Car1.Backward(1000);
      Car1.Brake();      
  }
  
  else if (results.value==0xA55AC13E)
    {Car1.Left(1000);      
      Car1.Brake();      
  }
  
  else if (results.value==0xA55A41BE)
    {Car1.Right(1000);      
      Car1.Brake();      
  }
  
  else if (results.value==0xA55A21DE)      
    {Car1.Brake();      
  }
  
  else if (results.value==0xA55A50AF)      
    {Car1.SetSpeed(90+20);
  }
        
  else if (results.value==0xA55AD02F)  
      {Car1.SetSpeed(90-20);
  }
}
  
