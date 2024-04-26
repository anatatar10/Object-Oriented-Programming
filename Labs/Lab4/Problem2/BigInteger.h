#pragma once
#include<string>
#include<iostream>


class BigInteger{

public:
	BigInteger();
	BigInteger(const std::string& number);
	int sgn() const;
	int compare(const BigInteger& N) const;
	bool operator==(const BigInteger& other) const;
	bool operator<(const BigInteger& other) const;
	bool operator<=(const BigInteger& other) const;
	bool operator>(const BigInteger& other) const;
	bool operator>=(const BigInteger& other) const;
	

private:
	int* array;
	int size;
	bool sign;
};
