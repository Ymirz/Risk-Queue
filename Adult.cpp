#include "Adult.h"
#include "Human.h"
#include <iostream>
#include <string>

using namespace std;

Adult::Adult()
{

}

Adult::Adult(string *oNames, string *oGenders, int *oAges, int *oMonths, int *oDays, int *oYears, int *oPriorities, int *oUnitId ,int size)
{
	aSize = size;
	aNames = new string[size];
	aGenders = new string[size];
	aAge = new int[size];
	aMonth = new int[size];
	aDay = new int[size];
	aYear = new int[size];
	aPriority = new int[size];
	aUnitId = new int[size];
	
	setPriorities(oPriorities, getSize());
	setNames(oNames, getSize());
	setGenders(oGenders, getSize());
	setAges(oAges, getSize());
	setMonths(oMonths, getSize());
	setDays(oDays, getSize());
	setYears(oYears, getSize());
	setUnitId(oUnitId, getSize());
}

void Adult::setNames(string *oNames, int size)
{
	for (int i = 0; i < size; i++)
	{
		aNames[i] = oNames[i];
	}
}

void Adult::setGenders(string *oGenders, int size)
{
	for (int i = 0; i < size; i++)
	{
		aGenders[i] = oGenders[i];
	}
}

void Adult::setAges(int *oAges, int size)
{
	for (int i = 0; i < size; i++)
	{
		aAge[i] = oAges[i];
	}
}

void Adult::setMonths(int *oMonths, int size)
{
	for (int i = 0; i < size; i++)
	{
		aMonth[i] = oMonths[i];
	}
}

void Adult::setDays(int *oDays, int size)
{
	for (int i = 0; i < size; i++)
	{
		aDay[i] = oDays[i];
	}
}

void Adult::setYears(int *oYears, int size)
{
	for (int i = 0; i < size; i++)
	{
		aYear[i] = oYears[i];
	}
}

void Adult::setPriorities(int *oPriorities, int size)
{
	for (int i = 0; i < size; i++)
	{
		aPriority[i] = oPriorities[i];
	}
}

void Adult::setUnitId(int *oUnitId, int size)
{
	for (int i = 0; i < size; i++)
	{
		aUnitId[i] = oUnitId[i];
	}
}

string Adult::displayCritical()
{
	for (int i = 0; i < getSize(); i++)
	{
		if (aPriority[i] == CRIT_LVL)
		{
			cout << "\nDisplaying admitted [ HIGH ALERT ] ";
			cout << "\n==================================\n\n";
			cout << "Full Name: " << aNames[i] << "\n";
			cout << "Gender: " << aGenders[i] << "\n";
			cout << "Age: " << aAge[i] << "\n";
			cout << "Date Admitted: " << aMonth[i] << "/" << aDay[i] << "/" << aYear[i] << "\n";
			cout << "Priority: " << aPriority[i] << "\n";
		}
	}
	return string();
}

string Adult::displayChildren()
{
	for (int i = 0; i < getSize(); i++)
	{
		if (aAge[i] < ADULT_AGE)
		{
			cout << "\nDisplaying admitted [ CLASS: MINOR ] ";
			cout << "\n====================================\n\n";
			cout << "Unit ID: " << aUnitId[i] << "\n";
			cout << "Full Name: " << aNames[i] << "\n";
			cout << "Gender: " << aGenders[i] << "\n";
			cout << "Age: " << aAge[i] << "\n";
			cout << "Date Admitted: " << aMonth[i] << "/" << aDay[i] << "/" << aYear[i] << "\n";
			cout << "Priority: " << aPriority[i] << "\n";
		}
	}
	return string();
}

string Adult::displayAdult()
{
	for (int i = 0; i < getSize(); i++)
	{
		if (aAge[i] >= ADULT_AGE)
		{
			cout << "\nDisplaying admitted [ CLASS: ADULT ] ";
			cout << "\n====================================\n\n";
			cout << "Unit ID: " << aUnitId[i] << "\n";
			cout << "Full Name: " << aNames[i] << "\n";
			cout << "Gender: " << aGenders[i] << "\n";
			cout << "Age: " << aAge[i] << "\n";
			cout << "Date Admitted: " << aMonth[i] << "/" << aDay[i] << "/" << aYear[i] << "\n";
			cout << "Priority: " << aPriority[i] << "\n";
		}
	}
	return string();
}

ostream & operator<<(ostream &os, const Adult &a)
{
	for (int i = 0; i < a.getSize(); i++)
	{
		numRec++;
		cout << "\nDisplaying admitted : ";
		cout << "\n=====================\n\n";
		os << "Unit ID: " << a.aUnitId[i] << "\n";
		os << "Full Name: " << a.aNames[i] << "\n";
		os << "Gender: " << a.aGenders[i] << "\n";
		os << "Age: " << a.aAge[i] << "\n";
		os << "Date Admitted: " << a.aMonth[i] << "/" << a.aDay[i] << "/" << a.aYear[i] << "\n";
		os << "Priority: " << a.aPriority[i] << "\n";
	}
	return os;
}

void Adult::displayType()
{
	cout << "\nClassification: Adult\n";
}


Adult::~Adult()
{
	delete[]aNames;
	delete[]aGenders;
	delete[] aAge;
	delete[] aMonth;
	delete[] aDay;
	delete[] aYear;
	delete[] aPriority;
}
