#include <iostream>

using namespace std;

int powerOfNumberUsingRecursion(int, int);
int powerOfNumberUsingLoops(int, int);
int powerOfNumberWithEfficientRecursionIteration(int, int);

/*
    Time Complexity: Creates Recursion till n times so O(n)
    Space Complexity: Creates Activation record upto n times so O(n)
*/
int powerOfNumberUsingRecursion(int m, int n) {
    if(n == 0)
        return 1;
    return m * powerOfNumberUsingRecursion(m,n-1);
}

/*
    Time Complexity: Executes loop till n times so O(n)
    Space Complexity: No activation record additional is created so O(1)
*/
int powerOfNumberUsingLoops(int m, int n) {
    int power = 1;
    for(int i = 1; i <= n; i++) {
        power = power * m; // Make sure to multiply m the number itself not i
    }
    return power;
}

/*
    Time Complexity: Creates Recursion till n by avoiding certain iterations therefore it is O(log n)
        Each steps halves the next iteration so it will be log2(n) recursive call
    Space Complexity: Creates Activation record upto n times so O(log n)
*/
// Best Approach among the other options since Time and Space complexity is better even for larger numbers
// By reducing the number of iterations using recursion
int powerOfNumberWithEfficientRecursionIteration(int m, int n) {
    if(n == 0)
        return 1;
    if(n % 2 == 0)
        return powerOfNumberWithEfficientRecursionIteration(m*m, n/2);
    else
        return (m * powerOfNumberWithEfficientRecursionIteration(m*m, (n-1)/2));
}

int main() {
    int m,n;
    cout << "Enter a number and its power value to be calculated with comma separated:" << endl;
    cin >> m >> n;
    if(n < 0) {
        cerr << "Power value is not correct" << endl;
        return 1;
    }
    cout << "Power using Recursion: " << powerOfNumberUsingRecursion(m,n) << endl;
    cout << "Power using Loops: " << powerOfNumberUsingLoops(m,n) << endl;
    cout << "Power using efficient Recursion: " << powerOfNumberWithEfficientRecursionIteration(m,n) << endl;
    return 0;
}