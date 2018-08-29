#include <iostream>
#include <memory>
#include <vector>
#include "Test.h"
#include "Test_Helper.h"

void check_unique_ptr(const std::unique_ptr<int> &ptr);

int main() {
    // Unique pointers own the resource and automatically free it when they fall out of scope.
    std::unique_ptr<int> up1 {new int {100}};
    std::cout << "Value of object up1 contains: " << *up1 << std::endl;
    *up1 = 200;
    std::cout << "Value of object up1 contains after assignment: " << *up1 << std::endl;
    std::cout << "The address of the pointer is: " << up1.get() << std::endl; // Returns raw pointer.

    std::cout << "Before release up1 status: ";
    check_unique_ptr(up1);
    up1.release(); // Releases the resource and sets the pointer to nullptr.
    std::cout << "After release up1 status: ";
    check_unique_ptr(up1);

    up1 = std::make_unique<int>(50); // Good practice, doesn't use new keyword.
    std::cout << "Value of object up1 after make_unique: " << *up1 << std::endl;

    std::unique_ptr<int> up2; // Initialised with nullptr.
    std::cout << "up1 status before move: ";
    check_unique_ptr(up1);
    std::cout << "up2 status before move: ";
    check_unique_ptr(up2);
    up2 = std::move(up1); // Unique pointers can only have one owner, hence moves only, no copies.
    std::cout << "up1 status after move: ";
    check_unique_ptr(up1);
    std::cout << "up2 status after move: ";
    check_unique_ptr(up2);

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

    // Shared pointers share the resource. Once all of the pointers fall out of scope, then the resource is freed.
    std::shared_ptr<int> sp1 {new int {100}};
    std::cout << "Value of object sp1 contains: " << *sp1 << std::endl;
    *sp1 = 200;
    std::cout << "Value of object sp1 contains after assignment: " << *sp1 << std::endl;
    std::cout << "The address of the pointer is: " << sp1.get() << std::endl;

    std::shared_ptr<int> sp2;
    std::cout << "Use count of sp1 before copy: " << sp1.use_count() << std::endl;
    std::cout << "Use count of sp2 before copy: " << sp2.use_count() << std::endl;
    sp2 = sp1;
    std::cout << "Use count of sp1 after copy: " << sp1.use_count() << std::endl; // Should be the same as...
    std::cout << "Use count of sp2 after copy: " << sp2.use_count() << std::endl; // ... this.
    std::shared_ptr<int> sp3 {std::move(sp2)}; // Sets sp2 to nullptr and moves resource.
    std::cout << "Use count of sp1 after move: " << sp1.use_count() << std::endl; // Unaffected.
    std::cout << "Use count of sp2 after move: " << sp2.use_count() << std::endl; // 0 because sp2 was moved/reset.
    std::cout << "Use count of sp3 after move: " << sp3.use_count() << std::endl;
    std::cout << std::endl;

    // Challenge.
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = Test_Helper::make();
    std::cout << "How many data points do you want to enter? ";
    int num;
    std::cin >> num;
    Test_Helper::fill(*vec_ptr, num);
    Test_Helper::display(*vec_ptr);

    return 0; // Smart pointers don't need to be deleted explicitly unlike raw pointers.
}

void check_unique_ptr(const std::unique_ptr<int> &ptr) {
    if(ptr) {
        std::cout << "Pointer is valid." << std::endl;
    } else {
        std::cout << "Pointer is invalid." << std::endl;
    }
}

/*
Quiz 1: When the reference count of a managed object reaches ________,
the destructor for the managed object is invoked.
zero

Quiz 2: Weak pointers do not share ________ of the managed object.
ownership

Quiz 3: What does the acronym RAII stand for?
Resource Acquisition Is Initialisation.

Quiz 4: Smart pointers can help prevent which of the following?
All of the above:
- Memory leaks.
- Uninitialised/wild pointers.
- Dangling pointers.

Quiz 5: Unique pointers can only be ________.
moved

Quiz 6: The use_count() method returns the ________.
the pointer's reference count

Quiz 7: Suppose we have a Node in a double-linked list defined as follows with
raw pointers. What smart pointer should we use in place of the raw pointers?
class Node {
   int data;
   Node *next;
   Node *prev;
};

a shared_ptr and a weak_ptr

Quiz 8: We can provide smart pointers with custom ________
functions that will be called upon manage object destruction.
deleter

Quiz 9: The get() method for smart pointers returns ________.
the raw pointer being managed

Quiz 10: When you declare a smart pointer object,
that object is placed on the ________.
stack
 */