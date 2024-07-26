#include<math.h>
class Solution {
public:
    int countPrimes(int n) {
    if (n <= 2) return 0; // If n is 2 or less, there are no primes less than n

    vector<int> seive(n, 1); // Initialize sieve with 1 (true) indicating potential primes
    seive[0] = seive[1] = 0; // 0 and 1 are not primes

    int sq = sqrt(n); // Compute the square root of n
    for (int i = 2; i <= sq; i++) {
        if (seive[i]) { // If i is a prime
            for (int j = i * i; j < n; j += i) { // Start marking multiples from i^2
                seive[j] = 0; // Mark j as non-prime
            }
        }
    }

    int cnt = 0;
    for (int i = 2; i < n; i++) {
        if (seive[i]) {
            cnt++;
        }
    }
    return cnt;
}
};