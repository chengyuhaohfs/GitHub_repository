#include "valarray"
#include "iostream"
#include "string"
#include "memory"
#include "stdafx.h"
#include "vector"

typedef std::valarray<double> ArrayDb;

class People : private std::string {
private:
	std::string name;
	int age;
public:
	const std::string &getName() const {
		return name;
	}
	People() {
		age = 0;
		name = "Nobody";
		std::cout << "Here a new people " << name << " is created.\n";
	}
	explicit People(std::string name_) : name(name_) {
			age = 0;
			std::cout << "Here a new people " << name << " is created.\n";
		}
	~People(){
		std::cout << "Here a people " << name << " is deleted.\n";
	}
};

class Student : private People {
private:
	ArrayDb scores;
public:
	Student() {
		scores = ArrayDb(0);
		std::cout << "Here a new student " << getName() << " is created.\n";
	}

	explicit Student(std::string name) : People(name) {
			scores = ArrayDb(6.0, 5);
			std::cout << "Here a new student " << getName() << " is created.\n";
		}
	double sum() const {
		return scores.sum();
	}

	~Student() {
		std::cout << "Here a student " << getName() << " is deleted.\n";
	}
};

int main(int argc, char** argv) {
	using namespace std;
	Student hfs("hfs");
	valarray<double> scores(5.0, 5);
	scores.resize(6, 9.8);
	scores[5] = 9.9;
	scores.shift(3);
/*	cout << "the size of valarray is " << scores.size() << endl;*/
	for(int i = 0; i < (int)scores.size(); i++){
		cout << scores[i] << ", ";
	}
	cout << endl;
	cout << hfs.sum() << endl;

	cout << pow(2, 3) << endl;

	vector<string> str{ "010-12345678", "0319-9876543", "021-123456789" };
	for (string st : str)
	{
		cout << st << endl;
	}

	return 0;
}
