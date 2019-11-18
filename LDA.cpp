#include <iostream>
#include <Eigen/Eigenvalues>	// Library to calculate eigenvalues and eigenvectors
#include <fstream>

using namespace std;
using namespace Eigen;

//------------------------------------------------- Matrix Class -----------------------------------------------------------

// Matrix class declaration
class matrix
{
private:
	int matrixRows;
	int matrixCols;
	double matrixData[500][10];
public:
	matrix(int, int);
	~matrix();
	void addData(double, int, int);
	double getData(int, int);
	int getRows(void);
	int getCols(void);
	double getMaxInCol(int col);
	int getMaxInRow(int row);
	int getMinInCol(int col);
	int getMinInRow(int row);
	int countClass(int col, int classVal);
	matrix* exportRow(int row);
	matrix* exportCol(int col);
	void print(string name);
	void printToFile(string name);

};

// Matrix class contructor
matrix::matrix(int rows, int cols)
{
	matrixRows = rows;
	matrixCols = cols;
	matrixData[0][0] = 0;
}

// Matrix class destructor
matrix::~matrix()
{

}

// Matrix class to add data
void matrix::addData(double data, int row, int col)
{
	matrixData[row][col] = data;
}

// Matrix class to get data
double matrix::getData(int row, int col)
{
	return matrixData[row][col];
}

// Matrix class to get row size
int matrix::getRows(void)
{
	return matrixRows;
}

// Matrix class to get column size
int matrix::getCols(void)
{
	return matrixCols;
}

// Matrix class to get maximum value
double matrix::getMaxInCol(int col)
{
	double max = numeric_limits<int>::min();
	
	for (int i = 0; i < matrixRows; i++)
	{
		if (matrixData[i][col] > max) { max = matrixData[i][col]; }
	}

	return max;
}

// Matrix class to get maximum value
int matrix::getMaxInRow(int row)
{
	int max = numeric_limits<int>::min();

	for (int i = 0; i < matrixCols; i++)
	{
		if (matrixData[row][i] > max) { max = matrixData[row][i]; }
	}

	return max;
}

// Matrix class to get minimum value
int matrix::getMinInCol(int col)
{
	int min = numeric_limits<int>::max();

	for (int i = 0; i < matrixRows; i++)
	{
		if (matrixData[i][col] < min) { min = matrixData[i][col]; }
	}

	return min;
}

// Matrix class to get minimum value
int matrix::getMinInRow(int row)
{
	int min = numeric_limits<int>::max();

	for (int i = 0; i < matrixCols; i++)
	{
		if (matrixData[row][i] < min) { min = matrixData[row][i]; }
	}

	return min;
}

// Matrix class to count class quantity
int matrix::countClass(int col, int classVal)
{
	int count = 0;

	for (int i = 0; i < matrixRows; i++)
	{
		if (matrixData[i][col] == classVal) { count++; }
	}

	return count;
}

// Export one row of data to a new matrix
matrix* matrix::exportRow(int row)
{
	matrix* result = new matrix(1, this->getCols());

	for (int j = 0; j < this->getCols(); j++)
	{
		result->addData(matrixData[row][j], 0, j);
	}
	return result;
}

// Export one column of data to a new matrix
matrix* matrix::exportCol(int col)
{
	matrix* result = new matrix(this->getRows(),1);

	for (int i = 0; i < this->getRows(); i++)
	{
		result->addData(matrixData[i][col], i, 0);
	}
	return result;
}

// Matrix class to print it on screen
void matrix::print(string name)
{
	cout << name << ": " << endl << matrixRows << " x " << matrixCols << " matrix" << endl << endl;

	for (int i = 0; i < this->getRows(); i++)
	{
		for (int j = 0; j < this->getCols(); j++)
		{
			cout << this->getData(i, j) << "    ";
		}
		cout << endl << endl;
	}
	cout << endl;
}

// Matrix class to print it on file
void matrix::printToFile(string name)
{
	name += ".csv";
	
	ofstream outputFile;
	outputFile.open(name);
	
	//outputFile << name << ": " << matrixRows << " x " << matrixCols << " matrix\n";

	for (int i = 0; i < this->getCols(); i++)
	{
		outputFile << name << " " << i << ";";
	}
	outputFile << "\n";

	for (int i = 0; i < this->getRows(); i++)
	{
		for (int j = 0; j < this->getCols(); j++)
		{
			outputFile << this->getData(i, j) << ";";
		}
		outputFile << "\n";
	}
	outputFile << "\n";

	outputFile.close();
}

//------------------------------------------------- Data Values -----------------------------------------------------------

// Alps Water data
double alps[17][2] = { {194.5, 20.79},
{194.3, 20.79},
{197.9, 22.4},
{198.4, 22.67},
{199.4, 23.15},
{199.9, 23.35},
{200.9, 23.89},
{201.1, 23.99},
{201.4, 24.02},
{201.3, 24.01},
{203.6, 25.14},
{204.6, 26.57},
{209.5, 28.49},
{208.6, 27.76},
{210.7, 29.04},
{211.9, 29.88},
{212.2, 30.06} };

