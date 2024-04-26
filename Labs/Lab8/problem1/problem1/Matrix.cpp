#include "Matrix.h"
#include<iostream>
#include <exception>
#include <stdexcept>
//using namespace std;
//
//template<typename TElem>
//void Matrix<TElem>::resize() {
//	//We allocate a new array of tuples with double capacity somewhere in the computer's memory
//	Triple<TElem>* elemsNou = new Triple[2 * cp];
//
//	//We copy all the elements from the old array into the new array
//	for (int i = 0; i < n; i++)
//	{
//		get<0>(elemsNou[i]) = get<0>(elems[i]);
//		get<1>(elemsNou[i]) = get<1>(elems[i]);
//		get<2>(elemsNou[i]) = get<2>(elems[i]);
//	}
//
//	//We double the capacity
//	cp = 2 * cp;
//
//	//We release the memory space occupied by the old array
//	delete[] elems;
//
//	//We make the field e to refer the new array (with double capacity)
//	elems = elemsNou;
//
//	//BC: θ(n);
//	//WC: θ(n);
//	//AC: O(n);
//}
//
//
//template<typename TElem>
//Matrix<TElem>::Matrix(int nrLines, int nrCols) {
//
//	//TODO - Implementation
//
//	//We initialize the capacity
//	this->cp = 1;
//
//	//We allocate memory space for an array with at most cp capacity
//	this->elems = new Triple<TElem>[this->cp];
//
//	//We initialize the number of elements
//	this->n = 0;
//	//We initialize the number of lines
//	this->nrLine = nrLines;
//	//We initialize the number of columns
//	this->nrCol = nrCols;
//
//	//BC: θ(1);
//	//WC: θ(1);
//	//AC: O(1);
//}
//
//template<class TElem>
//bool Matrix<TElem>::validLinesColumns(int i, int j) const {
//	// We check that the given position is valid
//	if ((i >= 0 && i < this->nrLine) && (j >= 0 && j < this->nrCol))
//	{
//		return true;
//	}
//	else
//		return false;
//
//	//BC: θ(1);
//	//WC: θ(1);
//	//AC: O(1);
//}
//
//template<class TElem>
//int Matrix<TElem>::nrLines() const {
//	// returns the number of lines in the matrix
//
//	return this->nrLine;
//
//	//BC: θ(1);
//	//WC: θ(1);
//	//AC: O(1);
//}
//
//
//template<class TElem>
//int Matrix<TElem>::nrColumns() const {
//	// returns the number of columns in the matrix
//
//	return this->nrCol;
//	//BC: θ(1);
//	//WC: θ(1);
//	//AC: O(1);
//}
//
//template<class TElem>
//TElem Matrix<TElem>::element(int i, int j) const {
//	// we get the element at the given position
//
//	if (validLinesColumns(i, j) == true)
//	{
//		for (int k = 0; k < this->n; k++)
//		{
//			if (get<0>(elems[k]) == i && get<1>(elems[k]) == j)
//			{
//				return get<2>(elems[k]);
//			}
//		}
//	}
//	else
//		throw exception("Invalid position");
//	return NULL_TELEM;
//
//	//BC: θ(1);
//	//WC: θ(n);
//	//AC: O(n);
//}
//
//template<class TElem>
//TElem Matrix<TElem>::modify(int i, int j, TElem e)
//{
//	// we modifiy the element at the given position if the current element is != 0, otherwise we add a new element in the array
//	if (e == NULL_TELEM) // delete element 
//	{
//		if (validLinesColumns(i, j))
//		{
//			TElem aux = NULL_TELEM;
//			int position = -1;
//			for (int k = 0; k < this->n; k++)
//			{
//				if (get<0>(elems[k]) == i && get<1>(elems[k]) == j)
//				{
//					position = k;
//					aux = get<2>(elems[k]);
//					get<2>(elems[k]) = NULL_TELEM;
//					break;
//				}
//			}
//			if (position != -1)
//			{
//				for (int j = position; j < this->n - 1; j++)
//				{
//					get<0>(elems[j]) = get<0>(elems[j + 1]);
//					get<1>(elems[j]) = get<1>(elems[j + 1]);
//					get<2>(elems[j]) = get<2>(elems[j + 1]);
//				}
//			}
//			return aux;
//		}
//		else
//			throw exception("Invalid position");
//	}
//
//	if (validLinesColumns(i, j))
//	{
//		for (int k = 0; k < this->n; k++)
//		{
//			if (get<0>(elems[k]) == i && get<1>(elems[k]) == j) // if the position is found in the element, we modify the current element with the new one
//			{
//				TElem aux = get<2>(elems[k]);
//				get<2>(elems[k]) = e;
//				return aux;
//			}
//		}
//	}
//	else
//		throw exception("Invalid position");
//
//	// if we didn't return the current element, it means that the current element is 0, so we need to create a new tuple where we add the new element
//	tuple <int, int, TElem> Triple1;
//	if (this->n == cp) // we check is the capacity is equal to the number of elements and in this case, we resize the array
//	{
//		resize();
//	}
//	Triple1 = make_tuple(i, j, e);
//	elems[this->n] = Triple1;
//	this->n++;
//	return NULL_TELEM;
//
//	//BC: θ(1);
//	//WC: θ(n);
//	//AC: O(n);
//}
//
//

