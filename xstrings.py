#!/bin/python3
import sys, os

if (len(sys.argv[1:]) != 1):
    print("Use: xstrings.py file")
    exit(0)


command = "strings --encoding={} "+sys.argv[1]
options = ['s', 'S', 'b', 'l', 'B', 'L', '{b,l}', '{B,L}']

for x in options:
    cmd = command.format(x)
    print("---------------"+cmd+"---------------------")
    if ('{' in x) == 0:
        os.system(cmd)
    else:
        print(cmd)
