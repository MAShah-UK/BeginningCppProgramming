#include <iostream>
#include <iomanip> // Provides definitions for IO stream format manipulation.
#include <vector>
#include <fstream> // Provides definitions to read/write to files.
#include <set>
#include <regex>
#include <sstream>

class Main {
public:
    int main() {
        boolean_manipulators();
        integer_manipulators();
        float_manipulators();
        field_manipulators();
        challenge_display_table();

        read_file();
        challenge_read_file("../MyFile.txt");
        challenge_automatic_grader();
        challenge_substring_counter();
        challenge_copy_file();

        string_streams();

        return 0;
    }
    void boolean_manipulators() {
        std::cout << "BEGIN: boolean_manipulators" << std::endl;

        std::cout << std::noboolalpha // Default: Displays true as 1, false as 0.
                  << "Result of (10 == 10): " << (10==10) << std::endl
                  << "Result of (10 == 20): " << (10==20) << std::endl
                  << std::boolalpha  // Default: Displays true as true, false as false.
                  << "Result of (10 == 10): " << (10==10) << std::endl
                  << "Result of (10 == 20): " << (10==20) << std::endl
                  << std::resetiosflags(std::ios::boolalpha); // Resets to noboolalpha.
    }
    void integer_manipulators() {
        std::cout << "\nBEGIN: integer_manipulators" << std::endl;
        // Defaults: dec, noshowbase, nouppercase, noshowpos.

        const int num {255};

        std::cout << std::dec // Default: Displays integers in base 10 - decimal.
                  << "The following decimal value will be converted to other bases: " << num << std::endl
                  << "To octal: " << std::oct << num << std::endl
                  << "To hexadecimal: " << std::hex << num << std::endl << std::endl
                  << std::resetiosflags(std::ios::dec);

        std::cout << std::showbase // Displays base prefix. Default: noshowbase.
                  << "Decimal: "  << std::dec <<  num << std::endl                // No prefix.
                  << "Octal: " << std::oct << num << std::endl                    // 0 prefix.
                  << "Hexadecimal: " << std::hex << num << std::endl << std::endl // 0x prefix.
                  << std::resetiosflags(std::ios::showbase);

        std::cout << std::showbase << std::uppercase // Displays letters in uppercase. Default: nouppercase.
                  << "Decimal: "  << std::dec <<  num << std::endl
                  << "Octal: " << std::oct << num << std::endl
                  << "Hexadecimal: " << std::hex << num << std::endl << std::endl // Affected.
                  << std::dec << std::noshowbase << std::nouppercase;

        std::cout << std::showpos   // Default: only displays -.
                  << "Positive: " << num << std::endl
                  << "Negative: " << -num << std::endl
                  << std::noshowpos // Displays + and -.
                  << "Positive: " << num << std::endl
                  << "Negative: " << -num << std::endl << std::endl
                  << std::resetiosflags(std::ios::showbase);
    }
    void float_manipulators() {
        std::cout << "\nBEGIN: float_manipulators" << std::endl;
        // Defaults: setprecision(6), fixed, noshowpoint, nouppercase, noshowpos.

        double num {1234.5678};

        std::cout << "Float with precision 4: " << std::setprecision(4) << num << std::endl // Sets significant figures.
                  << "Float with precision 4, fixed: " << std::fixed << num << std::endl // Sets decimal place.
                  << "Float with precision 6, fixed: " << std::setprecision(6) << num << std::endl
                  << "Float with precision 3, scientific: " << std::setprecision(3)
                    << std::scientific << num << std::endl  // Displays in scientific notation.
                  << "Float with precision 5, fixed, showpoint: " << std::setprecision(5) << std::fixed
                    << std::showpoint << num << std::endl   // Trailing zeroes to match precision.
                  << std::resetiosflags(std::ios::floatfield);
    }
    void field_manipulators() {
        std::cout << "\nBEGIN: field_manipulators" << std::endl;

        // Sets the field width, but only applies to the next data inserted.
        std::cout << "[" << std::setw(10) << 1234.5 << "]" << std::endl;
        // Same as before, but now data is left justified.
        std::cout << "[" << std::setw(10) << std::left << 1234.5 << "]" << std::endl;
        // Same as before, but now the empty spaces are replaced with -.
        std::cout << "[" << std::setw(10) << std::setfill('-') << std::left << 1234.5 << "]" << std::endl;
    }
    void challenge_display_table() {
        std::cout << "\nBEGIN: challenge_display_table" << std::endl;

        struct City {
            std::string name;
            long population;
            double cost;
        };
        struct Country {
            std::string name;
            std::vector<City> cities;
        };
        struct Tours {
            std::string title;
            std::vector<Country> countries;
        };

        Tours tours {"Tour Ticket Prices from Miami" , {  // Tours
                {"Argentina", {                           // Country
                        {"Buenos Aires", 3010000, 723.77} // City
                }},
                {"Brazil", {
                        {"Rio De Janeiro", 13500000, 567.45},
                        {"Salvador", 18234000, 855.99},
                        {"Sao Paulo", 11310000, 975.45}
                }},
                {"Chile", {
                        {"Santiago", 7040000, 520.00},
                        {"Valdivia", 260000, 569.12}
                }},
                {"Colombia", {
                        {"Bogota", 8778000, 400.98},
                        {"Cali", 2401000, 424.12},
                        {"Cartagena", 972000, 345.34},
                        {"Medellin", 2464000, 350.98}
                }}
        }};

        // Display title.
        constexpr int table_width {60};
        const int title_padding {static_cast<int>(table_width-tours.title.length())/2};

        std::cout << std::setw(table_width) << std::setfill('-') << "" << std::setfill(' ') << std::endl
                  << std::setw(title_padding) << "" << tours.title << std::endl
                  << std::setw(table_width) << std::setfill('=') << "" << std::setfill(' ') << std::endl;

        // Display headers.
        constexpr int column_width {table_width/4};

        std::cout << std::setw(column_width) << std::left << "Country"
                  << std::setw(column_width) << "City"
                  << std::setw(column_width) << "Population"
                  << std::setw(column_width) << std::right << "Price" << std::endl
                  << std::setw(table_width) << std::setfill('-') << "" << std::setfill(' ') << std::endl;

        // Display data.
        for(const Country &country : tours.countries) {
            bool next_city = true;
            for(const City &city : country.cities) {
                std::string country_string {""};
                if(next_city) {
                    country_string = country.name;
                    next_city = false;
                }
                std::cout << std::setw(column_width) << std::left << country_string
                          << std::setw(column_width) << city.name
                          << std::setw(column_width) << city.population
                          << std::fixed << std::setprecision(2) << std::setw(column_width) << std::right
                            << city.cost << std::endl;
            }
        }
    }

