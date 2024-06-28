// matrix.cpp
#include "../include/matrix.h"
#include <stdexcept>

Matrix::Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) {
  cells.resize(rows, std::vector<double>(cols, 0.0));
}

double& Matrix::operator()(size_t i, size_t j) {
  if (i >= rows || j >= cols) {
    throw std::out_of_range("Matrix indices out of range");
  }

  return cells[i][j];
}

const double& Matrix::operator()(size_t i, size_t j) const {
  if (i >= rows || j >= cols) {
    throw std::out_of_range("Matrix indices out of range");
  }

  return cells[i][j];
}

std::pair<size_t, size_t> Matrix::shape() const { return {rows, cols}; }

Matrix Matrix::operator+(const Matrix& other) const {
  if (rows != other.rows || cols != other.cols) {
    throw std::invalid_argument("Matrix dims not compatible");
  }
  Matrix result(rows, cols);
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      result(i, j) = data[i][j] + other(i, j);
    }
  }
  return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
  if (rows != other.rows || cols != other.cols) {
    throw std::invalid_argument("Matrix dims not compatible");
  }
  Matrix result(rows, cols);
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      result(i, j) = cells[i][j] - other(i, j);
    }
  }
  return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
  if (rows != other.rows || cols != other.cols) {
    throw std::invalid_argument("Matrix dims not compatible");
  }
  Matrix result(rows, other.cols);
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < other.cols; j++) {
      for (size_t k = 0; k < cols; k++) {
	result(i, j) += cells[i][j] * other(k, j);
      }
    }
  }
  return result;
}

bool Matrix::operator==(const Matrix &other) const {
  if (rows != other.rows || cols != other.cols) {
    return false;
  }
  
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      if (!fpEqual(cells[i][j], other(i, j))) {
	return false;
      }
    }
  }
  
  return true;
  
}

