//==========================================================
// Assignment- 01
// Name- Raisa Zaman
// Date- 1/16/2020
// Last edited- 5:00 PM
// Title: File read, compute and output
// Description:
//    This C++ console application loads two column of numbers, 
//and does arithmetic operations to the data points. 
//
//==========================================================

#include <conio.h> // For function getch()
#include <cstdlib>  // For several general-purpose functions
#include <cmath> //calculate power function
#include <fstream>  // For file handling
#include <iomanip>  // For formatted output
#include <iostream>  // For cin, cout, and system
#include <string>  // For string data

#include <vector>
using namespace std;

int main()
{
	// variable assigned
	ifstream datafile;
	double data1;
	double data2;
	vector<double> datanum1;
	vector <double> datanum2;
	int size = datanum1.size();
	vector <double> add;
	vector <double> multi;

	// read data from file
	datafile.open("Datafile1.data");
	if (!datafile.is_open())
	{
		cout << "Error: File datafile1.data cannot be processed";
	}
	else
	{
		cout << "File datafile1.data successfully opened. " << endl;

		while (datafile >> data1 >> data2)
		{
			datanum1.push_back(data1);
			datanum2.push_back(data2);
		}

		
	}
	datafile.close();

	// addition operation
	for (int i = 0; i < datanum1.size(); i++)
	{
		add.push_back(datanum1[i] + datanum2[i]);
	}


	// multiplication operation
	for (int j = 0; j < datanum1.size(); j++)
	{
		multi.push_back(datanum1[j] * datanum2[j]);
	}

	// write to files 
	ofstream outputM;
	outputM.open("Output-Multiplication.data");

	if (outputM.is_open())
	{
		cout << "Data successfully transferred to file Output-Multiplication.data." << endl;
		outputM << "MULTIPLICATION" << endl << endl;
		for (int a = 0; a < datanum1.size(); a++)
		{
			outputM << left << setw(20) <<  datanum1[a] << left << setw(20) << datanum2[a]  << " " << multi[a] << endl;
		}
	}
	else
	{
		cout << "Error: Cannot record data in file." << endl;
	}
	outputM.close();

	ofstream outputA;
	outputA.open("Output-Addition.data");
	if (outputA.is_open())
	{
		cout << "Data successfully transferred to file Output-Addition.data." << endl;
		outputA << "ADDITION" << endl << endl;
		for (int m = 0; m < datanum1.size(); m++)
		{
			outputA << left << setw(20) << datanum1[m] << left << setw(20) << datanum2[m] << " " << add[m] << endl;
		}
	}
	else
	{
		cout << "Error: Cannot record data in file." << endl;
	}
	outputA.close();

	return 0;

}