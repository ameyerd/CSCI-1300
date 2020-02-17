#include <iostream>
#include <cstdlib>
using namespace std;

void display(int[], int); // helper function to display a vector of integers, with given size argument

void selectSort(int values[], int size) {
    // for loop, over the element we will swap with the next-smalles element
    for (int first = 0; first < size; first++) {
        
        // loop over the *rest* of the array and find the smallest element
        // swap the values[first] with the samllest
        int smallest = values[first];
        int idx_smallest;
        for (int i = first + 1; i < size; i++) {
            if (values[i] < smallest ) { 
                smallest = values[i];
                idx_smallest = i;
                
            }
        } // end of the first time through this loop , we have smallest = 1; idx_smallest = 4
         // swap values[i] and values[first]
         if (idx_smallest != first) {
             int tmp = values[first];
             values[first] = values[idx_smallest];
             values[idx_smallest] = tmp;
         }
    }
    
}


int main() {
    
    // random test array
    srand(time(0)); // set random seed
    const int SIZE = 5;
    int array[5];
    for( int i = 0; i < SIZE; i++ ){
       array[i] = rand() % 101;
    }
    display(array,SIZE);
    
    // test our selection sort algorithm
    // TODO
    selectSort(array, SIZE);
    display(array,SIZE);
    
    
    return 0;
}

void display(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}