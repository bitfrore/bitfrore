#include <itoa.h>
#include <bignat.h>

const char DECIMAL[] = {"0123456789"};

void my_itoa(uint32_t val,char *buf,int limit){
    WORD abuf[BIGNATBUFSIZE(1)];
    struct bignat a(abuf,sizeof(abuf)/__S);
    a.Set(val);
    a.String(10,DECIMAL,buf,limit);
}
