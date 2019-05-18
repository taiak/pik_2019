#include <stdio.h>
void __attribute__((constructor)) func1(void);
void __attribute__((destructor)) func2(void);

int main(){
    printf("main\n");
    return 0;
}

void func1(void) {
    printf("mainden önce\n");
}

void func2(void){
    printf("mainden sonra\n");
}