// Books x Grades data
double books[40][3] = { {0,	9,	45},
{1,	15,	57},
{0,	10,	45},
{2,	16,	51},
{4,	10,	65},
{4,	20,	88},
{1,	11,	44},
{4,	20,	87},
{3,	15,	89},
{0,	15,	59},
{2,	8,	66},
{1,	13,	65},
{4,	18,	56},
{1,	10,	47},
{0,	8,	66},
{1,	10,	41},
{3,	16,	56},
{0,	11,	37},
{1,	19,	45},
{4,	12,	58},
{4,	11,	47},
{0,	19,	64},
{2,	15,	97},
{3,	15,	55},
{1,	20,	51},
{0,	6,	61},
{3,	15,	69},
{3,	19,	79},
{2,	14,	71},
{2,	13,	62},
{3,	17,	87},
{2,	20,	54},
{2,	11,	43},
{3,	20,	92},
{4,	20,	83},
{4,	20,	94},
{3,	9,	60},
{1,	8,	56},
{2,	16,	88},
{0,	10,	62} };

// US Census Dataset data
double census[11][2] = { {1900,	75.9950},
{1910,	91.9720},
{1920,	105.7110},
{1930,	123.2030},
{1940,	131.6690},
{1950,	150.6970},
{1960,	179.3230},
{1970,	203.2120},
{1980,	226.5050},
{1990,	249.6330},
{2000,	281.4220} };

