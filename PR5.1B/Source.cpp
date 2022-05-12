#include <iostream>
#include<Windows.h>
#include "Money.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool res;
	Money a, b;
	double x;

	do
	{
		try
		{
			res = true;

			Money c(5, 5);

			cout << "Enter a value of \"a\":"; cin >> a;
			cout << "Enter a value of \"b\":"; cin >> b;

			cout << "�i��i����� ����: " << a - b;
			cout << endl;

			cout << "��i� = "; cin >> x;
			cout << endl;

			cout << "���������� ��������: " << a * x;
			cout << endl;

			if (a == b)
			{
				cout << a.GetHrn() << "," << a.GetKop() << " == "
					<< b.GetHrn() << "," << b.GetKop() << endl << endl;
			}

			if (a != b)
			{
				cout << a.GetHrn() << "," << a.GetKop() << " != "
					<< b.GetHrn() << "," << b.GetKop() << endl << endl;
			}

			if (a > b)
			{
				cout << a.GetHrn() << "," << a.GetKop() << " > "
					<< b.GetHrn() << "," << b.GetKop() << endl << endl;
			}

			if (a < b)
			{
				cout << a.GetHrn() << "," << a.GetKop() << " < "
					<< b.GetHrn() << "," << b.GetKop() << endl << endl;
			}

			if (a >= b)
			{
				cout << a.GetHrn() << "," << a.GetKop() << " >= "
					<< b.GetHrn() << "," << b.GetKop() << endl << endl;
			}

			if (a <= b)
			{
				cout << a.GetHrn() << "," << a.GetKop() << " <= "
					<< b.GetHrn() << "," << b.GetKop() << endl << endl;
			}

			cout << "a++: " << a++;
			cout << "res: " << a;
			cout << "++a: " << ++a;

			cout << "a--: " << a--;
			cout << "res: " << a;
			cout << "--a: " << --a;
		}
		catch (invalid_argument ex)
		{
			res = false;
			cerr << ex.what() << endl;
		}
		catch (MyException& ex)
		{
			res = false;
			cerr << ex.What() << endl;
		}
		catch (Exception* ex)
		{
			res = false;
			cerr << ex->What() << endl;
		}

	} while (!res);

	system("pause");
	return 0;
}