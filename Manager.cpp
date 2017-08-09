// Myles Pruitt
// 4/15/2017

#include <iostream>
#include <fstream>
#include <string>
#include "Adult.h"

using namespace std;

const int NAME_SIZE = 100;

void checkFileIn(fstream &file, string dat);
void checkFileExists(int data);
void header();

int dataCounter(fstream &file, string data);

char getLetter();
int getInt();
double getNum();
double getBetween(double min, double max);
double getMonthLimit();
long byteNum(int recNum);


struct Info
{
	char name[NAME_SIZE];
	char gender[NAME_SIZE];

	int age;
	int month;
	int day;
	int year;
	double priority;
	int unitId = 0;
};

void search(Info info, fstream &datFile, string datName, int find);

int main()
{
	Info info;
	fstream datFile;
	string datName = "data.dat";

	char again;
	int count = 0;
	double option = 0;

	double max = 10, min = 0;

	int dataCheck = 0;
	int j = 0, datCnt, strctCnt, totalDat;
	
	string *oName = nullptr;
	string *oGender = nullptr;
	int find;

	int* oAge = nullptr;
	int* oMonth = nullptr;
	int* oDay = nullptr;
	int* oYear = nullptr;
	int* oPriority = nullptr;
	int * oUnitId = nullptr;

	while (true)
	{
		option = 0;

		count = 0;

		checkFileIn(datFile, datName);

		strctCnt = sizeof(Info);

		datCnt = dataCounter(datFile, datName);

		totalDat = datCnt / strctCnt;

		oName = new string[totalDat];
		oGender = new string[totalDat];

		oAge = new int[totalDat];
		oMonth = new int[totalDat];
		oDay = new int[totalDat];
		oYear = new int[totalDat];
		oPriority = new int[totalDat];
		oUnitId = new int[totalDat];

		datFile.open(datName, ios::in | ios::binary);

		datFile.read(reinterpret_cast<char *>(&info), sizeof(info));

		while (!datFile.eof())
		{
			dataCheck++;
	
			oPriority[j] = info.priority;
			oName[j] = info.name;
			oGender[j] = info.gender;
			oAge[j] = info.age;
			oMonth[j] = info.month;
			oDay[j] = info.day;
			oYear[j] = info.year;
			oUnitId[j] = info.unitId;
		
			j++;

			datFile.read(reinterpret_cast<char *>(&info), sizeof(info));
		}

		j = 0;

		Adult adult(oName, oGender, oAge, oMonth, oDay, oYear, oPriority, oUnitId, totalDat);

		checkFileExists(dataCheck);

		datFile.close();

		header();

		cout << "\n\nNumber of Records : " << totalDat << "\n";

		cout << "\nOption Choice: ";
		cin >> option; cin.ignore(80, '\n');

		try
		{
			if (cin.fail())
				throw "error";
			if (static_cast<int>(option) != option)
				throw  "error";
		}
		catch (char *error)
		{
			cout << "\nInvalid input try again: ";
			option = getInt();
		}
	
		system("CLS");

		if (option == 1)
		{
			datFile.open(datName, ios::out | ios::binary | ios::app);

			do
			{
				cout << "\n===============";
				cout << "\n[ Person #" << count + 1 << "]";
				cout << "\n===============\n";

				cout << "\nPerson ID: ";
				cout << info.unitId;

				cout << "\nPriority Level: ";
				info.priority = getBetween(max,min); 
			
				cout << "\nEnter Full Name: ";
				cin.getline(info.name, NAME_SIZE);

				cout << "\nGender: ";
				cin.getline(info.gender, NAME_SIZE);

				cout << "\nAge: ";
				info.age = getInt();

				if (info.age >= 18)
				{
					Adult adu;
					Human* adu1 = &adu;
					adu1->displayType();
				}
				else
					cout << "\nClassification: MINOR\n";

				cout << "\nDate Admitted:";
				cout << "\n==============";

				cout << "\nMonth: ";
				info.month = getMonthLimit();

				cout << "\nDay: ";
				info.day = getInt();

				cout << "\nYear: ";
				info.year = getInt();
			
				cout << endl;

				info.unitId++;
			
				datFile.write(reinterpret_cast<char *>(&info), sizeof(info));

				count++;

				cout << "\nDo you want to enter another person into queue? ";
				cin >> again; cin.ignore(80, '\n');
				system("CLS");

			} while (again == 'y' || again == 'Y');
		}

		if (option == 2)
			cout << adult.displayChildren();
		
		if (option == 3)
			cout << adult.displayAdult();
		
		if (option == 4)
			cout << adult.displayCritical();
		
		if (option == 5)
			cout << adult;
		
		if (option == 6)
		{
			cout << "\nFind Person by 'UNIT ID' Number [ Note: Each unit position is off by 1 ]: ";
			cin >> find; cin.ignore(80, '\n');

			try
			{
				if (cin.fail()) 
					throw "error";
			}
			catch (char *error)
			{
				find = getInt();
			}

			if (find < totalDat)
				search(info, datFile, datName, find);
			else
				cout << "\nExceeded limit\n";
		}

		cout << endl << endl;
		system("pause");
		system("cls");

		delete[]oName;
		delete[]oGender;
		delete[] oAge;
		delete[] oMonth;
		delete[] oDay;
		delete[] oYear;
		delete[] oPriority;
		delete[] oUnitId;
	}
}

