#include <stdio.h>
#include <x86intrin.h>
#include "matarith.c"

// compile params: gcc ders2_benchmark.c -g && ./a.out

// derleyici özelliklerine göre derle
// gcc ders2_benchmark.c -march=native && ./a.out

// 3.seviye optimizasyon
// gcc ders2_benchmark.c -march=native -O3 && ./a.out

// windozda
// __declspec(align[32])

//__attribute__((aligned[32]))

double mult_x86test(int * output, int * first_matrix, int * second_matrix, int f_row_count, int f_col_count, int s_col_count, const int loop_count);
double add_x86test(int * output, int * first_matrix, int * second_matrix, int row_count, int col_count, const int loop_count);
double sub_x86test(int * output, int * first_matrix, int * second_matrix, int row_count, int col_count, const int loop_count);

#define MATRIX_SIZE 100

typedef int mat[MATRIX_SIZE*MATRIX_SIZE] __attribute__((aligned(32)));

#define make_array(N)\
    mat a, b, o;

//    int __attribute__((aligned(32))) a[N*N] ;\
//    int __attribute__((aligned(32))) b[N*N] ;\
//    int __attribute__((aligned(32))) o[N*N] ;

//    a = (int *) malloc(N * N * sizeof(int));\
//    b = (int *) malloc(N * N * sizeof(int));\
//    o = (int *) malloc(N * N * sizeof(int));\


#define fill_array(array, N)\
    for(int i = 0; i < N * N; i++){\
        array[i] = i;\
    }

int main() {
    int edge_size = 100;
    int loop_count = 100;

    make_array(edge_size);
    
    fill_array(a, edge_size);
    fill_array(b, edge_size);

    double result = 0.0;

    result = mult_x86test(o, a, b, edge_size, edge_size, edge_size, loop_count);
	printf("%f\n", result);

    result = add_x86test(o, a, b, edge_size, edge_size, loop_count);
    printf("%f\n", result);

    result = sub_x86test(o, a, b, edge_size, edge_size, loop_count);
    printf("%f\n", result);

    return 0;
}

double mult_x86test(int * output, int * first_matrix, int * second_matrix, int f_row_count, int f_col_count, int s_col_count, const int loop_count){
    unsigned long long int temp = 0, total = 0;
    
    for(int i = 0; i < loop_count; i++) {
        temp = _rdtsc();
    	matrix_mult(output, first_matrix, second_matrix, f_row_count, f_col_count, s_col_count);
        total += _rdtsc() - temp;
    }
	
    return (double) (total / loop_count);
}

double add_x86test(int * output, int * first_matrix, int * second_matrix, int row_count, int col_count, const int loop_count){
    unsigned long long int temp = 0, total = 0;
    
    for(int i = 0; i < loop_count; i++) {
        temp = _rdtsc();
        matrix_add(output, first_matrix, second_matrix, row_count, col_count);
        total += _rdtsc() - temp;
    }

    return (double) (total / loop_count);
}

double sub_x86test(int * output, int * first_matrix, int * second_matrix, int row_count, int col_count, const int loop_count){
    unsigned long long int temp = 0, total = 0;
    
    for(int i = 0; i < loop_count; i++) {
        temp = _rdtsc();
        matrix_sub(output, first_matrix, second_matrix, row_count, col_count);
        total += _rdtsc() - temp;
    }

    return (double) (total / loop_count);
}
