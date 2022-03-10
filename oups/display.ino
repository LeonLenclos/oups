// OUPS - Display

void pickDigit(int x)
{
  digitalWrite(DISPLAY_D1, HIGH);
  digitalWrite(DISPLAY_D2, HIGH);
  digitalWrite(DISPLAY_D3, HIGH);
  digitalWrite(DISPLAY_D4, HIGH);
  digitalWrite(DISPLAY_A, LOW);
  digitalWrite(DISPLAY_B, LOW);
  digitalWrite(DISPLAY_C, LOW);
  digitalWrite(DISPLAY_D, LOW);
  digitalWrite(DISPLAY_E, LOW);
  digitalWrite(DISPLAY_F, LOW);
  digitalWrite(DISPLAY_G, LOW);
  digitalWrite(DISPLAY_P, LOW);

  switch(x){
    case 0:
    digitalWrite(DISPLAY_D1, LOW);
    break;
    case 1:
    digitalWrite(DISPLAY_D2, LOW);
    break;
    case 2:
    digitalWrite(DISPLAY_D3, LOW);
    break;
    case 3:
    digitalWrite(DISPLAY_D4, LOW);
    break;
  }
}

void dispCharAt(char c, int i){
      pickDigit(i);
      dispChar(c);
      delayMicroseconds(DELAY_DISPLAY);
}

void dispInt(int n){
  char timer[4];
  sprintf(timer, "%04d", n);
  for (int i = 0; i < 4; i = i + 1) {
      dispCharAt(timer[i], i);
  }
}

void dispOups(){
     dispCharAt('0', 0);
     dispCharAt('U', 1);
     dispCharAt('P', 2);
     dispCharAt('S', 3);
}

void dispWaiting(){
   int cycle = (stateTimer/1000)%4;
   for (int i = 0; i < 4; i = i + 1) {
      if(cycle >= i && cycle < i+1){
            dispCharAt('.', i);
      }
      else {
           dispCharAt(' ', i);

      }
    }
}

void clearDisplay(){
  for (int i = 0; i < 4; i = i + 1) {
     dispCharAt(' ', i);
  }
}

