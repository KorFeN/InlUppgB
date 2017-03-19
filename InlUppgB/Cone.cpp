#include "Cone.h"

Cone::Cone(int radius, int height)
	: Shape(height)
{
	this->radius = radius;
}

double Cone::volume() const
{
	return 3.141592 * static_cast<double>(this->radius) * static_cast<double>(this->radius) * (static_cast<double>(this->getHeight()) / 3);
}

string Cone::toStringSpecific() const
{
	return "Radius: " + to_string(this->radius) + "\n";
}


int Cone::getRadius() const
{
	return this->radius;
}

void Cone::setRadius(int newRadius)
{
	this->radius = newRadius;
}
