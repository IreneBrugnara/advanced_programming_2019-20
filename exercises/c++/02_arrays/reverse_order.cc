#include <iostream>

template <typename T>
T* create_array(std::size_t n) {            // allocates an array of size n in the heap and initialize its elements
  T* myarr {new T[n]};
  for(std::size_t i{0}; i<n; i++) {
    std::cout << "insert element " << i << ": ";
    std::cin >> myarr[i];
  }
  return myarr;         // return the address of first element
}
template <typename T>
void print_reverse(T* myarr, std::size_t n) {
  for(long long int i{n-1}; i>=0; i--)           // here I do not use unsigned int (std::size_t), because the counter goes below zero before exiting from the cycle!
    std::cout << "element " << i << " is : " << myarr[i] << std::endl;
}

int main() {
  std::size_t n;
  std::cout << "Size of array: ";
  std::cin >> n;
  auto *myarr = create_array<float>(n);
  std::cout << "Now I print in reverse order\n";
  print_reverse<float>(myarr, n);
  delete[] myarr;
  return 0;
}
