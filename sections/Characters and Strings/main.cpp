#include <iostream>
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
 */