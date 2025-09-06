#include <iostream>

using namespace std;

double exponentialUsingRecursion(int, int);
double exponentialUsingLoops(int, int);
double exponentialUsingLoopsTakingCommonMultiples(double, double);
double exponentialUsingRecursionTakingCommonMultiples(double, double);

// Calculate e^x using Taylor Series 
// My solution
/*
    Time Complexity: Number of Multiplication for each iteration based on formula
    1 + (x/1!) + x^2/2! + x^3/3! + x^4/4! + ...... + x^n/n!
    In first condition result 1, there is no multiplication done
    Similarly in second condition result x/1! no multiplication is done
    But from 2nd onwards multiplication for numerator is 1( i.e x*x) and denominator 2*1 is 1. i.e total multiplication combining numerator and denominator is 2.
    3rd is x*x*x , 2 multiplication in numerator and 3*2*1, 2 multiplication in denominator. Therefore total is 4,
    List goes on.
    Therefore 2[1 + 2 + 3 + 4 + .... + 5];  this is total number of multiplication required for n terms
    1 + 2 + 3 + .. + n is nothing but sum of n natural numbers which is,
    2 * ( n * (n+1) / 2);
    Therefore the equation becomes n*n+1;
    Which is n^2 + 1
    Time Complexity becomes O(n^2);
    Space Complexity: Creates Activation record upto n times so O(n)
*/
double exponentialUsingRecursion(int x, int n) {
    static double p = 1, f = 1;
    if(n == 0)
        return 1;
    return exponentialUsingRecursion(x, n-1) + (p*=x)/(f*=n);
}

// Abdul Bari's Solution
/*
double exponentialUsingRecursion(int x, int n) {
    static double p = 1, f = 1;
    if(n == 0)
        return 1;
    else {
        double res = exponentialUsingRecursion(x, n-1);
        p = p * x;
        f = f * n;
        return res + (p/f);
    }
    return exponentialUsingRecursion(x, n-1) + (p*=x)/(f*=n);
}
*/

// Bit cleaner way to avoid getting power and factorial
double exponentialUsingLoops(int x, int n) {
    double sum = 1;
    double num = 1;
    double den = 1;
    for(int i = 1; i <= n; i++) {
        num = num * x;
        den = den * i;
        sum = sum + (num/den);
    }   
    return sum;
}

// Below two approach with loops and recursion are efficient way
// Taking Common Multiple and avoiding extra multiplication
// With this approach time complexity will be reduced to O(n) from O(n^2)
// Horner's Rule solution with Loops
double exponentialUsingLoopsTakingCommonMultiples(double x, double n) {
    double sum = 1;
    for(; n > 0; n--) {
        sum = 1 + (x/n) * sum; 
    }
    return sum;
}

// Horner's Rule solution with Recursion
double exponentialUsingRecursionTakingCommonMultiples(double x, double n) {
    static int sum = 1;
    if(n == 0)
        return sum;
    sum = (1 + (x/n)) * sum;
    return exponentialUsingRecursionTakingCommonMultiples(x,n-1);
}

/*
double getPower(int m, int n) {
    double power = 1;
    for(int i= 1; i <= n; i++)
        power = power * m;
    return power;
}

double getFactorial(int n) {
    double fact = 1;
    for(int i=1; i <= n; i++)
        fact = fact * i;
    return fact;
}

double exponentialUsingLoops(int x, int n) {
    double sum = 1;
    for(int i = 1; i <= n; i++)
        sum = sum + (getPower(x,i)/getFactorial(i));
    return sum;
}
*/

int main() {
    int x, n;
    cout << "Enter exponential x " << endl;
    cin >> x;
    cout << "Enter n value" << endl;
    cin >> n;
    cout << "Result of exponential recursion " << exponentialUsingRecursion(x,n) << endl;
    cout << "Result of exponential using Loops inefficient: " << exponentialUsingLoops(x,n) << endl;
    cout << "Result of exponential using Loops Efficiently: " << exponentialUsingLoopsTakingCommonMultiples(x,n) << endl;
    cout << "Result of exponention using Recursion Efficiently " << exponentialUsingRecursionTakingCommonMultiples(x,n) << endl;
    return 0;
}