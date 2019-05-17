/*
    15.04.2019_09:55
    -ansi
    -std=c99
    -std=c11
    parametreleriyle çalıştırılabilir 
#pragma once
*/

int matrix_add(int *out, int *first, int *second, int satir, int sutun);
int matrix_sub(int *out, int *first, int *second, int satir, int sutun);
int matrix_mult(int *out, int *first_matrix, int *second_matrix, int first_col, int first_row, int second_row);
int matrix_trans(int * out, int * in, int row_count, int col_count);
