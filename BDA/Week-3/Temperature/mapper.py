#!/usr/bin/env python
import sys

for line in sys.stdin:
    year, temperature = line.strip().split()
    print(f"{year}\t{temperature}")
