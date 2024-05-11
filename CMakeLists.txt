cmake_minimum_required(VERSION 3.5)

project(EKF)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(EKF ${SOURCES})