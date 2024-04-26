
#include <iostream>
#include "Matrix.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
#include<string>
using namespace std;

int main() {


	/*testAll();
	testAllExtended();
	cout << "Test End" << endl;*/
	Matrix <int> intMatrix(3, 3);
	intMatrix.modify(1, 1, 2);
	std::cout << intMatrix.element(1, 1) << std::endl;

	Matrix<double> doubleMatrix(3, 3);
	doubleMatrix.modify(1, 1, 2.5);
	std::cout << doubleMatrix.element(1, 1) << std::endl;

	Matrix<char> stringMatrix(3, 3);
	stringMatrix.modify(1, 1, 'a');
	std::cout << stringMatrix.element(1, 1);



}