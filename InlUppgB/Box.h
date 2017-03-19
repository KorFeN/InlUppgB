#ifndef BOX_H
#define BOX_H

#include <string>
#include "Shape.h"

using namespace std;

class Box : public Shape
{
public:
	Box(int lenght, int width, int height);
	~Box();
	double volume() const;
	string toStringSpecific() const;
	
	int getLenght() const;
	int getWidth() const;
	void setLenght(int newLenght);
	void setWidth(int newWidth);

private:
	int lenght;
	int width;
};

#endif // !BOX_H