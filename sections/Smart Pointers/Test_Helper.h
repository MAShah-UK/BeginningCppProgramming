#pragma once

#include <memory>
#include <vector>
#include "Test.h"

class Test_Helper {
public:
    static std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
    static void fill(std::vector<std::shared_ptr<Test>> &vec, int num);
    static void display(const std::vector<std::shared_ptr<Test>> &vec);
};