void header()
{
	system("Title Myles Pruitt - Priority Queue");

	cout
		<< "\n\tThis program organizes people into a list\n"
		<< "\t           By condition level\n"
		<< "\t                M.Pruitt\n"
		<< "\t=========================================\n";

	cout << "\nMain Menu:\n"
		<< "\n 1) Add Person To Queue "
		<< "\n 2) Display Children "
		<< "\n 3) Display Adult "
		<< "\n 4) Display High Priority "
		<< "\n 5) Display All Admitted "
		<< "\n 6) Search ";
}

void checkFileIn(fstream &file, string dat)
{
	file.open(dat, ios::in | ios::binary);
	if (file.fail())
	{
		file.open(dat, ios::in | ios::binary | ios::app);
	}
	file.close();
}

void checkFileExists(int data)
{
	if (data <= 0)
	{
		cout << "\n[ ERROR # 2 ] No data inside of file, create a queue using option '1'\n";
	}
}

int dataCounter(fstream &file, string data)
{
	file.open(data, ios::in | ios::binary);
	int begin, end;
	begin = file.tellg();
	file.seekg(0, ios::end);
	end = file.tellg();
	file.close();

	return end - begin;
}



void search(Info info, fstream &datFile, string datName, int find)
{
	datFile.open(datName, ios::in | ios::binary);
	datFile.seekg(byteNum(find), ios::beg);
	datFile.read((char*)&info, sizeof(info));
	
	cout << "\nUnit ID: " << info.unitId;
	cout << "\nPriority Level: " << info.priority;
	cout << "\nFull Name: " << info.name;
	cout << "\nGender: " << info.gender;
	cout << "\nAge: " << info.age;
	cout << "\nGender: " << info.gender;
	cout << "\nMonth: " << info.month << " Day: " << info.day << " Year: " << info.year;
	
	datFile.close();
}


long byteNum(int recNum)
{
	return sizeof(Info) * recNum;
}

double getNum() 
{
	double userInput;
	while (!(cin >> userInput)) {
		cin.clear();
		cin.ignore(80, '\n');
		cout << "No letters. try again: ";
	}
	cin.ignore(80, '\n');
	return userInput;
}

int getInt() 
{
	double userInput = getNum();
	while (static_cast<int>(userInput) != userInput) {
		cout << userInput << " is NOT an integer. try again: ";
		userInput = getNum();
	}
	return static_cast<int> (userInput);
}

double getBetween(double min, double max)  
{
	double userInput = getInt();
	while (userInput > min || userInput < max) {
		cout << userInput << " is NOT between 0 and 10. try again: ";
		userInput = getInt();
	}
	return userInput;
}

double getMonthLimit()
{
	double userInput = getInt();
	while (userInput > 0 || userInput < 13) {
		cout << userInput << " is NOT between 0 and 12. try again: ";
		userInput = getInt();
	}
	return userInput;
}


char getLetter()  
{
	char userLetter;
	cin >> userLetter; cin.ignore(80, '\n');
	while (userLetter < 'A' || userLetter > 'Z' && userLetter < 'a' || userLetter > 'z') {
		cout << userLetter << " is NOT an letter. try again: ";
		cin >> userLetter; cin.ignore(80, '\n');
	}
	return userLetter;
}






