#include <iostream>
#include <ctime>

using namespace std;

const int NUMBERS_SIZE = 50000;
const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000;

int Partition(int*, int, int, int);

void Quicksort_Midpoint(int*, int, int);

void Quicksort_MedianOfThree(int*, int, int);

void InsertionSort(int*, int);

void fillArrays(int*, int*,int*);

int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1);
}

bool isOrdered(int* n){
    for (int i = 0; i < NUMBERS_SIZE - 1; i++) {
        if (n[i] > n[i + 1])
            return false;
    }
    return true;
}

int main() {
    int arr1[NUMBERS_SIZE];
    int arr2[NUMBERS_SIZE];
    int arr3[NUMBERS_SIZE];

    fillArrays(arr1, arr2, arr3);

    cout << endl;

    clock_t Start = clock();
    Quicksort_MedianOfThree(arr1, 0, NUMBERS_SIZE - 1);
    clock_t End = clock();

    cout << "Quicksort_MedianOfThree on arr1 took " << (End - Start) / CLOCKS_PER_MS << "ms" << endl;

    Start = clock();
    Quicksort_Midpoint(arr2, 0, NUMBERS_SIZE - 1);
    End = clock();

    cout << "Quicksort_Midpoint on arr2 took " << (End - Start) / CLOCKS_PER_MS << "ms" << endl;

    Start = clock();
    InsertionSort(arr3, NUMBERS_SIZE);
    End = clock();

    cout << "InsertionSort on arr3 took " << (End - Start) / CLOCKS_PER_MS << "ms" << endl;


    if (isOrdered(arr1)) {
        cout << "arr1 in order" << endl;
    }
    if (isOrdered(arr2)) {
        cout << "arr2 in order" << endl;
    }
    if (isOrdered(arr3)) {
        cout << "arr3 in order" << endl;
    }
    return 0;
}

void Quicksort_Midpoint(int* numbers, int i, int k) {
    if (i < k) {
        int pivot = Partition(numbers, i, k, (i + k) / 2); // partition array
        Quicksort_Midpoint(numbers, i, pivot - 1); // partition left
        Quicksort_Midpoint(numbers, pivot + 1, k); // partition right
    }
}

void Quicksort_MedianOfThree(int* numbers, int i, int k) {
    if (i < k) {
        int median;
        if (numbers[i] <= numbers[k] && numbers[i] >= numbers[(i + k) / 2]) {
            median = i;
        }
        else if (numbers[k] <= numbers[i] && numbers[k] >= numbers[(i + k) / 2]) {
            median = k;
        }
        else {
            median = (i + k) / 2;
        }
        int pivot = Partition(numbers, i, k, median); // partition array
        Quicksort_Midpoint(numbers, i, pivot - 1); // partition left
        Quicksort_Midpoint(numbers, pivot + 1, k); // partition right
    }
}

int Partition(int* numbers, int i, int k, int pivotPoint) {
    int temp = numbers[i];
    numbers[i] = numbers[pivotPoint]; // swap pivotPoint with the first value
    numbers[pivotPoint] = temp;
    
    int pivot = numbers[i]; // find pivot
    int x = i + 1;

    for (int y = x; y <= k; y++) { // go through array and swap in form [p | <p | >p | ...]
        if (numbers[y] < pivot) {
            int temp = numbers[x];
            numbers[x] = numbers[y];
            numbers[y] = temp;
            x = x + 1;
        }    
    }
    temp = numbers[i]; // swap pivot between <p and >p
    numbers[i] = numbers[x - 1];
    numbers[x - 1] = temp;
    return x - 1;
}

void InsertionSort(int* numbers, int numbersSize) {
    for (int i = 1; i < numbersSize; i++) {
        int j = i;
        while (j > 0 && numbers[j] < numbers[j - 1]) {
            int temp = numbers[j];
            numbers[j] = numbers[j - 1];
            numbers[j - 1] = temp;
            --j;
        }
    }
}

void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}