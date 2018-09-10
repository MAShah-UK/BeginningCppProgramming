#pragma once

#include <exception>

class InsufficientFundsException : public std::exception {
public:
    const char *what() const noexcept;
};