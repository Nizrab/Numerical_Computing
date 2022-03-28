#include<iostream>
using namespace std;
int main() {
	double x;
	double q = 100;
	long double approx = 0;
	long double abolu = 0;
	long double realative = 0;
	cout << "Enter value of X" << endl;
	cin >> x;
	cout << "The number Of terms: " << q << endl;
	cout << "True value: " << log(x) << endl;
	for (int i = 1; i <= q; i++) {
		 approx += pow((-1), i - 1) * (pow((x - 1), i) / i);
	}
	abolu= (log(x)) - approx;
	realative = abolu / log(x);
	cout << "Approximate value: " << approx << endl;
	cout << "Absolute Error: " << fixed << abolu << endl;
	cout << "Relative Error: " << realative << endl;
}