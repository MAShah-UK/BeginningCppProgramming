#include <iostream>
using namespace std;

int main() {
    // if statement: Allows executing code conditionally.
    int min {10}, max {100};
    int num {};
    cout << "Enter a number between " << min << " and " << max << ": " << endl;
    cin >> num;
    if (num > min && num < max) { // Checks that the condition evaluates to true or non-zero.
        const int diff {num - min}; // Declared within this scope. Falls out of scope end of block.
        cout << "Num entered was within range. It is above " << min << " by " << diff << ".";
    } else { // Executes if the expression evaluates to false or zero.
        cout << "Num entered was not within range.";
    }
    cout << "\n\n";

    // Nested if statements and else block.
    int score {92};
    // Implicit if-else pair:
    if (score > 90)
        if (score > 95)
            cout << "A+";
        else // Dangling else problem. In C++ it applies to the closest if statement.
            cout << "A";
    cout << endl;
    // Explicit if-else pair:
    if (score > 90) {
        if (score > 95) {
            cout << "A+";
        } else {
            cout << "A";
        }
    }
    cout << "\n\n";

    // Complex if statement combination.
    int grade_score {50};
    cout << "Enter grade score: ";
    cin >> grade_score;
    char grade_letter {};
    if (grade_score >= 0 && grade_score <= 100) {
        if (grade_score > 90) {
            grade_letter = 'A';
        } else if (grade_score > 80) {
            grade_letter = 'B';
        } else if (grade_score > 70) {
            grade_letter = 'C';
        } else if (grade_score > 60) {
            grade_letter = 'D';
        } else {
            grade_letter = 'F';
        }
        cout << "Your grade is : " << grade_letter << endl;
        if (grade_letter == 'F') {
            cout << "Sorry, you must repeat the year.";
        } else {
            cout << "Congrats!";
        }
        cout << endl;
    } else {
        cout << "Invalid grade score." << endl;
    }
    cout << endl;

    // Complex switch statement: Similar to if-else if statements, but different syntax and rules.
    // The expressions in the case statements must be constant integral types.
    int option {};
    cout << "Enter an option: ";
    cin >> option;
    switch (option) { // Control expression must be integral type.
        // Equivalent to if (option == 1) ...
        case 1: cout << "Option 1 selected."; break; // break exits switch statement.
        case 2: // Lack of break means case 2 and 3 will run.
        case 3:
            cout << "Option 2";
            cout << " or 3 selected."; // Can have multiple statements without code block.
            break; // Equivalent to option == 2 || option == 3.
        case 4: {
            int option_selected = option; // Only need code block if you declare a local variable.
            cout << "Option " << option_selected << " selected.";
        }
        // Equivalent to else ...
        default: cout << "Invalid option entered."; // Can break but it's unnecessary.
    }
    cout << "\n\n";

    // Enumerators and conditional operator.
    enum class Colour {
        red,
        green,
        blue
    }; // Scoped enum prevents namespace pollution.
    Colour colour = Colour::red; // Restricts programmer to provide valid values as opposed to an int.
    // Conditional operator takes three arguments: 1) Condition. 2) If condition is true. 3) If condition is false.
    (colour == Colour::red) ? cout << "Colour is red" : cout << "Colour is not red.";
    
    return 0;
}

/*
Challenge 1: Use if statement to determine if a person can drive.
#include <iostream>
using namespace std;
void can_you_drive(int age) {
    //----WRITE YOUR CODE BELOW THIS LINE----
    if (age >= 16) {
        cout << "Yes - you can drive!";
    }
    //----WRITE YOUR CODE ABOVE THIS LINE----
}

Challenge 2: Use if-else statement to determine if a person can drive.
#include <iostream>
using namespace std;
void can_you_drive(int age) {
    //----WRITE YOUR CODE BELOW THIS LINE----
    const int age_min {16};
    if (age >= age_min) {
        cout << "Yes - you can drive!";
    } else {
        const int diff {age_min-age};
        cout << "Sorry, come back in " << diff << " years";
    }
    //----WRITE YOUR CODE ABOVE THIS LINE----
}

Challenge 3: Use nested if statements to determine if a person can drive.
#include <iostream>
using namespace std;
void can_you_drive(int age, bool has_car) {
    //----WRITE YOUR CODE BELOW THIS LINE----
    const int age_min {16};
    if (age >= age_min) {
        if (has_car) {
            cout << "Yes - you can drive!";
        } else {
            cout << "Sorry, you need to buy a car before you can drive!";
        }
    } else {
        const int diff {age_min-age};
        cout << "Sorry, come back in " << diff << " years and be sure you own a car when you come back.";
    }
    //----WRITE YOUR CODE ABOVE THIS LINE----
}

Challenge 4: Use switch-case statements to determine the day of the week.
#include <iostream>
using namespace std;
void display_day(int day_code) {
    //----WRITE YOUR CODE BELOW THIS LINE----
    switch (day_code) {
        case 0: cout << "Sunday"; break;
        case 1: cout << "Monday"; break;
        case 2: cout << "Tuesday"; break;
        case 3: cout << "Wednesday"; break;
        case 4: cout << "Thursday"; break;
        case 5: cout << "Friday"; break;
        case 6: cout << "Saturday"; break;
        default: cout << "Error - illegal day code";
    }
    //----WRITE YOUR CODE ABOVE THIS LINE----
}



 */