#ifndef _EKF_INFO_HPP_
#define _EKF_INFO_HPP_

#include <stdio.h>

#define _EKF_MAX_ERROR_INFO_ 2048

template<typename ...Args>
void print(const char *format, Args... args);

#endif