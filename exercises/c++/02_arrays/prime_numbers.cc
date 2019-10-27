#include <iostream>

int main() {
  const unsigned int dim{100};
  unsigned int primes[dim-2];       // I allocate a big array in the stack that will not be fully popolated
  unsigned int p{0};
  for(unsigned int i{2}; i<dim; i++) {      // loop over the candidate prime numbers i
    unsigned int j;
    for(j=2; j<i; j++)        // loop over the divisors of i, called j
      if(i%j == 0)
        break;
    if(i%j != 0 || i==j) {        // If the number is prime...
      primes[p]=i;                // ... put it in the array
      std::cout << primes[p] << "  ";
      p++;
    }
  }
  return 0;
}
