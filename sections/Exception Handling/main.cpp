#include <iostream>

// Java style entry point.
class Main {
    // Inner classes for convenience. They describe two common exceptions.
    class DivideByZeroException {};
    class NegativeValueException {};
public:
    int main() {
        throwing_exception();
        propagating_exception();
        multi_catch_statements();

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

