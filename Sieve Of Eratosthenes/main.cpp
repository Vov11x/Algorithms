#include <iostream>



void findPrime(int n);
int main() {
    int maxNumber;
    
    std::cout << '>';
    std::cin >> maxNumber;  // n > 1 only

    findPrime(maxNumber);

    return 0;
}


void findPrime(int n) {
    bool sieve[n+1];
    for (int i = 0; i < n + 1; ++i) {
        sieve[i] = true;
    }

    int start = 2;
    while (start*start <= n) {
        if (sieve[start]) {
            for (int y = start*start; y <= n; y += start) {
                sieve[y] = false; // composite numbers
            }
        }
        start += 1;
    }

    for (int i = 0; i < n + 1; ++i) {
        if (sieve[i]) {
            std::cout << i << ' ';
        }
    }
    std::cout << '\n';
}
