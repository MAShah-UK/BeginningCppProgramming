#include "Printable.h"

std::ostream &operator<<(std::ostream &os, const Printable &rhs) {
    rhs.print(os);
    return os;
}
