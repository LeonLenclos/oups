// OUPS - Buzzer

void silence(){
   noTone(BUZZER);
}

void playNote(int note){
  tone (BUZZER, note);
}


void playMeloSad(){
  int step = stateTimer/3000;
  if     (step<4) {playNote(415);}
  else if(step<5) {playNote(392);}
  else if(step<6) {playNote(370);}
  else if(step<7) {playNote(349);}
  else {silence();}
}


void playMeloHappy(){
  int step = stateTimer/3000;
  if     (step<1) {playNote(440);}
  else if(step<2) {playNote(523);}
  else if(step<4) {playNote(659);}
  else {silence();}
}
