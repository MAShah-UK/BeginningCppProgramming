#include <iostream>
#include <string>
using namespace std;
int main() {
    // C-style/null-terminated strings.
    char name [] {"Crank"}; // C-style/null-terminated string is just an array of characters in memory.
    name[0] = 'F';
    int name_size {};
    // size_t is automatically set to the appropriate unsigned type for the platform, e.g. unsigned int in this case.
    for(size_t i {0}; name[i] != '\0'; i++) { // \0 is null character that's at the end of every C-style string.
        name_size++;
    }
    cout << "The name " << name << " has " << name_size << " characters." << endl;
    cout << "strlen returns the length of the name as " << strlen(name) << endl;

    char name2 [5] {"Tim"}; // Equivalent to "Tim\0\0".
    cout << "Characters in name2: ";
    for(char letter : name2) { // Includes all characters.
        cout << "[" << letter << "] ";
    }
    cout << "\n\n";

    // Assigning to character array.
    char str [10];
    // str = "Hello"; // Can't assign to a character array.
    strcpy_s(str, "Hello");

    // C++ strings.
    string s1; // Empty string.
    s1 = "C++ is "; // Assignment operator.
    s1 += "amazing."; // Compound assignment operator.
    string s2 {"Hello, world!"}; // string initialised using list initialization syntax.
    s2 = s1; // s2 overwritten using assignment operator.

    string hello {"hello"}, world {"world"};
    string helloWorld;
    // helloWorld = "hello " + "world"; // Can't concatenate two character array.
    helloWorld = hello + " world"; // string + char [] = string
    helloWorld = "hello " + world; // char [] + string = string

    helloWorld = hello + " " + world; // ((string + char []) + string) = ((string) + string) = (string + string) = string.
    cout << "The concatenated string is: " << helloWorld << endl;
    string helloSubstr = helloWorld.substr(0, 5); // Extracts a substring.
    cout << "The substring starting at index 0 to offset 5 is: " << helloSubstr << endl;
    int index_world = helloWorld.find("world");
    cout << "The starting index for the first occurrence of world is: " << index_world << endl;
    helloWorld.erase(5, 5);
    int length = helloWorld.length();
    cout << "The length of the string after erasing 'world' is: " << length;

    return 0;
}

/*
Challenge 1: Manipulate C-style strings using strcpy, strcat, and strlen.
#include <iostream>
#include <cstring>
using namespace std;
void strings_and_functions() {
    //----WRITE YOUR CODE BELOW THIS LINE----
    char first_name [] {"Bjarne"};
    char last_name [] {"Stroustrup"};
    char whole_name [16];

    int first_name_length = strlen(first_name);
    int last_name_length = strlen(last_name);
    strcpy(whole_name, first_name);
    strcat(whole_name, last_name);
    int whole_name_length = strlen(whole_name);
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    cout << "The length of the first name, " << first_name << ", is " << first_name_length
    << " letters long and the length of the last name, " << last_name << ", is " << last_name_length
    << " letters long. This means that the length of the whole name must be " << whole_name_length
    << " letters long.";
}

Challenge 2: Use C++ string to format a name.
#include <iostream>
#include <string>
using namespace std;
void cpp_strings() {
    string unformatted_full_name {"StephenHawking"};
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR CODE BELOW THIS LINE----
    string first_name(unformatted_full_name, 0, 7);
    string last_name = unformatted_full_name.substr(7, 7);
    string formatted_full_name = first_name + last_name;
    formatted_full_name.insert(7, " ");
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    cout << formatted_full_name;
}

Challenge 3: Sort strings by surname.
#include <iostream>
#include <string>
using namespace std;
void cpp_strings() {
    string journal_entry_1 {"Isaac Newton"};
    string journal_entry_2 {"Leibniz"};
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR CODE BELOW THIS LINE----
    journal_entry_1.erase(0, 6);
    if(journal_entry_1 > journal_entry_2) {
        journal_entry_1.swap(journal_entry_2);
    }
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    cout << journal_entry_1 << "\n" << journal_entry_2;
}
 */