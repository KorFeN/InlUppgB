#include "Cone.h"

Cone::Cone(int radius, int height)
	: Shape(height)
{
	this->radius = radius;
}

Cone::~Cone()
{

}

double Cone::volume()
{
	return 3.141592 * static_cast<double>(this->radius) * static_cast<double>(this->radius) * (static_cast<double>(this->getHeight()) / 3);
}

string Cone::toString()
{
	return "Radius: " + to_string( this->radius ) + "\n"
		+ "Height: " + to_string(this->getHeight()) + "\n"
		+ "Volume: " + to_string(this->volume()) + "\n";
}

int Cone::getRadius()
{
	return this->radius;
}

void Cone::setRadius(int newRadius)
{
	this->radius = newRadius;
}
