#ifndef _EKF_VECTOR_HPP_
#define _EKF_VECTOR_HPP_

#include <cstddef>

#include "info.hpp"

namespace lab {

/**
 * @brief 这是一个静态数组，不能动态更改数组大小
*/
template<typename _Ty>
class vector
{
public:
    vector(size_t element_size);
    vector(size_t element_size, _Ty ele_data);
    vector(const vector& vec);
    ~vector();
    _Ty& operator[](size_t i);
    void push_back(_Ty data);
    _Ty pop_back();
private:
    _Ty *data;
    int size, cap;
};

template<typename _Ty>
vector<_Ty>::vector(size_t element_size) {
    size = 0;
    cap = element_size;
    data = new _Ty[element_size];
}

template<typename _Ty>
vector<_Ty>::vector(size_t element_size, _Ty ele_data) {
    cap = size = element_size; 
    data = new _Ty[element_size];
    for (size_t i = 0;i < element_size;i ++ ) {
        data[i] = ele_data;
    }
}

template<typename _Ty>
vector<_Ty>::vector(const vector<_Ty>& vec) {
    cap = vec->cap;
    data = vec->data;
    size = vec->size;
}

template<typename _Ty>
vector<_Ty>::~vector() {
    delete []data;
}

template<typename _Ty>
_Ty& vector<_Ty>::operator[](size_t i) {
    return data[i];
}

}

#endif