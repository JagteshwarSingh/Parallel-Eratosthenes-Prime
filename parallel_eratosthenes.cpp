#include <iostream>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <thread>
#include <mutex>

using namespace std;

class word{
    public:
        uint64_t* wordArray;
        uint64_t numWords;
        uint64_t n;
    
              
};

void simple_erastosthenes(uint64_t start, uint64_t end); {
    // declare array/bits
    
    // find primes until sqrt(n) using single thread
    // find primes from sqrt(n) to n using multiple threads
}

void simple_multithreaded_eratosthenese(){
    



    return;
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


    /*
     * Use the following area for parallel and bitwise   
     */

    word primes;
    
    primes.n = n;
    primes.numWords = (n / 64) + 1;
    primes.wordArray = new uint64_t(primes.numWords);

    
    



    return 0;
}