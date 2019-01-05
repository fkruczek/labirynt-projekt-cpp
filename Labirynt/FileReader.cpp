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
	std::ifstream file(fileName);
	if (file.good()) {
		fileContent.assign((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
		return true;
	}
	else return false;
}

std::string FileReader::getFileContent()
{
	return fileContent;
}


