// cpp_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <string>
#include "testh.h"
#include <stdlib.h>
#include "time.h"

using namespace std;

// string & test(string &str1, const string &str2);

int main(int argc, char** argv){
	enum week {Monday, tuesday};
	enum class : short egg {Small, Medium, Large, Jumbo};
	egg chick = egg::Medium;
	enum struct t_shirt {Small, Medium, Large, Jumbo};
	t_shirt couple = t_shirt::Jumbo;
	week today = Monday;
	char atoint[] = "5200";
	struct tm tdate;
	time_t retime;
	time(&retime);
	localtime_s(&tdate, &retime);
	cout << tdate.tm_hour << endl;
	cout << atoi(atoint) << endl; 
	cout << today << endl;
	cout << (int)chick << "," << (int)couple << endl;
	return 0;
}