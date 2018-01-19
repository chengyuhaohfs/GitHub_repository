#ifndef TESTH_H_
#define TESTH_H_

using std::string;
string & test(string &str1, const string &str2);
void show_me();

struct polar{
	double distance;
	double angle;
};

struct rect{
	double x;
	double y;
};

#endif