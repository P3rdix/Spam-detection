
#include <stdio.h>
#include "spoof_data.h"

float risk(struct data*,struct data*,int,int,int);
float unlikeliness(struct call*,struct call*,int);

char** sort_calls(struct data* data,int size, int day, int hour, int time){
    char** list = (char**)malloc(sizeof(char*)*size);
    float p[size];
    for(int i=0;i<size;i++){
        p[i] = -1;
        *(list + i)= NULL;
    }
int start_time = day*24 + hour;

    for(int i=0;i<size;i++){
        float r = risk(data,(data+i),size,start_time,time);
        printf("%f  %s\n",r,(data+i)->number);
        int t=0;
        while(p[t]<r && p[t]!=-1){
            t++;
        }
        char* e = (data+i)->number;
        while(p[t]!=-1){
            float y = p[t];
            p[t] = r;
            r = y;
            char* x = *(list+t);
            *(list+t) = e;
            e = x;
            t++;
        }
        
        p[t] = r;
        *(list + t) = e;
    }
    return list;
}

float risk(struct data* pg, struct data* b, int size, int base, int disp){
    /* iterate through calls in time base to base + disp
    return the most suspicious call
    *** Maybe ask return the indices of the call?
    */
    int r = 0;
    int d = 0;
    float e = 1;
    struct call* t = NULL;
    for(int i=base;i<base+disp;i++){
        struct call* t = (b)->log+i;
        int w = 0;
        while(t!=NULL){
            float a = unlikeliness((b->log),t,i);
            if(a<e){
                e = a;
                r = i;
                d = w;
            }
            t = t->next;
            w++;
        }
        
   }
   return e;
}

float unlikeliness(struct call* call_log,struct call* c, int base){
    int p=0;
    int max=0;
    for(int i=0;i<base;i++){
        struct call* temp = call_log+i;
        while(temp!=NULL){
            if(temp->recipient == c->recipient){
                p++;
            }
            max++;
            temp = temp->next;
        }
    }
    return (float)p/max;
}
