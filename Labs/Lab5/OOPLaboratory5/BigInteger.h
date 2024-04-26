#pragma once
#include<string>
#include<iostream>

class BigInteger {

public:
	BigInteger();
	BigInteger(const std::string& number);
	int sgn() const;
	int compare(const BigInteger& N) const;
	bool operator==(const BigInteger& other) const;
	bool operator!=(const BigInteger& other) const;
	bool operator<(const BigInteger& other) const;
	bool operator<=(const BigInteger& other) const;
	bool operator>(const BigInteger& other) const;
	bool operator>=(const BigInteger& other) const;
	~BigInteger();
	BigInteger(const BigInteger& other);
	BigInteger& operator=(const BigInteger& other);
	BigInteger add(const BigInteger& N) const;
	BigInteger sub(const BigInteger& N) const;
	BigInteger operator+(const BigInteger& other);
	BigInteger operator+=(const BigInteger& other);
	BigInteger operator-(const BigInteger& other);
	BigInteger operator-=(const BigInteger& other);
	void prependZeros(int noOfZeros);
	void negate();
	BigInteger addArrays(const BigInteger& other);
	void digitizeArray();
	std::string to_string() const;
	friend std::ostream& operator<<(std::ostream& os, const BigInteger& b);
	BigInteger& operator++(); //pre-increment
	BigInteger operator++(int);

private:
	int* array;
	int size;
	bool sign;
};
