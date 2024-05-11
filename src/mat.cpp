#include "mat.h"

#include <cstdlib>
#include <cstring>

#include "./info.hpp"

namespace lab {

Mat::Mat() {
    data = NULL;
    row = col = 0;
}

Mat::Mat(double *data, int row, int col) {
    this->data = new double[row * col];
    memcpy(this->data, data, row * col);
    this->row = row, this->col = col;
}

/**
 *  Mat1(2x3):                           Mat2(3x2):
 *          10  04  29                              20  32
 *          21  43  10                              81  91
 *                                                  11  12
*/
Mat operator*(const Mat& mat1, const Mat& mat2) {
    if (mat1.col!=mat2.row) {
        ERROR("Mat1 column not equal Mat2 row.\n");
        return Mat();
    }
    return Mat();
}
    
}