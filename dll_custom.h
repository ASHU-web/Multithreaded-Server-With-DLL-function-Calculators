#ifndef dll_custom

#include<string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include<dlfcn.h>
#include"float_to_string.h"
// #include<stdbool.h>

typedef struct request {
    char* dll_name; // Name of a dynamically loaded library
    char* func_name; // Name of a function to call from the DLL
    char** func_args; // Arguments to pass to the function
}Request;
/*http://www.cs.sjsu.edu/faculty/pearce/modules/lectures/cpp/advanced/FunctionPointers.htm
Reference for fucntion calls*/
char* dll_calculation(Request* arguement, void* handle){
    // return "hello";
    char* error;

    // return "hfbh";
    char* return_value = malloc(sizeof(char)*100);

    if(strcmp(arguement->func_name, "cos") ==0){
        
        double (*fun_to_call)(double);
        fun_to_call = dlsym(handle, "cos");
        if((error = dlerror()) != NULL){
            strcat(return_value, "Error While loading the supplied function\n");
            return return_value;
        }
        gcvt((*fun_to_call)(atof(arguement->func_args[0])), 8, return_value);
        return return_value;

    }
    else if(strcmp(arguement->func_name, "sin") ==0){
       
        double (*fun_to_call)(double);
        fun_to_call = dlsym(handle, "sin");

        if((error = dlerror()) != NULL){
            strcat(return_value, "Error While loading the supplied function\n");
            return return_value;
        }

        double val = (*fun_to_call)(atof(arguement->func_args[0]));
        gcvt((*fun_to_call)(atof(arguement->func_args[0])), 5, return_value);
        return return_value;
    }
    else if(strcmp(arguement->func_name, "tan") ==0){
        
        
        double (*fun_to_call)(double);
        fun_to_call = dlsym(handle, "tan");
        if((error = dlerror()) != NULL){
            strcat(return_value, "Error While loading the supplied function\n");
            return return_value;
        }
        return_value = gcvt((*fun_to_call)(atof(arguement->func_args[0])), 8, return_value);
        return return_value;

    }else if(strcmp(arguement->func_name, "pow") ==0){
        
        double (*fun_to_call)(double, double);
        fun_to_call = dlsym(handle, "pow");
        if((error = dlerror()) != NULL){
            strcat(return_value, "Error While loading the supplied function\n");
            return return_value;
        }
        // power()
        gcvt((*fun_to_call)(atof(arguement->func_args[0]), atof(arguement->func_args[0])), 4, return_value);
        return return_value;

    }
    else if(strcmp(arguement->func_name, "pow") ==0){
        
        double (*fun_to_call)(double, double);
        fun_to_call = dlsym(handle, "pow");
        if((error = dlerror()) != NULL){
            strcat(return_value, "Error While loading the supplied function\n");
            return return_value;
        }
        return_value = gcvt((*fun_to_call)(atof(arguement->func_args[0]), atof(arguement->func_args[1])), 8, return_value);
        return return_value;

    }
    else if(strcmp(arguement->func_name, "sqrt") ==0){
        
        double (*fun_to_call)(double);
        fun_to_call = dlsym(handle, "sqrt");
        if((error = dlerror()) != NULL){
            strcat(return_value, "Error While loading the supplied function\n");
            return return_value;
        }
        return_value = gcvt((*fun_to_call)(atof(arguement->func_args[0])), 8, return_value);
        return return_value;

    }else {
        return "ERROR from dll_calcualtion function: INVALID Call to the Function Name\n";
    }

}

char* dll_function(int status,Request* arguement){
    void *handle;
    // char *errors;


    char dll_supported[100] = "/lib/x86_64-linux-gnu/libm.so.6"; // we only support this DLL

    if(strcmp(dll_supported, arguement->dll_name) != 0)
        return "DLL Entered is invalid. We only support /lib/x86_64-linux-gnu/libm.so.6\n";

    handle = dlopen ("/lib/x86_64-linux-gnu/libm.so.6", RTLD_LAZY);
    if (!handle) {
        fputs (dlerror(), stderr);
        exit(1);
    }
    //reached here
    char* answer = dll_calculation(arguement,handle );
    
    dlclose(handle);
   

    return answer;
}
#define dll_custom
#endif