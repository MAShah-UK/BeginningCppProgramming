#pragma once

class Mystring {
    // Can stick to using getters and setters for more encapsulation.
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);
    friend bool operator!=(const Mystring &lhs, const Mystring &rhs);
    friend bool operator<(const Mystring &lhs, const Mystring &rhs);
    friend bool operator>(const Mystring &lhs, const Mystring &rhs);

    char *str {nullptr};
    size_t length {};
public:
    Mystring();
    Mystring(const Mystring &source);
    Mystring(Mystring &&source);
    Mystring(const char *s);
    Mystring(char *s, size_t length);
    ~Mystring();

    Mystring &operator=(const Mystring &rhs);
    Mystring &operator=(Mystring &&rhs);
    Mystring &operator+=(const Mystring &rhs);
    Mystring operator-() const;
    Mystring operator+(const Mystring &rhs) const;
    Mystring operator*(int n) const;
    // bool operator==(const Mystring & rhs) const; // Member operator overload method.

    int get_length() const;
    const char *get_str() const;

    void display() const;
};

// TODO: Why do these need to be declared, but == and != do not?
std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
std::istream &operator>>(std::istream &is, Mystring &obj);