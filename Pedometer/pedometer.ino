
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"


int16_t ax, ay, az;


#define LED_PIN 13
bool blinkState = false;
MPU6050 accelgyro;

int i=0;
int ix=0;
int iy=0;
int iz=0;
int samplecount = 0;
bool inPhase1 = true;
int minx;
int miny;
int minz;
int maxx;
int maxy;
int maxz;
int gmax;
int gmid;
int gmin;
int axis = -1;  //0 for x, 1 for y, 2 for z
int old_register;
int new_register;
int new_sample;
int samplesFromLastStep;
const int LIMIT = 200;
int stepCounts = 0;

void setup() {

    Wire.begin();    
    Serial.begin(9600);
    Serial.println("Initializing I2C devices...");
    
    accelgyro.initialize();
    
    // verify connection
    Serial.println("Testing device connections...");
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");

    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    accelgyro.getAcceleration(&ax, &ay, &az);
    ax -= 2000;
    ay -= -290;
    az -= 16000;
    ix += ax;
    iy += ay;
    iz += az;
    if(i==3){
      i = 0;
      ix /= 4;
      iy /= 4;
      iz /= 4;
      // Todo
      samplecount++;
      samplesFromLastStep++;
      if(inPhase1) {
        if(samplecount == 1) {
          minx = maxx = ix;
          miny = maxy = iy;
          minz = maxz = iz;
        }
        else if(samplecount < 200) {
          if(ix < minx)
            minx = ix;
          if(ix > maxx)
            maxx = ix;
          if(iy < miny)
            miny = iy;
          if(iy > maxy)
            maxy = iy;
          if(iz < minz)
            minz = iz;
          if(iz > maxz)
            maxz = iz;          
        }
        else {
          samplecount = 0;
          inPhase1 = false;
          axis = 0;
          if((maxy-miny) > (maxx-minx)) {
            if((maxz-minz) > (maxy-miny))
              axis = 2;
            else
              axis = 1;
          }
          else if((maxz-minz) > (maxx-minx))
            axis = 2;
          if(axis == 0) {
            gmin = minx;
            gmax = maxx;
          } else if (axis == 1) {
            gmin = miny;
            gmax = maxy;
          } else {
            gmin = minz;
            gmax = maxz;
          }
          gmid = (gmax+gmin)/2;
          if(axis ==0)
            new_sample = ix;
          else if(axis == 1)
            new_sample = iy;
          else
            new_sample = iz;
          old_register = new_sample;
          new_register = new_sample;
          samplesFromLastStep = 0;
          Serial.print("Phase 1 Ended, Axis Chosen = ");
          Serial.println(axis);
        }
      } else { // In Phase 2
        /*
        if(samplecount < 50) {
          if(ix < minx)
            minx = ix;
          if(ix > maxx)
            maxx = ix;
          if(iy < miny)
            miny = iy;
          if(iy > maxy)
            maxy = iy;
          if(iz < minz)
            minz = iz;
          if(iz > maxz)
            maxz = iz;          
        }
        else {
          samplecount = 0;
          if(axis == 0) {
            gmin = minx;
            gmax = maxx;
          } else if (axis == 1) {
            gmin = miny;
            gmax = maxy;
          } else {
            gmin = minz;
            gmax = maxz;
          }
          gmid = (gmax+gmin)/2;
        }*/
        // New Sample is readed
        if(axis == 0)
          new_sample = ix;
        else if(axis == 1)
          new_sample = iy;
        else
          new_sample = iz;
        // Update Registers
        old_register = new_register;
        if(abs(new_sample - new_register) > LIMIT)
          new_register = new_sample;
        if(new_register < gmid && gmid < old_register) {
          Serial.print("Step is Made, samplesFromLastStep = ");
          Serial.println(samplesFromLastStep);
          if(samplesFromLastStep >= 25 && samplesFromLastStep <= 100) {
            Serial.print("New Step, Step Counts = ");
            Serial.println(++stepCounts);
          }
          samplesFromLastStep = 0;
        }
        
      }
      ///End here
      ix=0;
      iy=0;
      iz=0;
    }
    i++;
    delay(5);
//
//    // blink LED to indicate activity
//    blinkState = !blinkState;
//    digitalWrite(LED_PIN, blinkState);
}