// Iris flower database
double iris[150][5] = { {5.1, 3.5, 1.4, 0.2, 1},
{4.9,3.0,1.4,0.2,1},
{4.7,3.2,1.3,0.2,1},
{4.6,3.1,1.5,0.2,1},
{5.0,3.6,1.4,0.3,1},
{5.4,3.9,1.7,0.4,1},
{4.6,3.4,1.4,0.3,1},
{5.0,3.4,1.5,0.2,1},
{4.4,2.9,1.4,0.2,1},
{4.9,3.1,1.5,0.1,1},
{5.4,3.7,1.5,0.2,1},
{4.8,3.4,1.6,0.2,1},
{4.8,3.0,1.4,0.1,1},
{4.3,3.0,1.1,0.1,1},
{5.8,4.0,1.2,0.2,1},
{5.7,4.4,1.5,0.4,1},
{5.4,3.9,1.3,0.4,1},
{5.1,3.5,1.4,0.3,1},
{5.7,3.8,1.7,0.3,1},
{5.1,3.8,1.5,0.3,1},
{5.4,3.4,1.7,0.2,1},
{5.1,3.7,1.5,0.4,1},
{4.6,3.6,1.0,0.2,1},
{5.1,3.3,1.7,0.5,1},
{4.8,3.4,1.9,0.2,1},
{5.0,3.0,1.6,0.2,1},
{5.0,3.4,1.6,0.4,1},
{5.2,3.5,1.5,0.2,1},
{5.2,3.4,1.4,0.2,1},
{4.7,3.2,1.6,0.2,1},
{4.8,3.1,1.6,0.2,1},
{5.4,3.4,1.5,0.4,1},
{5.2,4.1,1.5,0.1,1},
{5.5,4.2,1.4,0.2,1},
{4.9,3.1,1.5,0.2,1},
{5.0,3.2,1.2,0.2,1},
{5.5,3.5,1.3,0.2,1},
{4.9,3.6,1.4,0.1,1},
{4.4,3.0,1.3,0.2,1},
{5.1,3.4,1.5,0.2,1},
{5.0,3.5,1.3,0.3,1},
{4.5,2.3,1.3,0.3,1},
{4.4,3.2,1.3,0.2,1},
{5.0,3.5,1.6,0.6,1},
{5.1,3.8,1.9,0.4,1},
{4.8,3.0,1.4,0.3,1},
{5.1,3.8,1.6,0.2,1},
{4.6,3.2,1.4,0.2,1},
{5.3,3.7,1.5,0.2,1},
{5.0,3.3,1.4,0.2,1},
{7.0,3.2,4.7,1.4,2},
{6.4,3.2,4.5,1.5,2},
{6.9,3.1,4.9,1.5,2},
{5.5,2.3,4.0,1.3,2},
{6.5,2.8,4.6,1.5,2},
{5.7,2.8,4.5,1.3,2},
{6.3,3.3,4.7,1.6,2},
{4.9,2.4,3.3,1.0,2},
{6.6,2.9,4.6,1.3,2},
{5.2,2.7,3.9,1.4,2},
{5.0,2.0,3.5,1.0,2},
{5.9,3.0,4.2,1.5,2},
{6.0,2.2,4.0,1.0,2},
{6.1,2.9,4.7,1.4,2},
{5.6,2.9,3.6,1.3,2},
{6.7,3.1,4.4,1.4,2},
{5.6,3.0,4.5,1.5,2},
{5.8,2.7,4.1,1.0,2},
{6.2,2.2,4.5,1.5,2},
{5.6,2.5,3.9,1.1,2},
{5.9,3.2,4.8,1.8,2},
{6.1,2.8,4.0,1.3,2},
{6.3,2.5,4.9,1.5,2},
{6.1,2.8,4.7,1.2,2},
{6.4,2.9,4.3,1.3,2},
{6.6,3.0,4.4,1.4,2},
{6.8,2.8,4.8,1.4,2},
{6.7,3.0,5.0,1.7,2},
{6.0,2.9,4.5,1.5,2},
{5.7,2.6,3.5,1.0,2},
{5.5,2.4,3.8,1.1,2},
{5.5,2.4,3.7,1.0,2},
{5.8,2.7,3.9,1.2,2},
{6.0,2.7,5.1,1.6,2},
{5.4,3.0,4.5,1.5,2},
{6.0,3.4,4.5,1.6,2},
{6.7,3.1,4.7,1.5,2},
{6.3,2.3,4.4,1.3,2},
{5.6,3.0,4.1,1.3,2},
{5.5,2.5,4.0,1.3,2},
{5.5,2.6,4.4,1.2,2},
{6.1,3.0,4.6,1.4,2},
{5.8,2.6,4.0,1.2,2},
{5.0,2.3,3.3,1.0,2},
{5.6,2.7,4.2,1.3,2},
{5.7,3.0,4.2,1.2,2},
{5.7,2.9,4.2,1.3,2},
{6.2,2.9,4.3,1.3,2},
{5.1,2.5,3.0,1.1,2},
{5.7,2.8,4.1,1.3,2},
{6.3,3.3,6.0,2.5,3},
{5.8,2.7,5.1,1.9,3},
{7.1,3.0,5.9,2.1,3},
{6.3,2.9,5.6,1.8,3},
{6.5,3.0,5.8,2.2,3},
{7.6,3.0,6.6,2.1,3},
{4.9,2.5,4.5,1.7,3},
{7.3,2.9,6.3,1.8,3},
{6.7,2.5,5.8,1.8,3},
{7.2,3.6,6.1,2.5,3},
{6.5,3.2,5.1,2.0,3},
{6.4,2.7,5.3,1.9,3},
{6.8,3.0,5.5,2.1,3},
{5.7,2.5,5.0,2.0,3},
{5.8,2.8,5.1,2.4,3},
{6.4,3.2,5.3,2.3,3},
{6.5,3.0,5.5,1.8,3},
{7.7,3.8,6.7,2.2,3},
{7.7,2.6,6.9,2.3,3},
{6.0,2.2,5.0,1.5,3},
{6.9,3.2,5.7,2.3,3},
{5.6,2.8,4.9,2.0,3},
{7.7,2.8,6.7,2.0,3},
{6.3,2.7,4.9,1.8,3},
{6.7,3.3,5.7,2.1,3},
{7.2,3.2,6.0,1.8,3},
{6.2,2.8,4.8,1.8,3},
{6.1,3.0,4.9,1.8,3},
{6.4,2.8,5.6,2.1,3},
{7.2,3.0,5.8,1.6,3},
{7.4,2.8,6.1,1.9,3},
{7.9,3.8,6.4,2.0,3},
{6.4,2.8,5.6,2.2,3},
{6.3,2.8,5.1,1.5,3},
{6.1,2.6,5.6,1.4,3},
{7.7,3.0,6.1,2.3,3},
{6.3,3.4,5.6,2.4,3},
{6.4,3.1,5.5,1.8,3},
{6.0,3.0,4.8,1.8,3},
{6.9,3.1,5.4,2.1,3},
{6.7,3.1,5.6,2.4,3},
{6.9,3.1,5.1,2.3,3},
{5.8,2.7,5.1,1.9,3},
{6.8,3.2,5.9,2.3,3},
{6.7,3.3,5.7,2.5,3},
{6.7,3.0,5.2,2.3,3},
{6.3,2.5,5.0,1.9,3},
{6.5,3.0,5.2,2.0,3},
{6.2,3.4,5.4,2.3,3},
{ 5.9,3.0,5.1,1.8,3} };

//------------------------------------------------- Support Functions -----------------------------------------------------------

// Copy matrix to Eigen library format
MatrixXd matrixToXd(matrix* ref)
{
	MatrixXd result(ref->getRows(), ref->getCols());

	for (int i = 0; i < ref->getRows(); i++)
	{
		for (int j = 0; j < ref->getCols(); j++)
		{
			result(i, j) = ref->getData(i, j);
		}
	}

	return result;
}

