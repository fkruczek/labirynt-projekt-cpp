#include "pch.h"
#include "FileReader.h"


FileReader::FileReader()
{
}


FileReader::~FileReader()
{
}

bool FileReader::readFromFile()
{
	char line;
	fstream myfile("maze.txt");
	if (myfile.is_open())
	{
		myfile >> line;
		cout << line << '\n';
		myfile.close();
	}

	else cout << "Unable to open file";
	return true;
}

const char * FileReader::getStringFromFile()
{
	return nullptr;
}
