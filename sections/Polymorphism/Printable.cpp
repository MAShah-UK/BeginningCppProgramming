#include "Printable.h"

Printable::~Printable() {

}

std::ostream &operator<<(std::ostream &os, const Printable &rhs) {
    rhs.print(os);
    return os;
}
