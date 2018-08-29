#pragma once

#include <iostream>

class Test {
    int data;
public:
    Test(int data = 0);
    ~Test();

    int get_data() const;
};