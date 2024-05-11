#include "mat.h"

using namespace lab;

int main()
{
    double data1[] = { 21, 34, 34.2, 123.2, 43.21, 54.01 };
    Mat mat1(data1, 2, 3), mat2(data1, 2, 2);
    mat1 * mat2;
    return 0;
}