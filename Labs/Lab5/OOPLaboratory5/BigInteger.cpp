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
	//this->array = new int[number.length()];
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

bool BigInteger::operator!=(const BigInteger& other) const
{
	return this->compare(other) == 1;
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


BigInteger::~BigInteger() 
{
	if (array)
	{
		delete[] array;
		array = nullptr;
	}
}

BigInteger::BigInteger(const BigInteger& other)
{
	this->size = other.size;
	this->sign = other.sign;
	this->array = new int[this->size];
	for (int i = 0; i < this->size; i++)
		array[i] = other.array[i];
}

BigInteger& BigInteger::operator=(const BigInteger& other)
{
	if (this != &other)
	{
		if (array)
			delete[] array;
		this->size = other.size;
		this->sign = other.sign;
		this->array = new int[this->size];
		for (int i = 0; i < this->size; i++)
			this->array[i] = other.array[i];
	}
	return *this;
}


BigInteger BigInteger::add(const BigInteger& N) const
{
	BigInteger c(*this);
	if (c.sign == 1 && N.sign == 1)
	{
		// Adun două numere pozitive
		BigInteger aux = c.addArrays(N);
		aux.digitizeArray();
		return aux;
	}
	else if (c.sign == 1 && N.sign == 0)
	{
		// Am număr pozitiv + numar negativ (2 + (-3) = 2 - 3)
		BigInteger c1(N);
		c1.sign = !c1.sign;
		return c.sub(c1);
	}
	else if (c.sign == 0 && N.sign == 1)
	{
		// Am un număr negativ + un număr pozitiv (-3 + 2 = 2 - 3)
		c.sign = !c.sign;
		return N.sub(c);

	}
	else if (c.sign == 0 && N.sign == 0)
	{
		// Adun două numere negative (-3 + (-2) = -3 - 2 = -5)
		BigInteger c1(N);
		c.sign = !c.sign;
		c1.sign = !c1.sign;
		BigInteger aux = c.add(c1);
		aux.sign = !aux.sign;
		return aux;
	}
}

BigInteger BigInteger::sub(const BigInteger& N) const
{
	BigInteger c(*this);
	if (c.sign == 0 && N.sign == 1)
	{
		// Am număr negativ - numar pozitiv (-3 - 2 = -(3 + 2))
		BigInteger c1(N);
		c.sign = !c.sign;
		c1.sign = !c1.sign;
		BigInteger aux = c1.add(c);
		aux.sign = !aux.sign;
		return aux;
	}
	else if (c.sign == 1 && N.sign == 0)
	{
		// Am număr pozitiv - număr negativ
		BigInteger c1(N);
		c1.sign = !c1.sign;
		BigInteger aux = c.add(c1);
		return aux;
	}
	else if (c.sign == 1 && N.sign == 1)
	{
		BigInteger c1(N);
		c1.negate();
		BigInteger aux = c.addArrays(c1);
		aux.digitizeArray();
		if (c < N) {
			aux.sign = false;
		} else {
			aux.sign = true;
		}
		return aux;
	}
	else 
	{
		// Negativ - Negativ = (-2) - (-3) = -2 + 3 = 3 - 2
		BigInteger c1(N);
		c.sign = !c.sign;
		c1.sign = !c1.sign;
		BigInteger aux = c1.sub(c);
		return aux;
	}
}

BigInteger BigInteger::operator+(const BigInteger& other)
{
	return this->add(other);
}

BigInteger BigInteger::operator+=(const BigInteger& other)
{
	*this = this->add(other);
	return *this;
}

BigInteger BigInteger::operator-(const BigInteger& other)
{
	return this->sub(other);
}

BigInteger BigInteger::operator-=(const BigInteger& other)
{
	*this = this->sub(other);
	return *this;
}

void BigInteger::prependZeros(int noOfZeros) // function 1
{
	int* copy = new int[size];
	for (int i = 0; i < this->size; i++)
	{
		copy[i] = array[i];
	}
	delete[] array;
	array = new int[size + noOfZeros];
	for (int i = 0; i < noOfZeros; i++)
		array[i] = 0;
	for (int i = noOfZeros; i < size + noOfZeros; i++)
		array[i] = copy[i - noOfZeros];
	size = size + noOfZeros;
}

void BigInteger::negate() //function 2
{
	for (int i = 0; i < size; i++)
		array[i] = -array[i];
	this->sign = !this->sign;
}

BigInteger BigInteger::addArrays(const BigInteger& other) // function 3
{
	BigInteger b(other);
	BigInteger c(*this);

	if (size < b.size)
	{
		int noOfZeros = b.size - size;
		c.prependZeros(noOfZeros);
		for (int i = 0; i < b.size; i++)
			b.array[i] = b.array[i] + c.array[i];
	}
	else if(size > b.size)
	{
		int noOfZeros = size - b.size;
		b.prependZeros(noOfZeros);
		for (int i = 0; i < b.size; i++)
			b.array[i] = b.array[i] + c.array[i];
	}
	else
	{
		for (int i = 0; i < b.size; i++)
			b.array[i] = b.array[i] + c.array[i];
	}
	return b;
}

void BigInteger::digitizeArray()
{
	/*int ok = 1;
	for (int i = 0; i < size; i++)
		if (this->array[i] < 0)
		{
			ok = 0;
			break;
		}
	if (ok == 1)
	{
		int carry = 0;
		for (int i = size - 1; i >= 0; i--)
		{
			array[i] = array[i] + carry;
			if (array[i] >= 10)
			{
				array[i] = array[i] - 10;
				carry = 1;
			}
			else
				carry = 0;
		}
		if (carry == 1)
		{
			this->prependZeros(1);
			array[0] = 1;
		}
	}
	else if (ok == 0)
	{
		int borrow = 0;
		for (int i = size - 1; i >= 0; i--)
		{
			array[i] = array[i] - borrow;
			if (array[i] < 0)
			{
				array[i] = array[i] + 10;
				borrow = 1;
			}
			else
				borrow = 0;
		}
		if (borrow == 1)
		{
			this->prependZeros(1);
			array[0] = 1;
		}
	}*/
	int i, ok = 0;;
	for (i = size - 1; i > 0; i--)
	{
		ok = 0;

		if (array[i] >= 10)
		{
			array[i - 1] += array[i] / 10 % 10;
			array[i] = array[i] % 10;

			ok = 1;
		}
		else


			if (array[i] <= -10)
			{
				array[i - 1] -= array[i] / 10 % 10;
				array[i] = -array[i];
				ok = 1;
			}

	}
	for (i = size - 1; i >= 0; i--)
		if (array[i] < 0)
			array[i] = -array[i];
}

std::string BigInteger::to_string() const
{
	string result;
	if (sign == 0)
		result = '-';
	for (int i = 0; i < size; i++)
	{
		result += std::to_string(array[i]);
	}
	return result;
}

BigInteger& BigInteger::operator++()
{
	BigInteger b("1");
	if (this->sign > -1)
		*this = this->add(b);
	else
		*this = this->sub(b);
	return *this;
	
}

BigInteger BigInteger::operator++(int)
{
	BigInteger b("1");
	BigInteger copy = *this;
	*this = this->add(b);
	return copy;
}

std::ostream& operator<<(std::ostream& os, const BigInteger& b)
{
	os << b.to_string();
	return os;
}
