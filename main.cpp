#include <iostream>
#include "Buffer.h"
using std::cout;
using std::endl;

int main(int argc,char*argv[]){
	int* tam = new int[10];
	Buffer* esto = new Buffer;
	esto->agregar(1);
	esto->imprimir();
	esto->agregar(3);
	esto->imprimir();
	esto->sacar();
	esto->imprimir();

	return 0;
}
