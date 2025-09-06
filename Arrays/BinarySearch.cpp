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

        int getLength();
        void create();
        int BinarySearch(int key);
        int BinarySearchWithRecursion(int low, int high, int key);
        void display();
};

int Array::getLength() {
    return length;
}

/*
    Time Complexity: O(log(n)) with reduced iterations it comes from O(n) to O(log(n))
    Space Complexity: O(1)
*/
int Array::BinarySearch(int key) {
    int low = 0; // Take 0th index as low
    int high = length - 1; // Take the last index as high
    int mid;
    // If low becomes greater than high, then it means the element are searched with all the possible way and it was not found
    // Then the low started to shift to the other side, which will still not have the element
    while(low <= high) {
        mid = (low + high)/2; // Always change low, high and mid in the loop to track the current values
        if(A[mid] == key) {
            return mid; // if key and mid matches return mid
        } else if(A[mid] < key) { // If mid is less than key, then the element will be present in the right half of the array
            low = mid + 1; // so increase low to search in the other half, by making low to mid + 1
        } else {    // If mid is greater than key, then the element will be present in the left half of the array
            high = mid - 1; // So decrease high by mid - 1
        }
    }
    return -1;
}

/*
    Time Complexity: O(log(n)) with reduced iterations it comes from O(n) to O(log(n))
    Space Complexity: O(log(n)) with Recursion stack need more space
    Since its Tail recursion its always better to replace with Iterative version
    As some compiler may also do this internally
    Which avoids additional stack usage
*/
int Array::BinarySearchWithRecursion(int low, int high, int key) {

    if(low <= high) { 
        int mid = (low + high)/2; // Chat Gpt suggested to use mid= (low + (high - low) / 2) which checks overflow in int
        if(A[mid] == key) {
            return mid;
        } else if(A[mid] < key) {
            return BinarySearchWithRecursion(mid + 1, high, key);
        } else {
            return BinarySearchWithRecursion(low, mid - 1, key);
        }
    }
    return -1;
}

void Array::create() {
    cout << "Enter the number of elements (length)" << endl;
    cin >> length;
    cout << "Enter the array in sorted order" << endl;
    for(int i= 0; i < length; i++) {
        cout << "Enter the element at index " << i <<" : ";
        cin >> A[i];
    }
    cout << endl;
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
        cout << arr.BinarySearchWithRecursion(0, arr.getLength() -1, key) << endl;
        cout << "Want to continue enter 1 else 0 " << endl;
        cin >> x; 
    }
    arr.display();
    return 0;
}