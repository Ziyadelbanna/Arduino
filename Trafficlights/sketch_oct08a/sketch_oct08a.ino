    int redLed = 4;
    int greenLed = 7;
    int pushBtn = 12;
    int ledstate = 0;
    long prest = 0;
    long interval = 5000;
     
    void setup() {
      Serial.begin(9600);
      pinMode (redLed, OUTPUT);
      pinMode (greenLed, OUTPUT);
      pinMode (pushBtn, OUTPUT);
     
    }
     
    void loop () {
      unsigned long  curset = millis();
      if ( curset - prest >= interval ) {
        prest = curset;
        if (ledstate == 0 ) {
          ledstate = 1;
          digitalWrite(redLed, LOW);
          digitalWrite(greenLed, HIGH);
        } else {
          ledstate = 0 ;
          digitalWrite(greenLed, LOW);
          digitalWrite(redLed, HIGH);
        }
      }
      if (digitalRead(pushBtn) == HIGH) {
        delay(100);
        Serial.write("HighFirst\n");
        if (digitalRead(pushBtn) == HIGH) {
          Serial.write("HighLast\n");
          if (ledstate == 0 ) {
            Serial.write("Inv\n");
            ledstate = 1;
            digitalWrite(redLed, LOW);
            digitalWrite(greenLed, HIGH);
          } else {
            Serial.write("Inv1\n");
            ledstate = 0 ;
            digitalWrite(greenLed, LOW);
            digitalWrite(redLed, HIGH);
          }
        }
      }
    }
