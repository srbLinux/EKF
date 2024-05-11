#ifndef _EKF_INFO_HPP_
#define _EKF_INFO_HPP_

#include <stdio.h>

#define _EKF_MAX_ERROR_INFO_ 2048

#define ERROR(str) \
    do { \
        char *__error_format_str__ = new char[_EKF_MAX_ERROR_INFO_]; \
        sprintf(__error_format_str__, "%s - %s: %s", __FILE__, __func__, str); \
        fprintf(stderr, __error_format_str__); \
    } while (0)

#endif