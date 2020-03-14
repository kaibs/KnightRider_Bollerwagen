#include "FastLED.h"


#define NUM_LEDS 19

CRGB leds[NUM_LEDS];


#define DATA_PIN 2

#define CLOCK_PIN 4

#define MAX_BRIGHTNESS 255

void setup()
{
	
FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);

}

void loop(){
  
  cylon(CRGB::Red, 60, 5000);
  }

//Cylon - LED sweeps back and forth, with the color, delay and number of cycles of your choice 
void cylon(CRGB color, uint16_t wait, uint8_t number_of_cycles)
{
	//FastLED.setBrightness(255);
	for (uint8_t times = 0; times<=number_of_cycles; times++)
	{
		// Make it look like one LED is moving in one direction
		for(int led_number = 2; led_number < NUM_LEDS-3; led_number++)
		{
			//Apply the color that was passed into the function
			leds[led_number].r = 255;
                        //leds[led_number] = color;
                        leds[led_number+1].r = 80;
                        leds[led_number+2].r = 5;
                        //leds[led_number+1, 120] = color;
                        leds[led_number-1].r = 80;
                        leds[led_number-2].r = 5;
                        
			//Actually turn on the LED we just set
			FastLED.show();
			// Turn it back off
			leds[led_number] = CRGB::Black;
                        leds[led_number+1] = CRGB::Black;
                        leds[led_number-1] = CRGB::Black;
                        leds[led_number+2] = CRGB::Black;
                        leds[led_number-2] = CRGB::Black;
			// Pause before "going" to next LED
			delay(wait);
		}

		// Now "move" the LED the other direction
		for(int led_number = NUM_LEDS-3; led_number >= 2; led_number--)
		{
			//Apply the color that was passed into the function
			leds[led_number].r = 255;
                        //leds[led_number] = color;
                        leds[led_number+1].r = 80;
                        leds[led_number+2].r = 5;
                        //leds[led_number+1, 120] = color;
                        leds[led_number-1].r = 80;
                        leds[led_number-2].r = 5;
                        //leds[led_number-1, 120] = color;
                        
			//Actually turn on the LED we just set
			FastLED.show();
			// Turn it back off
			leds[led_number] = CRGB::Black;
                        leds[led_number+1] = CRGB::Black;
                        leds[led_number-1] = CRGB::Black;
                        leds[led_number+2] = CRGB::Black;
                        leds[led_number-2] = CRGB::Black;
			// Pause before "going" to next LED
			delay(wait);
		}
	}
	return;
}




