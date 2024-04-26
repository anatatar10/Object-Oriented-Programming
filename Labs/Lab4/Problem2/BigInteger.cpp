#include "BigInteger.h"

#include <cctype> // for isdigit
#include <iostream>
#include <iomanip>
using namespace std;

BigInteger::BigInteger() : array{ nullptr }, size{ 0 }, sign{ false }
{}

BigInteger::BigInteger(const std::string& number)
{
	this->array = (int*)malloc(sizeof(int) * number.length());
	int i = 0;
	if (number[0] == '-')
	{
		sign = false; //negative sign is false
		i = 1;
	}
	else if (number[0] == '+')
	{
		sign = true;
		i = 1;
	}
	else
		sign = true;
	int k = 0;
	for (; i < number.length(); i++)
	{
		array[k] = number[i] - '0'; //'1' - '0' = 1
		k++;
	}
	size = k;
}

int BigInteger::sgn() const {
	if (this->size == 0)
		return 0;
	if (!this->sign)
		return -1;
	else {
		if (this->array[0] == 0)
			return 0;
		else
			return 1;
	}
}


int BigInteger::compare(const BigInteger& N) const {
	if (this->sign == 0 && N.sign == 0)
	{
		if (this->size < N.size)
		{
			return 1; //this is bigger
		}
		else if (this->size > N.size)
		{
			return -1;
		}
		else
		{
			for (int i = 0; i < this->size; i++)
			{
				if (this->array[i] < N.array[i])
					return 1;
				else if (this->array[i] > N.array[i])
					return -1;
			}
			return 0;
		}
	}
	else if (this->sign == 1 && N.sign == 1)
	{
		if (this->size < N.size)
		{
			return -1; //this is smaller
		}
		else if (this->size > N.size)
		{
			return 1;
		}
		else
		{
			for (int i = 0; i < this->size; i++)
			{
				if (this->array[i] < N.array[i])
					return -1;
				else if (this->array[i] > N.array[i])
					return 1;
			}
			return 0;
		}
	}
	else if (this->sign == 0 && N.sign == 1)
		return -1;
	else
		return 1;
}

bool BigInteger::operator==(const BigInteger& other) const
{
	return this->compare(other) == 0;
}

bool BigInteger::operator<(const BigInteger& other) const
{	
	return this->compare(other) == -1;
}

bool BigInteger::operator<=(const BigInteger& other) const
{
	return this->compare(other) == -1 || this->compare(other) == 0;
}

bool BigInteger::operator>(const BigInteger& other) const
{
	return this->compare(other) == 1;
}

bool BigInteger::operator>=(const BigInteger& other) const
{
	return this->compare(other) == 1 || this->compare(other) == 0;
}


