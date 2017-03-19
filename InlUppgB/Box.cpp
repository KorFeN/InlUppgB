#include "Box.h"

Box::Box(int lenght, int width, int height)
	: Shape(height)
{
	this->lenght = lenght;
	this->width = width;
}


double Box::volume() const
{
	return this->getHeight() * this->lenght * this->width;
}

string Box::toStringSpecific() const
{
	return "Width: " + to_string(this->width) + "\n"
		+ "Lenght: " + to_string(this->lenght) + "\n";
}

int Box::getLenght() const
{
	return this->lenght;
}

int Box::getWidth() const
{
	return this->width;
}

void Box::setLenght(int newLenght)
{
	this->lenght = newLenght;
}

void Box::setWidth(int newWidth)
{
	this->width = newWidth;
}
