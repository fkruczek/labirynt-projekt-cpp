#pragma once
#ifndef FILEREADER_H
#define FILEREADER_H
#include <fstream>
//!  klasa FileReader
/*!
  Klasa zczytuj�ca dane z pliku
*/
class FileReader
{
private:
	const char *fileName = "maze.txt";
	std::string fileContent;
public:
	FileReader();
	~FileReader();
	//! Zwraca true je�eli uda si� odczyta� dane z pliku
	bool readFromFile();
	//! Zwraca strumien odczytany z pliku
	std::string getFileContent();
};

#endif