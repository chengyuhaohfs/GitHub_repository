#include "valarray"
#include "iostream"
#include "string"
#include "memory"
#include "stdafx.h"

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
	for(int i = 0; i < 5; i++){
//		scores[i] = i + i * i;
		cout << scores[i] << ", ";
	}
	cout << endl;
	cout << hfs.sum() << endl;

	cout << pow(2, 3) << endl;
	return 0;
}
