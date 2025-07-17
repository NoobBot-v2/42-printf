//1) check if leftover_buf has value, if yes, go to 2) else got to 4)
//2) check if a new line is found in leftover_buf, if found, go to 3) else go to 4)
//3) return that new line and store the leftover_buf and return to 1)

//4) If no new line or no leftover, read for more data into read_buf
//   If read returns > 0, recombine into leftover_buf, if read returns 0, go to 5
//5) Read returned 0, EOF reached, check if current leftover_buf contains '\n' 
//   and return that, else check subject

//BONUS
//change leftover_buf into char *leftover_buf[FD]
//where #define FD 1024

//NOTE
//Control it by the bytes read and not by NULL terminators
