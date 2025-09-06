#include <iostream>

using namespace std;

/*
    Time Complexity: Executes loop till n times so O(n)
    Space Complexity: No additional activation records are created so O(1)
*/
int fact(int n) {
    int fact = 1;
    for(int i =1; i <=n; i++)
        fact = fact * i;
    return fact;
}

/*
    Time Complexity: Creates Recursion till 2^n times , Tree formation O(2^n)
    Space Complexity: Creates Activation record upto n times so O(n)
*/
int combination(int n, int r) {
    if(r == n && r == 0 )
        return 1;
    return combination(n-1,r-1) + combination(n-1,r);
}

int main() {
    int n,r;
    cout << "Enter number 'n' and range 'r' " << endl;
    cin >> n >> r;
    int t1 = fact(n);
    int t2 = fact(r);
    int t3 = fact(n-r);
    int res = (t1)/(t2 * t3);
    cout << "nCr value using Loops: " << res << endl;
    cout << "nCr value using Recursion is: " << combination(n,r) << endl;
    return 0;
}