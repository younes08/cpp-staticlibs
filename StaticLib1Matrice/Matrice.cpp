#include "pch.h"
#include "Matrice.h"
#include <cassert>
#include <iostream>

using namespace Algebra;
using namespace std;

Algebra::Matrice::Matrice(unsigned int line, unsigned int col)
{
	assert(line > 0 && col > 0);

	this->col = col;
	this->line = line;

	//allocate tab of lines
	this->Mat = new int* [line];
	
	//allocate tab of cols element for each line
	for (int i = 0; i < this->line; i++)
	{
		this->Mat[i] = new int[col];
		for (int j = 0; j < col; j++)
			this->Mat[i][j] = 0;
	}
}

void Algebra::Matrice::filler(int val)
{
	for (int i = 0; i < line; i++)
		for (int j = 0; j < col; j++)
			this->Mat[i][j] = val;
}

Matrice& Matrice::operator+(const Matrice& M) const
{
	//The new matrix
	Matrice* NewMat = new Matrice(this->line, this->col);

	if (this->col == M.col &&
		this->line == M.line)
	{
		//Summing up 
		for (int i = 0; i < this->col; i++)
			for (int j = 0; j < this->line; j++)
				NewMat->Mat[i][j] = this->Mat[i][j] + M.Mat[i][j];
	}
	else
		cout << "Incompatible dimensions\n";
	//if sum wasn't possible returning matrix of zeros

	return *NewMat;
}

Matrice& Algebra::Matrice::operator-(const Matrice& M) const
{
	//The new matrix
	Matrice* NewMat = new Matrice(this->line, this->col);

	if (this->col == M.col &&
		this->line == M.line)
	{
		//Summing up 
		for (int i = 0; i < this->col; i++)
			for (int j = 0; j < this->line; j++)
				NewMat->Mat[i][j] = this->Mat[i][j] - M.Mat[i][j];
	}
	else
	{
		cout << "Incompatible dimensions\n";
	}

	return *NewMat;
}

Matrice& Algebra::Matrice::operator*(const Matrice& M) const
{
	//The new matrix
	Matrice* NewMat = new Matrice(this->line, M.col);

	//check if dimensions are compatible
	if (this->col == M.line)
		for (int d = 0; d < M.col; d++)
			for (int i = 0; i < this->line; i++)
				for (int j = 0; j < this->col; j++)
					NewMat->Mat[i][d] += this->Mat[i][j] * M.Mat[j][d];
	else   
		cout << "Incompatible dimensions\n";

	return *NewMat;
}

Matrice& Algebra::Matrice::operator*(double val) const
{
	//The new matrix
	Matrice* NewMat = new Matrice(this->line, this->col);

	for (int i = 0; i < this->line; i++)
		for (int j = 0; j < this->col; j++)
			NewMat->Mat[i][j] = this->Mat[i][j] * val;

	return *NewMat;
}

Matrice& Algebra::Matrice::operator/(double val) const
{
	//The new matrix
	Matrice* NewMat = new Matrice(this->line, this->col);
	
	//checking if the value equals zero for division
	assert(val != 0);

	for (int i = 0; i < this->line; i++)
		for (int j = 0; j < this->col; j++)
			NewMat->Mat[i][j] = this->Mat[i][j] / val;

	return *NewMat;
}

void Algebra::Matrice::print() const
{
	for (int i = 0; i < this->line; i++)
	{
		cout << "|";
		for (int j = 0; j < this->col; j++)
			cout << " " << this->Mat[i][j] << " ";
		cout << "|" << endl;
	}
}

Algebra::Matrice::~Matrice()
{
	//deleting arrays of cols
	for (int i = 0; i < this->line; i++)
	{
		delete (this->Mat[i]);
		this->Mat[i] = 0;
	}
	
	//deleting lines array
	delete this->Mat;
	this->Mat = 0;
}