    void read_file() {
        std::cout << "\nBEGIN: read_file" << std::endl;

        // File will be created automatically if it doesn't exist.
        std::ofstream ofile {"../MyFile.txt"}; // Opens as output file.
        if(ofile.is_open()) {
            ofile << "Hi, my name is John Doe." << std::endl
                  << "My age is 30.";
        }
        ofile.close();

        std::cout << "Read line by line:" << std::endl;
        // File won't be created automatically.
        std::ifstream ifile {"../MyFile.txt"}; // Opens as input file.
        int line_count {1};
        if(ifile.is_open()) {
            while(!ifile.eof()) {
                std::string line;
                std::getline(ifile, line);
                std::cout << line_count << ") " << line << std::endl;
                ++line_count;
            }
        }
        ifile.close();

        std::cout << "Read character by character:" << std::endl;
        // File won't be created automatically.
        ifile.open("../MyFile.txt"); // Opens as input file.
        if(ifile.is_open()) {
            while(!ifile.eof()) {
                char c;
                ifile.get(c);
                std::cout << c;
            }
            std::cout << std::endl;
        }
        ifile.close();
    }
    void challenge_read_file(std::string file_path) {
        std::cout << "\nBEGIN: challenge_read_file" << std::endl;

        std::ifstream file {file_path};
        if(!file.is_open()) {
            std::cerr << "Error opening file" << std::endl;
            return;
        }
        while(!file.eof()) {
            std::string line;
            getline(file, line);
            std::cout << line << std::endl;
        }
    }
    void challenge_automatic_grader() {
        std::cout << "\nBEGIN: challenge_automatic_grader" << std::endl;

        std::ifstream file ("../responses.txt");
        if(!file.is_open()) {
            std::cerr << "Error: File not found.";
            return;
        }
        std::string key;
        std::getline(file, key);
        std::cout << std::left << std::setw(15) << "Student Name"
                  << std::right << std::setw(8) << "Score /5" << std::endl
                  << std::setfill('=') << std::setw(23) << "" << std::setfill(' ') << std::endl;
        int student_count {};
        int sum {};
        while(!file.eof()) {
            ++student_count;
            std::string name;
            std::string answers;
            int score {};
            std::getline(file, name);
            std::getline(file, answers);
            for(size_t i {}; i < key.length(); ++i) {
                if(answers.at(i) == key.at(i)) {
                    ++score;
                }
            }
            std::cout << std::left << std::setw(15) << name
                      << std::right << std::setw(8) << score << std::endl;
            sum += score;
        }
        const double average = static_cast<double>(sum)/student_count;
        std::cout << std::setfill('=') << std::setw(23) << "" << std::setfill(' ') << std::endl
                  << std::left << std::setw(15) << "Average score: "
                  << std::fixed << std::setprecision(1) << std::right << std::setw(8) << average << std::endl;
    }
    void challenge_substring_counter() {
        std::cout << "\nBEGIN: challenge_substring_counter" << std::endl;

        std::ifstream file {"../romeoandjuliet.txt"};
        if(!file.is_open()) {
            std::cerr << "Error: File not found." << std::endl;
            return;
        }
        std::cout << "Enter the substring that you want to search for: ";
        std::string str;
        std::getline(std::cin, str);
        int substring_matches {};
        int char_matches {};
        while(!file.eof()) {
            std::string line;
            std::getline(file, line);
            for(size_t i {}; i < line.length(); ++i) {
                if(line.at(i) == str.at(char_matches)) {
                    ++char_matches;
                    if(char_matches == str.length()) {
                        ++substring_matches;
                        char_matches = 0;
                    }
                } else {
                    char_matches = 0;
                }
            }
        }
        std::cout << "The substring '" << str << "' was found: " << substring_matches << " times." << std::endl;
    }
    void challenge_copy_file() {
        std::cout << "\nBEGIN: challenge_copy_file" << std::endl;

        std::ifstream source {"../romeoandjuliet.txt"};
        std::ofstream target {"../romeoandjuliet_copy.txt"};
        int current_line {};
        while(!source.eof()) {
            std::string line;
            std::getline(source, line);
            std::regex letter_regex {"[a-zA-Z]"};
            // Note: Could've just checked to see if line == "", but this is for practice.
            if(std::regex_search(line, letter_regex)) {
                ++current_line;
                target << std::left << std::setw(6)
                    << std::to_string(current_line) + ") " << line << std::endl;
            } else {
                target << std::endl;
            }
        }
    }

