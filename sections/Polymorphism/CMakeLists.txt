cmake_minimum_required(VERSION 3.12)
project(Polymorphism)

set(CMAKE_CXX_STANDARD 14)



add_executable(Polymorphism main.cpp Account.cpp Account.h Savings_Account.cpp Savings_Account.h Account_Helper.cpp Account_Helper.h Checking_Account.cpp Checking_Account.h Trust_Account.cpp Trust_Account.h)