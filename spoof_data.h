#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* generate_num(int);

struct data;

struct call{
    int time;
    int start_min;
    int recieved;
    struct data* recipient;
    struct call next;
};

struct log{
    struct call** log;
};

struct data{
    char* number;
    struct log* log;
    int res_city;
};

struct data* create_data(int size, int days, int max_calls){
    struct data* ptr = (struct data*)malloc(sizeof(struct data)*size);
    for(int i=0;i<size;i++){
        (ptr+i)->number = generate_num(10);
        (ptr+i)->res_city = rand()%4;
        (ptr+i)->log = generate_log(days, max_calls,size,ptr);
    }
    return ptr;
}

char* generate_num(int size){
    char* num= (char*)malloc(sizeof(char)*10);
    for(int i=0;i<size;i++){
        num[i] = (char)(48 + rand()%10);
    }
    return num;
}

struct call* generate_log(int days, int max, int size, struct data* init){
    struct call* new = (struct call*)malloc(sizeof(struct call)*days*24);
    int n = 0;
    for(int i=0;i<days*24;i++){
        if(n > 60){
            n-=60;
            (new+i)->start_min = -1;
            (new+i)->recipient = NULL;
            (new+i)->next = NULL;
            continue;
        }
        int l = rand()%max;
        l-=1;
        (new+i)->time = rand()%120;
        (new+i)->start_min = n;
        (new+i)->recipient = init+rand()%size;
        (new+i)->recieved = rand()%2;
        n += (new+i)->time + rand()%(60-n/2);
        (new+i)->next = NULL;
        struct call t = (new+i);
        while(n<60 && l > 0){
            t->next = (struct call*)malloc(sizeof(struct call));
            t = t->next;
            t->time = rand()%120;
            t->start_min = n;
            t->recipient = init+rand()%size;
            t->recieved = rand()%2;
            t->next = NULL;
            l--;
            n +=t->time+ rand()%(60-n/2);
        }
    }
    return new;
}