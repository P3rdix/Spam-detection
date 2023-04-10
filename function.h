
#include <stdio.h>
#include "spoof_data.h"

float risk(struct data*,struct data*,int,int,int);

char** sort_calls(struct data* data,int size, int day, int hour, int time){
    char** list = (char**)malloc(sizeof(char*)*size);
    float p[size];
    for(int i=0;i<size;i++){
        p[i] = -1;
        *(list + i)= NULL;
    }
int start_time = day*24 + hou;

    for(int i=0;i<size;i++){
        float r = risk(data,(data+i),size,start_time,time);
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

float risk(struct data* a, struct data* b, int size, int base, int disp){
    /* iterate through calls in time base to base + disp
    return the most suspicious call
    *** Maybe ask return the indices of the call?
    */
   int r = 0;
   float e = 1;

   for(int i=base;i<base+disp;i++){
        float a = unlikeliness((b->log),(b->log)+i,i);
        if(a<e){
            e = a;
            r = i;
        }
   }
   return recommendation(call at e);
}

float unlikeliness(struct call calls_made,struct call start, int base, int start_length){
    int p[start_length];
    int max=0;
    for(int i=0;i<start_length;i++){p[i]=0;}
    for(int i=0;i<base;i++){
        struct call temp = calls_made+i;
        while(temp!=NULL){
            int r = contains(temp->recipient,start);
            if (r>0){
                p[r]+=1;
            }
            max++;
            temp = temp->next;
        }
    }
}

int contains(struct data c, struct call p){
    int i=0;
    while(p!=NULL){
        if (p->recipient ==c){
            return i; 
        }
        p= p->next;
        i++;
    }
    return -1;
}