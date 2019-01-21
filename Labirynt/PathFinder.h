#pragma once
#ifndef PATHFINDER_H
#define PATHFINDER_H
#include "Grid.h"
#include "Field.h"
#include <queue>
#include <stack>
#include <vector>
#include <ctime>

//! Struktura CompareDistance.
/*! Struktura uzywana przy porownywaniu pol w kolejce priorytetowej.
	Pola z krotrzym dystansem do wyjscia sa ustawiane na  poczatek kolejki
*/
struct CompareDistance {
	bool operator()(std::stack<Field> & p1, std::stack<Field> & p2) {
		return p1.top().getDistance() > p2.top().getDistance();
	}
};

//!  klasa PathFinder 
/*!
  Klasa odpowiadajaca za znajdywanie sciezki
*/

class PathFinder
{
private:
	bool isPathExists = false;
	int mazeSize;
	int pathCounter = 0;
	//! Kolejka priorytetowa stosow pol. Uzywana przy szukaniu drogi. (pojedyncza  sciezka to stos)
	std::priority_queue<std::stack<Field>, std::vector<std::stack<Field>>, CompareDistance> paths;
	//std::queue<std::stack<Field>> paths;
	std::stack<Field> finalPath;
	//! Kluczowa skladowa - kolejka stosow pol
	std::vector<std::stack<Field>> pathVector;
	std::clock_t start;
	double duration;
public:
	PathFinder();
	~PathFinder();
	//! Ustawia rozmiar labiryntu
	void setMazeSize(int size);
	//! Znajduje drogê w labiryncie
	/*!
	  Przyjmuje przez referencjê obiekt Grid, zwraca informacje czy znaleziono scie¿ke. <br>
	  Algorytm dzia³a na podobnej zasadzie jak algorytm przeszukiwania grafu wszerz - BFS.
	  Zostal jednak zmodyfikowany przez dodanie kolejki priorytetowej co upodabnia go nieco do algorytmu A*.
	  Nie by³o konieczne równie¿ tworzenie macierzy s¹siedztwa gdyz w siatce kazdy wierzcho³ek ma znanych sasiadow. (Polnocny, Poludniowy, Wschodni, Zachodni).
	  Stad np. metoda isInBorder() wykorzystuje to, ze dzia³amy na siatce.
	*/
	bool findPath(Grid & maze);
	//! informuje czy dane pole znajduje siê w granicach labiryntu
	bool isInBorder(Field & field);
	//! zaznacza na siatce którêdy biegnie finalna œcie¿ka
	void selectFinalPath(Grid & maze);
	//! zaznacza na siatce którêdy biegnie n-ta œcie¿ka z wektora œcie¿ek
	void selectVectorPath(Grid & maze, int n);
	//! zwraca wartoœæ licznika œcie¿ek
	int getPathCounter();
	//! zwraca czas szukania œcie¿ki
	double getDuration();
};

#endif
