
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  int i=0;
     uint32_t example[5] = {0x48, 0x45, 0x4c, 0x4c, 0x4f};
     char stringBuffer[30]; // Needs to be more than big enough to hold all the digits of an int
     char outputStrings[6];

  for (i = 0 ; i < 5 ; i++)
  {
    snprintf(stringBuffer, 20, "%c", example[i]);
    outputStrings[i] = *stringBuffer;
  }
  outputStrings[5]=0;

  
   // as per comment from LS_dev, platform is int 16bits
   Serial.begin(9600);
    Serial.println(outputStrings);
   
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
