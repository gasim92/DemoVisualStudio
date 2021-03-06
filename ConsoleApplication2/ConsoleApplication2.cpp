// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#define NFS_FUNC(x) (x)*(x)

typedef unsigned char uint8;

typedef struct {
	uint8 *in_file;
	size_t prop;
	std::string name;
}NFS;



void alloc2fun(void **ptr,int num) {

	*ptr = (void*)calloc(num,sizeof(ptr[0]));

}


int fun2fun(NFS *obj1) {
	obj1->name = "Changed!";
	obj1->in_file = (uint8*)calloc(10, sizeof(uint8));
	for (int i = 0; i < 10; i++)
		obj1->in_file[i] = i + 1;

	return 10;
}

int main()
{
	NFS obj1;

	obj1.name = "POCKER";
	obj1.prop = 25;

	//Before
	if (obj1.in_file == NULL)
		std::cout << "pointer is NULL" << std::endl;
	else
		std::cout << "pointer is active" << std::endl;

	//Call function
	obj1.prop=fun2fun(&obj1);

	std::cout << "Value: " << (int)obj1.in_file[2]<<std::endl;
	std::cout << obj1.name<<std::endl;

	//mem deallocation
	free(obj1.in_file);
	obj1.in_file = NULL;
	
	//allocate with void function
	alloc2fun((void**)&(obj1.in_file), 10);

	for (int j = 0; j < 10; j++)
		obj1.in_file[j] = j + 1;

	std::cout << "Value(void): " << (int)obj1.in_file[2] << std::endl;
	std::cout << "MACROs:" << (int)obj1.in_file[2]<<"<-->" << NFS_FUNC(obj1.in_file[2]) << std::endl;


	//deallocate mem
	free(obj1.in_file);
	obj1.in_file = NULL;

	getchar();
    return 0;
}

