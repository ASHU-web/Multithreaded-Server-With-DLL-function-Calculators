#include "dll_custom.h"
#include<stdlib.h>
#include<stdio.h>
#include"float_to_string.h"

int main(){
    Request* temp = (Request*)malloc(sizeof(Request));
    char* tt = "10 23";
    temp->dll_name = "/lib/x86_64-linux-gnu/libm.so.6";
    temp->func_args = &tt;
    printf("%s\n hb ", temp->func_args[0]);

    printf("%s\n fl ", temp->func_args[1]);
    temp->func_name = "pow";
    // printf("here\n");
    
    printf("Ans: %s\n", dll_function(98, temp));
    return 0;
    
}