// Copy Eigen library format back to matrix
matrix* XdToMatrix(MatrixXd ref)
{
	matrix* result = new matrix(ref.rows(), ref.cols());

	for (int i = 0; i < ref.rows(); i++)
	{
		for (int j = 0; j < ref.cols(); j++)
		{
			result->addData(ref(i, j), i, j);
		}
	}

	return result;
}

// Copy Eigen library complex format back to matrix
matrix* XcdToMatrix(MatrixXcd ref)
{
	matrix* result = new matrix(ref.rows(), ref.cols());

	for (int i = 0; i < ref.rows(); i++)
	{
		for (int j = 0; j < ref.cols(); j++)
		{
			result->addData(real(ref(i, j)), i, j);
		}
	}

	return result;
}

// Matrix sum
matrix* matSum(matrix* matA, matrix* matB)
{
	matrix* result = new matrix(matA->getCols(), matA->getRows());

	for (int i = 0; i < matA->getRows(); i++)
	{
		for (int j = 0; j < matA->getCols(); j++)
		{
			result->addData(matA->getData(i, j) + matB->getData(i, j), i, j);
		}
	}
	return result;
}

// Matrix addition
matrix* matAdd(matrix* matA, matrix* matB)
{
	matrix* result = new matrix(matA->getRows(), matA->getCols());
	
	for (int i = 0; i < matA->getRows(); i++)
	{
		for (int j = 0; j < matA->getCols(); j++)
		{
			result->addData(matA->getData(i, j) + matB->getData(i, j), i, j);
		}
	}
	return result;
}

// Matrix subtraction
matrix* matSub(matrix* matA, matrix* matB)
{
	matrix* result = new matrix(matA->getRows(), matA->getCols());
	
	for (int i = 0; i < matA->getRows(); i++)
	{
		for (int j = 0; j < matA->getCols(); j++)
		{
			result->addData(matA->getData(i, j) - matB->getData(i, j), i, j);
		}
	}
	//matA->print("matA");
	//matB->print("matB");
	//result->print("Result");
	return result;
}

// Matrix transposer
matrix* matTrans(matrix* mat)
{
	matrix* result = new matrix(mat->getCols(), mat->getRows());

	for (int i = 0; i < mat->getRows(); i++)
	{
		for (int j = 0; j < mat->getCols(); j++)
		{
			result->addData(mat->getData(i, j), j, i);
		}
	}
	return result;
}

// Matrix multiplier
matrix* matMult(matrix* matA, matrix* matB)
{

	if (matA->getCols() != matB->getRows())
	{
		cout << "Matrix multiplication incompatibility" << endl;
	}

	matrix* result = new matrix(matA->getRows(), matB->getCols());
	double total;

	for (int i = 0; i < matA->getRows(); i++)
	{
		for (int j = 0; j < matB->getCols(); j++)
		{
			total = 0;
			for (int a = 0; a < matA->getCols(); a++)
			{
				total += matA->getData(i, a) * matB->getData(a, j);
			}
			result->addData(total, i, j);
		}
	}
	return result;
}

// Matrix scalar multiplier
matrix* matScalarMult(double mult, matrix* matA)
{
	matrix* result = new matrix(matA->getRows(), matA->getCols());

	for (int i = 0; i < matA->getRows(); i++)
	{
		for (int j = 0; j < matA->getCols(); j++)
		{
			result->addData(matA->getData(i, j) * mult, i, j);
		}
	}
	return result;
}

// Matrix minor build
matrix* matMinor(matrix* mat, int row, int col)
{
	matrix* calc = new matrix(mat->getRows() - 1, mat->getCols() - 1);

	for (int i = 0; i < mat->getRows(); i++)
	{
		for (int j = 0; j < mat->getCols(); j++)
		{
			if (i != row && j != col)
			{
				int a = i;
				int b = j;
				if (i > row)
				{
					a--;
				}
				if (j > col)
				{
					b--;
				}
				calc->addData(mat->getData(i, j), a, b);
			}
		}
	}
	return calc;
}

// Matrix determinant calculator
double matDet(matrix* mat)
{
	double det = 0;

	//for (int i = 0; i < mat->getRows(); i++)
	//{
	//	for (int j = 0; j < mat->getCols(); j++)
	//	{
	//		cout << mat->getData(i, j) << "    ";
	//	}
	//	cout << endl << endl;
	//}

	if (mat->getRows() == 2)
	{
		det = (mat->getData(0, 0) * mat->getData(1, 1)) - (mat->getData(0, 1) * mat->getData(1, 0));
	}
	else
	{
		for (int a = 0; a < mat->getCols(); a++)
		{
			matrix* calc = matMinor(mat, 0, a);

			if (a % 2 == 0)
			{
				det += mat->getData(0, a) * (matDet(calc));
			}
			else
			{
				det -= mat->getData(0, a) * (matDet(calc));
			}
		}
	}
	//cout << "determinant = " << det << endl << endl;
	return det;
}

