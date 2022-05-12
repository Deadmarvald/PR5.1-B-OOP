#include "Money.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void Money::SetHrn(long value)
{
	if (value < 0)
	{
		throw Exception("Numbers must be bigger than 0!");
	}
	else
	{
		hrn = value;
	}
}

void Money::SetKop(unsigned int value)
{
	if (value < 0)
	{
		throw Exception("Numbers must be bigger than 0!");
	}
	else
	{
		kop = value;
	}
}

Money::Money()
{
	hrn = 0;
	kop = 0;
}

Money::Money(long hrn = 0, unsigned long kop = 0)
{
	if (hrn < 0 || kop < 0)
	{
		throw invalid_argument("Numbers must be bigger than 0!");
	}
	else
	{
		long a = hrn;
		unsigned int b = kop;

		while (b > 99)
		{
			b -= 100;
			a++;
		}

		SetHrn(a);
		SetKop(b);
	}
}

Money::Money(const Money& x)
{
	this->hrn = x.hrn;
	this->kop = x.kop;
}

Money::~Money()
{ }

Money& Money::operator = (const Money& x)
{
	hrn = x.hrn;
	kop = x.kop;

	return *this;
}

Money::operator string () const
{
	stringstream sout;
	sout << endl;
	sout << hrn << "," << kop << endl;

	return sout.str();
}

Money operator -(const Money& l, const Money& r)
{
	Money t(0, 0);

	t.hrn = l.hrn - r.hrn + floor((l.kop - r.kop) / 100);

	t.kop = (l.kop - r.kop) % 100;

	return t;
}

Money operator *(const Money& l, const double& r)
{
	Money t(0, 0);

	if (r != 0)
	{
		t.hrn = l.hrn * r;
		t.kop = l.kop * r;
	}

	return t;
}

bool Money::operator ==(const Money& x)
{
	return this->hrn == x.hrn && this->kop == x.kop;
}

bool Money::operator !=(const Money& x)
{
	return !(this->hrn == x.hrn && this->kop == x.kop);
}

bool Money::operator >(const Money& x)
{
	if (this->hrn > x.hrn)
	{
		return true;
	}

	if (this->hrn == x.hrn)
	{
		if (this->kop > x.kop)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	if (this->hrn < x.hrn)
	{
		return false;
	}
}

bool Money::operator <(const Money& x)
{
	if (this->hrn < x.hrn)
	{
		return true;
	}

	if (this->hrn == x.hrn)
	{
		if (this->kop < x.kop)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	if (this->hrn > x.hrn)
	{
		return false;
	}
}

bool Money::operator >=(const Money& x)
{
	if (this->hrn > x.hrn)
	{
		return true;
	}

	if (this->hrn == x.hrn)
	{
		if (this->kop > x.kop)
		{
			return true;
		}

		if (this->kop == x.kop)
		{
			return true;
		}

		if (this->kop < x.kop)
		{
			return false;
		}
	}

	if (this->hrn < x.hrn)
	{
		return false;
	}
}

bool Money::operator <=(const Money& x)
{
	if (this->hrn < x.hrn)
	{
		return true;
	}

	if (this->hrn == x.hrn)
	{
		if (this->kop < x.kop)
		{
			return true;
		}

		if (this->kop == x.kop)
		{
			return true;
		}

		if (this->kop > x.kop)
		{
			return false;
		}
	}

	if (this->hrn > x.hrn)
	{
		return false;
	}
}

ostream& operator << (ostream& out, const Money& x)
{
	out << string(x);

	return out;
}

istream& operator >> (istream& in, Money& x)
{
	long hrn;
	unsigned int kop;

	cout << endl;
	cout << "UAH = "; in >> hrn;
	cout << "Coin = "; in >> kop;
	cout << endl;

	if (hrn < 0 || kop < 0)
	{
		throw MyException("Numbers must be bigger than 0!!!");
	}
	else
	{
		x.SetHrn(hrn);
		x.SetKop(kop);
	}

	return in;
}

Money& Money::operator ++()
{
	hrn++;
	kop++;

	return *this;
}

Money& Money::operator --()
{
	hrn--;
	kop--;

	return *this;
}

Money Money::operator ++(int)
{
	Money t(*this);
	hrn++;
	kop++;

	return t;
}

Money Money::operator --(int)
{
	Money t(*this);
	hrn--;
	kop--;

	return t;
}