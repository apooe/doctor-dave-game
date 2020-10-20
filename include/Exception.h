#pragma once
#include <exception>
#include <string>
#include <iostream>

using namespace std;

class UnidentifiedColl : public exception {

public:

	UnidentifiedColl(){}

	const char* what() const throw() {
		std::string s;
		s.append("unidentified collision");
		return s.c_str();
	}
};

class FileNotFoundException : public exception {

public:
	FileNotFoundException(const char* name)
	{
		filename.append(name);
	}
	const char* what() const throw() {
		std::string s;
		s.append("FileNotFoundException : ").append(filename);
		return s.c_str();
	}

private:
	std::string filename;
};