cmake_minimum_required(VERSION 3.12)
project(Exception_Handling)

set(CMAKE_CXX_STANDARD 14)

add_executable(Exception_Handling main.cpp Account.cpp Printable.cpp IllegalBalanceException.cpp IllegalBalanceException.h InsufficientFundsException.cpp InsufficientFundsException.h)