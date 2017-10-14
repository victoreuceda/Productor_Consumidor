#include "Buffer.h"
#include <iostream>
#include <pthread.h>

using std::cout;
using std::cin;
using std::endl;

Buffer::Buffer(int size){
	this->size = size;
	cubetas = new int[size];
	entrada = 0;
	salida = 0;
	n = 0; 
}
Buffer::Buffer(){
	this->size = 10;
	cubetas = new int[10];
	entrada = 0;
	salida = 0;
	n = 0; 
}
void Buffer::agregar(int x){
		if (n < size) {
            cubetas[entrada] = x;
            n++;
            entrada = (entrada + 1) % size;
        } else {
        	pthread_cond_wait(&cond,&mutex);
        }
}
int Buffer::sacar(){
	 	if (n > 0) {
            int x = cubetas[salida];
            salida = (salida + 1) % size;
            n--;
            pthread_cond_signal(&cond);
            return x;
        }
		return -1;
}
void Buffer::imprimir(){
        for (int i = 0; i < n; i++) {
        	cout << cubetas[(salida + i) % size] <<" ";
        }
        cout << ""<<endl;
}
