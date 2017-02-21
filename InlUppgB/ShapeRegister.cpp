#include "ShapeRegister.h"

ShapeRegister::ShapeRegister(int arrSize)
{
	shapeArr = new Shape*[arrSize];
	shapesInArr = 0;
	arrCap = arrSize;
}

ShapeRegister::ShapeRegister(const ShapeRegister & origObj)
{
	this->shapeArr = new Shape*[origObj.arrCap];
	this->arrCap = origObj.arrCap;
	this->shapesInArr = origObj.shapesInArr;
	for (int i = 0; i < origObj.shapesInArr; i++)
	{
		Cone* conePtr = nullptr;
		conePtr = dynamic_cast<Cone*>(origObj.shapeArr[i]);
		if (conePtr != nullptr) //IT IS A CONE
		{
			this->shapeArr[i] = new Cone(conePtr->getRadius(), conePtr->getHeight());
		}
		else //IT IS A BOX
		{
			Box* boxPtr = nullptr;
			boxPtr = dynamic_cast<Box*>(origObj.shapeArr[i]);
			this->shapeArr[i] = new Box(boxPtr->getLenght(), boxPtr->getWidth(), boxPtr->getHeight());
		}
	}
}

ShapeRegister::~ShapeRegister()
{
	deleteArr();
}

ShapeRegister & ShapeRegister::operator=(const ShapeRegister & origObj)
{
	if (this != &origObj)
	{
		deleteArr();
		this->shapeArr = new Shape*[origObj.arrCap];
		this->arrCap = origObj.arrCap;
		this->shapesInArr = origObj.shapesInArr;
		for (int i = 0; i < origObj.shapesInArr; i++)
		{
			Cone* conePtr = nullptr;
			conePtr = dynamic_cast<Cone*>(origObj.shapeArr[i]);
			if (conePtr != nullptr) //IT IS A CONE
			{
				this->shapeArr[i] = new Cone(conePtr->getRadius(), conePtr->getHeight());
			}
			else //IT IS A BOX
			{
				Box* boxPtr = nullptr;
				boxPtr = dynamic_cast<Box*>(origObj.shapeArr[i]);
				this->shapeArr[i] = new Box(boxPtr->getLenght(), boxPtr->getWidth(), boxPtr->getHeight());
			}
		}
	}
	return *this;
}

bool ShapeRegister::addCone(int radius, int height)
{
	bool addShape = true;

	if (indexOfShape(height) != -1)
		addShape = false;
	
	if (addShape)
	{
		if (shapesInArr == arrCap)
			expandArr(2);

		shapeArr[shapesInArr] = new Cone(radius, height);
		shapesInArr++;
	}

	return addShape;
}

bool ShapeRegister::addBox(int width, int height, int lenght)
{
	bool addShape = true;

	if (indexOfShape(height) != -1)
		addShape = false;

	if (addShape)
	{
		if (shapesInArr == arrCap)
			expandArr(2);

		shapeArr[shapesInArr] = new Box(lenght,width,height);
		shapesInArr++;
	}

	return addShape;
}

bool ShapeRegister::removeShape(int height)
{
	bool remove = false;
	int idx = indexOfShape(height);
	if (idx != -1)
		remove = true;

	if (remove)
	{
		if (idx == (shapesInArr - 1))
		{
			delete shapeArr[idx];
			shapeArr[idx] = nullptr;
			shapesInArr = (shapesInArr - 1);
		}
		else
		{
			delete shapeArr[idx];
			shapeArr[idx] = shapeArr[shapesInArr - 1];
			shapeArr[shapesInArr - 1] = nullptr;
			shapesInArr = (shapesInArr - 1);
		}
	}

	return remove;
}

bool ShapeRegister::getAllShapesAsStrings(string arr[], int capOfArr) const
{
	bool fillArr = true;

	if (capOfArr < shapesInArr)
		fillArr = false;

	for (int i = 0; i < shapesInArr; i++)
	{
		arr[i] = shapeArr[i]->toString();
	}

	return fillArr;
}

