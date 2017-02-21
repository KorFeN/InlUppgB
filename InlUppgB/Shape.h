#ifndef SHAPE_H
#define SHAPE_H

#include <string>

using namespace std;

class Shape
{
public:
	Shape(int height);
	~Shape();
	virtual double volume() = 0;
	virtual string toString() = 0;

	int getHeight();
	void setHeight(int newHeight);

private:
	int height;
};

#endif // !SHAPE_H
