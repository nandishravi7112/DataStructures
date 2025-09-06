#include <iostream>

using namespace std;
int sumofNaturalNumbersUsingRecursion(int);
int sumOfNaturalNumbersUsingLoop(int);
int sumOfNaturalNumbersUsingFormula(int);

/*
    Time Complexity: Creates Recursion till n times so O(n)
    Space Complexity: Creates Activation record upto n times so O(n)
*/
int sumofNaturalNumbersUsingRecursion(int n) {
    if(n == 1)
        return 1;
    return n + sumofNaturalNumbersUsingRecursion(n-1);
}

/*
    Time Complexity: Executes loop till n times so O(n)
    Space Complexity: No activation record additional is created so O(1)
*/
int sumOfNaturalNumbersUsingLoop(int n) {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

/*
    Best Approach unless explicitly specified to use loop or recursion
    
    Time Complexity: Calculates using Formula so O(1)
    Space Complexity: No activation record additional is created so O(1)
*/
int sumOfNaturalNumbersUsingFormula(int n) {
    int sum = 0;
    sum = (n * (n+1))/2;
    return sum;
}

int main() {
    int n;
    cout << "Enter number" << endl;
    cin >> n;
    cout << "sum of n natural numbers using Recursion is: " <<  sumofNaturalNumbersUsingRecursion(n) << endl;;
    cout << "Sum of n natural numbers using loop is: " << sumOfNaturalNumbersUsingLoop(n) << endl;
    cout << "Sum of n natural numbers using formula is: " << sumOfNaturalNumbersUsingFormula(n) << endl;
    return 0;
}