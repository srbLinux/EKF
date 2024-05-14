#ifndef _EKF_MAT_H_
#define _EKF_MAT_H_

#include <cstddef>
#include <iostream>

namespace lab {

class Mat 
{
public:
    Mat();
    Mat(size_t row, size_t col);
    Mat(double *data, size_t row, size_t col);
    Mat(const Mat& mat);
    ~Mat();

    void resize(size_t row, size_t col);

    Mat row(size_t i);
    Mat col(size_t j);

    bool empty();
    void print();
    Mat operator[](int i);
    double at(size_t row, size_t col) const;
    void insert(size_t row, size_t col, double data);


    friend Mat operator*(const Mat& mat1, const Mat& mat2);

    friend std::ostream& operator<<(std::ostream& out, const Mat& mat);
private:
    double *data;
    size_t rows, cols;
};

}


#endif