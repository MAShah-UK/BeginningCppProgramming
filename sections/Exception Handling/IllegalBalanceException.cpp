#include "IllegalBalanceException.h"

const char *IllegalBalanceException::what() const noexcept {
    return "The balance balance cannot be negative.";
}