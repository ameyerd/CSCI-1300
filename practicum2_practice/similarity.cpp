#include <iostream>
using namespace std;

bool similarity(int arr1[], int size1, int arr2[], int size2) {
    
    int count = 0;
    for(int i = 0; i < size1; i++) {
        if (arr1[i] == arr2[i]) {
            count++;
        }
    }
    
    if (count == size1) {
        return true;
    }
    else {
        return false;
    }
    
}

int main() {
    
    int arr1[] = {1, 4, 6, 7, 23, 3};
    int arr2[] = {1, 4, 6, 7, 23, 3};
    
    cout << similarity(arr1, 6, arr2, 6) << endl;
    
    int arr3[] = {1, 4, 6, 7, 23, 3};
    int arr4[] = {1, 14, 6, 7, 23, 3};
    
    cout << similarity(arr3, 6, arr4, 6);
}