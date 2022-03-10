// OUPS - Buzzer

void silence(){
  noTone(BUZZER);
}

void playNote(int note){
  tone (BUZZER, note);
}


// Return true if melo is playing
bool playMeloSad(){
  int step = stateTimer/3000;
  if(step<4) {
    playNote(415);
    return true;
  }
  if(step<5) {
    playNote(392);
    return true;
  }
  if(step<6) {
    playNote(370);
    return true;
  }
  if(step<7) {
    playNote(349);
    return true;
  }
  silence();
  return false;
}


// Return true if melo is playing
bool playMeloHappy(){
  bool step = stateTimer/3000;
  if(step<1) {
    playNote(440);
    return true;
  }
  if(step<2) {
    playNote(523);
    return true;
  }
  if(step<4) {
    playNote(659);
    return true;
  }
  silence();
  return false;
}