// Matrix inverter
matrix* matInv(matrix* mat)
{
	double det = matDet(mat);
	matrix* calc = new matrix(mat->getRows(), mat->getCols());

	if (mat->getRows() == 1)
	{
		calc->addData(1 / mat->getData(0, 0), 0, 0);
	}
	else if (mat->getRows() == 2)
	{
		calc->addData(mat->getData(1, 1) / det, 0, 0);
		calc->addData(-mat->getData(0, 1) / det, 0, 1);
		calc->addData(-mat->getData(1, 0) / det, 1, 0);
		calc->addData(mat->getData(0, 0) / det, 1, 1);
	}
	else
	{
		matrix* cofactors = new matrix(mat->getRows(), mat->getCols());
		matrix* adjugate = new matrix(mat->getRows(), mat->getCols());

		for (int i = 0; i < mat->getRows(); i++)
		{
			for (int j = 0; j < mat->getCols(); j++)
			{
				if (((i % 2 == 0) && (j % 2 == 0)) || ((i % 2 != 0) && (j % 2 != 0)))
				{
					cofactors->addData(matDet(matMinor(mat, i, j)), i, j);
				}
				else
				{
					cofactors->addData(-matDet(matMinor(mat, i, j)), i, j);
				}
			}
		}

		for (int i = 0; i < cofactors->getRows(); i++)
		{
			for (int j = i; j < cofactors->getCols(); j++)
			{
				if (i == j)
				{
					adjugate->addData(cofactors->getData(i, j), i, j);
				}
				else
				{
					adjugate->addData(cofactors->getData(i, j), j, i);
					adjugate->addData(cofactors->getData(j, i), i, j);
				}
			}
		}

		for (int i = 0; i < adjugate->getRows(); i++)
		{
			for (int j = 0; j < adjugate->getCols(); j++)
			{
				calc->addData(adjugate->getData(i, j) / det, i, j);
			}
		}
	}
	return calc;
}

// Linear regression
matrix* linear(matrix* x, matrix* y)
{
	cout << "Linear:" << endl << endl;

	matrix* xt = matTrans(x);
	matrix* xtx = matMult(xt, x);
	matrix* xty = matMult(xt, y);
	matrix* xtx1 = matInv(xtx);
	matrix* beta = matMult(xtx1, xty);

	beta->print("Beta");

	return beta;
}

// Quadratic regression
matrix* quad(matrix* x, matrix* y)
{
	cout << "Quadratic:" << endl << endl;

	matrix* x2 = new matrix(x->getRows(), (x->getCols() * 2) - 1);

	for (int i = 0; i < x->getRows(); i++)
	{
		x2->addData(1, i, 0);
		for (int j = 1; j < ((x->getCols() * 2) - 1); j++)
		{
			if (j < x->getCols())
			{
				x2->addData(x->getData(i, j), i, j);
			}
			else
			{
				x2->addData(pow(x->getData(i, j - x->getCols() + 1), 2), i, j);
			}
		}
	}

	matrix* xt = matTrans(x2);
	matrix* xtx = matMult(xt, x2);
	matrix* xty = matMult(xt, y);
	matrix* xtx1 = matInv(xtx);
	matrix* beta = matMult(xtx1, xty);

	beta->print("Beta");

	return beta;
}

// Robust regression
matrix* robust(matrix* x, matrix* y, matrix* ref)
{
	cout << "Robust:" << endl << endl;

	matrix* w = new matrix(x->getRows(), 1);
	for (int i = 0; i < x->getRows(); i++)
	{
		w->addData(abs(1 / (y->getData(i, 0) - (ref->getData(0, 0) + x->getData(i, 1) * ref->getData(1, 0)))), i, 0);
	}
	//w->print();

	matrix* wx = new matrix(x->getRows(), x->getCols());
	for (int i = 0; i < x->getRows(); i++)
	{
		for (int j = 0; j < x->getCols(); j++)
		{
			wx->addData(x->getData(i, j) * w->getData(i, 0), i, j);
		}

	}

	matrix* wy = new matrix(y->getRows(), y->getCols());
	for (int i = 0; i < y->getRows(); i++)
	{
		wy->addData(y->getData(i, 0) * w->getData(i, 0), i, 0);
	}

	matrix* xt = matTrans(x);
	matrix* xtx = matMult(xt, wx);
	matrix* xty = matMult(xt, wy);
	matrix* xtx1 = matInv(xtx);
	matrix* beta = matMult(xtx1, xty);

	beta->print("Beta");

	return beta;
}

