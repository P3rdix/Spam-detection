#include <stdio.h>
#include <stdlib.h>
struct data;

struct call{
    int time;
    int start_min;
    int recieved;
    int sndr_twr;
    int rcvr_twr;
}

struct log{
    struct data* recipient;
    struct call[24]* log;
}

struct data{
    char* number;
    struct log* log;
    int res_city;
}

int create_data(int size, struct data* ptr){
    ptr = (struct data*)malloc(sizeof(struct data)*size);
    for(int i=0;i<size;i++){
        (ptr+i)->number = generate_num(10);
        res_city = rand()%4;

    }
}

char* generate_num(int size){
    char* num= (char*)malloc(sizeof(char)*10);
    for(int i=0;i<size;i++){
        num[i] = (char)(48 + rand()%10);
    }
    return num;
}