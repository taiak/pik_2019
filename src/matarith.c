int matrix_add(int * out, int * first, int *second, int satir, int sutun) {
	int size = satir * sutun;
	while(size--)
		*(out++) = *(first++) + *(second++);
		
	return 0;
}

int matrix_sub(int * out, int * first, int *second, int satir, int sutun) {
	int size = satir * sutun;
	while(size--)
		*(out++) = *(first++) - *(second++);
		
	return 0;
}

int matrix_mult(int * out, int * first_matrix, int *second_matrix, int first_col, int first_row, int second_row) {
	int i, j, k;
	
	for(i = 0; i < first_col; i++) {
		for(j = 0; j < second_row; j++) {
			out[i * second_row + j] = 0;
			for(k = 0; k < first_row; k++) {
				out[i * second_row + j] += first_matrix[i * first_row + k] * second_matrix[k * second_row + j];
			}
		}
	}
	
	return 0;
}

int matrix_trans(int * out, int * in, int row_count, int col_count) {
	int row, col;

	for(row = 0; row < row_count; row++) {
		for(col = 0; col < col_count; col++) {
			out[row * col_count + col] = in[col * row_count + row];
		}
	}

	return 0;
}
