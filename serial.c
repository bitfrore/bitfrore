#include <serial.h>

#include "inc/LPC11xx.h"

#define SYSTEM_CLOCK_IN_MHZ 50                    //main clock in MHz.
#define FALSE 0

#define LSR_THRE 0x20
#define LSR_TEMT 0x40
#define LSR_RDR 0x01
#define TEMT (1<<6)
#define LINE_FEED 0xA
#define CARRIAGE_RET 0xD

void serialinit(){

    unsigned int baudrate=38400;

    unsigned int regVal;
    unsigned int Fdiv;

    LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16); /* Enable IOCON block */
    LPC_IOCON->PIO1_6 &= ~0x07;    //Clear the first 3 bits in the FUNC of the 'PIO1_6'
    LPC_IOCON->PIO1_6 |= 0x01;     //Set PIO1_6 as UART RXD
    LPC_IOCON->PIO1_7 &= ~0x07;       //Clear the first 3 bits in the FUNC of the 'PIO1_7'
    LPC_IOCON->PIO1_7 |= 0x01;     //Set PIO1_7 as UART TXD
    /*Enable UART Clock*/
    LPC_SYSCON->SYSAHBCLKCTRL |= (1<<12);    //Enable UART clock
    LPC_SYSCON->UARTCLKDIV = 0x01;    //Divide by 1

    LPC_UART->LCR = 0x83;           //8 bits, no parity, 1 stop bit, DLAB(divisor latch access bit) = 1
    regVal = LPC_SYSCON->UARTCLKDIV;
    Fdiv = (((50000000)/regVal)/16)/baudrate ;    /*baud rate */

    LPC_UART->DLM = Fdiv / 256;
    LPC_UART->DLL = Fdiv % 256;
    LPC_UART->LCR = 0x03;        /* Diable latch access bit DLAB = 0 */ //Skal være 0 for at kunne skrive til THR
    LPC_UART->FCR = 0x07;        /* Enable and reset TX and RX FIFO. */

    /* Read to clear the line status. */
    regVal = LPC_UART->LSR;

    /* Ensure a clean start, no data in either TX or RX FIFO. */
    while (( LPC_UART->LSR & (LSR_THRE|LSR_TEMT)) != (LSR_THRE|LSR_TEMT) );
    while ( LPC_UART->LSR & LSR_RDR )
    {
        regVal = LPC_UART->RBR;    /* Dump data from RX FIFO */
    }
}

void serialprint(const char *msg){
  int i=0;
  while(*msg!=0){

    while ( !(LPC_UART->LSR & LSR_THRE) );
    LPC_UART->THR = *msg++;
    i++;
    if(i>=512){
      break;
    }
  }
}

