#pragma once
#include "pch.h"
#include <fstream>
#include <iostream>
using namespace std;
class FileReader
{
private:
	const char *stringFromFile;
public:
	FileReader();
	~FileReader();
	bool readFromFile();
	const char *getStringFromFile();
};

