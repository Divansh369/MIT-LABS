#!/usr/bin/env python
import sys

current_name = None
student_details = []

for line in sys.stdin:
    name, details = line.strip().split("\t")
    registration_no, marks = details.split(",")
    marks = int(marks)

    if current_name == name:
        student_details.append((registration_no, marks))
    else:
        if current_name:
            sorted_details = sorted(student_details, key=lambda x: x[0])
            for reg_no, mark in sorted_details:
                print(f"{reg_no},{current_name},{mark}")
        current_name = name
        student_details = [(registration_no, marks)]

if current_name == name:
    sorted_details = sorted(student_details, key=lambda x: x[0])
    for reg_no, mark in sorted_details:
        print(f"{reg_no},{current_name},{mark}")
