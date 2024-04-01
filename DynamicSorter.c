#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
//Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    printf("Sorted array using Bubble Sort: ");
    printArray(arr, n);
}
// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
    printf("Sorted array using Quick Sort: ");
    printArray(arr, high - low + 1);
}
// Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
    printf("Sorted array using Merge Sort: ");
    printArray(arr, r - l + 1);
}
// Selection Sort
void selectionSort(int arr[], int n) {
    int min_idx;
    for (int i = 0; i < n - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
    printf("Sorted array using Selection Sort: ");
    printArray(arr, n);
}
// Insertion Sort
void insertionSort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    printf("Sorted array using Insertion Sort: ");
    printArray(arr, n);
}
// Shell Sort
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    printf("Sorted array using Shell Sort: ");
    printArray(arr, n);
}
// Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
    printf("Sorted array using Heap Sort: ");
    printArray(arr, n);
}
// Radix Sort
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }
    return mx;
}
void countSort(int arr[], int n, int exp) {
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
    printf("Sorted array using Radix Sort: ");
    printArray(arr, n);
}
// Counting Sort
void countingSort(int arr[], int n) {
    int output[n];
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int count[max + 1];
    for (int i = 0; i < max + 1; ++i) {
        count[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        ++count[arr[i]];
    }
    for (int i = 1; i <= max; ++i) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
    printf("Sorted array using Counting Sort: ");
    printArray(arr, n);
}
// Cocktail Shaker Sort
void cocktailShakerSort(int arr[], int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    while (swapped) {
        swapped = false;

        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
    printf("Sorted array using Cocktail Shaker Sort: ");
    printArray(arr, n);
}
// Gnome Sort
void gnomeSort(int arr[], int n) {
    int index = 0;
    while (index < n) {
        if (index == 0) {
            index++;
        }
        if (arr[index] >= arr[index - 1]) {
            index++;
        } else {
            swap(&arr[index], &arr[index - 1]);
            index--;
        }
    }
    printf("Sorted array using Gnome Sort: ");
    printArray(arr, n);
}
// Comb Sort
void combSort(int arr[], int n) {
    double shrinkFactor = 1.3;
    int gap = n;
    bool swapped = true;
    while (gap > 1 || swapped) {
        if (gap > 1) {
            gap /= shrinkFactor;
        }
        swapped = false;
        for (int i = 0; i + gap < n; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(&arr[i], &arr[i + gap]);
                swapped = true;
            }
        }
    }
    printf("Sorted array using Comb Sort: ");
    printArray(arr, n);
}
// Pigeonhole Sort
void pigeonholeSort(int arr[], int n) {
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    int range = max - min + 1;
    int holes[range];
    for (int i = 0; i < range; i++) {
        holes[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        holes[arr[i] - min]++;
    }
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (holes[i] > 0) {
            arr[index] = i + min;
            index++;
            holes[i]--;
        }
    }
    printf("Sorted array using Pigeonhole Sort: ");
    printArray(arr, n);
}
// Stooge Sort
void stoogeSort(int arr[], int low, int high) {
    if (low >= high) return;
    if (arr[low] > arr[high]) {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
    }
    if (high - low + 1 > 2) {
        int t = (high - low + 1) / 3;
        stoogeSort(arr, low, high - t);
        stoogeSort(arr, low + t, high);
        stoogeSort(arr, low, high - t);
    }
    printf("Sorted array using Stooge Sort: ");
    printArray(arr, high - low + 1);
}
// Bitonic Sort
void bitonicMerge(int arr[], int low, int cnt, bool dir) {
    if (cnt > 1) {
        int k = cnt / 2;
        for (int i = low; i < low + k; i++) {
            if ((arr[i] > arr[i + k]) == dir) {
                int temp = arr[i];
                arr[i] = arr[i + k];
                arr[i + k] = temp;
            }
        }
        bitonicMerge(arr, low, k, dir);
        bitonicMerge(arr, low + k, k, dir);
    }
}
void bitonicSort(int arr[], int low, int cnt, bool dir) {
    if (cnt > 1) {
        int k = cnt / 2;
        bitonicSort(arr, low, k, true);
        bitonicSort(arr, low + k, k, false);
        bitonicMerge(arr, low, cnt, dir);
        printf("Sorted array using Bitonic Sort: ");
        printArray(arr, cnt);
    }
}
// Pancake Sort
int findMax(int arr[], int n) {
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[max]) max = i;
    }
    return max;
}
void flip(int arr[], int i) {
    int temp, start = 0;
    while (start < i) {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}
void pancakeSort(int arr[], int n) {
    for (int curr_size = n; curr_size > 1; curr_size--) {
        int max_idx = findMax(arr, curr_size);
        if (max_idx != curr_size - 1) {
            flip(arr, max_idx);
            flip(arr, curr_size - 1);
        }
    }
    printf("Sorted array using Pancake Sort: ");
    printArray(arr, n);
}
// Cycle Sort
void cycleSort(int arr[], int n) {
    int writes = 0;
    for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) {
        int item = arr[cycle_start];
        int pos = cycle_start;
        for (int i = cycle_start + 1; i < n; i++) {
            if (arr[i] < item) pos++;
        }
        if (pos == cycle_start) continue;
        while (item == arr[pos]) pos++;
        if (pos != cycle_start) {
            int temp = item;
            item = arr[pos];
            arr[pos] = temp;
            writes++;
        }
        while (pos != cycle_start) {
            pos = cycle_start;
            for (int i = cycle_start + 1; i < n; i++) {
                if (arr[i] < item) pos++;
            }
            while (item == arr[pos]) pos++;
            if (item != arr[pos]) {
                int temp = item;
                item = arr[pos];
                arr[pos] = temp;
                writes++;
            }
        }
    }
    printf("Sorted array using Cycle Sort: ");
    printArray(arr, n);
}
// Cocktail Sort
void cocktailSort(int arr[], int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    while (swapped) {
        swapped = false;
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
    printf("Sorted array using Cocktail Sort: ");
    printArray(arr, n);
}

int main() {
    int n;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Select sorting technique:\n");
    printf("1. Bubble Sort\n");
    printf("2. Quick Sort\n");
    printf("3. Merge Sort\n");
    printf("4. Selection Sort\n");
    printf("5. Insertion Sort\n");
    printf("6. Shell Sort\n");
    printf("7. Heap Sort\n");
    printf("8. Radix Sort\n");
    printf("9. Counting Sort\n");
    printf("10. Cocktail Shaker Sort\n");
    printf("11. Gnome Sort\n");
    printf("12. Comb Sort\n");
    printf("13. Pigeonhole Sort\n");
    printf("14. Stooge Sort\n");
    printf("15. Bitonic Sort\n");
    printf("16. Pancake Sort\n");
    printf("17. Cycle Sort\n");
    printf("18. Cocktail Sort\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Bubble Sort: It repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.\n\n");
            printf("Best case: O(n)\n");
            printf("Average case: O(n^2)\n");
            printf("Worst case: O(n^2)\n");
            printf("Space complexity: O(1)\n");
            bubbleSort(arr, n);
            break;
        case 2:
            printf("Quick Sort: It is a divide-and-conquer algorithm that works by selecting a pivot element and partitioning the array into two sub-arrays according to the pivot. It then recursively sorts the sub-arrays.\n\n");
            printf("Best case: O(n log n)\n");
            printf("Average case: O(n log n)\n");
            printf("Worst case: O(n^2)\n");
            printf("Space complexity: O(log n)\n");
            quickSort(arr, 0, n - 1);
            break;
        case 3:
            printf("Merge Sort: It is a divide-and-conquer algorithm that divides the input array into two halves, recursively sorts the halves, and then merges them into a single sorted array.\n\n");
            printf("Best case: O(n log n)\n");
            printf("Average case: O(n log n)\n");
            printf("Worst case: O(n log n)\n");
            printf("Space complexity: O(n)\n");
            mergeSort(arr, 0, n - 1);
            break;
        case 4:
            printf("Selection Sort: It works by repeatedly finding the minimum element from the unsorted portion of the array and swapping it with the element at the beginning of the unsorted portion.\n\n");
            printf("Best case: O(n^2)\n");
            printf("Average case: O(n^2)\n");
            printf("Worst case: O(n^2)\n");
            printf("Space complexity: O(1)\n");
            selectionSort(arr, n);
            break;
        case 5:
            printf("Insertion Sort: It builds the final sorted array one element at a time by repeatedly taking elements from the unsorted part and inserting them into their correct position in the sorted part.\n\n");
            printf("Best case: O(n)\n");
            printf("Average case: O(n^2)\n");
            printf("Worst case: O(n^2)\n");
            printf("Space complexity: O(1)\n");
            insertionSort(arr, n);
            break;
        case 6:
            printf("Shell Sort: It is an extension of Insertion Sort that allows the exchange of items that are far apart. It starts by sorting pairs of elements far apart from each other and then progressively reduces the gap between elements to be compared and exchanged.\n\n");
            printf("Best case: O(n log^2 n)\n");
            printf("Average case: O(n log^2 n)\n");
            printf("Worst case: O(n log^2 n)\n");
            printf("Space complexity: O(1)\n");
            shellSort(arr, n);
            break;
        case 7:
            printf("Heap Sort: It is based on the heap data structure. It first builds a heap from the input data, then repeatedly removes the maximum element from the heap and places it at the end of the sorted array.\n\n");
            printf("Best case: O(n log n)\n");
            printf("Average case: O(n log n)\n");
            printf("Worst case: O(n log n)\n");
            printf("Space complexity: O(1)\n");
            heapSort(arr, n);
            break;
        case 8:
            printf("Radix Sort: It is a non-comparative integer sorting algorithm that sorts data with integer keys by grouping keys by individual digits which share the same significant position and value.\n\n");
            printf("Best case: O(nk)\n");
            printf("Average case: O(nk)\n");
            printf("Worst case: O(nk)\n");
            printf("Space complexity: O(n + k)\n");
            radixSort(arr, n);
            break;
        case 9:
            printf("Counting Sort: It is an integer sorting algorithm that works by determining the number of occurrences of each unique element in the input array and using this information to place the elements in sorted order.\n\n");
            printf("Best case: O(n + k)\n");
            printf("Average case: O(n + k)\n");
            printf("Worst case: O(n + k)\n");
            printf("Space complexity: O(k)\n");
            countingSort(arr, n);
            break;
        case 10:
            printf("Cocktail Shaker Sort: It is a variation of Bubble Sort that sorts the array in both directions, starting from the beginning and the end. It continuously swaps adjacent elements if they are in the wrong order until the array is sorted.\n\n");
            printf("Best case: O(n)\n");
            printf("Average case: O(n^2)\n");
            printf("Worst case: O(n^2)\n");
            printf("Space complexity: O(1)\n");
            cocktailShakerSort(arr, n);
            break;
        case 11:
            printf("Gnome Sort: It works by moving elements one position forward if they are in the correct order, otherwise, it swaps them and moves one position backward.\n\n");
            printf("Best case: O(n^2)\n");
            printf("Average case: O(n^2)\n");
            printf("Worst case: O(n^2)\n");
            printf("Space complexity: O(1)\n");
            gnomeSort(arr, n);
            break;
        case 12:
            printf("Comb Sort: It is an improvement over Bubble Sort. It compares elements that are far apart and reduces the gap between them in each iteration until it becomes 1, similar to how a comb's teeth decrease in size from the top.\n\n");
            printf("Best case: O(n log n)\n");
            printf("Average case: O(n^2/2^p)\n");
            printf("Worst case: O(n^2)\n");
            printf("Space complexity: O(1)\n");
            combSort(arr, n);
            break;
        case 13:
            printf("Pigeonhole Sort: It is a sorting algorithm that is suitable for sorting lists of elements where the number of elements and the range of key values are approximately the same. It works by distributing elements into 'holes' or 'buckets' and then sorting them individually.\n\n");
            printf("Best case: O(n + range)\n");
            printf("Average case: O(n + range)\n");
            printf("Worst case: O(n + range)\n");
            printf("Space complexity: O(range)\n");
            pigeonholeSort(arr, n);
            break;
        case 14:
            printf("Stooge Sort: It is a recursive sorting algorithm that works by recursively sorting the first two-thirds and last two-thirds of the array, and then recursively sorting the first two-thirds again. It keeps repeating until the array is sorted.\n\n");
            printf("Best case: O(n log n)\n");
            printf("Average case: O(n log n)\n");
            printf("Worst case: O(n log n)\n");
            printf("Space complexity: O(log n)\n");
            stoogeSort(arr, 0, n - 1);
            break;
        case 15:
            printf("Bitonic Sort: It is a sorting algorithm designed for parallel processing. It works by recursively sorting sub-sequences of the input sequence in both increasing and decreasing order, and then merging them in a specific manner.\n\n");
            printf("Best case: O(n log^2 n)\n");
            printf("Average case: O(n log^2 n)\n");
            printf("Worst case: O(n log^2 n)\n");
            printf("Space complexity: O(log^2 n)\n");
            bitonicSort(arr, 0, n, true);
            break;
        case 16:
            printf("Pancake Sort: It is a sorting algorithm that works by repeatedly flipping the elements of the array until they are sorted. It finds the position of the maximum element, flips the array up to that position, and then flips the whole array.\n\n");
            printf("Best case: O(n)\n");
            printf("Average case: O(n^2)\n");
            printf("Worst case: O(n^2)\n");
            printf("Space complexity: O(1)\n");
            pancakeSort(arr, n);
            break;
        case 17:
            printf("Cycle Sort: It is an in-place, unstable sorting algorithm that minimizes the number of memory writes. It works by finding the correct position of each element and rotating the cycle to move the element to its correct position.\n\n");
            printf("Best case: O(n^2)\n");
            printf("Average case: O(n^2)\n");
            printf("Worst case: O(n^2)\n");
            printf("Space complexity: O(1)\n");
            cycleSort(arr, n);
            break;
        case 18:
            printf("Cocktail Sort: It is a variation of Bubble Sort that sorts the array in both directions, starting from the beginning and the end. It continuously swaps adjacent elements if they are in the wrong order until the array is sorted.\n\n");
            printf("Best case: O(n)\n");
            printf("Average case: O(n^2)\n");
            printf("Worst case: O(n^2)\n");
            printf("Space complexity: O(1)\n");
            cocktailSort(arr, n);
            break;
        default:
            printf("Invalid\n");
            break;
    }
    return 0;
}
