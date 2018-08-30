#include "InsufficientFundsException.h"

const char* InsufficientFundsException::what() const noexcept {
    return "The account doesn't have enough enough funds for this transaction.";
}