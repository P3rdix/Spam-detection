#include <stdio.h>
#include "spoof_data.h"

float risk(struct data*,struct data*);

char** sort_calls(struct data* data, int[]),int size{
    char** list = (char**)malloc(sizeof(char*)*size);
    float p[size];
    for(int i=0;i<size;i++){
        p[i] = 100;
        *(list + i)= NULL;
    }
    for(int i=0;i<size;i++){
        float r = risk(data,(data+i));
        int t=0;
        while(p[t]<r){
            t++;
        }
        while(p[t]!=100){
            int y = p[t];
            p[t] = r;
            r = y;
            t++;
            char* m = *(list+t);

        }
        p[t] = r;
    }
}

float risk(struct data* a, struct data* b){
    return (float)rand()/RAND_MAX;
}