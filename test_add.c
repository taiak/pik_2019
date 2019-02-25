#include <stdio.h>
#include "matarith.h"

int main(){
	int a[] = {1,2,3,4,5,6};
	int b[] = {1,2,3,4,5,6};
	int o[6];
	int satir = 3, sutun = 2;
	matrix_add(o, a, b, satir, sutun);
	printf("%d\n", o[0]);
	return 0;
}
