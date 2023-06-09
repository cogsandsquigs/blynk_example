/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/admin/Projects/blynk_example/src/blynk_example.ino"
/*
 * Project blynk_example
 * Description: Example of using Blynk with the Particle Argon.
 * Author: Ian Pratt <ianjdpratt@gmail.com>
 * Date: 2023-06-09
 */

/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

/* Fill-in information from Blynk Device Info here */
void setup();
void loop();
#line 15 "/Users/admin/Projects/blynk_example/src/blynk_example.ino"
#define BLYNK_TEMPLATE_ID "TMPL2wCM6kDSb"
#define BLYNK_TEMPLATE_NAME "Blynk Example Template"
// BLYNK_AUTH_TOKEN is loaded from "src/env.h"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include "env.h"
#include <blynk.h>

volatile int r = 0;
volatile int g = 0;
volatile int b = 0;

// This function is called every time the Virtual Pin 0 (onboard blue LED) changes state
BLYNK_WRITE(V0) // onboard blue LED assigned to V0
{
	// get a LED state
	int ledState = param.asInt();

	// turn the LED on
	if (ledState == 1)
	{
		digitalWrite(D7, HIGH);
	}
	// turn the LED off
	else
	{
		digitalWrite(D7, LOW);
	}
}

// This function is called every time the Virtual Pin 1 (zeRGBa red) changes state
BLYNK_WRITE(V1) // zeRGBa assigned to V1
{
	// get a RED channel value
	r = param.asInt();

	// set the color of the LED
	RGB.color(r, g, b);
}

// This function is called every time the Virtual Pin 2 (zeRGBa green) changes state
BLYNK_WRITE(V2) // zeRGBa assigned to V2
{
	// get a GREEN channel value
	g = param.asInt();

	// set the color of the LED
	RGB.color(r, g, b);
}

// This function is called every time the Virtual Pin 3 (zeRGBa blue) changes state
BLYNK_WRITE(V3) // zeRGBa assigned to V3
{
	// get a BLUE channel value
	b = param.asInt();

	// set the color of the LED
	RGB.color(r, g, b);
}

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
}

void setup()
{
	// Debug console
	Serial.begin(9600);

	// take control of the LED
	RGB.control(true);

	// Let the onboard LED turn on and off
	pinMode(D7, OUTPUT);

	// Allow board to settle
	delay(1000);

	Blynk.begin(BLYNK_AUTH_TOKEN);
}

void loop()
{
	Blynk.run();
	// You can inject your own code or combine it with other sketches.
	// Check other examples on how to communicate with Blynk. Remember
	// to avoid delay() function!
}
