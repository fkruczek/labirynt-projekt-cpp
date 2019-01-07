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
	else
		throw "Plik jest wadliwy lub nie istnieje";
}

std::string FileReader::getFileContent()
{
	return fileContent;
}


