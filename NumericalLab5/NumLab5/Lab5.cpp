#define _USE_MATH_DEFINES
#include<iostream>
#include<math.h>
#include <sstream>
#include <iomanip>
using namespace std;
//Factoral function 
int factorialMath(int nValue) {
	double factorial = 1.0;
	for (int i = 1; i <= nValue; i++){
		factorial *= i;
	}
	//returns factorial of given number 
	return factorial;
}
int main() {
	double userIn;
	double x = M_PI/3.0;
	double approx = 1.0;
	double relativeError = 0.0;
	double absoluteError = 100.0;
	double xact = cos(x);
	double n = 1;
	while (1) {
		cout << "Enter your error bound: ";
		cin >> userIn;
		cout << "EXACT VALUE" << "\t" << "APPROX VAL" << "\t" << "ABSOLUTE ERROR" << "\t" << "RELATIVE ERROR" << endl;
		while (absoluteError > userIn) {
			approx += pow(-1.0, n) * (pow(x, 2 * n) / factorialMath(2* n));
			absoluteError = abs(xact - approx);
			relativeError = 100*abs(absoluteError / xact);
			cout << fixed << xact << "\t" << approx << "\t" << absoluteError << "\t" << relativeError <<endl;
			n++;
		}
	}
}

