#!/usr/bin/env python
import sys

for line in sys.stdin:
    parts = line.strip().split(",")
    matrix_name = parts[0]
    row = int(parts[1])
    col = int(parts[2])
    value = int(parts[3])
    if matrix_name == "a":
        for k in range(3):
            print(f"{row},{k}\t{matrix_name},{col},{value}")
    else:
        for i in range(3):
            print(f"{i},{col}\t{matrix_name},{row},{value}")
