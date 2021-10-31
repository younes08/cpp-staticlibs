#pragma once
namespace Algebra
{
	class Matrice
	{
		//Attributes
		private:
			int col;
			int line;
			int** Mat;
		//Methods

		public:
			//constructor
			Matrice(unsigned int, unsigned int);

			//Removing value returning or accessing
			Matrice(Matrice&) = delete;
			Matrice& operator=(const Matrice&) = delete;
			
			void filler(int val);
			Matrice& operator+(const Matrice&) const;
			Matrice& operator-(const Matrice&) const;
			Matrice& operator*(const Matrice&) const;
			Matrice& operator*(double) const;
			Matrice& operator/(double) const;
			void print() const;

			//destructor
			~Matrice();
	};
}