bool ShapeRegister::getAllConesAsStrings(string arr[], int capOfArr) const
{
	bool fillArr = true;
	int currCones = 0;

	if (capOfArr < nrOfCones())
		fillArr = false;

	for (int i = 0; i < shapesInArr; i++)
	{
		Cone* conePtr = nullptr;
		conePtr = dynamic_cast<Cone*>(shapeArr[i]);
		if (conePtr != nullptr)
		{
			arr[currCones] = shapeArr[i]->toString();
			currCones++;
		}
	}

	return fillArr;
}

bool ShapeRegister::getAllBoxesAsStrings(string arr[], int capOfArr) const
{
	bool fillArr = true;
	int currBoxes = 0;

	if (capOfArr < nrOfBoxes())
		fillArr = false;

	for (int i = 0; i < shapesInArr; i++)
	{
		Box* boxPtr = nullptr;
		boxPtr = dynamic_cast<Box*>(shapeArr[i]);
		if (boxPtr != nullptr)
		{
			arr[currBoxes] = shapeArr[i]->toString();
			currBoxes++;
		}
	}

	return fillArr;
}

bool ShapeRegister::editACone(int height, int newRadius, int newHeight)
{
	bool edit = true;

	int idx = indexOfShape(height);
	if (idx == -1)
		edit = false;

	if (edit)
	{
		Cone* conePtr = nullptr;
		conePtr = dynamic_cast<Cone*>(shapeArr[idx]);
		if (conePtr = nullptr)
			edit = false;
		if (edit)
		{
			conePtr->setRadius(newRadius);
			conePtr->setHeight(newHeight);
		}
	}

	return edit;
}

bool ShapeRegister::editABox(int height, int newWidth, int newHeight, int newLenght)
{
	bool edit = true;

	int idx = indexOfShape(height);
	if (idx == -1)
		edit = false;

	if (edit)
	{
		Box* boxPtr = nullptr;
		boxPtr = dynamic_cast<Box*>(shapeArr[idx]);
		if (boxPtr = nullptr)
			edit = false;
		if (edit)
		{
			boxPtr->setWidth(newWidth);
			boxPtr->setHeight(newHeight);
			boxPtr->setLenght(newLenght);
		}
	}

	return edit;
}

int ShapeRegister::nrOfShapes() const
{
	return shapesInArr;
}

int ShapeRegister::nrOfCones() const
{
	int cones = 0;

	for (int i = 0; i < shapesInArr; i++)
	{
		Cone* conePtr = nullptr;
		conePtr = dynamic_cast<Cone*>(shapeArr[i]);
		if (conePtr != nullptr)
			cones++;
	}

	return cones;
}

int ShapeRegister::nrOfBoxes() const
{
	int boxes = 0;

	for (int i = 0; i < shapesInArr; i++)
	{
		Box* boxPtr = nullptr;
		boxPtr = dynamic_cast<Box*>(shapeArr[i]);
		if (boxPtr != nullptr)
			boxes++;
	}

	return boxes;
}

int ShapeRegister::indexOfShape(int height) const
{
	int exist = -1;

	for (int i = 0; i < shapesInArr; i++)
	{
		if (shapeArr[i]->getHeight() == height)
			exist = i;
	}

	return exist;
}

void ShapeRegister::expandArr(int expandAmount)
{
	Shape ** temp = new Shape*[arrCap + expandAmount];
	for (int i = 0; i < shapesInArr; i++)
	{
		temp[i] = shapeArr[i];
	}
	arrCap = arrCap + expandAmount;
	delete[] shapeArr;
	shapeArr = temp;
}

void ShapeRegister::deleteArr()
{
	for (int i = 0; i < shapesInArr; i++)
	{
		delete shapeArr[i];
	}
	delete[] shapeArr;
}