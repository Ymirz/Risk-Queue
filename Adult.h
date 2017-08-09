#pragma once
#ifndef ADULT_H
#define ADULT_H
#include "Human.h"
#include <fstream>
#include <string>
using namespace std;

const int SIZE = 100;
const int CRIT_LVL = 10, ADULT_AGE = 18;

static int numRec = 0;

class Adult : public Human
{
private:
	string* aNames = nullptr;
	string* aGenders = nullptr;

	int* aAge = nullptr;
	int* aMonth = nullptr;
	int* aDay = nullptr;
	int* aYear = nullptr;
	int* aPriority = nullptr;
	int* aUnitId = nullptr;

	int aSize = 0;

public:

	Adult();
	Adult(string *, string*, int*, int*, int*, int*, int*, int *, int size);
	void setNames(string *, int);
	void setGenders(string *, int);

	void setAges(int *, int);
	void setMonths(int *, int);
	void setDays(int *, int);
	void setYears(int *, int);
	void setPriorities(int *, int);
	void setUnitId(int *, int);

	string displayCritical();
	string displayChildren();
	string displayAdult();

	int getSize() const { return aSize; }
	int getRec() const { return numRec; }

	friend ostream &operator << (ostream &, const Adult &);

	void displayType() override;

	~Adult();
};

#endif 

