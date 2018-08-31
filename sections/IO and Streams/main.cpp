#include <iostream>
#include <iomanip> // Provides definitions for IO stream format manipulation.
#include <vector>

class Main {
public:
    int main() {
        boolean_manipulators();
        integer_manipulators();
        float_manipulators();
        field_manipulators();
        challenge1();
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

    void challenge1() {
        std::cout << "\nBEGIN: challenge1" << std::endl;

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
                          << std::setw(column_width) << std::right << city.cost << std::endl;
            }
        }
    }
};

int main() {
    return Main().main();
}