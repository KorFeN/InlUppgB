#include "ShapeRegister.h"
#include <string>
#include <iostream>

using namespace std;

bool addShape(ShapeRegister * sReg);
bool removeShape(ShapeRegister * sReg);
bool editShape(ShapeRegister * sReg);
void showAllShapes(ShapeRegister * sReg);
void showCones(ShapeRegister * sReg);
void showBoxes(ShapeRegister * sReg);


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	ShapeRegister * sReg = new ShapeRegister(2);
	bool running = true;

	while (running)
	{
		system("CLS");
		cout << "Boxes: " + to_string(sReg->nrOfBoxes()) << endl
			<< "Cones: " + to_string(sReg->nrOfCones()) << endl
			<< "Total: " + to_string(sReg->nrOfShapes()) << endl << endl
			<< "1. Add Shape" << endl
			<< "2. Remove Shape" << endl
			<< "3. Edit Shape" << endl
			<< "4. Show all shapes" << endl
			<< "5. Show Cones" << endl
			<< "6. Show Boxes" << endl << endl
			<< "0. Quit" << endl;

		string input = "";
		getline(cin, input);
		system("CLS");
		switch (input[0])
		{
		case '1':
			if (addShape(sReg))
			{
				cout << "Shape added successfully" << endl;
			}
			else
			{
				cout << "Shape could not be added" << endl;
			}
			break;
		case '2':
			if (removeShape(sReg))
			{
				cout << "Shape was successfully removed" << endl;
			}
			else
			{
				cout << "Shape could not be removed" << endl;
			}
			break;
		case '3':
			if (editShape(sReg))
			{
				cout << "Shape was edited" << endl;
			}
			else
			{
				cout << "Shape could not be edited" << endl;
			}
			break;
		case '4':
			showAllShapes(sReg);
			break;
		case '5':
			showCones(sReg);
			break;
		case '6':
			showBoxes(sReg);
			break;
		case '0':
			running = false;
			cout << "Press Enter to quit." << endl;
			break;

		default:
			cout << "Invalid input" << endl;
			break;
		}
		getchar();
	}
	delete sReg;
	return 0;
}

bool addShape(ShapeRegister * sReg)
{
	bool shapeAdded = false;

	cout << "1. Cone" << endl
		<< "2. Box" << endl;
	string input = "";
	getline(cin, input);
	system("CLS");

	int radius = 0;
	int height = 0;
	string radiusStr = "";
	string heightStr = "";

	int width = 0;
	int lenght = 0;
	string widthStr = "";
	string lenghtStr = "";

	switch (input[0])
	{
	case '1':
		cout << "Radius: ";
		getline(cin, radiusStr);
		radius = stoi(radiusStr);
		cout << "Height: ";
		getline(cin, heightStr);
		height = stoi(heightStr);
		
		shapeAdded = sReg->addCone(radius, height);
		break;
	case '2':
		cout << "Width: ";
		getline(cin, widthStr);
		width = stoi(widthStr);
		cout << "Height: ";
		getline(cin, heightStr);
		height = stoi(heightStr);
		cout << "Lenght: ";
		getline(cin, lenghtStr);
		lenght = stoi(lenghtStr);

		shapeAdded = sReg->addBox(width,height,lenght);
		break;
	default:
		cout << "invalid input" << endl;
		break;
	}

	return shapeAdded;
}

bool removeShape(ShapeRegister * sReg)
{
	cout << "Height of shape you want to remove: " << endl;
	string input = "";
	getline(cin, input);
	int height = stoi(input);

	return sReg->removeShape(height);
}

bool editShape(ShapeRegister * sReg)
{
	bool shapeEdited = false;

	cout << "1. Cone" << endl
		<< "2. Box" << endl;
	string input = "";
	getline(cin, input);
	system("CLS");

	int editObjHeight = 0;
	string editObjHeightStr = "";

	int radius = 0;
	int height = 0;
	string radiusStr = "";
	string heightStr = "";

	int width = 0;
	int lenght = 0;
	string widthStr = "";
	string lenghtStr = "";

	switch (input[0])
	{
	case '1':
		cout << "Height of cone you wish to edit: ";
		getline(cin, editObjHeightStr);
		editObjHeight = stoi(editObjHeightStr);
		cout << "New Radius: ";
		getline(cin, radiusStr);
		radius = stoi(radiusStr);
		cout << "New Height: ";
		getline(cin, heightStr);
		height = stoi(heightStr);

		shapeEdited = sReg->editACone(editObjHeight, radius, height);
		break;
	case '2':
		cout << "Height of box you wish to edit: ";
		getline(cin, editObjHeightStr);
		editObjHeight = stoi(editObjHeightStr);
		cout << "New Width: ";
		getline(cin, widthStr);
		width = stoi(widthStr);
		cout << "New Height: ";
		getline(cin, heightStr);
		height = stoi(heightStr);
		cout << "New Lenght: ";
		getline(cin, lenghtStr);
		lenght = stoi(lenghtStr);

		shapeEdited = sReg->editABox(editObjHeight, width, height, lenght);
		break;
	default:
		cout << "invalid input" << endl;
		break;
	}

	return shapeEdited;
}

void showAllShapes(ShapeRegister * sReg)
{
	int arrCap = sReg->nrOfShapes();
	string * strArr = new string[arrCap];
	bool added = sReg->getAllShapesAsStrings(strArr, arrCap);
	if (added)
	{
		for (int i = 0; i < arrCap; i++)
		{
			cout << strArr[i] << endl;
		}
	}
}

void showCones(ShapeRegister * sReg)
{
	int arrCap = sReg->nrOfCones();
	string * strArr = new string[arrCap];
	bool added = sReg->getAllConesAsStrings(strArr, arrCap);
	if (added)
	{
		for (int i = 0; i < arrCap; i++)
		{
			cout << strArr[i] << endl;
		}
	}
}

void showBoxes(ShapeRegister * sReg)
{
	int arrCap = sReg->nrOfBoxes();
	string * strArr = new string[arrCap];
	bool added = sReg->getAllBoxesAsStrings(strArr, arrCap);
	if (added)
	{
		for (int i = 0; i < arrCap; i++)
		{
			cout << strArr[i] << endl;
		}
	}
}
