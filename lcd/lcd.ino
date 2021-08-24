#include <StateMachine.h>
#include <LiquidCrystal.h>

const int grayButton = 5, acceptButton = 6;
int grayInput = 0, acceptInput = 0;

const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int initialState = 0;

StateMachine machine = StateMachine();

State* S0 = machine.addState(&state0);
State* S1 = machine.addState(&state1);

void setup() {
  lcd.begin(16, 2);
  pinMode(grayButton, INPUT_PULLUP);
  pinMode(acceptButton, INPUT_PULLUP);
  S0->addTransition(&transitionS0S1, S1);

  Serial.begin(9600);
}

void loop() {
  delay(1000);
  machine.run();
}

//--------------------------------- State Actions ------------------------------

void state0(){
   lcd.clear();
   grayInput = digitalRead(grayButton);
   Serial.print(grayInput);
   lcd.print("state 0");
   lcd.print(grayInput);
}

void state1(){
  lcd.clear();
  lcd.print("state 1");
}

//--------------------------------- State Transitions -------------------------

bool transitionS0S1(){
  return false;
}
