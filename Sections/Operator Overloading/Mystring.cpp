#include <iostream>
#include <string>
#include "Mystring.h"

Mystring::Mystring() {

}

Mystring::Mystring(const Mystring &source)
    : length {source.length} {
    str = new char[length];
    for (size_t i {}; i < length; i++) {
        str[i] = source.str[i];
    }
}

Mystring::Mystring(Mystring &&source)
    : str {source.str}, length {source.length}{
    source.str = nullptr;
}

Mystring::Mystring(const char *s) {
    if(s == nullptr) {
        str = nullptr;
    } else {
        for(; s[length] != '\0'; ++length);
        str = new char[length];
        for(size_t i {}; i < length; ++i) {
            str[i] = s[i];
        }
    }
}

Mystring::Mystring(char *s, size_t length)
    : str {s}, length {length} {

}

Mystring::~Mystring() {
    delete [] str;
}

Mystring &Mystring::operator=(const Mystring &rhs) {
    if(this == &rhs) { // If this and rhs are the same object then save time by returning early.
        return *this;
    }

    delete [] str;
    length = rhs.length;
    str = new char[length];
    for (size_t i {}; i < length; i++) {
        str[i] = rhs.str[i];
    }

    return *this;
}

Mystring &Mystring::operator=(Mystring &&rhs) {
    if(this == &rhs) {
        return *this;
    }

    length = rhs.length;

    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;

    return *this;
}

Mystring &Mystring::operator+=(const Mystring &rhs) {
    *this + rhs;
    return *this;
}

Mystring Mystring::operator-() const {
    char *new_str = new char[length];
    for(size_t i {}; i < length; ++i) {
        new_str[i] = tolower(str[i]);
    }
    return {new_str, length};
}

Mystring Mystring::operator+(const Mystring &rhs) const {
    size_t new_length = length + rhs.length;
    char *new_str = new char[new_length];
    for(size_t i {}; i < length; ++i) {
        new_str[i] = str[i];
    }
    for(size_t i {}; i < rhs.length; ++i) {
        new_str[length+i] = rhs.str[i];
    }
    return {new_str, new_length};
}

Mystring Mystring::operator*(int n) const {
    size_t new_length = length * n;
    char *new_str = new char[new_length];
    for(size_t i {}; i < new_length; ++i) {
        new_str[i] = str[i%length];
    }
    return {new_str, new_length};
}

//bool Mystring::operator==(const Mystring &rhs) const {
//    if(this == &rhs) {
//        return true;
//    }
//    if(length != rhs.length) {
//        return false;
//    }
//    for(size_t i {}; i < length; ++i) {
//        if(str[i] != rhs.str[i]) {
//            return false;
//        }
//    }
//    return true;
//}

int Mystring::get_length() const {
    return length;
}

const char *Mystring::get_str() const {
    return str;
}

void Mystring::display() const {
    for (size_t i {}; i < length; i++) {
        std::cout << str[i];
    }
}

// Parameter count must match the number of operands == expects, i.e. 2 since there's no this pointer for lhs.
bool operator==(const Mystring &lhs, const Mystring &rhs) { // Non-member operator overload function declaration.
    if(&lhs == &rhs) {
        return true;
    }
    if(lhs.length != rhs.length) {
        return false;
    }
    for(size_t i {}; i < lhs.length; ++i) {
        if(lhs.str[i] != rhs.str[i]) {
            return false;
        }
    }
    return true;
}

bool operator!=(const Mystring &lhs, const Mystring &rhs) {
    return !(lhs==rhs);
}

bool operator<(const Mystring &lhs, const Mystring &rhs) {
    std::string lhs_str = lhs.str;
    std::string rhs_str = rhs.str;
    return lhs_str < rhs_str;
}

bool operator>(const Mystring &lhs, const Mystring &rhs) {
    std::string lhs_str = lhs.str;
    std::string rhs_str = rhs.str;
    return lhs_str > rhs_str;
}

// Allows Mystring to work with output stream, i.e. cout.
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.get_str(); // Not friends so must use getter.
    return os; // Allows chaining multiple << operations.
}

// Allows Mystring to work with instream stream, i.e. cin.
std::istream &operator>>(std::istream &is, Mystring &obj) {
    char *buffer = new char[1000];
    is >> buffer;
    obj += buffer; // obj = obj + Mystring {buffer}, obj += Mystring {buffer}, obj += buffer;
    delete [] buffer;
    return is;
}