
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
     uint32_t entrada[5] = {0x48, 0x45, 0x4c, 0x4c, 0x4f};
     // converte hexadecimais em String
     char *saida =  convert(entrada, 5);
  
    // as per comment from LS_dev, platform is int 16bits
    Serial.begin(9600);
    Serial.println(saida);
    
     // vamos quebrar a String saida 
     char *pos = saida;
     // declara as variaveis que eu quero quebrar
     char string1[4] = {0}; // 3 caractes
     char string2[3] = {0}; // 2 caracteres 
     // ... declara outra strings...

     // copia primeira variavel String
     strncpy ( string1, pos, 3 );
     // atualiza posicao
     pos+=3;
     // copia 2a string
     strncpy ( string2, pos, 2 );
     *pos+=2;
      
     Serial.println(string1);
     Serial.println(string2);

    //digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    //delay(1000);              // wait for a second
    //digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);              // wait for a second
}



char* convert(uint32_t example[], int size) {
  int i=0;
  char stringBuffer[size*4]; // Needs to be more than big enough to hold all the digits of an int
  char *outputStrings = (char *) malloc(sizeof(char) * (size+1));

  for (i = 0 ; i < size ; i++)
  {
    snprintf(stringBuffer, (size*4), "%c", example[i]);
    outputStrings[i] = *stringBuffer;
  }
  outputStrings[(size)]=0;
  return outputStrings;
}

