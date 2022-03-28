/********************************************************************************************
* File Name: Ass2.cpp
* Version: 1.0
* Author: Barzin Farahani
* Student Number: 040922695
* Course Name: CTS8233
* Lab Section: 312
* Assignment Number: 2
* Assignment Name: Assignement 2 
* Due Date: 20/11/2020
* Submission Date: 20/11/2020
* Professors Name: Hala Own
* Purpose: To do the liniar regression for moores law and be able to estimate the future tansistor count and rate of increase  
**********************************************************************************************/
//Includes statments
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
//using std
using namespace std;
/********************************************************************************************
* Function Name: Main
* Purpose: Main Function, This has the main menu for the user it also dose the linar regression for moores law, and also allows the user to input there future or past years to see the rate of increase.
* Function In Paramaters: (none)
* Fuction Output Paramaters: 0
* Version: 1.0
* Author: Barzin Farahani
**********************************************************************************************/
int main() {
	//member variables
	string fileText;
	double dummy = 1;
	double userIn, i;
	double pairs = 14;
	double a1 = 0;
	double a0 = 0;
	double xAdded = 0;
	double yAdded = 0;
	double xSquared = 0;
	double xyTimed = 0;
	double part1 = 0;
	double part2 = 0;
	int userYear = 0;
	double tansCount;
	double rateIncrease;
	double yerZ[100];
	double transisor[100];
	string names[100];
	int x = 0;
	//Start menu
	while (dummy == 1) {
		cout << "1. Exponential Fit\n2. Quit" << endl;
		cin >> userIn;
		//error checking 
		if (!cin) {
			cout << "Please enter a correct file" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			dummy = 1;
		}
		else if (userIn < 1 || userIn > 2) {
			dummy = 1;
		}
		//checks if it can open file
		else {
			cout << "Please enter a file to read from: ";
			cin >> fileText;
			if (!cin) {
				cout << "Please enter a correct file" << endl;
				cin.clear();
				cin.ignore(256, '\n');
				dummy = 1;
			}
			else
				dummy = 0;
		}
	}
	//Outputs the text file as shown
	ifstream file(fileText);
	if (file.is_open()) {
		string line;
		while (!file.eof()) {
			getline(file, line, '\t');
			cout << line;
		}
	}
	file.close();
	//Reopens file and assigns collums to arrays 
	file.open(fileText);
	if (file.is_open()) {
		string line;
		getline(file, line);
		while (!file.eof()) {
			file >> yerZ[x];
			file >> transisor[x];
			file >> names[x];
			x++;
		}
		file.close();
	}
	//This dose the math for the equations 
	for (int x = 0; x < pairs; x++) {
		xAdded += yerZ[x];
		yAdded += log(transisor[x]);
		xyTimed += yerZ[x] * log(transisor[x]);
		xSquared += pow(yerZ[x], 2);
	}
	//Dose the math sepreatly for the equation
	part1 = (pairs * xyTimed) - (xAdded * yAdded);
	part2 = ((pairs * xSquared) - pow(xAdded, 2));
	a1 = part1 / part2;
	a0 = exp((yAdded / pairs) - a1 *(xAdded - (1970 * pairs)) / pairs);
	dummy = 1;
	cout << "\nThere are 14 records." << endl;
	cout << "Linear Regression Fit:  transistor count = " << setprecision(3) << scientific << a0 << "exp(" << setprecision(3) << scientific << a1 << "*(year-1970))" << endl;
	//Loop for second menu
	while (dummy == 1) {
		cout << "\n1. Extrapolation Fit\n2. Quit" << endl;
		cin >> userIn;
		//error checking
		if (!cin) {
			cin.clear();
			cin.ignore(256, '\n');
			dummy = 1;
		}
		else if (userIn < 1 || userIn > 2) {
			dummy = 1;
		}
		else if (userIn == 2) {
			cout << "Thank you for using my program :)" << endl;
			dummy = 0;
		}
		//Outputing the liniar regression
		else {
			cout << "Please enter a year to extrapolate to: ";
			cin >> userYear;
			rateIncrease = (a0 * a1) * exp(a1 * (userYear - 1970));
			tansCount = a0 * exp(a1 * (userYear - 1970));
			cout << "Year = " << fixed <<  userYear << endl;
			cout << "Transistor count = " << setprecision(3) << scientific << tansCount << endl;
			cout << "rate of count increase = " << setprecision(3) << scientific << rateIncrease <<" Tansistors/year"<< endl;
		}
	}
}//end of main 