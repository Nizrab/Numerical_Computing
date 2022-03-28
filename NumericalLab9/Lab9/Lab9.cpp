#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
int main() {
	//Variables
	double pairs;
	double dummy = 1;
	double a1 = 0;
	double xAdded = 0;
	double yAdded = 0;
	double xSquared = 0;
	double xyTimed = 0;
	double a0 = 0;
	double yFitted = 0;
	double part1 = 0;
	double part2 = 0;
	//2d arry for vlaues
	double xyArry[10][10];
	while (dummy == 1) {
		cout << "Please enter the amout of data pairs to be enterd: ", cin >> pairs;
		//error detection  
		if (pairs < 0 || pairs > 10)
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
	//get Xvalu from user
	for (int x = 0; x < pairs; x++)

		cout << "Enter The x-axis values: ", cin >> xyArry[x][0];
	//get Yvalu from user
	for (int y = 0; y < pairs; y++) 
		cout << "Enter The y-axis values: ", cin >> xyArry[y][1];
	//Meth
	for (int x = 0; x < pairs; x++) {
		xyTimed += xyArry[x][0] * xyArry[x][1];
		xAdded += xyArry[x][0];
		yAdded += xyArry[x][1];
		xSquared += pow(xyArry[x][0], 2);
	}
	part1 = (pairs * xyTimed) - (xAdded * yAdded);
	part2 = (pairs * xSquared - pow(xAdded, 2));
	a1 = part1 / part2;
	a0 = (yAdded - a1 * xAdded) / pairs;
	//checiking a1a0
	cout << "a1-> " << a1 << endl;
	cout << "a0-> " << a0 << endl;
	//output
	cout << "S.no\tX\tY(Observed)\tY(Fitted)" << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	for (int x = 0; x < pairs; x++) {
		yFitted = a1 * xyArry[x][0] + a0;
		cout << x + 1 << ". " << setw(6) << xyArry[x][0] << setw(11) << xyArry[x][1] << setw(18) << yFitted << endl;
	}
	cout << "The liniar fit line is of the form:\ny = " << a1 << "x + " << a0 << endl;
}//end of main