#include <stdio.h>
#include <iostream>
#include <iomanip> 
using namespace std;
int main() {
	double x[100], y[100];
	double n, iNp, yp, p;
	int cnt = 0;
	cout << "Please enter the number of data: ", cin >> n;
	cout << "Enter data: " << endl;
	for (int i = 0; i < n; i++) {
		cout << "x[" << i + 1 << "] = ", cin >> x[i];
		cout << "y[" << i + 1 << "] = ", cin >> y[i];
		cnt++;
	}
	cnt--;
	while (true) {
		iNp = 0;
		cout << "Please enter interpolation point: ", cin >> iNp;
		if (iNp > x[cnt] || iNp < x[0]) {
			cout << "INvalid Point" << endl;
			break;
		}
		else{
			yp = 0;
			for (int i = 0; i < n; i++){
				p = 1;
				for (int j = 0; j < n; j++){
					if (i != j){
						p = p * ((iNp - x[j]) / (x[i] - x[j]));
					}
				}
				yp = yp + p * y[i];
			}
			cout << fixed << setprecision(3) << "Interpolated value at: " << iNp << " is " << yp << endl;
			continue;
		}
	}
}