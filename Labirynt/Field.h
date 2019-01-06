#ifndef FIELD_H
#define FIELD_H

class Field
{
private:
	int X;
	int Y;
public:
	Field(int x, int y);
	~Field();
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
};

#endif