// Miller Rabin prime test,
// Source: https://rosettacode.org/wiki/Miller%E2%80%93Rabin_primality_test#Deterministic_up_to_341.2C550.2C071.2C728.2C321

#include <stdint.h>

uint64_t power(uint64_t a, uint64_t n, uint64_t mod){
	uint64_t power = a;
	uint64_t result = 1;
 
	while (n){
		if (n & 1) result = (result * power) % mod;
		power = (power * power) % mod;
		n >>= 1;
	}
	return result;
}
 
int witness(uint64_t n, uint64_t s, uint64_t d, uint64_t a){
	uint64_t x = power(a, d, n);
	uint64_t y;
 
	while (s) {
		y = (x * x) % n;
		if (y == 1 && x != 1 && x != n-1) return 0;
		x = y;
		--s;
	}
	if (y != 1) return 0;
	return 1;
}
 
int is_prime_mr(uint64_t n){
	if (((!(n & 1)) && n != 2 ) || (n < 2) || (n % 3 == 0 && n != 3)) return 0;
	if (n <= 3) return 1;
 
	uint64_t d = n / 2;
	uint64_t s = 1;
	while (!(d & 1)) {
		d /= 2;
		++s;
	}
 
	if (n < 1373653)
		return witness(n, s, d, 2) && witness(n, s, d, 3);
	if (n < 9080191)
		return witness(n, s, d, 31) && witness(n, s, d, 73);
	if (n < 4759123141)
		return witness(n, s, d, 2) && witness(n, s, d, 7) && witness(n, s, d, 61);
	if (n < 1122004669633)
		return witness(n, s, d, 2) && witness(n, s, d, 13) && witness(n, s, d, 23) && witness(n, s, d, 1662803);
	if (n < 2152302898747)
		return witness(n, s, d, 2) && witness(n, s, d, 3) && witness(n, s, d, 5) && witness(n, s, d, 7) && witness(n, s, d, 11);
	if (n < 3474749660383)
		return witness(n, s, d, 2) && witness(n, s, d, 3) && witness(n, s, d, 5) && witness(n, s, d, 7) && witness(n, s, d, 11) && witness(n, s, d, 13);
	return witness(n, s, d, 2) && witness(n, s, d, 3) && witness(n, s, d, 5) && witness(n, s, d, 7) && witness(n, s, d, 11) && witness(n, s, d, 13) && witness(n, s, d, 17);
}

int isprime(uint64_t in){
	return is_prime_mr((uint64_t)in);
}
