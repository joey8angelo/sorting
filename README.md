## QuickSort/InsertionSort
A program to show the speeds of quicksort median of three, quicksort midpoint, and insertion sort and how they work.
### Quicksort Partitioning
Each quicksort uses the same partitioning algorithm, the difference between the two quicksort's are where they choose to partition the array. One uses the middle element, and the other uses the median of the first, middle, and last element in the array. The partitioning function works by making the pivot point the first element 
```c++
    /* i = lower bound of array */
    int temp = numbers[i];
    numbers[i] = numbers[pivotPoint];
    numbers[pivotPoint] = temp;
    
    int pivot = numbers[i];
    int x = i + 1;
```
Then sorting the array in the form p | <p | >p | ... meaning, the pivot is first, all elements smaller than the pivot come after it, and all elements larger than the pivot come after the last smaller element. 
```c++
    for (int y = x; y <= k; y++) {
        if (numbers[y] < pivot) {
            int temp = numbers[x];
            numbers[x] = numbers[y];
            numbers[y] = temp;
            x = x + 1;
        }    
    }
```
Then the pivot is placed in between the two sets of values and the pivot location is returned
```c++
    temp = numbers[i];
    numbers[i] = numbers[x - 1];
    numbers[x - 1] = temp;
    return x - 1;
```
The quicksort algorithm repeats partitioning smaller and smaller arrays until the lower bound i, is >= the upper bound k
```c++
void Quicksort_Midpoint(int* numbers, int i, int k) {
    if (i < k) {
        int pivot = Partition(numbers, i, k, (i + k) / 2);
        Quicksort_Midpoint(numbers, i, pivot - 1);
        Quicksort_Midpoint(numbers, pivot + 1, k);
    }
}
```

### Insertion Sort
Much Slower, and much less interesting, is the insertion sort. This sorting algorithm goes through the array one by one and checks if the current value is greater than the previous value. If it is not, it will trickle that value backwards until it is greater than the previous value. Repeating this process until it has gone through the entire array.