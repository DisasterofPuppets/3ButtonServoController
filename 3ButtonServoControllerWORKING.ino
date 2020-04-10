/*
Disaster of Puppets is owning up to writing this trash
I'm sure it can be done a lot easier but eh, it works.
Twitch.tv/disasterofpuppets PCA6985 controller board
*/

#include <FastLED.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN 125
#define SERVOMAX 620
// 125/620 for the 9g 
//125/610 for HobbyKing™ High Torque Servo MG/BB W/Proof 12.8kg / 0.22sec / 58g


#define LED_PIN 12
#define NUM_LEDS 3
#define COLOR_ORDER GRB
#define BRIGHTNESS 50

CRGB leds[NUM_LEDS];

const int zeroPin = 2;
const int ninetyPin = 4;
const int oneeightyPin = 6;

int zButton;
int nButton;
int oButton;


void setup() 

{

pwm.begin();

pwm.setPWMFreq(60); 



FastLED.addLeds<WS2812, LED_PIN, COLOR_ORDER>(leds,NUM_LEDS).setCorrection( TypicalLEDStrip );
FastLED.setBrightness(BRIGHTNESS);

 
    pinMode(zeroPin,INPUT_PULLUP);
    pinMode(ninetyPin,INPUT_PULLUP);
    pinMode(oneeightyPin,INPUT_PULLUP);

    FastLED.clear();
    
    Serial.begin(9600);

}


void loop() 
  {
    FastLED.clear();
    
    zButton = digitalRead(zeroPin);
    Serial.println(digitalRead(zeroPin));
    delay(200);
    
    nButton = digitalRead(ninetyPin);
    
    oButton = digitalRead(oneeightyPin);

//if button one is pressed do this

if (zButton == 0)
    {
      FastLED.clear();
      for (int i = 0; i < 17; i++)
        {
          pwm.setPWM(i, 0, angleToPulse(0) );
        }
          delay(15);
          leds[0] = CRGB::Blue;
          FastLED.show();
    }

if (nButton == 0)
    { 
      FastLED.clear();
      for (int i = 0; i < 17; i++)
        {
          pwm.setPWM(i, 0, angleToPulse(90) );
        }
      delay(15);
      leds[1] = CRGB::Blue;
      FastLED.show();
      
    }

if (oButton == 0)
    { 
      
      FastLED.clear();
            for (int i = 0; i < 17; i++)
                  {
                    pwm.setPWM(i, 0, angleToPulse(180) );
                  }
      delay(15);
      leds[2] = CRGB::Blue;
      FastLED.show();
    }
 
}

int angleToPulse(int ang) 
{
  int pulse = map(ang,0,180, SERVOMIN,SERVOMAX);
  return pulse;
}
