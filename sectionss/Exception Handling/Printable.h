#pragma once

#include <iostream>

// Printable is an interface since it only contains pure virtual functions.
class Printable {
    friend std::ostream &operator<<(std::ostream &os, const Printable &rhs); // Not needed.
public:
    static constexpr char POUND_SYMBOL = 156;

    // Tells compiler to use default destructor.
    virtual ~Printable() = default;

    virtual void print(std::ostream &os) const = 0;
};