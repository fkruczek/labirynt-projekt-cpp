#pragma once
#ifndef FILEREADER_H
#define FILEREADER_H
#include <fstream>

class FileReader
{
private:
	const char *fileName = "maze.txt";
	std::string fileContent;
public:
	FileReader();
	~FileReader();
	bool readFromFile();
	std::string getFileContent();
};

#endif