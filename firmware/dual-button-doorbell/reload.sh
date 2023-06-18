#!/bin/zsh
idf.py build && idf.py -p /dev/cu.SLAB_USBtoUART flash
