#include <iostream>

using namespace std;

int factorialUsingRecursion(int); // Use long long or unsigned long to avoid overflow of res
int factorialUsingLoops(int);

/*
    Time Complexity: Creates Recursion till n times so O(n)
    Space Complexity: Creates Activation record upto n times so O(n)
*/
int factorialUsingRecursion(int n) {
    if(n == 0 || n == 1)
        return 1;
    return n * factorialUsingRecursion(n-1);
}

/*
    Time Complexity: Executes loop till n times so O(n)
    Space Complexity: No additional activation records are created so O(1)
*/
int factorialUsingLoops(int n) {
    int fact = 1;
    for(int i=1; i <= n; i++)
        fact = fact * i;
    return fact;
}

int main() {
    int n;
    cin >> n;
    if(n < 0) {
        cerr << "Enter correct input" << endl;
        return 1;
    }
    cout << "Factorial of a number using recursion: " << factorialUsingRecursion(n) << endl;
    cout << "Factorial of a number using loops: " << factorialUsingLoops(n) << endl;
    return 0;
}