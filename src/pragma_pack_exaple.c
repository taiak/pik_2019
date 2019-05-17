#include <stdio.h>


// pragma elemanları paketlerken 1 e göre paketliyor
#pragma pack(1)
// kalanı en yakın diğer elemanın katına yuvarlıyor
// typedef __attribute__(__packed__) struct ...
 
typedef struct typedef_example
{
  //int  int_arr[10];
  char c_arr[10];
  long long int ll_arr[10];
} uni_t, uni[1];


int main(){
    uni_t a;
    uni_t *b = &a;
    
    printf("uni_t: %ld\nuni: %ld\n", sizeof(a),sizeof(long long int));

    return 0;
}

