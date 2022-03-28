/********************************************************************************************
* File Name: ass1.cpp
* Version: 1.0
* Author: Barzin Farhani
* Student Number: 040922695
* Course Name: CTS8233
* Lab Section: 312
* Assignment Number: 1
* Assignment Name: Maclurin Series Application
* Due Date: 9/10/2020
* Submission Date: 9/10/2020
* Professors Name: Hala Own
* Purpose: To compute the speed of the rocket relative to a person
observe it on the earth 
**********************************************************************************************/
//include statments
#include <iostream>
#include <sstream>
#include <iomanip>
//using std 
using namespace std;
/********************************************************************************************
* Function Name: Main
* Purpose: Main Function, This has the main menu for the user it also dose the muclaren sereis calculations for the problem. It will output the b value approxamite value, exact value, 
relative error, and the trunkcation error
* Function In Paramaters: (none)
* Fuction Output Paramaters: 0
* Version: 1.0
* Author: Barzin Farahnan
**********************************************************************************************/
int main(){
	//Member variables
	double userIn = 0;
	double termz = 0;
	double b = 0.0;
	double xact = 1.0;
	double trueB = 0.0;
	double dummy = 0.0;
	double aprox = 1.0;
	double trunks = 0.0;
	double trunkError = 0.0;
	double abslErr = 0.0;
	double relativeError = 0.0;
	//while loop for menu
	while (1) {
		//menu
		cout << "1: Evaluate the series" << endl;
		cout << "2: quit" << endl;
		cin >> userIn;
		//Evaluate if statment
		if (userIn == 1) {
			cout << "Evaluating the series" << endl;	
			//Terms Input
			cout << "Please enter the number of (non-zero) terms in the series (1, 2, 3, 4, 5, 6): " << endl;
			cin >> termz;
			if (termz < 1 || termz > 6) {
				cout << "Please enter a number between 1-6" << endl;
				continue;
			}
			else if (termz >= 1 || termz <= 6) {
				//B value Input
				cout << "Please enter the range of B to evaluate in 10 increments (0.0 < B <= 0.9): " << endl;
				cin >> b;
				if (b < 0.0 || b > 0.9) {
					cout << "Please enter a proper range" << endl;
					continue;
				}
				else if (b > 0.0 || b < 0.9) {
					cout << endl;
					//Sets the B to 0.0_
					cout << "B\t  V(B) SERIES\t\tV(B) EXACT\tRELATIVE ERROR\t\t%ERRER" << endl;
					cout << trueB << "\t\t" << aprox << "\t\t\t" << xact << "\t\t" << relativeError << "\t\t" << trunkError << endl;
					trueB = b / 10;
					dummy = b / 10;
					for (int i = 0; i < 10; i++) {
						aprox = 1;
						//if statment for only 1 term
						if (termz == 1) {
							aprox = 1;
							trunks = (trueB * trueB) / 2.0 + 3.0;
						}
						//if statment for 2 terms
						else if (termz == 2) {
							//Macluren series math using power series
							aprox = 1 + (trueB * trueB) / 2.0 + 3.0;
							trunks = 3.0 * (trueB * trueB * trueB * trueB) / 8.0;
						}
						//if statment for 3 terms
						else if (termz == 3) {
							//Macluren series math using power series 
							aprox = 1 + (trueB * trueB) / 2.0 + 3.0 * (trueB * trueB * trueB * trueB) / 8.0;
							trunks = (trueB * trueB * trueB * trueB * trueB * trueB) * 5.0 / 16.0;
						}
						//if statment for 4 terms
						else if (termz == 4) {
							//Macluren series math using power series
							aprox = 1 + (trueB * trueB) / 2.0 + 3.0 * (trueB * trueB * trueB * trueB) / 8.0 + (trueB * trueB * trueB * trueB * trueB * trueB) * 5.0 / 16.0;
							trunks = (trueB * trueB * trueB * trueB * trueB * trueB * trueB * trueB) * 35.0 / 128.0;
						}
						//if statment for 5 terms
						else if (termz == 5) {
							//Macluren series math using power series
							aprox = 1 + (trueB * trueB) / 2.0 + 3.0 * (trueB * trueB * trueB * trueB) / 8.0 + (trueB * trueB * trueB * trueB * trueB * trueB) * 5.0 / 16.0 + (trueB * trueB * trueB * trueB * trueB * trueB * trueB * trueB) * 35.0 / 128.0;
							trunks = (trueB * trueB * trueB * trueB * trueB * trueB * trueB * trueB * trueB * trueB) * 63.0 / 256.0;
						}
						//if statment for 6 terms
						else if (termz == 6) {
							//Macluren series math using power series
							aprox = 1 + (trueB * trueB) / 2.0 + 3.0 * (trueB * trueB * trueB * trueB) / 8.0 + (trueB * trueB * trueB * trueB * trueB * trueB) * 5.0 / 16.0 + (trueB * trueB * trueB * trueB * trueB * trueB * trueB * trueB) * 35.0 / 128.0 + (trueB * trueB * trueB * trueB * trueB * trueB * trueB * trueB * trueB * trueB) * 63.0 / 256.0;
							//Gets 7th terms Macluren series 
							trunks = (trueB * trueB * trueB * trueB * trueB * trueB * trueB * trueB * trueB * trueB * trueB * trueB) * 231.0 / 1024.0;
						}
						//Truncation Error
						trunkError = 100 * abs(trunks / aprox);
						//V(B) Exact 
						xact = 1 / sqrt(1 - pow(trueB, 2));
						//Absolute Error
						abslErr = xact - aprox;
						//Realative Error
						relativeError = abs(abslErr / xact);
						//Otuput for Table
						cout << trueB << setw(18) << setprecision(11)
							<< aprox << setw(20)
							<< xact << setw(20)
							<< relativeError << setw(20)
							<< trunkError << endl;
						//adds the range 
						trueB += dummy;
					}
				}
			}
			else
				continue;
		}
		//Quit if statment
		else if (userIn == 2){
			cout << "Thank you for using this application:)" << endl;
			break;
			}
		else
			continue;
	}
}