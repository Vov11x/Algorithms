

template <typename T>
void bubbleSort(T *pArr, int size) {  // O(n^2) complexity
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (pArr[j] > pArr[j+1]) {
                std::swap(pArr[j], pArr[j+1]);
            }
        }
    }
}
