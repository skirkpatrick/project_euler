#include<stdio.h>
#include<stdbool.h>

/* forward declarations */
long long int largest_prime_factor(long long int);
bool is_prime(long long int);


/* function definitions */

int main() {
    long long int num = 600851475143LL;
    printf("%lld\n", largest_prime_factor(num));

    return 0;
}


// Return the largest prime factor of a number.
// The algorithm is based on the following information:
// 1) We check for divisors one-by-one starting from two
// 2) Every time we find a divisor, we actually find two: the next lowest one and the next highest one
// 3) If the higher divisor is a prime, we know right away it is the largest prime
// 3) If the higher divisor is not a prime, we know that we only have to check for divisors up to that number
//          (because we've found all divisors beyond that point).
//
// Algorithm:
// max = num
// n = 2
// largest_prime = 1 <- no prime factors
// From n to max:
//   if num % n == 0:
//     if num / n is prime: return num / n
//     else if n is prime: largest_prime = n
//     max = num / n
// return largest_prime
long long int largest_prime_factor(long long int num) {
    long long int max = num;
    long long int largest_prime = 1LL;
    for (long long int n = 2LL; n < max; ++n) {
        if (num % n == 0LL) {
            long long int result = num / n;
            if (is_prime(result)) {
                return result;
            } else if (is_prime(n)) {
                largest_prime = n;
            }
            max = result;
        }
    }
    return largest_prime;
}


// Naive check prime function
bool is_prime(long long int n) {
    for (long long int i = 2LL; i*i <= n; ++i) {
        if (n % i == 0LL) return false;
    }
    return true;
}
