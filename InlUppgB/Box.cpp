#include "Box.h"

Box::Box(int lenght, int width, int height)
	: Shape(height)
{
	this->lenght = lenght;
	this->width = width;
}

Box::~Box()
{
}

double Box::volume()
{
	return this->getHeight() * this->lenght * this->width;
}

string Box::toString()
{
	return "Width: " + to_string(this->width) + "\n"
		+ "Lenght: " + to_string(this->lenght) + "\n"
		+ "Height: " + to_string(this->getHeight()) + "\n"
		+ "Volume: " + to_string(this->volume()) + "\n";
}

int Box::getLenght()
{
	return this->lenght;
}

int Box::getWidth()
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
