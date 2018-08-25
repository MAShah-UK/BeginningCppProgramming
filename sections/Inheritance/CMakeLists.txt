cmake_minimum_required(VERSION 3.12)
project(Inheritance)

set(CMAKE_CXX_STANDARD 14)

add_executable(Inheritance main.cpp Account.cpp Account.h Savings_Account.cpp Savings_Account.h)