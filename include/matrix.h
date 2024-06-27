/*
 * Matrix.h 
 */

#pragma once
#include <cstddef>
#include <vector>
#include <utility>
#include <cmath>

class Matrix {
private:
  std::vector<std::vector<double>> data;
  size_t rows;
  size_t cols;

public:
  Matrix(size_t rows, size_t cols);

  // Access
  double& operator()(size_t i, size_t j);
  const double& operator()(size_t i, size_t j) const;

  // like .shape() from numpy
  std::pair<size_t, size_t> shape() const;

  // to get shape() to work we need getters
  size_t numRows() const { return rows; }
  size_t numCols() const { return cols; }

  // essentials 
  Matrix operator+(const Matrix& other) const; 
  Matrix operator-(const Matrix& other) const;
  Matrix operator*(const Matrix& other) const;
  bool operator==(const Matrix& other) const;

  // help with floating point precision
  static bool fpEqual(double a, double b, double eps=1e-9) {
    return std::abs(a - b) < eps;
  }
};
