#include <iostream>
#include <vector>
#include <algorithm> // Contains various STL algorithms.
#include <numeric>
#include <utility> // pair
#include <tuple>
#include <array>

void square(int x) {
    std::cout << x*x << " ";
}

class Main {
public:
    int main() {
        STL_algorithms();
        template_function();
        pair_and_tuple();
        STL_arrays();
        iterators();

        return 0;
    }

    void STL_algorithms() {
        std::cout << "BEGIN: STL_algorithms" << std::endl;

        std::vector<int> data {5, 1, 10, 3, 6, 4};
        std::cout << "Original vector: ";
        print(data); // T is deduced by the compiler as int.
        std::cout << std::endl;

        std::cout << "Sorted: ";
        std::sort(data.begin(), data.end());
        print(data);
        std::cout << std::endl;

        std::cout << "Reversed elements: ";
        std::reverse(data.begin(), data.end());
        print(data);
        std::cout << std::endl;

        std::cout << "Sum of elements: ";
        int sum {std::accumulate(data.begin(), data.end(), 0)};
        std::cout << sum << std::endl;

        std::cout << "Does element 10 exist? ";
        auto it = std::find(data.begin(), data.end(), 10); // Returns iterator pointing to first occurrence.
        std::cout << (it!=data.end() ? "Yes." : "No.") << std::endl;

        std::cout << "Each element squared is (functor): ";
        class Square { // A functor is a function object.
        public:
            void operator()(int x) {
                std::cout << x*x << " ";
            }
        } square_functor;
        std::for_each(data.begin(), data.end(), square_functor);
        std::cout << std::endl;

        std::cout << "Each element squared is (function pointer): ";
        std::for_each(data.begin(), data.end(), square);
        std::cout << std::endl;

        std::cout << "Each element squared is (lambda): ";
        std::for_each(data.begin(), data.end(),
                [](int x) { std::cout << x*x << " "; });
        std::cout << std::endl;

        std::cout << "Does the data only consist of even numbers? "
                  << (std::all_of(data.begin(), data.end(), [](int x) { return x%2 == 0; })
                    ? "Yes." : "No.")
                  << std::endl;

        std::cout << "The count of even numbers is: "
                  << std::count_if(data.begin(), data.end(), [](int x) { return x%2 == 0; })
                  << std::endl;

        std::cout << "Replacing 10 with 100: ";
        std::replace(data.begin(), data.end(), 10, 100);
        print(data);
        std::cout << std::endl;

        std::cout << "Replacing each element with its square: ";
        std::transform(data.begin(), data.end(), data.begin(), [](int x) { return x*x; });
        print(data);
        std::cout << std::endl;
    }
    void template_function() {
        std::cout << "\nBEGIN: template_function" << std::endl;

        int int_a = 5, int_b = 10;
        // Specifying the type in the angle brackets tells the compiler to generate an
        // int version of max at compile time.
        std::cout << "The higher integer is: " << max<int>(int_a, int_b) << std::endl;

        double double_a = 5.5, double_b = 5.06;
        // Not specifying the type to be generated is valid if the compiler can
        // deduce the type of the T by looking at the arguments provided.
        std::cout << "The higher double is: " << max<>(double_a, double_b) << std::endl;

        char char_a = 'A', char_b = 'B';
        // Providing empty brackets is optional, you can omit them.
        std::cout << "The higher char is: " << max(char_a, char_b) << std::endl;

        class Custom {
            int data;
        public:
            Custom(int data) : data {data} {}
            bool operator>(const Custom &rhs) {
                return data > rhs.data;
            }
            int get_data() const {
                return data;
            }
        } custom_a {5}, custom_b {10};
        // Generic programming even works with custom classes,
        // as long the the semantics are valid, e.g. > must be defined in this case.
        std::cout << "The higher custom data type is: " << max(custom_a, custom_b).get_data() << std::endl;
    }
    void pair_and_tuple() {
        std::cout << "\nBEGIN: pair_and_tuple" << std::endl;

        // Used to associate two pieces of data - any type.
        std::pair<std::string, int> student1 {"Josh", 20}, student2 {std::make_pair("Jason", 25)};
        std::cout << "Student 1 [name] " << student1.first << " [age] " << student1.second << std::endl;
        std::cout << "Student 2 [name] " << student2.first << " [age] " << student2.second << std::endl;

        // Type aliases allow reusing type declarations.
        using student = std::tuple<std::string, int, char>;
        // Used to associate n pieces of data - any type.
        student student3 {"Miraz", 24, 'A'};
        student student4 {std::make_tuple("Monty", 23, 'B')};
        std::cout << "Student 3 [name] " << std::get<0>(student3) << " [age] " << std::get<1>(student3)
                  << " [grade] " << std::get<2>(student3) << std::endl;
        std::cout << "Student 4 [name] " << std::get<0>(student4) << " [age] " << std::get<1>(student4)
                  << " [grade] " << std::get<2>(student4) << std::endl;
    }
    void STL_arrays() {
        std::cout << "\nBEGIN: STL_arrays" << std::endl;

        std::array<int, 5> data {};
        std::cout << "Initialised array: ";
        print(data); // T is int, N is 5.
        std::cout << std::endl;

        std::cout << "Filled array: ";
        data.fill(10);
        print(data);
        std::cout << std::endl;

        std::cout << "Array size: " << data.size() << std::endl;
    }
    void iterators() {
        std::cout << "\nBEGIN: iterators" << std::endl;

        std::vector<int> data {1, 2, 3, 4, 5};

        std::cout << "Source vector: ";
        // It's common to use auto type deduction rather than fully qualifying the type.
        // begin() returns the first element. end() returns one passed the last element.
        // Incrementing an iterator moves it to the next element in the sequence.
        for(std::vector<int>::iterator it {data.begin()}; it != data.end(); ++it) {
            // This is how a range-based for loop works.
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::cout << "Middle elements: ";
        for(auto it {data.begin()+1}; it != data.end()-1; ++it) {
            // This is how a range-based for loop works.
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::cout << "Vector in reverse: ";
        for(std::vector<int>::reverse_iterator it {data.rbegin()}; it != data.rend(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    template <typename T> // This template function can accept any vector argument.
    void print(const std::vector<T> &data) {
        for(const T &i : data) {
            std::cout << i << " ";
        }
    }
    template <typename T, size_t N> // Integer being passed at compile time.
    void print(const std::array<T, N> &data) {
        for(const T &i : data) {
            std::cout << i << " ";
        }
    }
    template <typename T>
    T max(T a, T b) {
        return (a > b) ? a : b;
    }
};

int main() {
    return Main().main();
}