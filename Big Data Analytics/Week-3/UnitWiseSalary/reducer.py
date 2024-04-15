#!/usr/bin/env python
import sys

current_unit = None
total_salary = 0

for line in sys.stdin:
    unit, salary = line.strip().split("\t")
    salary = int(salary)

    if current_unit == unit:
        total_salary += salary
    else:
        if current_unit:
            print(f"{current_unit}\t{total_salary}")
        current_unit = unit
        total_salary = salary

if current_unit == unit:
    print(f"{current_unit}\t{total_salary}")
