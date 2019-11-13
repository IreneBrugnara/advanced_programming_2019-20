#include <iostream>
#include <array>

// computes the transpose B of a matrix A with dimensions (nrows, ncols)
template<typename T, size_t N>
void transpose(std::array<T,N> A, std::array<T,N> &B, std::size_t nrow, std::size_t ncol) {
  for(std::size_t i{0}; i<nrow; ++i)
    for(std::size_t j{0}; j<ncol; ++j)
      B[j*nrow+i] = A[i*ncol+j];
}


// prints the elements of an std::array representing a matrix of dimensions (nrows, ncols)
template<typename T, size_t N>
void print_matrix(std::array<T,N> mat, std::size_t nrow, std::size_t ncol) {
  for(std::size_t i{0}; i<nrow; ++i) {
    for(std::size_t j{0}; j<ncol; ++j)
      std::cout << mat[i*ncol+j] << "\t";
    std::cout << "\n";
  }

}

int main() {
  const std::size_t nrow=2, ncol=4;
  const std::size_t N = nrow * ncol;
  std::array<double,N> mat{1,2,3,4,5,6,7,8};
  print_matrix(mat, nrow, ncol);
  std::array<double,N> trasp{};
  transpose(mat, trasp, nrow, ncol);
  std::cout << "After transposition:\n";
  print_matrix(trasp, ncol, nrow);
  return 0;
}