// Covariance calculation
matrix* covariance(matrix* ref)
{
	matrix* cov = new matrix(ref->getCols(), ref->getCols());

	// Averages calculation
	matrix* avg = new matrix(ref->getCols(), 1);
	for (int i = 0; i < avg->getRows(); i++)
	{
		double sum = 0;
		for (int j = 0; j < ref->getRows(); j++)
		{
			sum += ref->getData(j, i);
		}
		double mean = sum / ref->getRows();
		avg->addData(mean, i, 0);
	}

	avg->print("Averages");

	// Covariance calculation
	for (int i = 0; i < ref->getRows(); i++)
	{
		for (int j = i; j < ref->getCols(); j++)
		{
			double sum = 0;
			for (int a = 0; a < ref->getRows(); a++)
			{
				sum += (ref->getData(a, i) - avg->getData(i, 0)) * (ref->getData(a, j) - avg->getData(j, 0));
			}
			cov->addData(sum / double(ref->getRows() - (double)1), i, j);
			if (i != j) { cov->addData(cov->getData(i, j), j, i); }
		}
	}
	
	cov->print("Covariance");
	return cov;
}

// Eigenvalue calculation
matrix* eigenvalues(matrix* ref)
{
	matrix* eigenval = new matrix(ref->getRows(), 1);

	if (ref->getRows() == 2)
	{
		// Based on 2x2 determinant (y as lambda): y^2 - (a + d)*y + (a*d - c*b)
		// For matrix:
		// |a  b|
		// |c  d|
		double a = 1;
		double b = -(ref->getData(0, 0) + ref->getData(1, 1));
		double c = (ref->getData(0, 0) * ref->getData(1, 1)) - (ref->getData(1, 0) * ref->getData(0, 1));

		//cout << "a = " << a << " b = " << b << " c = " << c << endl << endl;
		//cout << (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a) << endl;

		eigenval->addData((-b + sqrt(pow(b, 2) - (4 * a * c))) / (2 * a), 0, 0);
		eigenval->addData((-b - sqrt(pow(b, 2) - (4 * a * c))) / (2 * a), 1, 0);
	}
	else
	{
		MatrixXd refXdVal = matrixToXd(ref);

		EigenSolver<MatrixXd> eVal(refXdVal);

		eigenval = XcdToMatrix(eVal.eigenvalues());
	}

	eigenval->print("Eigenvalues");

	return eigenval;
}

// Eigenvectros calculation
matrix* eigenvectors(matrix* ref, matrix* eigenvalues)
{
	matrix* eigvector = new matrix(ref->getRows(), eigenvalues->getRows());

	if (ref->getRows() == 2)
	{
		for (int i = 0; i < eigenvalues->getRows(); i++)
		{
			eigvector->addData(ref->getData(0, 1) / (eigenvalues->getData(i, 0) - ref->getData(0, 0)), 0, i);
			eigvector->addData(1, 1, i);
		}
	}
	else
	{
		MatrixXd refXdVec = matrixToXd(ref);

		EigenSolver<MatrixXd> eVec(refXdVec);

		eigvector = XcdToMatrix(eVec.eigenvectors());

		for (int j = 0; j < eigvector->getCols(); j++)
		{
			double pot = (double)1 / eigvector->getData(eigvector->getRows() - (double)1, j);
			for (int i = 0; i < eigvector->getRows(); i++)
			{
				eigvector->addData(eigvector->getData(i, j) * pot, i, j);
			}
		}
	}

	eigvector->print("Eigenvectors");

	return eigvector;
}

// Best eigenvector selection
matrix* bestEigenvec(matrix* eigenvec, matrix* eigenval, int quantity)
{
	matrix bestCol(quantity, 1);
	matrix support = *eigenval;

	for (int i = 0; i < quantity; i++)
	{
		double maxEigVal = support.getMaxInCol(0);

		for (int j = 0; j < support.getRows(); j++)
		{
			if (support.getData(j, 0) == maxEigVal)
			{
				support.addData(numeric_limits<double>::min(), j, 0);
				bestCol.addData(j, i, 0);
			}
		}
	}

	matrix* bestvec = new matrix(eigenvec->getRows(), quantity);

	for (int i = 0; i < eigenvec->getRows(); i++)
	{
		for (int j = 0; j < quantity; j++)
		{
			bestvec->addData(eigenvec->getData(i, bestCol.getData(j, 0)), i, j);
		}
	}

	eigenvec->print("Eigen");
	bestCol.print("Bestcol:");
	bestvec->print("Best Eigenvectors:");

	return bestvec;
}

// Si calculation
matrix* SiCalc(matrix* x, matrix* y, matrix* classMean, int cat)
{
	matrix* Si = new matrix(classMean->getCols(), classMean->getCols());

	for (int i = 0; i < Si->getRows(); i++)
	{
		for (int j = 0; j < Si->getCols(); j++)
		{
			Si->addData(0, i, j);
		}
	}

	matrix* mu = new matrix(1, x->getCols() - 1);

	for (int i = 0; i < x->getRows(); i++)
	{
		if (y->getData(i, 0) == cat)
		{
			for (int j = 1; j < x->getCols(); j++)
			{
				mu->addData(x->getData(i, j) - classMean->getData(y->getData(i, 0) - 1, j - 1), 0, j - 1);
			}
			matrix* mut = matTrans(mu);
			matrix* mult = matMult(mut, mu);
			Si = matAdd(Si, mult);
		}
	}

	string text("S" + to_string(cat));
	Si->print(text);

	return Si;
}

