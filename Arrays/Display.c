#include <stdio.h>
struct Arr {
    int *arr;
    int size;
    int length;
};

void display(struct Arr a) {
    printf("Displaying Array elements of length: %d \n", a.length);
    for(int i = 0; i < a.length; i++) {
        printf(" %d ", a.arr[i]);
    }
    printf("\n");
} 

void append(struct Arr a, int value) {
    if(a.length > a.size ) {
        printf("Array size exceeds \n");
        return;
    }
    printf("Appending element %d at the end of index %d \n", value, a.length);
    a.arr[a.length++] = value; 
}

int main() {
    struct Arr a1;
    printf("Enter the max size of array \n");
    scanf("%d", &a1.size);
    // a1.length = 0;

    printf("Enter the length of elements \n");
    scanf("%d", &a1.length);

    for(int i = 0; i < a1.length; i++) {
        printf("Enter the element\t");
        scanf("%d", &a1.arr[i]);
    }

    display(a1);
    append(a1,4);
    display(a1);
    append(a1,5);
    display(a1);
    append(a1,6);
    display(a1);
    return 0;
}