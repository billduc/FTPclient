/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nguyen trung duc 
 *
 * Created on December 12, 2017, 9:31 AM
 */

#include "Headers/FTPs.h"
#include <cstdlib>

#define SERVER_PORT 12345
#define CLIENT_PORT 12345
#define SERVER_HOST_ADDR "127.0.0.1"

#define MAX_SIZE 512

using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {
    int sockid, newsockid, getfile, ack, smg_2, len;
    int no_write, start_xfer, num_blks, num_last_blk;
    struct sockaddr_in my_addr, server_addr;
    
    FILE *fp;
    char in_buf[MAX_SIZE];
    if (argc != 2)
    {
        cerr << "usage: ./ftpclient <filepath> \n";
        return 0;
    }
    no_write = 0;
    num_blks = 0;
    num_last_blk = 0;
    
    len = strlen(argv[1]);
    cout << "Client: crate socket" << endl;
    
    sockid = socket(AF_INET, SOCK_STREAM, 0);
    if (sockid < 0){
        cerr << "Client: create socket fail!!!";
        exit(0);
    }
    
    cout << "Client: binding my local socket" << endl;
    bzero((char *) my_addr, sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    my_addr.sin_port = htons(CLIENT_PORT);
    
    if ( bind(sockid, (struct sockaddr *) &my_addr, sizeof(my_addr)) < 0 ){
        cerr << "Clinet: binding error!!!" << endl;
        exit(0);
    }
    
    
    
    return 0;
}

