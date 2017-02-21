#ifndef SHAPEREGISTER_H
#define SHAPEREGISTER_H

#include "Box.h"
#include "Cone.h"
#include "Shape.h"

using namespace std;

class ShapeRegister
{
public:
	ShapeRegister(int arrSize);
	ShapeRegister(const ShapeRegister & origObj);
	~ShapeRegister();
	ShapeRegister & operator=(const ShapeRegister & origObj);

	bool addCone(int radius, int height);
	bool addBox(int width, int height, int lenght);
	bool removeShape(int height);
	bool getAllShapesAsStrings(string arr[], int capOfArr) const;
	bool getAllConesAsStrings(string arr[], int capOfArr) const;
	bool getAllBoxesAsStrings(string arr[], int capOfArr) const;
	bool editACone(int height, int newRadius, int newHeight);
	bool editABox(int height, int newWidth, int newHeight, int newLenght);

	int nrOfShapes() const;
	int nrOfCones() const;
	int nrOfBoxes() const;

	int indexOfShape(int height) const;

private:
	Shape ** shapeArr;
	int arrCap;
	int shapesInArr;

	void expandArr(int expandAmount);
	void deleteArr();
};

#endif // !SHAPEREGISTER_H
