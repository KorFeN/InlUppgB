#include "Shape.h"

Shape::Shape(int height)
{
	this->height = height;
}

Shape::~Shape()
{
}

string Shape::toString() const
{
	return "Height: " + to_string(this->getHeight()) + "\n"
		+ "Volume: " + to_string(this->volume()) + "\n"
		+ this->toStringSpecific();
}

int Shape::getHeight() const
{
	return this->height;
}

void Shape::setHeight(int newHeight)
{
	this->height = newHeight;
}
