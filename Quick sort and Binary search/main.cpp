#include <iostream>



//
//   - Quick sort;
//   - Binary search;
//



void setArray(int *pArray, int arrSize);
void printArray(int *pArray, int arrSize);
void quickSort(int *pArray, int minIndex, int maxIndex);
void binSearch(const int *pArray, int arrSize, int n);

int main() {
    const int SIZE = 10;
    int array[SIZE];  // array initializing

    setArray(array, SIZE);
    std::cout << "Beginning array:\t";
    printArray(array, SIZE);

    quickSort(array, 0, SIZE - 1);
    std::cout << "Sorted array:\t\t";
    printArray(array, SIZE);

    binSearch(array, SIZE, 77);

    return 0;
}


void setArray(int *pArray, int arrSize) {
    for(size_t i = 0; i < arrSize; i++)
        pArray[i] = rand() % 100;
}

void printArray(int *pArray, int arrSize) {
    for (size_t i = 0; i < arrSize; i++)
        std::cout << pArray[i] << " ";
    std::cout << std::endl;

}

void quickSort(int *pArray, int minIndex, int maxIndex) {
    int i = minIndex, j = maxIndex;
    int mid = pArray[(minIndex + maxIndex) / 2];

    do {
        while (pArray[i] < mid && i < maxIndex) i++;
        while (pArray[j] > mid && j > minIndex) j--;

        if (i <= j) {
            std::swap(pArray[i], pArray[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (minIndex < j) quickSort(pArray, minIndex, j);
    if (maxIndex > i) quickSort(pArray, i, maxIndex);
}

void binSearch(const int *pArray, int arrSize, int n) {
    int low = 0;
    int high = arrSize - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (n == pArray[mid]) {
            std::cout << "Value " << n << " is at index:\t" << mid << std::endl;
            return;
        }
        else if (n > pArray[mid]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }

    }
    return;
}