    void string_streams() {
        std::cout << "\nBEGIN: string_streams" << std::endl;

        std::ostringstream oss;
        oss << "Hi, my name is John Doe." << std::endl
            << "My age is 30.";
        std::cout << "String stream contains: " << oss.str() << std::endl;

        std::string input {"Moe 100 1234.5"};
        std::istringstream iss {input};
        std::cout << "The input is: " << input << std::endl;
        std::string text;
        int integer;
        double floating_point;
        iss >> text >> integer >> floating_point;
        std::cout << "The string is: " << text << std::endl
                  << "The integer is: " << integer << std::endl
                  << "The floating point is: " << floating_point << std::endl;
    }
};

int main() {
    return Main().main();
}

/*
Quiz 1: The ________ class can be used to create files
that can be written to, but not read from?
ofstream

Quiz 2: The ________ class can be used to create files
that can be both written to and read from?
fstream

Quiz 3: The ________ method reads in an entire line from a text file.
getline

Quiz 4: The ________ method writes a single character to a text file.
put

Quiz 5: You must #include  ________  in order to perform file I/O in C++.
<fstream>

Quiz 6: Which of the following stream manipulators is not persistent?
setw

Quiz 7: Which class can be used to write formatted
data to an in-memory string object?
stringstream

Quiz 8: By default, when we open a file for output,
the contents of that file are ________.
truncated

Quiz 9: What are the steps, in order, that
should be used when using a file in C++?
- Open the file.
- Check if the file was opened successfully.
- Read/write data.
- Close the file.

Quiz 10: Closing an output file  ________
should always be done since it writes out any unwritten buffers.

*/