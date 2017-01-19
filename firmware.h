void fhrst(void);
void fhrcv(unsigned char data);


extern unsigned char fhRXcmp; // Flag if packet is received, i.e. newline (chr 13, 0x0D), is
extern unsigned char RXNod; // The node that is beeing addressed
extern unsigned long int RXCmd; // Command received
extern signed int RXArg; // Argument received
