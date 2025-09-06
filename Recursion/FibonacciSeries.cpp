#include <iostream>

using namespace std;
void fibonacciSeriesUsingLoops(int);
int fibonacciSeriesUsingRecursion(int n);

static int count = 0;

/*
    Time Complexity: Executes loop till n times so O(n)
    Space Complexity: No additional activation records are created so O(1)
*/
void fibonacciSeriesUsingLoops(int n) {
    int n1 = 0;
    int n2 = 1;
    cout << n1 << " ";
    cout << n2 << " ";
    for(int i = 1; i < n-1; i++) {
        count++;
        int temp = n2;
        n2 = n1 + n2;
        n1 = temp;
        cout << n2 << " ";
    }
}

/*
    Time Complexity: Creates Recursion till n times so O(2^n)
    
    Each call to fibonacciSeriesUsingRecursion(n) spawns two recursive calls
    The height of the tree is n, and at each level, the number of calls roughly doubles.
    Therefore: T(n)=T(n−1)+T(n−2)+O(1)

    Space Complexity: Creates Activation record upto n times so O(n)
*/
int fibonacciSeriesUsingRecursion(int n) {
    count++;
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fibonacciSeriesUsingRecursion(n-2) + fibonacciSeriesUsingRecursion(n-1);
}

// Declare Array before the function definition else Compiler will throw error.
int arr[10];

void setArray() {
    for(int i=0; i < 10; i++) {
        arr[i] = -1;
    }
}

void printArray() {
    for(int i=0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << "Printing Done" << endl;
}

/*
    Time Complexity: Saves some recursive call by taking the existing value from the array,thus O(log n)
    Space Complexity: Creates Activation records for n number of recursive calls O(n)
*/
int fibonacciSeriesUsingEfficientRecursion(int n) {
    if(n == 0) {
        arr[0] = 0;
        count++;
        return 0;
    }
    if(n == 1) {
        arr[1] = 1;
        count++;
        return 1;
    }
    if(arr[n] == -1) {
        count++;
        arr[n] = fibonacciSeriesUsingEfficientRecursion(n-1) + fibonacciSeriesUsingEfficientRecursion(n-2);
    }
    return arr[n];
}

int main() { 
    int n;
    cout << "Enter number of terms" << endl;
    cin >> n;
    cout << endl;

    cout << "Fibonacci series using Loops: ";
    fibonacciSeriesUsingLoops(n);
    cout << endl << "Count used in Loops is: " << count + 2 << endl;
    count = 0;
    cout << endl;

    cout << "Fibonacci series using Recursion: ";
    for(int i=0; i < n; i++)
        cout << fibonacciSeriesUsingRecursion(i) << " ";
    cout << endl << "Count used in Recursion is: " << count - 1 << endl;
    count = 0;
    cout << endl;

    setArray();
    cout << "Fibonacci Series using Efficient Recursion:";
    for(int i=0; i < n; i++)
        cout << fibonacciSeriesUsingEfficientRecursion(i) << " ";
    cout << endl << "Count used in Efficient Recursion is: " << count - 1 << endl;
    return 0;
}