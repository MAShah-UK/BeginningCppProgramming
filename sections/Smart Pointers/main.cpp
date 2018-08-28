#include <iostream>
#include <memory>
#include <vector>

void check_unique_ptr(const std::unique_ptr<int> &ptr);

int main() {
    // Unique pointers own the resource and automatically free it when they fall out of scope.
    std::unique_ptr<int> p1 {new int {100}};
    std::cout << "Value of object p1 contains: " << *p1 << std::endl;
    *p1 = 200;
    std::cout << "Value of object p1 contains after assignment: " << *p1 << std::endl;

    std::cout << "The address of the pointer is: " << p1.get() << std::endl; // Returns raw pointer.

    std::cout << "Before release p1 status: ";
    check_unique_ptr(p1);
    p1.release(); // Releases the resource and sets the pointer to nullptr.
    std::cout << "After release p1 status: ";
    check_unique_ptr(p1);

    p1 = std::make_unique<int>(50); // Good practice, doesn't use new keyword.
    std::cout << "Value of object p1 after make_unique: " << *p1 << std::endl;

    std::unique_ptr<int> p2; // Initialised with nullptr.
    std::cout << "p1 status before move: ";
    check_unique_ptr(p1);
    std::cout << "p2 status before move: ";
    check_unique_ptr(p2);
    p2 = std::move(p1); // Unique pointers can only have one owner, hence moves only, no copies.
    std::cout << "p1 status after move: ";
    check_unique_ptr(p1);
    std::cout << "p2 status after move: ";
    check_unique_ptr(p2);

    std::vector<std::unique_ptr<int>> unique_ints {
//        std::make_unique<int>(50),    // TODO: Why does this cause an error?
//        std::make_unique<int>(100),
//        std::make_unique<int>(150),
//        std::make_unique<int>(200),
//        std::make_unique<int>(250)
    };
    unique_ints.push_back(std::make_unique<int>(50));
    unique_ints.push_back(std::make_unique<int>(100));
    unique_ints.push_back(std::make_unique<int>(150));
    unique_ints.push_back(std::make_unique<int>(200));
    unique_ints.push_back(std::make_unique<int>(250));
    std::cout << "Values of integers in vector: ";
    for(const auto &ptr: unique_ints) { // auto type: std::unique_ptr<int>
        std::cout << *ptr << " ";
    }
    std::cout << std::endl << std::endl;

    return 0; // Smart pointers don't need to be deleted explicitly like raw pointers to.
}

void check_unique_ptr(const std::unique_ptr<int> &ptr) {
    if(ptr) {
        std::cout << "Pointer is valid." << std::endl;
    } else {
        std::cout << "Pointer is invalid." << std::endl;
    }
}