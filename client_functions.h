#ifndef client_functions

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
#include"common_client_server_functions.h"

/**
 * Sends a message to the server socket.
 * @param msg Message to send
 * @param socket_file Path of the server socket on localhost.
 */
void send_message_to_socket(int argc, char* argv[],char *socket_file) {
    int sockfd = make_named_socket(socket_file, true);

    /* Write some stuff and read the echoes. */
    log_msg("CLIENT: Connect to server, about to write some stuff...", false);
   
    /* get confirmation echoed from server and print */
    char buffer[5000];

    // struct request * hehe = (struct request*)malloc(sizeof(struct request));
    memset(buffer, '\0', sizeof(buffer));
    if (read(sockfd, buffer, sizeof(buffer)) > 0) {
        printf("CLIENT: Received from server:: %s\n", buffer);
        
    }
    
    unsigned int no_of_args = htonl(argc -3);

    write(sockfd, &no_of_args, sizeof(no_of_args));


    for(int i= 3; i< argc;i++){
        memset(buffer, '\0', sizeof(buffer));
        strcpy(buffer, argv[i]);
        send(sockfd, buffer, 5000, 0);
    }


      // Recieving Enqueue confirmation from server
    memset(buffer, '\0', sizeof(buffer));
    if (read(sockfd, buffer, sizeof(buffer)) > 0) {
            printf("CLIENT: Received from server:: %s\n", buffer);
        }
    
    // Recieving final result msg from server
    memset(buffer, '\0', sizeof(buffer));
    if (read(sockfd, buffer, sizeof(buffer)) > 0) {
        printf("CLIENT: Received from server:: %s\n", buffer);
    }

    log_msg("CLIENT: Processing done, about to exit...", false);
    close(sockfd); /* close the connection */
}

#define client_functions
#endif
