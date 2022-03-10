// OUPS - Main script


// DISPLAY DIGITAL PINS
// 2   3   4   5   6   7
// D1  A   F   D2  D3   B
// E   D   P   C   G    D4
// 8   9   10  11  12   13

const char DISPLAY_D1 = 2;
const char DISPLAY_D2 = 5;
const char DISPLAY_D3 = 6;
const char DISPLAY_D4 = 13;
const char DISPLAY_A = 3;
const char DISPLAY_B = 7;
const char DISPLAY_C = 11;
const char DISPLAY_D = 9;
const char DISPLAY_E = 8;
const char DISPLAY_F = 4;
const char DISPLAY_G = 12;
const char DISPLAY_P = 10;


// OTHER DIGITAL PINS
//const char FREE_PIN = 0;
const char BUZZER = 1;


// ANALOG INPUT
const char WIRE = A0;
const char START = A1;
const char END = A2;
int ANALOG_INPUT_THRESHOLD = 20;

// TIME
const int DELAY_DISPLAY = 55; //ms

// STATES
const int IDLE=0;
const int PLAYING=1;
const int WIN=2;
const int LOOSE=3;

// GLOBALS
int currentState;
unsigned long stateTimer;
unsigned long lastTimer;
unsigned long lastSetStateTime;


void setState(int state){
  currentState = state;
  lastSetStateTime = millis();
  lastTimer = stateTimer;
  stateTimer = 0;
}


void setup() {

  // PIN SETUP
  pinMode(DISPLAY_D1, OUTPUT);
  pinMode(DISPLAY_D2, OUTPUT);
  pinMode(DISPLAY_D3, OUTPUT);
  pinMode(DISPLAY_D4, OUTPUT);
  pinMode(DISPLAY_A, OUTPUT);
  pinMode(DISPLAY_B, OUTPUT);
  pinMode(DISPLAY_C, OUTPUT);
  pinMode(DISPLAY_D, OUTPUT);
  pinMode(DISPLAY_E, OUTPUT);
  pinMode(DISPLAY_F, OUTPUT);
  pinMode(DISPLAY_G, OUTPUT);
  pinMode(DISPLAY_P, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  // GLOBALS INIT
  stateTimer = 0;
  lastTimer = 0;
  setState(IDLE);

  //Serial.begin(9600);
  //Serial.println("---------------------- OUPS ----------------------");
}

bool wired(char pin){
  return analogRead(pin) > ANALOG_INPUT_THRESHOLD;
}

void loop() {
  // TIMER
  stateTimer = millis()-lastSetStateTime;
  stateMachine();

  // DEBUG
  //dispOups();
  //char debug[60];
  //sprintf(debug, "stateTimer:%d  state:%d  wire:%d  start:%d  stop:%d",
  //stateTimer/1000, currentState, wired(WIRE), wired(START), wired(END));
  //Serial.println(debug);
}

void stateMachine(){
  switch(currentState)
  {
    case IDLE:
      if(wired(START)){
        setState(PLAYING);
      }
      else {
        silence();
        dispWaiting();
      }
    break;

    case PLAYING:
      if(wired(START)){
        setState(PLAYING);
      }
      else if(wired(WIRE) || stateTimer >= 100000){ //100 sec
        setState(LOOSE);
      }
      else if(wired(END)){
        setState(WIN);
      }
      else {
        silence();
        dispInt(stateTimer/1000);
      }
    break;

    case WIN:
      if(wired(START)){
        setState(PLAYING);
      }
      else {
        bool meloPlaying = playMeloHappy();
        if(meloPlaying){
          dispTime(lastTimer);
        }
        else{
          if(stateTimer%1000>300){
            if(stateTimer%2000>1000){
              dispTime(lastTimer);
            }
            else{
              dispRank(lastTimer);
            }
          }
        }
      }
    break;

    case LOOSE:
      if(wired(START)){
        setState(PLAYING);
      }
      else {
        if(playMeloSad()){
          dispOups();
        }
        else{
          setState(IDLE);
        }
      }
    break;
  }
}
