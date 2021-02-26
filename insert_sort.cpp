#include <iostream>

template<typename T>
void insert_sort(T *ptr, int size) {
    for (int i = 1; i < size; ++i) {
        int k = i;
        while (k > 0 && ptr[k-1] > ptr[k]) {
            std::swap(ptr[k-1], ptr[k]);
            k--;
        }
    }
}

template<typename T>
void print(T *ptr, int size) {
    for (int i = 0; i < size; ++i) std::cout << *(ptr + i) << ' ';
    std::cout << '\n';
}

int main() {
    // tests
    const int SIZE = 7;
    int arr[SIZE] = {6, 5, 4, 3, 2, 1, 0};
    char arr2[SIZE] = "bcadma";

    print(arr, SIZE);
    insert_sort(arr, SIZE);
    print(arr, SIZE);

    print(arr2, SIZE);
    insert_sort(arr2, SIZE);
    print(arr2, SIZE);
    return 0;
}
