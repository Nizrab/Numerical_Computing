#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
int main() {
	//size of arry either 7 or 6 check 
	//Variables
	double xyTimed = 0;
	double xAdded = 0;
	double yAdded = 0;
	double xSquared = 0;
	double part1 = 0;
	double part2 = 0;
	double a1, a0;
	//xyArry
	double xyArry[2][14] = {
		{83,71,64,69,69,64,68,59,81,91,57,65,58,62},//X values
		{183,168,171,178,176,172,165,158,183,182,163,175,164,175}//Y values
	};
	//Log all the values 
	//Math for all the values
	for (int x = 0; x < 14; x++) {
		xyTimed += log(xyArry[0][x]) * log(xyArry[1][x]);
		xAdded += log(xyArry[0][x]);
		yAdded += log(xyArry[1][x]);
		xSquared += pow(log(xyArry[0][x]), 2);
	}
	part1 = (14 * xyTimed) - (xAdded * yAdded);
	part2 = (14 * xSquared - pow(xAdded, 2));
	a1 = part1 / part2;
	a0 = exp((yAdded - a1 * xAdded) / 14);
	//outputs
	cout << "The reggression Parramaters are: " << endl;
	cout << "a1-> " << a1 << endl << "a0-> " << a0 << endl << "The NonLiniar regresion model is: " << endl;
	cout << "Y=" << a0 << "x X^" << a1;
}