void dispChar(char c){
  // afficher le point n'efface rien. Tous les autres cas effacent le point
  //    A
  //  F   B
  //    G
  //  E   C
  //    D    P
  switch(c){
    case '.':
    digitalWrite(DISPLAY_P, HIGH);
    break;
    case ' ':
    digitalWrite(DISPLAY_A, LOW);
    digitalWrite(DISPLAY_B, LOW);
    digitalWrite(DISPLAY_C, LOW);
    digitalWrite(DISPLAY_D, LOW);
    digitalWrite(DISPLAY_E, LOW);
    digitalWrite(DISPLAY_F, LOW);
    digitalWrite(DISPLAY_G, LOW);
    digitalWrite(DISPLAY_P, LOW);
    break;
    case '0':
    digitalWrite(DISPLAY_A, HIGH);
    digitalWrite(DISPLAY_B, HIGH);
    digitalWrite(DISPLAY_C, HIGH);
    digitalWrite(DISPLAY_D, HIGH);
    digitalWrite(DISPLAY_E, HIGH);
    digitalWrite(DISPLAY_F, HIGH);
    digitalWrite(DISPLAY_G, LOW);
    digitalWrite(DISPLAY_P, LOW);
    break;
    case 'U':
    digitalWrite(DISPLAY_A, LOW);
    digitalWrite(DISPLAY_B, HIGH);
    digitalWrite(DISPLAY_C, HIGH);
    digitalWrite(DISPLAY_D, HIGH);
    digitalWrite(DISPLAY_E, HIGH);
    digitalWrite(DISPLAY_F, HIGH);
    digitalWrite(DISPLAY_G, LOW);
    digitalWrite(DISPLAY_P, LOW);
    break;
    case 'P':
    digitalWrite(DISPLAY_A, HIGH);
    digitalWrite(DISPLAY_B, HIGH);
    digitalWrite(DISPLAY_C, LOW);
    digitalWrite(DISPLAY_D, LOW);
    digitalWrite(DISPLAY_E, HIGH);
    digitalWrite(DISPLAY_F, HIGH);
    digitalWrite(DISPLAY_G, HIGH);
    digitalWrite(DISPLAY_P, LOW);
    break;
    case 'S':
    digitalWrite(DISPLAY_A, HIGH);
    digitalWrite(DISPLAY_B, LOW);
    digitalWrite(DISPLAY_C, HIGH);
    digitalWrite(DISPLAY_D, HIGH);
    digitalWrite(DISPLAY_E, LOW);
    digitalWrite(DISPLAY_F, HIGH);
    digitalWrite(DISPLAY_G, HIGH);
    digitalWrite(DISPLAY_P, LOW);
    break;
    case '1':
    digitalWrite(DISPLAY_A, LOW);
    digitalWrite(DISPLAY_B, HIGH);
    digitalWrite(DISPLAY_C, HIGH);
    digitalWrite(DISPLAY_D, LOW);
    digitalWrite(DISPLAY_E, LOW);
    digitalWrite(DISPLAY_F, LOW);
    digitalWrite(DISPLAY_G, LOW);
    digitalWrite(DISPLAY_P, LOW);
    break;
    case '2':
    digitalWrite(DISPLAY_A, HIGH);
    digitalWrite(DISPLAY_B, HIGH);
    digitalWrite(DISPLAY_C, LOW);
    digitalWrite(DISPLAY_D, HIGH);
    digitalWrite(DISPLAY_E, HIGH);
    digitalWrite(DISPLAY_F, LOW);
    digitalWrite(DISPLAY_G, HIGH);
    digitalWrite(DISPLAY_P, LOW);
    break;
    case '3':
    digitalWrite(DISPLAY_A, HIGH);
    digitalWrite(DISPLAY_B, HIGH);
    digitalWrite(DISPLAY_C, HIGH);
    digitalWrite(DISPLAY_D, HIGH);
    digitalWrite(DISPLAY_E, LOW);
    digitalWrite(DISPLAY_F, LOW);
    digitalWrite(DISPLAY_G, HIGH);
    digitalWrite(DISPLAY_P, LOW);
    break;
    case '4':
    digitalWrite(DISPLAY_A, LOW);
    digitalWrite(DISPLAY_B, HIGH);
    digitalWrite(DISPLAY_C, HIGH);
    digitalWrite(DISPLAY_D, LOW);
    digitalWrite(DISPLAY_E, LOW);
    digitalWrite(DISPLAY_F, HIGH);
    digitalWrite(DISPLAY_G, HIGH);
    digitalWrite(DISPLAY_P, LOW);
    break;
    case '5':
    digitalWrite(DISPLAY_A, HIGH);
    digitalWrite(DISPLAY_B, LOW);
    digitalWrite(DISPLAY_C, HIGH);
    digitalWrite(DISPLAY_D, HIGH);
    digitalWrite(DISPLAY_E, LOW);
    digitalWrite(DISPLAY_F, HIGH);
    digitalWrite(DISPLAY_G, HIGH);
    digitalWrite(DISPLAY_P, LOW);
    break;
    case '6':
    digitalWrite(DISPLAY_A, HIGH);
    digitalWrite(DISPLAY_B, LOW);
    digitalWrite(DISPLAY_C, HIGH);
    digitalWrite(DISPLAY_D, HIGH);
    digitalWrite(DISPLAY_E, HIGH);
    digitalWrite(DISPLAY_F, HIGH);
    digitalWrite(DISPLAY_G, HIGH);
    digitalWrite(DISPLAY_P, LOW);
    break;
    case '7':
    digitalWrite(DISPLAY_A, HIGH);
    digitalWrite(DISPLAY_B, HIGH);
    digitalWrite(DISPLAY_C, HIGH);
    digitalWrite(DISPLAY_D, LOW);
    digitalWrite(DISPLAY_E, LOW);
    digitalWrite(DISPLAY_F, LOW);
    digitalWrite(DISPLAY_G, LOW);
    digitalWrite(DISPLAY_P, LOW);
    break;
    case '8':
    digitalWrite(DISPLAY_A, HIGH);
    digitalWrite(DISPLAY_B, HIGH);
    digitalWrite(DISPLAY_C, HIGH);
    digitalWrite(DISPLAY_D, HIGH);
    digitalWrite(DISPLAY_E, HIGH);
    digitalWrite(DISPLAY_F, HIGH);
    digitalWrite(DISPLAY_G, HIGH);
    digitalWrite(DISPLAY_P, LOW);
    break;
    case '9':
    digitalWrite(DISPLAY_A, HIGH);
    digitalWrite(DISPLAY_B, HIGH);
    digitalWrite(DISPLAY_C, HIGH);
    digitalWrite(DISPLAY_D, HIGH);
    digitalWrite(DISPLAY_E, LOW);
    digitalWrite(DISPLAY_F, HIGH);
    digitalWrite(DISPLAY_G, HIGH);
    digitalWrite(DISPLAY_P, LOW);
    break;
  }
}
