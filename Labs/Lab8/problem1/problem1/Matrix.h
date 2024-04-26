#pragma once
#include<tuple>
#include<iostream>
#include<ostream>
#include <exception>
#include <stdexcept>
template<typename T>
using Triple = std::tuple<int, int, T>;
#define NULL_T 0

template<typename T>
class Matrix {

private:
    Triple<T>* elems; // array of elements of type tuple
    int cp; // capacity
    int n; // size
    int nrLine, nrCol;

    void resize();
    bool validLinesColumns(int i, int j) const; // checks if the ith line and jth column are valid

public:
    // constructor
    Matrix(int nrLines, int nrCols);

    // returns the number of lines
    int nrLines() const;

    // returns the number of columns
    int nrColumns() const;

    // returns the element from line i and column j (indexing starts from 0)
    // throws exception if (i,j) is not a valid position in the Matrix
    T element(int i, int j) const;

    // modifies the value from line i and column j
    // returns the previous value from the position
    // throws exception if (i,j) is not a valid position in the Matrix
    T modify(int i, int j, T e);
};

template<typename T>
Matrix<T>::Matrix(int nrLines, int nrCols)
    : cp{ nrLines * nrCols }, n{ 0 }, nrLine{ nrLines }, nrCol{ nrCols }, elems{ new Triple<T>[cp] } {}

template<typename T>
int Matrix<T>::nrLines() const
{
    return nrLine;
}

template<typename T>
int Matrix<T>::nrColumns() const
{
    return nrCol;
}

template<typename T>
T Matrix<T>::element(int i, int j) const
{
    if (!validLinesColumns(i, j)) {
        std::cout<<"Invalid position in the Matrix";
    }

    for (int k = 0; k < n; ++k) {
        if (std::get<0>(elems[k]) == i && std::get<1>(elems[k]) == j) {
            return std::get<2>(elems[k]);
        }
    }

    return NULL_T;
}

template<typename T>
T Matrix<T>::modify(int i, int j, T e)
{
    if (!validLinesColumns(i, j)) {
        std::cout << "Invalid position in the Matrix";
    }

    for (int k = 0; k < n; ++k) {
        if (std::get<0>(elems[k]) == i && std::get<1>(elems[k]) == j) {
            T old_value = std::get<2>(elems[k]);
            elems[k] = std::make_tuple(i, j, e);
            return old_value;
        }
    }

    elems[n++] = std::make_tuple(i, j, e);
    if (n == cp) {
        resize();
    }

    return NULL_T;
}

template<typename T>
void Matrix<T>::resize()
{
    cp *= 2;
    Triple<T>* new_elems = new Triple<T>[cp];
    for (int i = 0; i < n; ++i) {
        new_elems[i] = elems[i];
    }
    delete[] elems;
    elems = new_elems;
}

template<typename T>
bool Matrix<T>::validLinesColumns(int i, int j) const
{
    return i >= 0 && i < nrLine && j >= 0 && j < nrCol;
}
