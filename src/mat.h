#ifndef _EKF_MAT_H_
#define _EKF_MAT_H_

#include <cstddef>

namespace lab {

class Mat 
{
public:
    Mat();
    Mat(double *data, int row, int col);
    Mat(const Mat& mat);

    friend Mat operator*(const Mat& mat1, const Mat& mat2);
private:
    double *data;
    size_t row, col;
};

}


#endif