#include "stdafx.h"
#include "iostream"

template <class T>
void init_array(T *arra, int size);

template <class T>
void show_array(T *arra, int size);

int main(int argc, char** argv){
	int arra[5] = {12, 23, 6, 33, 21};
	int iarra[50];
	char str[100];
	show_array(arra, 5);
	init_array(iarra, 50);
	init_array(arra, 5);
	init_array(str, 100);
	show_array(arra, 5);
	return 0;
}

template <class T>
void init_array(T *arra, int size){
	for(int i = 0; i < size; i++){
		arra[i] = '\0';
	}
}

template <class T>
void show_array(T *arra, int size){
	using std::cout;
	using std::endl;
	for(int i = 0; i < size; i++){
		cout << arra[i] << endl;
	}
}