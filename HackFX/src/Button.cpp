#include "Button.h"

uint8_t Button::getId(){
  return id;
}

void Button::setState(uint8_t st){
  if(st != last_debounce_state){
    lastDebounceTime = millis();
  }

  if((millis() - lastDebounceTime) > debounceDelay){
      last_state = state;
      state = st;
  }
  last_debounce_state = st;
}

uint8_t Button::getState(){
  return state;
}

uint8_t Button::changed(){
  if(state != last_state)
    return 1;
  else
    return 0;
}
