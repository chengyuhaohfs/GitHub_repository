#include "stdafx.h"
#include "iostream"
#include "stdio.h"
#include "cctype"

enum meiju {first, second, third};
enum {age = 10};

int main(int argc, char** argv){
	using namespace std;
	char buffer[32] = {};
	int i;
	do
	{
		cout << "Input whatever you want and I will change it to upper style:\n";
		cin.getline(buffer, 32);
		//_strupr_s(buffer, 32);
		i = 0;
		while(buffer[i] != '\0') {
			buffer[i] = toupper(buffer[i]);
			//toupper(buffer[i]);
			i ++;
		}
		if(!strcmp(buffer, "QUIT")) {
			return 0;
		}
		cout << buffer << endl;
	} while (true);
	return 0;
}
