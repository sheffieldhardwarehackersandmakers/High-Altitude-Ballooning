void rtty_txbit(int bit){
  
  if (bit){
    digitalWrite(RADIOPIN, HIGH);
  }
  else{
    digitalWrite(RADIOPIN, LOW);
  }
  
  delayMicroseconds(DL1);
  delayMicroseconds(DL2);
}

