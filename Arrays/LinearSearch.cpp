#include <iostream>
using namespace std;

class Array {
    private:
        int *A;
        int size;
        int length;

    public:
        Array(int size) {
            this->size = size;
            A = new int[size];
        }

        ~Array() {
            delete[] A;
        }

        void create();
        int LinearSearch(int key);
        int LinearSearchWithTransposition(int key);
        int LinearSearchWithMovetoHead(int key);
        void swap(int *x, int *y);
        void display();
};

void Array::create() {
    cout << "Enter the number of elements (length)" << endl;
    cin >> length;
    for(int i= 0; i < length; i++) {
        cout << "Enter the element at index " << i <<" : ";
        cin >> A[i];
    }
    cout << endl;
}

void Array::swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/*
    Time Complexity remains same in all the 3 cases which O(n)
    Space Complexity also stays same O(1)
    Linear Search with Transposition and Move to Head has no effect in the first iteration,
    In the subsequent iterations the data will be moved so that time taken to search the same element will be reduced.
    Transposition:  Moves the element by one position everytime it finds the element
    Move to Head: Moves the element to 0th index when its finds the element.
*/
int Array::LinearSearch(int key) {
    for(int i = 0; i < length; i++) {
        if(key == A[i]) {
            return i;
        }
    }
    return -1;
}

int Array::LinearSearchWithTransposition(int key) {
    for(int i = 0; i < length; i++) {
        if(key == A[i]) {
            if(i > 0) {
                swap(&A[i], &A[i-1]);
                return i-1;
            }
            return i; // Already at the front, if swap with i=0, then it would swap with -1 which is invalid.
        }
    }
    return -1;
}

int Array::LinearSearchWithMovetoHead(int key) {
    for(int i = 0; i < length; i++) {
        if(key == A[i]) {
            swap(&A[i], &A[0]);
            return 0; // Return 0 the new index after swapping.
        }
    }
    return -1;
}

void Array::display() {
    for (int i= 0; i < length; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    Array arr(10);
    arr.create();
    int x = 1;
    while(x) {
        cout << "Enter element to be searched: ";
        int key;
        cin >> key;
        arr.LinearSearchWithTransposition(key);
        arr.display();
        cout << "Want to continue enter 1 else 0 " << endl;
        cin >> x; 
    }
    return 0;
}