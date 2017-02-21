#ifndef SHAPE_H
#define SHAPE_H

#include <string>

using namespace std;

class Shape
{
public:
	Shape(int height);
	~Shape();
	virtual double volume() const = 0;
	virtual string toString() const = 0;

	int getHeight() const;
	void setHeight(int newHeight);

private:
	int height;
};

#endif // !SHAPE_H
