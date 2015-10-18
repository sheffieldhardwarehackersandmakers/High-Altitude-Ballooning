void rtty_txbyte(char c){
  int i;
  
  rtty_txbit(0);  // start bit
  
  for(i=0; i<7; i++){
    if (c & 1) rtty_txbit(1);
    else rtty_txbit(0);
    c = c >> 1;
  }
  
  rtty_txbit(1);  // stop bit
  rtty_txbit(1);  // stop bit
}

  
  
