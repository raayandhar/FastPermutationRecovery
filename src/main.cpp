// main.cpp
#include "../include/matrix.h"
#include <iostream>

void printMatrix(const Matrix& m) {
  
  size_t rows = m.shape().first;
  size_t cols = m.shape().second;
 
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      std::cout << m(i, j) << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

int main() {
  Matrix A(3, 3);

  A(0, 0) = 1; A(0, 1) = 0; A(0, 2) = 0;
  A(1, 0) = 0; A(1, 1) = 2; A(1, 2) = 0;
  A(2, 0) = 0; A(2, 1) = 0; A(2, 2) = 3;

  printMatrix(A);

  Matrix B(3, 3);

  B(0, 0) = 1; B(0, 1) = 0; B(0, 2) = 0;
  B(1, 0) = 0; B(1, 1) = 2; B(1, 2) = 0;
  B(2, 0) = 0; B(2, 1) = 0; B(2, 2) = 3;

  printMatrix(B);

  Matrix mult = A*B;

  printMatrix(mult);

  Matrix sub = A-B;

  printMatrix(sub);

  bool eq = A == B;

  std::cout << eq << std::endl;
  
  std::cout << "Matrix operations working successfully" << std::endl;
  
  return 0;
}
