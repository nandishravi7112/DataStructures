#include <iostream>
using namespace std;

class Array {
    private:
        int* A;
        int size;
        int length;

    public:
        explicit Array(int size) {
            this->size = size;
            this->length = 0;
            A = new int[size];
        }
    
        ~Array() {
            delete[] A;
        }

        int getLength();

        int get(int index);
        void set(int index, int value);

        int sum();
        double avg();

        Array Union(Array& B);
        Array Intersection(Array& B);
        Array Difference(Array& B);
        bool Membership(int key);

        int min();
        int max();

        void reverse();
        void reverseWithoutAdditionalArray();

        void leftShift();
        void rightShift();

        void leftRotate();
        void rightRotate();

        bool isSorted();

        void arrange();
    
        void swap(int *a, int *b);

        void create();
        void display();
        bool append(int value);
        void insert(int value);
        bool insert(int index, int value);
        bool delete_element(int index);
        Array merge(Array& B);
};

int Array::getLength() {
    return length;
}

int Array::get(int index) {
    if(index >=0 && index < length) {
        return A[index];
    } else {
        cerr << "Index is not valid " << endl;
        return -1;
    }
}

void Array::set(int index, int value) {
    if(index >=0 && index < length) {
        A[index] = value;
    } else {
        cerr << "Index is not valid " << endl;
    }
}

int Array::max() {
    int max = A[0];
    for(int i = 1; i < length; i++) {
        if(max < A[i]) {
            max = A[i];
        }
    }
    return max;
}

int Array::min() {
    int min = A[0];
    for(int i = 1; i < length; i++) {
        if(min > A[i]) {
            min = A[i];
        }
    }
    return min;
}

int Array::sum() {
    int sum = 0;
    for(int i = 0; i < length; i++) {
        sum = sum + A[i];
    }
    return sum;
}

double Array::avg() {
    double avg = 0;
    double sum = this->sum();
    int length = getLength();
    return (sum/length);
}

// Set Operations on Array
Array Array::Union(Array& B) {
    Array C(50);
    // Sorted arrays uses similar to merge techinque
    // Union has to copy all the elements of A and B without duplicating the elements
    int m = this->length;
    int n = B.length;

    if(this->isSorted() && B.isSorted()) {
        int i = 0, j = 0, k = 0;
        while((i < m) && (j < n)) {
            if(A[i] == B.A[j]) {
                C.A[k++] = A[i++];
                j++;
            } else if(A[i] < B.A[j]) {
                C.A[k++] = A[i++];
            } else {
                C.A[k++] = B.A[j++];
            }
        }
        while(i<m) {
            C.A[k++] = A[i++];
        }
        while(j<n) {
            C.A[k++] = B.A[j++];
        }
        C.length = k;
        return C;
    } else {
        cout << "Arrays are not sorted, Performing Union Operation" << endl;
        int i =0, j = 0, k = 0;
        while(i < m) {
            C.A[k++] = A[i++];
        }
        C.length = k;
        for(; j < n; j++) {
            if(!C.Membership(B.A[j])) {
                C.A[k++] = B.A[j];
                C.length = k;
            }
        }
        C.length = k;
        return C;
    }
}

Array Array::Intersection(Array& B) {
    Array C(50);
    // Sorted arrays uses similar to merge techinque
    // Intersection has to copy only those elements which are common in both the arrays.
    int m = this->length;
    int n = B.length;

    if(this->isSorted() && B.isSorted()) {
        int i = 0, j = 0, k = 0;
        while((i < m) && (j < n)) {
            if(A[i] == B.A[j]) {
                C.A[k++] = A[i++];
                j++;
            } else if(A[i] < B.A[j]) {
                i++;
            } else {
                j++;
            }
        }
        C.length = k;
        return C;
    } else {
        cout << "Arrays are not sorted performing Intersection" << endl;
        int k = 0;
        for(int i = 0; i < m; i++) {
            if(B.Membership(A[i]) && !C.Membership(A[i])) {
                C.A[k++] = A[i];
            }
        }
        C.length = k;
        return C;
    }
}

Array Array::Difference(Array& B) {
    Array C(50);
    // Sorted arrays uses similar to merge techinque
    // Difference has to copy only those elements which are there only in A, (if its in B then dont copy).
    int m = this->length;
    int n = B.length;

    if(this->isSorted() && B.isSorted()) {
        int i = 0, j = 0, k = 0;
        while((i < m) && (j < n)) {
            if(A[i] < B.A[j]) {
                C.A[k++] = A[i++];
            } else if(A[i] > B.A[j]) {
                j++;
            } else {
                i++;
                j++;
            }
        }
        while(i<m) {
            C.A[k++] = A[i++];
        }
        C.length = k;
        return C;
    } else {
        int k = 0;
        cout << "Arrays are not sorted, Performing Difference Operation" << endl;
        for(int i = 0; i < m; i++) {
            if(!B.Membership(A[i]) && !C.Membership(A[i])) {
                C.A[k++] = A[i];
            }
        }
        C.length = k;
        return C;
    }
}

