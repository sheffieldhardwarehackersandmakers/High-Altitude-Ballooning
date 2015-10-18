void rtty_txstring(char * string){
  char c;
  
  c = *string++;
  
  while( c != '\0'){
    rtty_txbyte(c);
    c = *string++;
  }
}
