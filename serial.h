#ifndef SERIAL_H
#define SERIAL_H

#ifdef __cplusplus
extern "C" {
#endif

void serialinit();
void serialprint(const char *msg);
void serialwrite(const char *msg,int len);
void serialputc(const char c);

#ifdef __cplusplus
}
#endif

#endif

