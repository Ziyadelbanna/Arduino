    int buzzer = 13;
    int control = A0;
    float val=0;
     
    void setup() {
      Serial.begin(9600);
      pinMode (buzzer, OUTPUT);
    }
     
    void loop () {
       val = analogRead(control)*(5.0/1023.0);  
       Serial.println(val);
       if(val>=3.0){
       digitalWrite(buzzer, HIGH);     
       delay(10);
       }
       if(val<=2.5){
      digitalWrite(buzzer, LOW); 
      delay(10);    
       }                
     
    }
