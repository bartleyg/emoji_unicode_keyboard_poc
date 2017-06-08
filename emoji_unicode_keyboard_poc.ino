/* Simple USB Emoji Keyboard POC
   Teensy becomes a USB keyboard and types characters
   You must select Keyboard from the "Tools > USB Type" menu
   
   Arduino microcontroller: Sparkfun Pro Micro 5V
   Mac OS X keyboard input set to: Unicode Keyboard

   Proof of concept that sends a few emojis as keyboard input to the Mac on switch press.
*/

#include <Bounce2.h>

Bounce button0 = Bounce();
Bounce button1 = Bounce();

const int LED = 17;

void setup() {
  pinMode(LED, OUTPUT);  // Set LED as an output
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  button0 .attach(8); button0 .interval(10);
  button1 .attach(9); button1 .interval(10);
  Keyboard.begin();
  delay(1000);
}

void loop() {
  button0.update();
  button1.update();

  /* if button pressed */
  
  if (button0.fell()) {
    //😉 = U+1F609 = Opt + D83D DE09
    Keyboard.press(KEY_RIGHT_ALT);
    Keyboard.press('d');Keyboard.release('d');Keyboard.press('8');Keyboard.release('8');
    Keyboard.press('3');Keyboard.release('3');Keyboard.press('d');Keyboard.release('d');
    Keyboard.press('d');Keyboard.release('d');Keyboard.press('e');Keyboard.release('e');
    Keyboard.press('0');Keyboard.release('0');Keyboard.press('9');Keyboard.release('9');
    Keyboard.release(KEY_RIGHT_ALT);
  }
/* optimal 
    Keyboard.press('d');Keyboard.release('d');Keyboard.press('8');
    Keyboard.press('3');Keyboard.press('d');Keyboard.release('d');
    Keyboard.press('d');Keyboard.press('e');
    Keyboard.press('0');Keyboard.press('9');
    Keyboard.releaseAll();
*/
  
  if (button1.fell()) {
    //👐🏾 = D83D DC50 + D83C DFFE 
    Keyboard.press(KEY_RIGHT_ALT);
    Keyboard.press('d');Keyboard.release('d');Keyboard.press('8');Keyboard.release('8');
    Keyboard.press('3');Keyboard.release('3');Keyboard.press('d');Keyboard.release('d');
    Keyboard.press('d');Keyboard.release('d');Keyboard.press('c');Keyboard.release('c');
    Keyboard.press('5');Keyboard.release('5');Keyboard.press('0');Keyboard.release('0');
    Keyboard.press('d');Keyboard.release('d');Keyboard.press('8');Keyboard.release('8');
    Keyboard.press('3');Keyboard.release('3');Keyboard.press('c');Keyboard.release('c');
    Keyboard.press('d');Keyboard.release('d');Keyboard.press('f');Keyboard.release('f');
    Keyboard.press('f');Keyboard.release('f');Keyboard.press('e');Keyboard.release('e');
    Keyboard.release(KEY_RIGHT_ALT);
  }
/*  
  if (button2.fallingEdge()) {
    //U+2764
    Keyboard.press(KEY_RIGHT_ALT);
    Keyboard.press('2');Keyboard.release('2');Keyboard.press('7');Keyboard.release('7');
    Keyboard.press('6');Keyboard.release('6');Keyboard.press('4');Keyboard.release('4');
    Keyboard.release(KEY_RIGHT_ALT);    
    /* //⚡ = U+26A1
    Keyboard.press(KEY_RIGHT_ALT);
    Keyboard.press('2');Keyboard.release('2');Keyboard.press('6');Keyboard.release('6');
    Keyboard.press('a');Keyboard.release('a');Keyboard.press('1');Keyboard.release('1');
    Keyboard.release(KEY_RIGHT_ALT);
    */
  //}
/*
  if (button3.fallingEdge()) {
    //🇹🇬= TG = Opt + D83C DDF9 + D83C DDEC
    Keyboard.press(KEY_RIGHT_ALT);
    Keyboard.press('d');Keyboard.release('d');Keyboard.press('8');Keyboard.release('8');
    Keyboard.press('3');Keyboard.release('3');Keyboard.press('c');Keyboard.release('c');
    Keyboard.press('d');Keyboard.release('d');Keyboard.press('d');Keyboard.release('d');
    Keyboard.press('f');Keyboard.release('f');Keyboard.press('9');Keyboard.release('9');
    Keyboard.press('d');Keyboard.release('d');Keyboard.press('8');Keyboard.release('8');
    Keyboard.press('3');Keyboard.release('3');Keyboard.press('c');Keyboard.release('c');
    Keyboard.press('d');Keyboard.release('d');Keyboard.press('d');Keyboard.release('d');
    Keyboard.press('e');Keyboard.release('e');Keyboard.press('c');Keyboard.release('c');
    Keyboard.release(KEY_RIGHT_ALT);
  }
*/
}
