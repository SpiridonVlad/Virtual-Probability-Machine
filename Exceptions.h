#pragma once
#include<exception>
using namespace std;

class Insufficient_funds :public exception {
public:
	const char* what() const throw() {
		return "Insufficient funds";
	}
};

class Wrong_Bank :public exception {
public:
	const char* what() const throw() {
		return "Wrong Bank";
	}
};