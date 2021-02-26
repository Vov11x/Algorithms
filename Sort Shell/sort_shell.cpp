#include <iostream>


template<typename T>
void sort_shell(T *ptr, int size) {
    for (int d = size/2; d >= 1; d /= 2) {
        for (int i = d; i < size; ++i) {
            for (int j = i; j >= d && ptr[j-d] > ptr[j]; j -= d) {
                std::swap(ptr[j], ptr[j-d]);
            }
        }
    }
}

template<typename T>
void print(T *ptr, int size) {
    for (int i = 0; i < size; ++i) std::cout << *(ptr + i) << ' ';
    std::cout << '\n';
}
int main() {
    const int SIZE = 7;
    int arr[SIZE] = {6, 5, 4, 3, 2, 1, 0};
    char arr2[SIZE] = "bcadma";

    print(arr, SIZE);
    sort_shell(arr, SIZE);
    print(arr, SIZE);

    print(arr2, SIZE);
    sort_shell(arr2, SIZE);
    print(arr2, SIZE);
    return 0;
}
