// MatrixTester.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Matrice.h"

using namespace std;
using namespace Algebra;

int main()
{
	Matrice M1(2, 2);
	Matrice M2(2, 2);
	M1.filler(5);
	M2.filler(-1);

	Matrice* M3;
	M3 = &(M1 + M2);
	M3->print();

	M3 = &(M1 - M2);
	M3->print();

	M3 = &(M1 * -1);
	M3->print();

	M3 = &(M1 / 5);
	M3->print();

	M3 = &(M1 * M2);
	M3->print();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
