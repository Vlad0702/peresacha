#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <Windows.h>
#define garbage_collector() cin.ignore(cin.rdbuf()->in_avail())

using namespace std;

struct Nation
{
	char NameCountry[15],
		Capital[13],
		statelenguage[255],
		Population[255],
		area[255],
		moneycapital[255],
		PoliticalSystem[255],
		headofstate[255];

};

Nation* InitArray(int Dimension);
Nation InitPerson();
void DisplayArray(Nation* Massive, int Dimaension);
void DisplayPerson(Nation);
int& CheckCorectDigitValue(int&);

void main(int argc, char* argv)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "");

	int Dimension;
	char SexTag[7];
	int LowAge, UpperAge;
	bool begin = true;
tryagain:
	Nation* MassiveStruct = nullptr;
	do
	{
		cout << "\nEnter the number of landline owners:  ";//Введите кол-во владельцев стационарных телефонов
		do {
			cin >> Dimension;
			if (cin.fail())
			{
				cout << "[!]Input Error! try again" << endl;//[!]Ошибка ввода! Попробуйте еще раз
				cin.clear();
				cin.ignore(32222, '\n');
			}
			else
				break;
		} while (true);
		MassiveStruct = InitArray(Dimension);
		if (MassiveStruct == nullptr)
		{
			cout << "\n[!]Dynamic array don't exist!\n";

			do {
				cout << "[!] Enter '+' to try again or press '-' to exit the program ... ";//[!]Введите '+' для того чтобы повторить попытку или нажмите '-' чтобы выйти из програмы...
				char symbol;
				symbol = getchar();
				(symbol == '+') ? begin == true : begin == false;
				if (symbol == '+')
					goto tryagain;
				exit(777);

			} while (!begin);
		}


	} while (begin != true);

	cout << "\nAll information: " << endl;//Вся информация
	DisplayArray(MassiveStruct, Dimension);


	cout << "\nSorted list of selected people: " << endl; //Отсортированный список выбранных людей
	DisplayArray(MassiveStruct, Dimension);

	delete MassiveStruct;
}
Nation InitPerson()
{
	Nation Man;

	cout << "\nEnter Name Country,: ";
	garbage_collector();
	cin.getline(Man.NameCountry, 255);


	cout << "Enter Capital: ";
	garbage_collector();
	cin.getline(Man.Capital, 255);

	cout << "Enter state lenguage: ";
	garbage_collector();
	cin.getline(Man.statelenguage, 255);

	cout << "Enter Population: ";
	garbage_collector();
	cin.getline(Man.Population, 255);

	cout << "Enter area: ";
	garbage_collector();
	cin.getline(Man.area, 255);

	cout << "Enter money capital: ";
	garbage_collector();
	cin.getline(Man.moneycapital, 255);

	cout << "Enter Political System: ";
	garbage_collector();
	cin.getline(Man.PoliticalSystem, 255);

	cout << "Enter head of state: ";
	garbage_collector();
	cin.getline(Man.headofstate, 255);


	return Man;
}

Nation* InitArray(int Dimension)
{
	Nation* Massive = new Nation[Dimension];
	if (Massive == nullptr)
		return nullptr;
	for (size_t i = 0; i < Dimension; i++)
	{
		printf("\nEnter the information %d person: ", i + 1);
		Massive[i] = InitPerson();
	}
	return Massive;
}

void DisplayArray(Nation* Massive, int Dimension)
{
	for (size_t i = 0; i < Dimension; i++) { DisplayPerson(Massive[i]); }
}

void DisplayPerson(Nation Man)
{
	cout << "NameCountry: " << Man.NameCountry << endl;
	cout << "Capital: " << Man.Capital << endl;
	cout << "State lenguage: " << Man.statelenguage << endl;
	cout << "Population: " << Man.Population << endl;
	cout << "Area: " << Man.area << endl;
	cout << "Money capital: " << Man.moneycapital << endl;
	cout << "Political System: " << Man.PoliticalSystem << endl;
	cout << "Head of state: " << Man.headofstate << endl;

}

int& CheckCorectDigitValue(int& value)
{
	bool flag = false;
	do {
		if (flag) {
			cout << "[!]Try again";
		}flag = false;
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32222, '\n');
		}
		else
		{
			return value;
		}
	} while (true);
}