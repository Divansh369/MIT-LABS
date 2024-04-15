#!/usr/bin/env python
import sys

current_year = None
temperature_list = []

for line in sys.stdin:
    year, temperature = line.strip().split("\t")
    temperature = int(temperature)

    if current_year == year:
        temperature_list.append(temperature)
    else:
        if current_year:
            avg_temp = sum(temperature_list) / len(temperature_list)
            min_temp = min(temperature_list)
            max_temp = max(temperature_list)
            print(f"{current_year}\t{avg_temp}\t{min_temp}\t{max_temp}")
        current_year = year
        temperature_list = [temperature]

if current_year == year:
    avg_temp = sum(temperature_list) / len(temperature_list)
    min_temp = min(temperature_list)
    max_temp = max(temperature_list)
    print(f"{current_year}\t{avg_temp}\t{min_temp}\t{max_temp}")
