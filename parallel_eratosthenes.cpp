#include <iostream>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <thread>
#include <mutex>

using namespace std;

void simple_erastosthenes(uint64_t n, int num_threads) {
    // declare array/bits
    
    // find primes until sqrt(n) using single thread
    // find primes from sqrt(n) to n using multiple threads
}

int main(int _argc, char* _argv[]) {
    if (_argc < 2) {
        cerr << "Usage: " << _argv[0] << " <n> [num_threads]" << endl;
        return 1;
    }
    uint64_t n = atol(_argv[1]);
    int num_threads = _argc > 2 ? atoi(_argv[2]) : thread::hardware_concurrency();

    cout << "Finding primes up to " << n << " using " << num_threads << " threads." << endl;

    simple_erastosthenes(n, num_threads);

    return 0;
}