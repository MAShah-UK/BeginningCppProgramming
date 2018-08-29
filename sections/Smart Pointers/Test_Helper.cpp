#include "Test_Helper.h"

std::unique_ptr<std::vector<std::shared_ptr<Test>>> Test_Helper::make() {
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void Test_Helper::fill(std::vector<std::shared_ptr<Test>> &vec, int num) {
    for(int i {0}; i < num; ++i) {
        std::cout << "\tEnter data point " << i+1 << "/" << num << ": ";
        int data;
        std::cin >> data;
        vec.push_back(std::make_shared<Test>(data));
    }
}

void Test_Helper::display(const std::vector<std::shared_ptr<Test>> &vec) {
    std::cout << "The following data was entered: " << std::endl;
    int i {1};
    for(const std::shared_ptr<Test> &ptr: vec) {
        std::cout << "\t" << i << "/" << vec.size() << ") "
                  << ptr->get_data() << std::endl;
        ++i;
    }
}