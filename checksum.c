#include <checksum.h>

#include <stdint.h>

//Build places length and crc at known memory locations
#define PROG_LEN (*((volatile int*)0x7FF8))
#define CRC (*((volatile int*)0x7FFC))

#define READ_FLASH(object, adr) (*((object volatile *) (adr)))

int verifyChecksum(){
  int i;
  int calccrc=0;

  if(PROG_LEN<100 || PROG_LEN > (32*1024)-8){
    return 0;
  }

  for(i=0xC0;i<PROG_LEN;i++){
    uint8_t b=READ_FLASH(uint8_t, i);
    calccrc+=b;
  }

  if(calccrc != CRC ){
    return 0;
  }

  return 1;
}

