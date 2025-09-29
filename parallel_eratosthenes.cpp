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
    
        bool is_prime(uint64_t curr_num){

            const uint64_t wordArrayIndex = curr_num / 128;
            const uint64_t  wordBitPosition = (curr_num % 128) >> 1;
            const uint64_t mask = 1LL << wordBitPosition;

            const bool isPrime = (wordArray[wordArrayIndex] & mask) == 0;

            //std::cout << "currnum: " << curr_num << ", index: " << wordArrayIndex << ", mask: " << mask << ", isPrime: " << isPrime << std::endl;
            

            return isPrime;
        }

        void set_word(uint64_t i){

            const uint64_t wordArrayIndex = i / 128;
            const uint64_t wordBitPosition = (i % 128) >> 1;
            const uint64_t mask = 1LL << wordBitPosition;
            
            wordArray[wordArrayIndex] |= mask;

            return;
        }   

        uint64_t bitwise_eratosthenes(uint64_t lim, uint64_t size) {
		
            uint64_t count = 1; // 2 is a special case
                
            //uint64_t lim = sqrt(size);
            for (uint64_t i = 3; i <= lim; i += 2){
                if (is_prime(i)) { //isprime(3)
                    count++;    //count = 2
                    //printf("count: %ld\n", count);
                    
                    for (uint64_t j = i * i; j <= size; j += 2 * i){
                        set_word(j);
                        //printf("j: %ld\n", j);
                    }
                }
            }

            return count;
        }

        uint64_t count_primes(uint64_t start, uint64_t end, uint64_t count){

            for (uint64_t i = (start + 1) | 1; i <= end; i += 2)
                if (is_prime(i)){
                    count++;
                    //printf("i: %ld, count: %ld\n", i, count);
                }

            return count;
        }

        uint64_t serial_eratosthenes(uint size){

            uint64_t count;
            uint64_t lim = sqrt(size);
            count = bitwise_eratosthenes(lim, size);
            count = count_primes(lim, size, count);


            return count;
        }

        uint64_t multithreaded_eratosthenes(uint64_t numThreads){

            uint64_t count;
            uint64_t serialEnd = sqrt(n);
            count = serial_eratosthenes(serialEnd);

            std::thread* threads = new std::thread[numThreads];

            for (int t = 0; t < numThreads; t++){
                threads[t] = std::thread();

            }

            for (int t = 0; t < numThreads; t++){
                threads[t].join();
            }

            delete threads;
            return count;
        }


              
};




int main(int _argc, char* _argv[]) {
    if (_argc < 2) {
        cerr << "Usage: " << _argv[0] << " <n> [numThreads]" << endl;
        return 1;
    }
    uint64_t n = atol(_argv[1]);
    int numThreads = _argc > 2 ? atoi(_argv[2]) : thread::hardware_concurrency();

    cout << "Finding primes up to " << n << " using " << numThreads << " threads." << endl;

    //simple_erastosthenes(n, num_threads);


    word primes;
    

    primes.n = n;
    primes.numWords = (n / 64) + 1;

    primes.wordArray = new uint64_t[primes.numWords];
    for (uint64_t i = 0; i < primes.numWords; i++){
        primes.wordArray[i] = 0;
    }

    uint64_t count;

    if (numThreads == 0){
        printf("number of threads mus be at least 1\n");
    }
    else if (numThreads == 1){
        count = primes.serial_eratosthenes(n);
    }
    else {
        count = primes.multithreaded_eratosthenes(numThreads);
    }

    delete(primes.wordArray);
    
   
    printf("count: %ld\n", count);



    return 0;
}






