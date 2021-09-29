#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/un.h>
#include <stddef.h>
#include <dlfcn.h>
#include"float_to_string.h"
#include"dll_custom.h"
#include"server_functions.h"
#include"client_functions.h"


/**
 * This is the driver function you can use to test client-server
 * communication using sockets.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [server|client] [Local socket file path] [arguements as in Readme.txt provided]\n",
               argv[0]);
        exit(-1);
    }
    if (0 == strcmp("server", argv[1])) {
        start_server_socket(argv[2], 10);
    } else if(strcmp("client", argv[1]) ==0){

        send_message_to_socket(argc, argv, argv[2]);

    }
    else {
        printf("Usage: %s [server|client] [Local socket file path] [arguements as in Readme.txt provided]\n",
               argv[0]);
        exit(-1);
    }
}