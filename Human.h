#pragma once
#include <iostream>
using namespace std;
#ifndef HUMAN_H
#define HUMAN_H

class Human
{

public:
	virtual void displayType()
	{
		cout << "\nClassification:...\n";
	};
};
#endif 

