#!/usr/bin/python

import struct
import sys

binarylen=0xC0
calccrc=0

with open(sys.argv[1],'rb') as f:
  byte = f.read(0xC0)
  byte = f.read(1)
  while byte:
    v, = struct.unpack('B',byte)
    calccrc = calccrc + v
    binarylen+=1
    byte = f.read(1)

swappedbinarylen = struct.unpack('<I',struct.pack('>I',binarylen))
swappedcalccrc = struct.unpack('<I',struct.pack('>I',calccrc))

with open(sys.argv[2]) as f:
  for line in f:
    line=line.strip()
    if line == ':00000001FF':
      print ':047FF800%08X1B' % (swappedbinarylen)
      print ':047FFC00%08X1B' % (swappedcalccrc)
    print line
