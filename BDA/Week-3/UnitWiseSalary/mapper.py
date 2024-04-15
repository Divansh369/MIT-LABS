#!/usr/bin/env python
import sys

for line in sys.stdin:
    emp_no, emp_name, unit, designation, salary = line.strip().split()
    print(f"{unit}\t{salary}")
