#include "Keypad.h"
/**
 * Keypad library can be found at
 * https://playground.arduino.cc/Code/Keypad/#Download
 * 
 * Save it under Arduino/libraries folder.
 */
const byte ROWS = 4; //number of rows on membrane switch
const byte COLUMNS = 4; //number of columns on membrane switch
char keys[ROWS][COLUMNS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9,8,7,6}; //D9 - D6
byte colPins[COLUMNS] = {5,4,3,2}; // D5 - D2

Keypad membrane = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLUMNS);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = membrane.getKey();
  if (key != NO_KEY) {
    Serial.println(key);
  }
}
