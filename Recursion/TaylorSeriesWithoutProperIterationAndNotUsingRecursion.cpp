/*
 My understanding without proper iteration, recursion to calculate Taylor Series
*/

#include <iostream>
using namespace std;
double calculateTaylorSeries(int, int);
double getPower(int, int);
double factorial(int);

double calculateTaylorSeries(int x, int n) {
    double sum = 1;
    for(int i=1; i < n; i++) {
        sum = sum + (getPower(x,i)/factorial(i));
        if(i >= 11)
            cout << sum;
    }
    return sum;
}

double getPower(int m, int n) {
    int power = m;
    while(n > 1) {
        power *= m;
        n--;
    }
    return power;
}

double factorial(int n) {
    int fact = 1;
    for(int i=1; i <= n; i++) {
        fact = fact * i;
    }
    return fact;
}

int main() {
    int x, n;
    cout << "Enter e power to be calculated" << endl;
    cin >> x;
    cout << "Enter the number of terms to be calculated" << endl;
    cin >> n;
    double res = calculateTaylorSeries(x, n);
    cout << "Taylor series output for " << x << " is : " << res << endl;
    return 0;
}