#ifndef BUFFER_H
#define BUFFER_H
#include <pthread.h>
class Buffer{
	private: 
    	int* cubetas;
    	int n, salida, entrada, size;
  	public:
  		pthread_cond_t      cond  = PTHREAD_COND_INITIALIZER;
		pthread_mutex_t     mutex = PTHREAD_MUTEX_INITIALIZER;
		Buffer(int);
		Buffer();
		void agregar(int);
		int sacar();
		void imprimir();
};

#endif
