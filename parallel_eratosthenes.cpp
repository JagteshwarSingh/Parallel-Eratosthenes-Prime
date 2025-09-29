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

            std::cout << "currnum: " << curr_num << ", index: " << wordArrayIndex << ", mask: " << mask << ", isPrime: " << isPrime << std::endl;
            //printf("currnum: %ld, index: %ld, mask: %ld, isprime: %i\n", curr_num, wordArrayIndex, mask);
            

            return isPrime;
        }

        void setnclear_word(uint64_t i){

            const uint64_t wordArrayIndex = i / 128;
            const uint64_t wordBitPosition = (i % 128) >> 1;
            const uint64_t mask = 1LL << wordBitPosition;
            
            wordArray[wordArrayIndex] |= mask;

            return;
        }   

        uint64_t bitwise_eratosthenes(uint64_t size) {
		
            uint64_t count = 1; // 2 is a special case
                
            uint64_t lim = sqrt(size);
            for (uint64_t i = 3; i <= lim; i += 2){
                if (is_prime(i)) { //isprime(3)
                    count++;    //count = 2
                    printf("count: %ld\n", count);
                    
                    for (uint64_t j = i * i; j <= size; j += 2 * i){
                        setnclear_word(j);
                        printf("j: %ld\n", j);
                    }
                }
            }

            for (uint64_t i = (lim + 1) | 1; i <= size; i += 2)
                if (is_prime(i)){
                    count++;
                    printf("i: %ld, count: %ld\n", i, count);
                }
            return count;
        }
              
};



void simple_erastosthenes(uint64_t start, uint64_t end) {
    
}

//uint64_t bitwise_eratosthenes();

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
    for (uint64_t i = 0; i < primes.numWords; i++){
        primes.wordArray[i] = 0;
    }

    uint64_t be_count = primes.bitwise_eratosthenes(n);
   
    printf("becount: %ld\n", be_count);



    return 0;
}






