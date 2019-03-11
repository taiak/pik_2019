#include <stdio.h>
#include "../src/matarith.h"

int main(){
	int a[] = {
		1, 2, 3,
		4, 5, 6,
		7, 8, 9
	};
	int b[] = {
		1, 2, 3,
		4, 5, 6,
		7, 8, 9
	};
	int o[9];
	int a_satir = 3, a_sutun = 3;
	int b_satir = 3, b_sutun = 3;
	matrix_mult(o, a, b, a_satir, a_sutun, b_sutun);
	printf("%d\n", o[0]);
	return 0;
}
