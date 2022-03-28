#include <stdio.h>
#include <iostream>
#include <iomanip> 
#include <algorithm>
using namespace std;
int main() {
	double userIn, mean, var, z, sum = 0, remainder = 0, sd = 0;
	int median = 0;
	int big, small, range;
	int median1 = 0;
	int median2 = 0;
	int ranger = 0;
	int dummy = 1;
	//set as default 10
	double numbers[10];
	double secondArr[10];
	while(dummy == 1){
		cout << "Please enter a range of numbers between 1-10" << endl;
		cin >> ranger;
		//Error Detection
		if (ranger < 0 || ranger > 10)
			dummy = 1;
		else if (!cin) {
			cout << "Please enter correct number" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			dummy = 1;
			}
		else
			dummy = 0;
	}
	//Adding numbers
	for (int i = 0; i < ranger; i++) {
		cout << "Enter a Number: " << endl;
		cin >> numbers[i];
		//Error Detection
		while (!cin) {
			cout << "Enter a Correct Number: " << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> numbers[i];
		}
	}
	//Mean
	for (int i = 0; i < ranger; i++) {
		sum += numbers[i];
	}
	mean = sum / ranger;
	//SD
	for (int i = 0; i < ranger; i++) {
		sd += pow((numbers[i] - mean), 2);
	}
	var = (sd / (ranger - 1));
	sd = sqrt(var);
	//unsorted array for output 
	for (int cash = 0; cash < ranger; cash++) {
		secondArr[cash] = numbers[cash];
	}
	while(1){
		//menu
		cout << "\n1-Mean" << endl;
		cout << "2-Median" << endl;
		cout << "3-Standard deviation" << endl;
		cout << "4-Range" << endl;
		cout << "5-Normalization(z-score)" << endl;
		cout << "6-Exit" << endl;
		cout << "Selection: ", cin >> userIn;
		//err checking
		if (cin.fail()) {
			cout << "Please enter a correct number" << endl;
		}
		else if (userIn >= 0 && userIn <= 6) {
				if (userIn == 1) {
					cout << "Mean= " << mean << endl;
				}
				else if (userIn == 2) {
					//sort
					sort(secondArr, secondArr + ranger);
					remainder = ranger % 2;
					if (remainder == 0) {
						median = ranger / 2;
						cout << "Median= " << secondArr[median] << endl;
					}
					else {
						//9.5 with data set
						median1 = ranger / 2;
						median2 = median1+1;
						cout << "Median= " << (secondArr[median1] + secondArr[median2]) / 2 << endl;
					}		
				}
				else if (userIn == 3) {
					cout << "Standard deviation= " << sd << endl;
				}
				else if (userIn == 4) {
					sort(secondArr, secondArr + ranger);
					big = small = secondArr[0];
					//range calc r=ymax-ymin
					for (int i = 1; i < ranger; ++i) {
						if (secondArr[i] > big)
							big = secondArr[i];
						if (secondArr[i] < small)
							small = secondArr[i];
					}
					range = big - small;
					cout << "Range= " << range << endl;
				}
				else if (userIn == 5) {
					cout << "Data after standerdization: " << endl;
					for (int i = 0; i < ranger; i++) {
						z = (numbers[i] - mean) / sd;
						cout << z << endl;
					}
				}
				else if (userIn == 6) {
					cout << "Thank you for using my program =)" << endl;
					break;
				}
		}
		else
			cout << "Please enter a correct number" << endl;
	}
}