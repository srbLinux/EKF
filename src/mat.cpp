#include "mat.h"

#include <cstdlib>
#include <cstring>

#include "./info.hpp"

#define NIL INT32_MAX

namespace lab {

Mat::Mat() {
    data = nullptr;
    rows = cols = 0;
}

Mat::Mat(const Mat& mat) {
    if (data) {
        rows = mat.rows;
        cols = mat.cols;
        data = (double *)realloc(data, sizeof(double)*mat.cols*mat.rows);
        memcpy(data, mat.data, sizeof(double)*mat.cols*mat.rows);
    } else {
        data = nullptr;
        rows = cols = 0; 
    }
}

Mat::Mat(size_t row, size_t col) {
    this->data = new double[row * col];
    this->rows = row, this->cols = col;
    memset(this->data, 0, row * col * sizeof(double));
}

Mat::Mat(double *data, size_t row, size_t col) {
    this->data = new double[row * col];
    memcpy(this->data, data, row * col * sizeof(double));
    this->rows = row, this->cols = col;
}

Mat::~Mat() {
    delete []data;
    data = nullptr;
    rows = cols = 0;
}

bool Mat::empty() {
    return (data==nullptr);
}

double Mat::at(size_t row, size_t col) const {
    // std::cout << row << " " << col << std::endl;
    return data[this->cols*(row)+col];
}

void Mat::insert(size_t row, size_t col, double data) {
    this->data[this->cols*(row)+col] = data;
}

Mat Mat::row(size_t i) {
    double *jmp_data = new double[this->cols];
    
}


Mat operator*(const Mat& mat1, const Mat& mat2) {
    if (mat1.cols!=mat2.rows) {
        // ERROR("Mat1 column not equal Mat2 row.\n");
        return Mat();
    }
    double temp;
    Mat resMat(mat1.rows, mat2.cols);
    for (size_t i=0;i<mat1.rows;i++) {
        for (size_t j=0;j<mat2.cols;j++) {
            temp = 0;
            for (size_t k=0;k<mat1.cols;k++) {
                temp += mat1.at(i, k) * mat2.at(k, j);
            }
            resMat.insert(i, j, temp);
        }
    }
    std::cout << "operator *\n";
    return resMat;
}

std::ostream& operator<<(std::ostream& out, const Mat& mat) {
    std::cout << "operator<< " << mat.cols << " " << mat.rows << std::endl;
    for (size_t i = 0; i < mat.rows;i ++ ) {
        for (size_t j = 0;j < mat.cols;j ++ ) {
            out << mat.at(i, j) << ";"; 
        }
        out << "\n";
    }
    return out;
}
    
}