// numlab2.cpp : Defines the entry point for the application.
#include "numlab2.h"
#include <iostream>
#include <string>
#include <cmath> 
//Member Variables
using namespace std;
void decimalTobinary();
void binaryTodecimal();
void menu();
int userIn = 0;
//Main
int main() {
	menu();
	cin >> userIn;
	if (userIn == 1) {
		decimalTobinary();
	}
	else if (userIn == 2) {
		binaryTodecimal();
	}
	else {
		decimalTobinary();
	}
	return 0;
}
//Menu
void menu() {
	cout << "[1] To do decimal to binary conversion\n[2] To do binary to decimal" << endl;
}
//Decimal to binary 
void decimalTobinary() {
	double num1;
	double decimal;
	int whole;
	cout << "Enter a number: ";
	cin >> num1;
	//checks if number is decimal
	if (num1 < 0) {
		whole = floor(num1);
		decimal = num1 - floor(whole);
	}
	else if (num1 > 0) {
		//rounding
		whole = floor(num1);
		decimal = num1 - floor(whole);
		//fractail decimal to binary 
		if (decimal != 0){
			int i = 1;
			//array for first half
			int array[10];
			//seprate array of other half of decimal
			int decimalz[10];
			//changing variable type
			int x = int(whole);
			int k = int(decimal);
			//Math for converion
			for (i = 0; x > 0; i++) {
				array[i] = x % 2;
				x = x / 2;
			}
			cout << "The Number in binary is: " << endl;
			//Outputing the binary number
			for (i = i - 1; i >= 0; i--) {
				cout << array[i];
			}
			//decimal half conversion
			int j;
			/*depending on if it is a number lower than 1 
			  it will either put a 0 or a 1 in the array*/
			for (j = 0; j < 3; j++) {
				decimal = decimal * 2;
				if (decimal >= 1.0){
					int z=1;
					decimalz[j] = z;
					continue;
				}
				else if (decimal < 1.0) {
					int	z = 0;
					decimalz[j] = z;
					continue;
				}			
			}
			//decimal point
			cout << ".";
			//Outputs the array in the proper order only up to 3 decimal places 
			for (j = 0; j < 3; j++) {
				cout << decimalz[j];
			}
		}
		//regular decimal to binary
		else if (decimal == 0) {
			int i = 1;
			int array[10];
			//changing variable type
			int x = int(whole);
			//Math for converion
			for (i = 0; x > 0; i++) {
				array[i] = x % 2;
				x = x / 2;
			}
			//Outputing the binary number
			cout << "The Number in binary is: " << endl;
			for (i = i - 1; i >= 0; i--) {
				cout << array[i];
			}
		}		
	}
}
//straight binary to decimal 
void binaryTodecimal() {
	//member variables
	double num1;
	double decimal;
	int firstH;
	int output = 0;
	int dummo = 0;
	int base = 1;
	int lastNum;
	//userinput
	cout << "Enter a number: ";
	cin >> num1;
	double j = num1;
	int dummy = j;
	//changes input to string 
	string decimalP = to_string(j);
	//gets location for "."
	int q = decimalP.find(".");
	//gets the second part of the decimal using a substring 
	string secondH = decimalP.substr(decimalP.find(".")+1);
	//returns the second part of the decimal as a int 
	int secondHInt = stoi(secondH);
	firstH = floor(num1);
	//Checks if there is a decimal point or not 
	if(size_t ass = decimalP.find(".")){
		//while loop to do calc for first num
		while (firstH) {
			lastNum = firstH % 10;
			firstH = firstH / 10;
			output += lastNum * base;
			base = base * 2;
		}
		cout << "The Number in Decimal is: " << endl;
		cout << output;
		cout << ".";
		//while loop to do calc for second num
		while (secondHInt) {
			lastNum = secondHInt % 10;
			secondHInt = secondHInt / 10;
			dummo += lastNum * base;
			base = base * 2;
		}
		cout << dummo;
	}
	//if no decimals 
	else {
		//While loop to do calc for no decimal binary num
		while (dummy) {
			lastNum = dummy % 10;
			dummy = dummy / 10;
			output += lastNum * base;
			base = base * 2;
		}
		cout << "The Number in Decimal is: " << endl;
		cout << output;
	}
}	