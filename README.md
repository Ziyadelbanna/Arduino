# Arduino projects

>_The goal is to have a solid knowledge of hardware coding and to deal with electronic devices such as Arduino development board through providing code to the kit and tracking your code impact on it_

### Translate string to morse code
**How to use the program**
* Use the serial monitor to input your message
* Connect your arduino kit and use Leds and high volume buzzer for a better view
* After you have connected your kit, Press Enter.

### Remote control with IR receiver
>_Every remote control has its own IR code so to know your remote control copy the following code to your Arduino IDE_

The first step is to connect your IR reciever.

To connect a breakout board mounted IR receiver, hook it up to the Arduino like this:
![Breakout mounter IR receiver](https://github.com/ziyadelbanna/Arduino/blob/master/IR/Arduino-IR-Remote-Receiver-Stand-Alone-IR-Receiver-Wiring-Diagram.png)

And to connect a stand-alone receiver diode, wire it like this:

![Stand alone receiver diode](https://github.com/ziyadelbanna/Arduino/blob/master/IR/To%20connect%20a%20stand-alone%20receiver%20diode%2C%20wire%20it%20like%20this:)


Then, copy the following code into your Arduino IDE.

```
#include <IRremote.h>
const int RECV_PIN = 7; //Your default output pin
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop(){
  if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);
        irrecv.resume();
  }
}
```
Now press each key on your remote and record the hexadecimal code printed for each key press.

Write down the value of each key and save it.

Finally, use each key in your remote control to do a specific function, By following my code you will figure out that I used my remote control to perform the function of a calculator.