bool Array::Membership(int value) {
    for(int i = 0; i < length; i++) {
        if(A[i] == value) {
            return true;
        }
    }
    return false;
}

void Array::create() {
    cout << "Enter the Length of the array elements" << endl;
    cin >> length;
    if(length > size) {
        cerr << "Array length exceeds" << endl;
        length = 0; // Reset if array length is more than the size
        return;
    }
    cout << "Enter the array elements: " << endl;
    for(int i = 0; i < length; i++) {
        cout << "Array element: " << i << " = " << flush;
        cin >> A[i];
    }
    cout << "Displaying array after creation with length " << length << endl;
    display();
}

void Array::display() {
    for (int i= 0; i < length; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

bool Array::append(int value) {
    if(length >= size) {
        cerr << "Cannot append element, Array Size exceeds" << endl;
        return false;
    }
    A[length++] = value;
    cout << "Displaying array after appending successfully with value " << value << endl;
    display();
    return true;
}

void Array::reverse() {
    int B[getLength()];
    for(int i = 0, j = length -1; i < length; i++, j--) {
        B[i] = A[j];
    }
    for(int i = 0; i < length; i++) {
        A[i] = B[i];
    }
    cout << "Displaying array after Reversing" << endl;
    display();
}

// 2 Pointer techinque for reversing
void Array::reverseWithoutAdditionalArray() {
    int i = 0;
    int j = length - 1;
    while(i < j) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        i++;
        j--;
    }
    cout << "Displaying array after Reversing" << endl;
    display();
}

void Array::leftShift() {
    for(int i = 0; i < length - 1; i++) {
        A[i] = A[i+1];
    }
    A[length - 1] = 0;
    cout << "Displaying array after Left Shift" << endl;
    display();
}

void Array::rightShift() {
    for(int i = length -1; i > 0; i-- ) {
        A[i] = A[i-1];
    }
    A[0] = 0;
    cout << "Displaying array after Right Shift" << endl;
    display();
}

void Array::leftRotate() {
    int first = A[0];
    for(int i = 0; i < length - 1; i++) {
        A[i] = A[i+1];
    }
    A[length - 1] = first;
    cout << "Displaying array after Left rotate" << endl;
    display();
}

void Array::rightRotate() {
    int last = A[length - 1];
    for(int i = length -1; i > 0; i-- ) {
        A[i] = A[i-1];
    }
    A[0] = last;
    cout << "Displaying array after Right Rotate" << endl;
    display();
}

// Inserts value in an sorted array.
void Array::insert(int value) {
    if(!isSorted()) {
        cerr << "Array is not sorted" << endl;
        return;
    }
    if(length >= size) {
        cerr << "Array size limit exceeds, cannot insert value : " << value << endl;
        return;
    }

    int i = length - 1;
    // Check till the element is greater than A[i], if the element is smaller or negative it should not go beyond 0
    while(i >= 0 && A[i] > value) {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = value;
    length++;
    cout << "Displaying array after inserting element " << value << " according to its value in the sorted array "<< endl;
    display();
}

bool Array::insert(int index, int value) {
    if(length >= size) {
        cerr << "Cannot insert element, Array size exceeds" << endl;
        return false;
    }
    if(index < 0 || index > length) {
        cerr << "Invalid index" << endl;
        return false;
    }
    for(int i = length; i > index; i--) {
        A[i] = A[i-1];
    }
    A[index] = value;
    length++; // Since inserted new element, length should be incremented.
    cout << "Displaying array after inserting element " << value << " at the index " << index << endl;
    display();
    return true;
}

Array Array::merge(Array& B) {
    int m = this->length;
    int n = B.length;
    Array C(m+n);
    int i = 0, j = 0, k = 0;
    while((i < m) && (j < n)) {
        if(this->A[i] < B.A[j]) {
            C.A[k++] = this->A[i++];
        } else {
            C.A[k++] = B.A[j++];
        } 
    }
    while(i < m) {
        C.A[k++] = this->A[i++];
    }
    while(j < n) {
        C.A[k++] = B.A[j++];
    }
    C.length = k;
    return C;
}

void Array::swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool Array::isSorted() {
    // i < length -1 since comparision can be done till second last element if its greater or not.
    for(int i = 0; i < length - 1; i++) {
        if(A[i] > A[i+1])
            return false;
    }
    return true;
}

// Arranges negative and positive elements in Negative and Positive order
// Previously i used 2 if conditions and while loop instead of 3 while loops
// If i use 2 if conditions i will recheck the same elements again and again.
// To avoid that i can use while loops to check if element is less than 0, increment else check j is greater than 0 else decrement
// After this the i and j values can be modified and it may be more than i>=j,
// In order to avoid such case if(i<j) is also checked
// Swap elements and increment i and j
void Array::arrange() {
    int i = 0, j = length - 1;
    while(i < j) {
        while(i < j && A[i] < 0) {
            i++;
        }
        while(i < j && A[j] >= 0) {
            j--;
        }
        if(i < j) {
            swap(&A[i], &A[j]);
            i++;
            j--;
        }
    }
    display();
}

bool Array::delete_element(int index) {
    if(index >=0 && index < length) {
        for(int i=index; i < length-1; i++) {
            A[i] = A[i+1];
        }
        length--;
        cout << "Displaying array after deleting element from index " << index << endl;
        display();
        return true;
    } else {
        cerr << "Invalid index" << endl;
        return false;
    }
}

void display_menu() {
    cout << "Options" << endl;
    cout << "1. Append" << endl;
    cout << "2. Insert" << endl;
    cout << "3. Delete" << endl;
    cout << "4. Merge" << endl;
    cout << "5. Rearrange" << endl;
    cout << "6. Reverse" << endl;
    cout << "7. Shift Operations" << endl;
    cout << "8. Print Array Details" << endl;
    cout << "9. Set Operations" << endl;
}

int main() {
    int size;
    cout << "Enter the maximum size of array" << endl;
    cin >> size;
    Array arr(size), arr2(10);
    arr.create();

    cout << endl;
    display_menu();

    char ch;
    cin >> ch;
    bool to_continue = 1;
    while(to_continue) {
        switch(ch) {
            case '1': {
                int value;
                cout << "Enter element to append: ";
                cin >> value;
                arr.append(value);
                break;
            }
            case '2': {
                int value;
                cout << endl << "Enter element to insert: ";
                cin >> value;
                arr.insert(value);
                break;
            }
            case '3': {
                int index;
                cout << endl << "Enter the index of the element to be deleted: ";
                cin >> index;
                arr.delete_element(index);
                break;
            }
            case '4': {
                arr2.create();
                cout << "First array" << endl;
                arr.display();
                cout << "Second array" << endl;
                arr2.display();
                Array C = arr.merge(arr2);
                cout << "Array C after merging arr1 and arr2" << endl;
                C.display();
                break;
            }
            case '5': {
                cout << endl << "Rearranging array elements into Negatives and Positives" << endl;
                arr.arrange();
                break;
            }
            case '6': {
                cout << endl << "Reversing the Array";
                cout << "Array before reveresal" << endl;
                arr.display();
                cout << "Array after reveresal" << endl;
                arr.reverseWithoutAdditionalArray();
                break;
            }
            case '7': {
                char op;
                cout << "Select the Shift operations" << endl;
                cout << "a. Left Shift" << endl;
                cout << "b. Right Shift" << endl;
                cout << "c. Left Rotate" << endl;
                cout << "a. Right Rotate" << endl;

                cin >> op;
                switch(op) {
                    case 'a':
                        arr.leftShift();
                        break;
                    case 'b':
                        arr.rightShift();
                        break;
                    case 'c':
                        arr.leftRotate();
                        break;
                    case 'd':
                        arr.leftRotate();
                        break;
                    default:
                        cout << "invalid choice" << endl;
                        break;
                }
                break;
            }
            case '8': {
                cout << "Details of Array:" << endl;
                arr.display();
                cout << "Array Sum: " << arr.sum() << endl;
                cout << "Array Avg: " << arr.avg() << endl;
                cout << "Minimum element in the array: " << arr.min() << endl;
                cout << "Maximum element in the array: " << arr.max() << endl;
                cout << "Current length: " << arr.getLength() << endl;
                if(!arr.isSorted()) {
                    cout << "Array is not sorted" << endl;
                }
                break;
            }
            case '9': {
                char op;
                cout << "Select the Set operations" << endl;
                cout << "a. Union" << endl;
                cout << "b. Intersection" << endl;
                cout << "c. Difference" << endl;
                cout << "a. Set Membership" << endl;
                cin >> op;
                Array arr3(50);
                arr3.create();
                switch(op) {
                    case 'a': {
                        Array C = arr.Union(arr3);
                        C.display();
                        break;
                    }
                    case 'b': {
                        Array C = arr.Intersection(arr3);
                        C.display();
                        break;
                    }
                    case 'c': {
                        Array C = arr.Difference(arr3);
                        C.display();
                        break;
                    }
                    case 'd': {
                        // Array C = arr.membership(arr3);
                        
                        break;
                    }
                    default:
                        cout << "Invalid set operation" << endl;
                        break;
                }
                break;
            }
            default: {
                cout << "Invalid operation" << endl;
                break;
            }
        }
        cout << "If you wish to continue press 1 else 0: ";
        int cont;
        cin >> cont;
        if(cont != 1)
            break;
        cout << endl;
        display_menu();
    }
    return 0;
}

/*
    Two pointer techniques:
        Arranging, Reversing
        Also can be used for Quick Sort (partitioning)
*/
