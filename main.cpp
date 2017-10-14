#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>    
#include <time.h> 
#include "Buffer.h"

void *RunC(void *threadid);
void *RunP(void *threadid);

int main(int argc,char*argv[]){
    int* tam = new int[10];
	Buffer* bufer = new Buffer;
    pthread_t Productor;
    pthread_t Consumidor;
    int i=0;
    pthread_create(&Productor,NULL, RunP, (void *)i);
    i=1;
    pthread_create(&Consumidor,NULL, RunC, (void *)i);
    for(;;){
        bufer->imprimir();
        sleep(5);
    }
    pthread_exit(NULL);
    return 0;
}

void *RunP(void *threadid){
    int x;
    for(;;){
        srand (time(NULL));
        x= rand() % 100;
        bufer->agregar(x);
        sleep(2);
    }
}

void *RunC(void *threadid){
    for(;;){
        bufer->sacar();
        sleep(3);
    }
}
