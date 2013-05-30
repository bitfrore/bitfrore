#ifndef M190PRINTER_H
#define M190PRINTER_H
// Copyright 2013 Steven Pearson
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.
#include <stdint.h>

namespace m190{

  typedef bool (*pixelsource)(void *ctx,int x,int y);

  void initialize();
  void formfeed(int rows);
  void print(pixelsource s,void *ctx,int rows,bool overlap);
  void print(char *x);
  void printP(const uint8_t *bitmap,int w,int h);
}

#endif
