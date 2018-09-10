#include <iostream>
#include <vector>
#include <algorithm> // Contains various STL algorithms.
#include <numeric>
#include <utility> // pair
#include <tuple>
#include <array>
#include <deque>
#include <regex>
#include <list>
#include <forward_list>
#include <exception>
#include <set>
#include <unordered_set>
#include <fstream>
#include <iomanip>
#include <queue>

void square(int x) {
    std::cout << x*x << " ";
}

class Main {
public:
    int main() {
        algorithms();
        template_function();
        pair_and_tuple();
        STL_arrays();
        iterators();
        deques();
        challenge_deque_palindrome();
        lists();
        challenge_playlist();
        sets();
        maps();
        challenge_unique_words();
        stacks();
        queues();
        challenge_sq_palindrome();
        priority_queues();

        return 0;
    }

    void algorithms() {
        std::cout << "BEGIN: algorithms" << std::endl;

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

        std::cout << "Reassigned array: ";
        data = {1, 2, 3, 4, 5};
        print(data);
        std::cout << std::endl;

        std::cout << "First element: " << data.front() << std::endl;

        std::cout << "Last element: " << data.back() << std::endl;
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
    void deques() {
        std::cout << "\nBEGIN: deques" << std::endl;

        // Double ended queue: O(1) insert/delete from front/back.
        std::deque<int> data {1, 2, 3, 4, 5};

        std::cout << "Initial data: ";
        print(data);
        std::cout << std::endl;

        std::cout << "Add new first and new last elements: ";
        data.push_front(0);
        data.push_back(6);
        print(data);
        std::cout << std::endl;

        std::cout << "Remove first and last elements: ";
        data.pop_front();
        data.pop_back();
        print(data);
        std::cout << std::endl;
    }
    void challenge_deque_palindrome() {
        std::cout << "\nBEGIN: challenge_deque_palindrome" << std::endl;

        std::string input {"A Santa at Nasa."};
        std::cout << "The input is: " << input << std::endl;

        // Process input and remove ignored characters.
        std::transform(input.begin(), input.end(), input.begin(), toupper);
        auto erase_begin = std::remove_if(input.begin(), input.end(),
                [](char c) { return !(c >= 'A' && c <= 'Z'); });
        input.erase(erase_begin, input.end());
        // Use deques to confirm if processed input is a palindrome.
        std::deque<char> chars;
        std::move(input.begin(), input.end(), std::back_inserter(chars));
        input.erase();
        const size_t max = chars.size()/2;
        for(size_t i {}; i < max; ++i) {
            if(chars.front() == chars.back()) {
                chars.pop_front();
                chars.pop_back();
            } else {
                break;
            }
        }
        bool is_valid = (chars.size() <= 1);

        std::cout << "Is the input a palindrome? " << (is_valid ? "Yes." : "No.") << std::endl;
    }
    void lists() {
        std::cout << "\nBEGIN: lists" << std::endl;

        // Double linked list: insert/remove O(1), traverse O(n).
        std::list<int> data {1, 5, 9};
        std::list<int>::iterator it = std::find(data.begin(), data.end(), 5);
        data.insert(it, 3); // 1,3,5,9
        std::advance(it, 2); // Same as ++it; ++it;
        data.insert(it, 7); // 1,3,5,7,9
        data.erase(std::find(data.begin(), data.end(), 9)); // 1,3,5,7
        data.resize(2);     // 1,3
        data.resize(3);     // 1,3,0
        data.push_front(0); // 0,1,3,0
        data.pop_back();    // 0,1,3
        data.pop_back();    // 0,1
        data.push_back(2);  // 0,1,2
        std::cout << "list contents: ";
        print(data);
        std::cout << std::endl;

        // Singly linked list: Like list, but not bi-directional and no size()/back() methods.
        std::forward_list<int> data2 {1, 5, 9};
        auto it2 = data2.begin();
        data2.insert_after(it2, 3); // 1,3,5,9
        std::advance(it2, 2);
        data2.insert_after(it2, 7); // 1,3,5,7,9
        std::cout << "forward_list contents: ";
        print(data2);
        std::cout << std::endl;
    }
    void challenge_playlist() {
        std::cout << "\nBEGIN: challenge_playlist" << std::endl;

        class Playlist {
            class EmptyPlaylistException : public std::exception {
                const char *what() const noexcept override {
                    return "The playlist is empty.";
                }
            };

            std::list<std::string> playlist;
            std::list<std::string>::iterator it = playlist.end();

            void is_valid_request() {
                if(is_empty()) {
                    throw EmptyPlaylistException();
                }
            }
            void play() {
                std::cout << "Playing: " << *it << std::endl;
            }
        public:
            bool is_empty() {
                return (playlist.size() == 0);
            }

            void play_first() {
                is_valid_request();
                it = playlist.begin();
                play();
            }
            void play_next() {
                is_valid_request();
                if(it == playlist.end() ||
                   it == std::prev(playlist.end())) {
                    it = playlist.begin();
                } else {
                    ++it;
                }
                play();
            }
            void play_previous() {
                is_valid_request();
                if(it == playlist.begin()) {
                    it = std::prev(playlist.end());
                } else {
                    --it;
                }
                play();
            }
            void add_play(std::string name) {
                if(name.empty()) {
                    throw std::invalid_argument("name argument was empty.");
                }
                playlist.insert(it, name);
                --it;
                play();
            }
            void list_playlist() {
                is_valid_request();
                size_t i {1};
                for(std::string name : playlist) {
                    std::cout << '\t' << i << ") " << name << std::endl;
                    ++i;
                }
            }
        } playlist;
        class Menu {
            Playlist playlist;

            void print_help() {
                std::cout << "F - Play first song." << std::endl
                          << "N - Play next song." << std::endl
                          << "P - Play previous song." << std::endl
                          << "A - Add and play a new song." << std::endl
                          << "L - List of songs." << std::endl
                          << "Q - Quit.";
            }

            void add_play() {
                std::cout << "Enter the name of the song you wish to add: ";
                std::string name;
                std::cin >> name;
                playlist.add_play(name);
            }
        public:
            void loop() {
                char input {};
                while(input != 'Q') {
                    std::cout << "[Playlist Manager]" << std::endl;
                    print_help();
                    std::cout << std::endl << std::endl
                              << "Enter choice: ";
                    std::cin >> input;
                    input = static_cast<char>(toupper(input));
                    switch(input) {
                        case 'F': playlist.play_first(); break;
                        case 'N': playlist.play_next(); break;
                        case 'P': playlist.play_previous(); break;
                        case 'A': add_play(); break;
                        case 'L': playlist.list_playlist(); break;
                        case 'Q': std::cout << "Goodbye." << std::endl; break;
                        default:  std::cout << "Invalid input. Please try again." << std::endl;
                    }
                    std::cout << std::endl;
                }
            }
        } menu;
        menu.loop();
    }
    void sets() {
        std::cout << "\nBEGIN: sets" << std::endl;

        // A set ignores duplicate data.
        // Insertions/deletions/find operations are constant time.
        // Ordered by key.
        std::set<int> s {1,2,1,2,3,4,3}; // 1,2,3,4
        s.insert(0); // 0,1,2,3,4
        s.insert(5); // 0,1,2,3,4,5
        s.insert(5); // 0,1,2,3,4,5
        auto it = s.find(5);
        s.erase(it);  // 0,1,2,3,4
        std::cout << "Set contains: ";
        print(s); // 0,1,2,3,4
        std::cout << std::endl
                  << "Set size is: " << s.size() << std::endl
                  << "How many 1s are there? " << s.count(1) << std::endl
                  << "How many 5s are there? " << s.count(5) << std::endl;
        s.clear();
        std::cout << "Is the set empty? " << (s.empty() ? "Yes." : "No.") << std::endl << std::endl;

        // A multiset allows duplicate data, otherwise it's the same as set.
        std::multiset<int> ms {1,2,1,2,3,3,4}; // 1,2,3,4
        std::cout << "Multiset contains: ";
        print(ms);
        std::cout << std::endl
                  << "Multiset size is: " << ms.size() << std::endl
                  << "How many 1s are there? " << ms.count(1) << std::endl;

        // An unordered set is unordered, otherwise it's the same as set.
        // Elements cannot be modified, they must be erased and a new element must be inserted.
        // No reverse iterators are allowed.
        std::unordered_set<int> us {1,3,2,2}; // 1,3,2
        std::cout << "Unordered set contains: ";
        print(us); // 1,3,2
        std::cout << std::endl;

        // An unordered multiset is unordered and allows duplicates, otherwise it's the same as set.
        // No reverse iterators allowed.
        std::unordered_multiset<int> ums {1,3,2,2}; // 1,3,2,2
        std::cout << "Unordered multiset contains: ";
        print(ums);
        std::cout << std::endl;
    }
    void maps() {
        std::cout << "\nBEGIN: maps" << std::endl;

        std::map<std::string, int> name_age = {
                {"Alan", 20},
                {std::string("Bob"), int(20)}, // Inefficient, requires a move.
                std::make_pair("Carla", 25) // Inefficient, requires a move.
        };
        name_age.insert(std::make_pair("David", 30));
        name_age.insert({"Emily", 22});
        name_age.at("Carla") = 26; // Overwrites, but will throw exception if key doesn't exist.
        name_age["David"] = 29;    // Overwrites, but will insert if key doesn't exist.
        name_age.erase("Emily");   // Removes.
        name_age["Emily"] = 22;    // Inserts since it doesn't exist in the map.
        std::cout << "Contents of map: ";
        for(const std::pair<std::string, int> pair : name_age) {
            std::cout << pair.first << " -> " << pair.second << ". ";
        }
        std::cout << std::endl
                  << "Does Emily exist? " << (name_age.count("Emily") > 0 ? "Yes." : "No.")
                  << std::endl;
    }
    void challenge_unique_words() {
        std::cout << "\nBEGIN: challenge_unique_words" << std::endl;

        std::ifstream source {"../words.txt"};
        if(!source.is_open()) {
            throw std::invalid_argument("File not found");
        }
        std::map<std::string, std::set<int>> words;
        size_t max_length {};
        int line_number {};
        while(!source.eof()) {
            std::string line;
            getline(source, line);
            ++line_number;
            std::stringstream line_stream {line};
            while(line.size()>0 && !line_stream.eof()) {
                std::string word;
                line_stream >> word;
                word.erase(std::remove_if(word.begin(), word.end(),
                        [](char c) { return !isalpha(c); }),
                        word.end());
                std::transform(word.begin(), word.end(), word.begin(),
                        [](char c) { return tolower(c); });
                word.at(0) = static_cast<char>( toupper(word.at(0)) );
                words[word].insert(line_number);
                max_length = std::max(max_length, word.size());
            }
        }
        std::cout << "The unique words and their frequencies are: " << std::endl;
        for(auto pair : words) {
            std::string line_numbers {"[ "};
            for(int line_no : pair.second) {
                line_numbers.append(std::to_string(line_no)).append(" ");
            }
            line_numbers.append("]");
            std::cout << '\t' << std::left << std::setw(max_length) << pair.first << " "
                      << pair.second.size() << ": "
                      << line_numbers << std::endl;
        }
    }
    void stacks() {
        std::cout << "\nBEGIN: stacks" << std::endl;

        // Stack operations occur at the end of the stack - the top.
        // It's a LIFO data structure.
        // It's a container adapter. It can adapt a deque, vector, or list.
        std::stack<int> data {std::deque<int>{1,2,3,4,5}}; // Front... back.
        // std::stack<int, std::deque<int>>... equivalent.
        // std::stack<int, std::vector<int>>... uses vector.
        // std::stack<int, std::list<int>>... uses list.
        std::cout << "Size of stack: " << data.size() << std::endl
                  << "Top element: " << data.top() << std::endl; // Doesn't remove element.
        data.push(6); // Pushes to the back!
        std::cout << "Top element after push: " << data.top() << std::endl;
        data.pop();   // Pops from the back!
        std::cout << "Top element after pop: " << data.top() << std::endl;
        std::cout << "Is stack empty? " << (data.empty() ? "Yes." : "No.") << std::endl;
        std::cout << "The stack contains: ";
        while(!data.empty()) {
            std::cout << data.top() << " ";
            data.pop();
        }
        std::cout << std::endl
                  << "Is stack empty? " << (data.empty() ? "Yes." : "No.") << std::endl;
    }
    void queues() {
        std::cout << "\nBEGIN: queues" << std::endl;

        // Queue data is pushed from the back and popped from the front.
        // It's a FIFO structure.
        // It's a container adapter. It can adapt a deque or a list.
        std::queue<int> data {std::deque<int>{1,2,3,4,5}}; // Front... back.
        //std::queue<int, std::deque<int>>... equivalent.
        //std::queue<int, std::list<int>>... uses list.
        std::cout << "Queue size is: " << data.size() << std::endl
                  << "The front element is: " << data.front() << std::endl // Doesn't remove element.
                  << "The back element is: " << data.back() << std::endl;  // Doesn't remove element.
        data.push(6); // Pushes to the back!  // 1,2,3,4,5,6
        std::cout << "After pushing the back element is: " << data.back() << std::endl;
        data.pop();   // Pops from the front! // 2,3,4,5,6
        std::cout << "After popping the front element is: " << data.front() << std::endl
                  << "The queue contains: ";
        while(!data.empty()) {
            std::cout << data.front() << " ";
            data.pop();
        }
        std::cout << std::endl
                  << "Is the queue empty? " << (data.empty() ? "Yes." : "No.") << std::endl;
    }
    void challenge_sq_palindrome() {
        std::cout << "\nBEGIN: challenge_sq_palindrome" << std::endl;

        std::string input {"A Santa at Nasa."};
        std::cout << "The input is: " << input << std::endl;
        std::transform(input.begin(), input.end(), input.begin(), toupper);
        auto erase_begin = std::remove_if(input.begin(), input.end(),
                                          [](char c) { return !isalpha(c); });
        input.erase(erase_begin, input.end());
        // Use stack and a queue to determine if the input is a palindrome.
        std::stack<char> stack;
        std::queue<char> queue;
        for(char c : input) {
            stack.push(c);
            queue.push(c);
        }
        while(!stack.empty()) {
            if(stack.top() == queue.front()) {
                stack.pop();
                queue.pop();
            } else {
                break;
            }
        }
        std::cout << "Is the input a palindrome? " << (stack.empty() ? "Yes." : "No.") << std::endl;
    }
    void priority_queues() {
        std::cout << "\nBEGIN: priority_queues" << std::endl;

        std::priority_queue<int> data;
        for(int i : {9,1,3,5,4,1}) { // 1,1,3,4,5,9
            data.push(i);
        }
        std::cout << "The priority queue contains: ";
        while(!data.empty()) {
            std::cout << data.top() << " "; // 9,5,4,3,1,1
            data.pop();
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
    void print(const T &data) { // Will work with any container.
        for(const auto &item: data) {
            std::cout << item << " ";
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

/*
Quiz 1: Three of the main components of the STL are:
Containers, iterators, and algorithms.

Quiz 2: Three types of containers in the STL are ________________
sequence, associative, and adapter containers.

Quiz 3: Which of the following are container adapters?
Stack, queue, and priority queue.

Quiz 4: In order to use and compare user-defined Classes
in the STL, the following operators must be overloaded:
operator== and operator<.

Quiz 5: We should use _______________ to obtain an
iterator to the first element in a container.
begin()

Quiz 6: The ____________ container should be considered if we expect
to insert many elements into the middle of the container.
list

Quiz 7: The ____________ container should be considered if
we want to store unique key/value pairs sorted by key.
map

Quiz 8: Some STL container classes provide the same function that is provided
by in the algorithms library. For example, the list container provides a
sort function as does the algorithms library? Why is this so?
The function in the algorithms library is generic, while the function in
the container class is optimised for that container type.

Quiz 9: The STL algorithms use iterators and in many cases allow
the programmer to provide specific behavior by using ____________.
All of the above:
- Functors (function objects).
- Lambda expressions.
- Function pointers.

Quiz 10: The ____________ container should be considered if we expect
to insert and remove elements from the front and back of the container.
deque.
 */