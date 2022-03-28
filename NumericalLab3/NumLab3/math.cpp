#define _CRT_SECURE_NO_WARNINGS
//Includes
#include <iostream>
#include <stdio.h>
#include<math.h>
#include<cmath>
#include <iomanip> 
using namespace std;
int main(){
    ///Variables
    int uIn;
    int n, i;
    int pie = 1;
    unsigned long long factorial = 1;
    double e = exp(1.0);
    long double approx;
    long double aboslute;
    //While loop for menu
    while(pie==1){
        //userinputs
        cout << "For Part 1 press [1]\nFor part 2 press [2]\nTo exit [3]" << endl;
        cin >> uIn;
        if (uIn == 2) {
            cout << "Enter an integer: " << endl;
            cin >> n;
            getchar();
            // Show error if the user enters a negative intege
            if (n < 0)
                cout << "Error! Factorial of a negative number doesn't exist" << endl;
            else {
                //sets collums 
                cout << setw(15) << "N" <<
                        setw(15) << "N!" <<
                        setw(15) << "Approxx" <<
                        setw(15) << "Absolute" <<
                        setw(15) << "Relative" << endl;
                //Outputs Rows with the data 
                for (i = 1; i <= n; ++i) {
                    //math for factoral 
                    factorial *= i;
                    //Approx
                    approx = pow((i / e), i) * sqrt(2 * (4.0 * atan(1.0)) * i);
                    //aboslute
                    aboslute = factorial - approx;
                    cout << setw(15) << i <<
                            setw(15) << factorial <<
                   fixed << setw(15) << approx <<
                            setw(15) << aboslute <<
                            setw(15) << aboslute / factorial << endl;
                }
             }
        }
        //Part 1 given codes
        else if(uIn==1){
            int s;
            float t, y;
            t = 1.0;
            for (s = 0; s <= 127; s++) {
                t = t * 2.0;
                y = 1.0 / t;
                printf("%d %e %E\n", s, y, t);
            }
        }
        //if anything exit
        else {
            cout << "GoodBye" << endl;
            pie = 0;
        }
    }
    return 0;
}//main end 