#pragma once

#include <exception>

class IllegalBalanceException : public std::exception {
public:
    const char *what() const noexcept;
};