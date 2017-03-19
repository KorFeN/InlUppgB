#ifndef CONE_H
#define CONE_H

#include <string>
#include "Shape.h"

using namespace std;

class Cone : public Shape
{
public:
	Cone(int radius, int height);
	~Cone();
	double volume() const;
	string toStringSpecific() const;

	int getRadius() const;
	void setRadius(int newRadius);

private:
	int radius;
};

#endif // !CONE_H