// Sw calculation
matrix* SwCalc(matrix* x, matrix* y, matrix* classMean)
{
	matrix* Sw = new matrix(classMean->getCols(), classMean->getCols());
	
	for (int i = 0; i < Sw->getRows(); i++)
	{
		for (int j = 0; j < Sw->getCols(); j++)
		{
			Sw->addData(0, i, j);
		}
	}

	for (int i = 1; i <= y->getMaxInCol(0); i++)
	{
		Sw = matAdd(Sw, SiCalc(x, y, classMean, i));
	}

	Sw->print("Sw");

	return Sw;
}

// Sb calculation
matrix* SbCalc(matrix* x, matrix* y, matrix* classMean, matrix* grandMean, matrix* sw)
{
	matrix* Sb = new matrix(classMean->getCols(), classMean->getCols());

	for (int i = 0; i < Sb->getRows(); i++)
	{
		for (int j = 0; j < Sb->getCols(); j++)
		{
			Sb->addData(0, i, j);
		}
	}

	//classMean->print("Class Mean Sb");
	//grandMean->print("Grand Mean Sb");

	for (int i = 0; i < y->getMaxInCol(0); i++)
	{
		matrix* calc = matSub(classMean->exportRow(i), grandMean->exportRow(0));
		matrix* calct = matTrans(calc);

		Sb = matAdd(Sb, matScalarMult(y->countClass(0, i + 1), matMult(calct, calc)));
	}

	Sb->print("Sb");

	return Sb;
}

// PCA calculation
matrix* PCA(matrix* x, matrix* y, int quantity)
{
	cout << "--------PCA------" << endl << endl;
	
	matrix* xy = new matrix(x->getRows(), x->getCols());

	for (int i = 0; i < xy->getRows(); i++)
	{
		for (int j = 0; j < x->getCols(); j++)
		{
			xy->addData(x->getData(i, j + 1), i, j);
		}
		xy->addData(y->getData(i, 0), i, x->getCols() - 1);
	}

	matrix* cov = covariance(xy);
	matrix* eigenval = eigenvalues(cov);
	matrix* eigenvec = eigenvectors(cov, eigenval);
	matrix* featureEig = bestEigenvec(eigenvec, eigenval, quantity);
	matrix* featureEigT = matTrans(featureEig);
	matrix* xyT = matTrans(xy);
	matrix* result = matMult(featureEigT, xyT);
	result = matTrans(result);
	//featureEig->print("Feature");
	//xyT->print("xyT");
	result->print("Result");

	return result;
}

// LDA calculation
matrix* LDA(matrix* x, matrix* y)
{
	cout << "--------LDA------" << endl << endl;
	
	// Calculating data mean vector
	matrix* classMean = new matrix(y->getMaxInCol(0), x->getCols() - 1);
	matrix* classSum = new matrix(y->getMaxInCol(0), x->getCols() - 1);
	
	matrix* grandMean = new matrix(1, x->getCols() - 1);
	matrix* grandSum = new matrix(1, x->getCols() - 1);

	for (int i = 0; i < classSum->getRows(); i++)
	{
		for (int j = 0; j < classSum->getCols(); j++)
		{
			classSum->addData(0, i, j);
			classMean->addData(0, i, j);
			grandSum->addData(0, 0, j);
			grandMean->addData(0, 0, j);
		}
	}
	
	for (int i = 0; i < x->getRows(); i++)
	{
		for (int j = 0; j < x->getCols() - 1; j++)
		{
			classSum->addData(classSum->getData(y->getData(i, 0) - 1, j) + x->getData(i, j + 1), y->getData(i, 0) - 1, j);
			grandSum->addData(grandSum->getData(0, j) + x->getData(i, j + 1), 0, j);
		}
	}

	for (int i = 0; i < x->getRows(); i++)
	{
		for (int j = 0; j < y->getMaxInCol(0); j++)
		{
			classMean->addData(classSum->getData(j, i) / y->countClass(0, j + 1), j, i);
			grandMean->addData(grandSum->getData(j, i) / y->getRows(), j, i);
		}
	}

	classMean->print("Class Mean");
	grandMean->print("Grand Mean");

	matrix* Sw = SwCalc(x, y, classMean);
	matrix* Sb = SbCalc(x, y, classMean, grandMean, Sw);
	matrix* Sw1 = matInv(Sw);
	matrix* SwSb = matMult(matInv(Sw), Sb);

	SwSb->print("SwSb");

	matrix* eigenval = eigenvalues(SwSb);
	matrix* eigenvec = eigenvectors(SwSb,eigenval);

	return eigenvec;
}

//------------------------------------------------- Data Calculations -----------------------------------------------------------

