#include "ShapeRegister.h"
#include <string>
#include <iostream>

using namespace std;

void step2(ShapeRegister * sReg);
void step3(ShapeRegister * sReg);
void step4(ShapeRegister * sReg);
void step5(ShapeRegister * sReg);
void step6(ShapeRegister * sReg);
void step7(ShapeRegister * sReg);
void step8(ShapeRegister * sReg);

void printArr(ShapeRegister * sReg);

int mainTest()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//STEP 1
	ShapeRegister * sReg = new ShapeRegister(2);
	cout << "Press Space to go forward in the test steps" << endl;
	getchar();

	//STEP 2
	system("CLS");
	step2(sReg);
	getchar();

	//STEP 3
	system("CLS");
	step3(sReg);
	getchar();

	//STEP 4
	system("CLS");
	step4(sReg);
	getchar();

	//STEP 5
	system("CLS");
	step5(sReg);
	getchar();

	//STEP 6
	system("CLS");
	step6(sReg);
	getchar();

	//STEP 7
	system("CLS");
	step7(sReg);
	getchar();

	//STEP 8
	system("CLS");
	step8(sReg);
	getchar();
	
	system("PAUSE");
	return 0;
}

void step2(ShapeRegister * sReg)
{
	//TEST 2
	cout << "Step 2: Add 2 shapes." << endl << endl;
	sReg->addBox(1, 2, 3);
	sReg->addCone(2, 6);
	printArr(sReg);
}

void step3(ShapeRegister * sReg)
{
	//TEST 3
	cout << "Step 3: Add a shape, Array expand" << endl << endl;
	sReg->addCone(7, 12);
	printArr(sReg);
}

void step4(ShapeRegister * sReg)
{
	//TEST 4
	cout << "Step 4: Remove and nonexisting shape" << endl
		<< "Try to remove shape with height 5" << endl << endl;

	int heightToRemove = 5;

	printArr(sReg);
	if (sReg->removeShape(heightToRemove))
		cout << "The Shape was successfully removed" << endl;
	else
		cout << "The Shape with height " << to_string(heightToRemove) << " did not exist." << endl;
}

void step5(ShapeRegister * sReg)
{
	cout << "Step 5: Remove shape" << endl << endl
		<< "Before:" << endl;
	printArr(sReg);
	sReg->removeShape(2);
	cout << "After:" << endl;
	printArr(sReg);
}

void step6(ShapeRegister * sReg)
{
	cout << "Step 6: Remove remaining shapes." << endl << endl
		<< "Before:" << endl;
	printArr(sReg);
	sReg->removeShape(6);
	sReg->removeShape(12);
	cout << "After:" << endl;
	printArr(sReg);
}

void step7(ShapeRegister * sReg)
{
	cout << "Step 7: Add 2 new shapes" << endl << endl;
	sReg->addBox(1, 2, 3);
	sReg->addCone(4, 3);
	printArr(sReg);
}

void step8(ShapeRegister * sReg)
{
	cout << "Step 7: Test Copyconstructor and assignment operator" << endl << endl;
	ShapeRegister * newSReg = new ShapeRegister(*sReg);
	ShapeRegister * newSReg2 = new ShapeRegister(2);
	*newSReg2 = *sReg;
	delete sReg;

	cout << "Register made by Copy Constructor:" << endl;
	printArr(newSReg);

	cout << "Register made by Assignment operator:" << endl;
	printArr(newSReg2);

	delete newSReg;
	delete newSReg2;
}

void printArr(ShapeRegister * sReg)
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
	delete[] strArr;
}
