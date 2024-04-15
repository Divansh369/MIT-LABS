#!/usr/bin/env python
import sys

for line in sys.stdin:
    registration_no, name, marks = line.strip().split(",")
    print(f"{name}\t{registration_no},{marks}")