// Alps Water Calculus
void AlpsCalc(void)
{
	cout << "------------------------  Calculating Alps Water  ------------------------" << endl << endl;

	matrix* x = new matrix(17, 2);
	for (int i = 0; i < x->getRows(); i++)
	{
		x->addData(1, i, 0);
		x->addData(alps[i][0], i, 1);
	}

	matrix* y = new matrix(17, 1);
	for (int i = 0; i < y->getRows(); i++)
	{
		y->addData(alps[i][1], i, 0);
	}

	//matrix* lin = linear(x, y);
	//matrix* qua = quad(x, y);
	//matrix* rob = robust(x, y, lin);

	matrix* pca = PCA(x, y, 1);
}

// Books and grades calculus
void BooksCalc(void)
{
	cout << "------------------------  Calculating Books and Grades  ------------------------" << endl << endl;

	matrix* x = new matrix(40, 3);
	for (int i = 0; i < x->getRows(); i++)
	{
		x->addData(1, i, 0);
		x->addData(books[i][0], i, 1);
		x->addData(books[i][1], i, 2);
	}

	matrix* y = new matrix(40, 1);
	for (int i = 0; i < y->getRows(); i++)
	{
		y->addData(books[i][2], i, 0);
	}

	matrix* xy = new matrix(40, 3);
	for (int i = 0; i < xy->getRows(); i++)
	{
		xy->addData(x->getData(i, 1), i, 0);
		xy->addData(x->getData(i, 2), i, 1);
		xy->addData(y->getData(i, 0), i, 2);
	}

	//matrix* cov = covariance(xy);
	//matrix* eigenval = eigenvalues(cov);

	matrix* pca = PCA(x, y, 2);

	//matrix* lin = linear(x, y);
	//matrix* qua = quad(x, y);
	//matrix* rob = robust(x, y, lin);
}

// US census calculation
void CensusCalc(void)
{
	cout << "------------------------  Calculating US Census  ------------------------" << endl << endl;

	matrix* x = new matrix(11, 2);
	for (int i = 0; i < x->getRows(); i++)
	{
		x->addData(1, i, 0);
		x->addData(census[i][0], i, 1);
	}

	matrix* y = new matrix(11, 1);
	for (int i = 0; i < y->getRows(); i++)
	{
		y->addData(census[i][1], i, 0);
	}

	//matrix* lin = linear(x, y);
	//matrix* qua = quad(x, y);
	//matrix* rob = robust(x, y, lin);

	matrix* pca = PCA(x, y, 1);
}

// Iris flower calculation
void irisCalc(void)
{
	cout << "------------------------  Calculating Iris Flower  ------------------------" << endl << endl;

	matrix* xPCA = new matrix(150, 4);
	matrix* yPCA = new matrix(150, 1);
	for (int i = 0; i < xPCA->getRows(); i++)
	{
		xPCA->addData(1, i, 0);
		xPCA->addData(iris[i][0], i, 1);
		xPCA->addData(iris[i][1], i, 2);
		xPCA->addData(iris[i][2], i, 3);
		yPCA->addData(iris[i][3], i, 0);
	}

	
	for (int i = 0; i < yPCA->getRows(); i++)
	{
		yPCA->addData(iris[i][4], i, 0);
	}

	matrix* xLDA = new matrix(150, 5);
	matrix* yLDA = new matrix(150, 1);
	for (int i = 0; i < xLDA->getRows(); i++)
	{
		xLDA->addData(1, i, 0);
		xLDA->addData(iris[i][0], i, 1);
		xLDA->addData(iris[i][1], i, 2);
		xLDA->addData(iris[i][2], i, 3);
		xLDA->addData(iris[i][3], i, 4);

		yLDA->addData(iris[i][4], i, 0);
	}

	cout << "--------------------  Independent PCA and LDA  --------------------" << endl << endl;

	matrix* pca = PCA(xPCA, yPCA, 2);
	pca->printToFile("PCA Original");

	matrix* lda = LDA(xLDA, yLDA);
	lda->printToFile("LDA Original");

	for (int i = 1; i < 4; i++)
	{
		cout << "---------------  LDA and PCA with " << i << " dimmensions  -------------" << endl << endl;
		matrix* pca = PCA(xPCA, yPCA, i);
		matrix* newData = new matrix(pca->getRows(), pca->getCols() + 1);
		for (int i = 0; i < pca->getRows(); i++)
		{
			newData->addData(1, i, 0);
			for (int j = 0; j < pca->getCols(); j++)
			{
				newData->addData(pca->getData(i, j), i, j + 1);
			}
		}

		string name = "PCA with " + to_string(i) + " dimmension";
		newData->printToFile(name);

		matrix* lda = LDA(newData, yLDA);
		name = "LDA after " + to_string(i) + " dimmension PCA";
		lda->printToFile(name);
	}
}

//------------------------------------------------- Main Loop -----------------------------------------------------------

// Main loop
int main()
{
	//AlpsCalc();

	//BooksCalc();

	//CensusCalc();

	irisCalc();

	cin.get();
}