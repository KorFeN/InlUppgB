#include "Shape.h"

Shape::Shape(int height)
{
	this->height = height;
}

Shape::~Shape()
{

}

int Shape::getHeight()
{
	return this->height;
}

void Shape::setHeight(int newHeight)
{
	this->height = newHeight;
}
