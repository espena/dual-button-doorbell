#!/bin/zsh
idf.py build && idf.py -p /dev/cu.usbserial-FS200001 flash -b 115200
