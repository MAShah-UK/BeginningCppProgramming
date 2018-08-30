#include <iostream>
#include "Account.h"

// Java style entry point.
class Main {
    // Inner classes for convenience. They describe two common exceptions.
    class DivideByZeroException : public std::exception {
    public:
        const char *what() const noexcept override { // noexcept tells the compiler that no exceptions will be thrown.
            return "Division by zero was attempted.";
        }
    };
    class NegativeValueException : public std::exception {
    public:
        const char *what() const noexcept override { // noexcept tells the compiler that no exceptions will be thrown.
            return "Argument was negative.";
        }
    };
public:
    int main() {
        throwing_exception();
        propagating_exception();
        multi_catch_statements();
        subclassing_std_exception();
        account_challenge();

        return 0;
    }
    void throwing_exception() {
        std::cout << "BEGIN: throwing_exception" << std::endl;

        std::cout << "100 / 0 = " << std::endl;
        double miles {100};
        double gallons {};
        try {
            if(gallons == 0) {
                throw 0; // Throwing exception using primitive type. Bad practice, should use objects.
            }
            // Following code skipped if exception is thrown.
            std::cout << miles/gallons << std::endl;
        } catch (int ex) { // Exception handler / catch statement deals with the exception.
            std::cerr << "Exception: Dividing by zero is undefined." << std::endl; // Outputs to standard error stream.
        }
    }
    void propagating_exception() {
        std::cout << "\nBEGIN: propagating_exception" << std::endl;

        try {
            std::cout << "100 / 10 = " << calculate_mpg(100, 10) << std::endl;
            std::cout << "100 / -5  = " << calculate_mpg(100, -5) << std::endl;
        } catch(const std::string &ex) { // Will be called if either calculate_mpg call throws an integer.
            std::cerr << std::endl << ex << std::endl;
        }
    }
    void multi_catch_statements() {
        std::cout << "\nBEGIN: multi_catch_statements" << std::endl;

        try {
            std::cout << "100 / 10 = " << calculate_mpg2(100, 10) << std::endl;     // Fine.
            std::cout << "100 / -5  = " << calculate_mpg2(100, -5) << std::endl;    // Throws NegativeValueException.
            std::cout << "100 / -5  = " << calculate_mpg2(100, 0) << std::endl;     // Throws DivideByZeroException.
            std::cout << "100 / -5  = " << calculate_mpg(100, 0) << std::endl;     // Throws std::string.
        } catch(const NegativeValueException &ex) {
            std::cerr << "Exception: Arguments cannot be negative." << std::endl;
        } catch(const DivideByZeroException &ex) {
            std::cerr << "Exception: Dividing by zero is undefined." << std::endl;
        } catch(...) {  // Catch-all statement can be used for 'other' exceptions.
            std::cerr << "Exception: Unknown..." << std::endl;
        }
    }
    void subclassing_std_exception() {
        std::cout << "\nBEGIN: subclassing_std_exception" << std::endl;

        try {
            std::cout << "100 / 10 = " << calculate_mpg2(100, 10) << std::endl;     // Fine.
            std::cout << "100 / -5  = " << calculate_mpg2(100, 0) << std::endl;     // Throws DivideByZeroException.
            std::cout << "100 / -5  = " << calculate_mpg2(100, -5) << std::endl;    // Throws NegativeValueException.
        } catch(const std::exception &ex) {
            std::cerr << "Exception: " << ex.what() << std::endl;
        }
    }
    void account_challenge() {
        std::cout << "\nBEGIN: account_challenge" << std::endl;

        try {
            Account john_doe {"John Doe", 1000.00};
            std::cout << "John's balance before withdrawing £500: " << john_doe << std::endl;
            john_doe.withdraw(500);
            std::cout << "John's balance after withdrawing £500: " << john_doe << std::endl;

            Account jane_doe {"Jane Doe", 250.00};
            std::cout << "Jane's balance before withdrawing £500: " << jane_doe << std::endl;
            jane_doe.withdraw(500); // throws InsufficientFundsException.
            std::cout << "Jane's balance after withdrawing £500: " << jane_doe << std::endl;
        } catch(std::exception &ex) {
            std::cerr << "Exception: " << ex.what() << std::endl;
        }
    }

    double calculate_mpg(double miles, double gallons) {
        if(gallons == 0) {
            throw std::string {"Exception: Dividing by zero is undefined."};
        }
        if(miles < 0 || gallons < 0) {
            throw std::string {"Exception: Arguments cannot be negative."};
        }
        return miles/gallons;
    }
    double calculate_mpg2(double miles, double gallons) {
        if(gallons == 0) {
            throw DivideByZeroException();
        }
        if(miles < 0 || gallons < 0) {
            throw NegativeValueException();
        }
        return miles/gallons;
    }
};

int main() {
    return Main().main();
}

/*
Quiz 1: What happens in C++ if an exception is thrown but not caught?
The program terminates.

Quiz 2: The C++ catch-all exception handler is written as ________.
catch(...)

Quiz 3: Code that could potentially throw an exception
should be written in the ________ block.
try

Quiz 4: An exception is thrown using the ________ keyword?
throw

Quiz 5: The C++ Standard Library defines a rich set of
exception classes that are derived from ________.
std::exception

Quiz 6: The virtual function what() is first defined in ________.
std::exception

Quiz 7: What is the output from the following program?
#include <iostream>
using namespace std;
int main()
{
   try {
       throw 'X';
   } catch (const int &ex) {
      cout << "Integer exception" << endl;
   } catch (...) {
      cout << "Any exception" << endl;
   }
   cout << "Goodbye" << endl;
   return 0;
}

Any exception
Goodbye

Quiz 8: What is the output from the following program?

#include <iostream>
void func_a();
void func_b();
void func_c();
void func_a() {
    std::cout << "Starting func_a" << std::endl;
    func_b();
    throw 3000;
    std::cout << "Ending func_a" << std::endl;
}
void func_b() {
    std::cout << "Starting func_b" << std::endl;
    func_c();
    throw 2000;
    std::cout << "Ending func_b" << std::endl;
}
void func_c()  {
    std::cout << "Starting func_c" << std::endl;
    throw 1000;
    std::cout << "Ending func_c" << std::endl;
}
int main() {
    try {
        func_a();
    } catch(int &ex) {
        std::cerr << "Caught error thrown: " << ex << std::endl;
    }
    std::cout << "Continuing in main" << std::endl;
    return 0;
}

Starting func_a
Starting func_b
Starting func_c
Caught error thrown: 1000
Continuing in main

Quiz 9: What is wrong with the following code?
#include <iostream>
#include <exception>
// this function only knows how to double values
// that are less than 5000
int double_it(int val) {
   if (val >= 5000)
      throw std::exception();
   return val * 2;
}
int main() {
   try {
      int *values = new int[10000];
      for (int i=0; i < 10000; ++i)
         values[i] = double_it(i); // double_it may throw a std::exception
      delete [] values;
   } catch (const std::exception &ex) {
      std::cerr << "Don't know how to double numbers > 5000" << std::endl;
   }
   std::cout << "Program complete" << std::endl;
   return 0;
}

Memory leak since the allocated memory is never deallocated.

Quiz 10: Which of the following is true about user-defined exception classes.
They can be regular C++ classes.
*/
