#!/usr/bin/env python
import sys

matrix_a = [[0] * 3 for _ in range(3)]
matrix_b = [[0] * 3 for _ in range(3)]

for line in sys.stdin:
    key, value = line.strip().split("\t")
    row, col = map(int, key.split(","))
    matrix_name, matrix_row, matrix_col = value.split(",")
    matrix_row = int(matrix_row)
    matrix_col = int(matrix_col)

    if matrix_name == "a":
        matrix_a[row][col] = matrix_row, matrix_col
    else:
        matrix_b[row][col] = matrix_row, matrix_col

for i in range(3):
    for j in range(3):
        result = 0
        for k in range(3):
            a_val, b_val = matrix_a[i][k], matrix_b[k][j]
            result += a_val[1] * b_val[1]
        print(f"{i},{j}\t{result}")
