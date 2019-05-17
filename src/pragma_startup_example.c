#include <stdio.h>

// pragma's startup and exit 
// not working on gcc   

#pragma startup func1()
#pragma exit    func2()

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
