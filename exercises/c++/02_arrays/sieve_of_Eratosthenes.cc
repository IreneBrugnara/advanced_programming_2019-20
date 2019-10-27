#include <iostream>

int main() {
  unsigned int N;
  std::cout << "Prime numbers up to? ";
  std::cin >> N;
  unsigned int *sieve {new unsigned int [N-1]};       // allocate in the heap because N is known at runtime
  for(unsigned int i{2}; i<=N; i++)
    sieve[i-2] = i;

  for(unsigned int i{2}; i<=N; i++) {
    //std::cout << "i = " << i << "\n";
    if(sieve[i-2]==0)
      continue;
    std::cout << i << "  ";
    for(unsigned int j=i*2; j<=N; j+=i)      // I cross out all the multiples of i
      sieve[j-2] = 0;           // I decide that a number is "crossed out" if it is equal to 0
}

  return 0;
}
