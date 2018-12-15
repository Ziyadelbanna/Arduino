/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 13;

IRrecv irrecv(RECV_PIN);

decode_results results;

int sum = 0;
bool add_flag = false;
bool sub_flag = false;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {

    if(results.value != 4294967295){
    
      if(results.value == 551487735){
        if(add_flag == true){
          sum = sum + 0;
          add_flag = false;
        }
        else if(sub_flag == true){
          sum = sum - 0;
          sub_flag = false;
        }
        else{
          sum = 0;
        }
      }
  
      if(results.value == 551520375){
        if(add_flag == true){
          sum = sum + 1;
          add_flag = false;
        }
        else if(sub_flag == true){
          sum = sum - 1;
          sub_flag = false;
        }
        else{
          sum = 1;
        }
      }
  
      if(results.value == 551504055){
        if(add_flag == true){
          sum = sum + 2;
          add_flag = false;
        }
        else if(sub_flag == true){
          sum = sum - 2;
          sub_flag = false;
        }
        else{
          sum = 2;
        }
      }
  
      if(results.value == 551536695){
        if(add_flag == true){
          sum = sum + 3;
          add_flag = false;
        }
        else if(sub_flag == true){
          sum = sum - 3;
          sub_flag = false;
        }
        else{
          sum = 3;
        }
      }
  
      if(results.value == 551495895){
        if(add_flag == true){
          sum = sum + 4;
          add_flag = false;
        }
        else if(sub_flag == true){
          sum = sum - 4;
          sub_flag = false;
        }
        else{
          sum = 4;
        }
      }
  
      if(results.value == 551528535){
        if(add_flag == true){
          sum = sum + 5;
          add_flag = false;
        }
        else if(sub_flag == true){
          sum = sum - 5;
          sub_flag = false;
        }
        else{
          sum = 5;
        }
      }
  
      if(results.value == 551512215){
        if(add_flag == true){
          sum = sum + 6;
          add_flag = false;
        }
        else if(sub_flag == true){
          sum = sum - 6;
          sub_flag = false;
        }
        else{
          sum = 6;
        }
      }
  
      if(results.value == 551544855){
        if(add_flag == true){
          sum = sum + 7;
          add_flag = false;
        }
        else if(sub_flag == true){
          sum = sum - 7;
          sub_flag = false;
        }
        else{
          sum = 7;
        }
      }
  
      if(results.value == 551491815){
        if(add_flag == true){
          sum = sum + 8;
          add_flag = false;
        }
        else if(sub_flag == true){
          sum = sum - 8;
          sub_flag = false;
        }
        else{
          sum = 8;
        }
      }
  
      if(results.value == 551524455){
        if(add_flag == true){
          sum = sum + 9;
          add_flag = false;
        }
        else if(sub_flag == true){
          sum = sum - 9;
          sub_flag = false;
        }
        else{
          sum = 9;
        }
      }
  
      if(results.value == 551502015){
          add_flag = true;
          Serial.println("+");
      }else if(results.value == 551534655){
          sub_flag = true;
          Serial.println("-");
      }else{
          Serial.print("Answer = " );
          Serial.println(sum );
      }
    }
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
