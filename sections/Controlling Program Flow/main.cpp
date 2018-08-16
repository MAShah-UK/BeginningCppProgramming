#include <iostream>
#include <vector>
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
            break; // break statement required regardless of code block.
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
    cout << "\n\n";

    // For loop: used to execute body of code a certain number of times.
    cout << "One loop variable:" << endl;
    for(int i {0}; i < 5; ++i) { // Semi-colons required, but expressions are optional.
        cout << "[i]: " << i << " ";
    }
    cout << endl;

    cout << "Two loop variables:" << endl;
    for(int i {1}, j {4}; i < 5; i++, j--) { // Variables declared in the loop/body are local to the loop.
        cout << "[i]: " << i << " [j]: " << j << "\t\t";
    }
    cout << endl;

    cout << "Loop through array:" << endl;
    int test_results [] {5, 4, 4, 2, 3};
    for(int i = 0; i < 5; i++) {
        cout << "[i]: " << i << " [res]: " << test_results[i] << "\t\t";
    }
    cout << endl;

    cout << "Loop through vector:" << endl;
    vector <double> miles_per_hour {10.5, 11.0, 25.2, 30.4, 15.4};
    for(unsigned i = 0; i < miles_per_hour.size(); i++) { // unsigned because index will never be negative.
        cout << "[i]: " << i << " [mph]: " << miles_per_hour.at(i) << "\t\t";
    }
    cout << "\n\n";

    // Range-based for loop: for loop with convenient syntax for use with collections.
    int lottery_numbers_arr [] {10, 12, 44, 36, 5};
    cout << "[array] The lottery numbers are: ";
    for(int lottery_number : lottery_numbers_arr) {
        cout << lottery_number << " ";
    }
    cout << endl;

    vector <int> lottery_numbers_vec {10, 12, 44, 36, 5};
    cout << "[vector] The lottery numbers are: ";
    for(int lottery_number : lottery_numbers_vec) {
        cout << lottery_number << " ";
    }
    cout << endl;

    cout << "[auto] The lottery numbers are: ";
    for(auto lottery_number : lottery_numbers_vec) { // Automatic type deduction by the compiler.
        cout << lottery_number << " ";
    }
    cout << endl;

    cout << "[list initialisation] The lottery numbers are: ";
    for (int lottery_number : {10, 12, 44, 36, 5}) {
        cout << lottery_number << " ";
    }
    cout << "\n\n";

    // While loop: used to loop until a condition is no longer true.
    int i {1};
    cout << "While loop index:";
    while(i <= 5) {
        cout << " [i]: " << i;
        i++; // If you forget this it will result in an infinite loop that may crash the program.
    }
    cout << endl;

    int number {};
    while(number < 10 || number > 20) { // Ensures valid input.
        cout << "(while) Enter number between 10 and 20 inclusive: ";
        cin >> number;
    }

    int number2 {};
    do { // do-while loop is better since number2 doesn't have to be initialised to a 'safe' value.
        cout << "(do-while) Enter number between 10 and 20 inclusive: ";
        cin >> number2;
    } while(number2 < 10 || number2 > 20);

    // Nested loops: used for multidimensional data.
    vector <vector<int>> movie_ratings {
            {5, 3, 4}, // Movie 1.
            {2, 2, 1}, // Movie 2.
            {3, 4, 3} // Movie 3.
    };
    for(vector <int> movie : movie_ratings) { // Could use auto to simplify this.
        cout << "Ratings for movie: ";
        for(int rating : movie) {
            cout << rating << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}

/*
Challenge 1: Determine if a person can drive 1/3.
#include <iostream>
using namespace std;
void can_you_drive(int age) {
    //----WRITE YOUR CODE BELOW THIS LINE----
    if (age >= 16) {
        cout << "Yes - you can drive!";
    }
    //----WRITE YOUR CODE ABOVE THIS LINE----
}

Challenge 2: Determine if a person can drive 2/3.
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

Challenge 3: Determine if a person can drive 3/3.
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

Challenge 4: Determine the day of the week.
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

Challenge 5: Find the sum of odd integers from 1 to 15 inclusive.
int calculate_sum() {
    //---- WRITE YOUR CODE BELOW THIS LINE
    int sum {};
    for(int i {1}; i <= 15; i++) {
        if(i % 2 == 1) {
            sum += i;
        }
    }
    //---- WRITE YOUR CODE ABOVE THIS LINE
    //---- DO NOT MODIFY THE CODE BELOW
    return sum;
}

Challenge 6: Count integers divisible by 3 or 5 in vector.
#include <vector>
using namespace std;
int count_divisible() {
    vector<int> vec {1,3,5,15,16,17,18,19,20,21,25,26,27,30,50,55,56,58,100,200,300,400,500,600,700};
    //---- WRITE YOUR CODE BELOW THIS LINE----
    int count {};
    for(auto i : vec) {
        if(i%3==0 || i%5==0) {
            count++;
        }
    }
    //---- WRITE YOUR CODE ABOVE THIS LINE----
    //---- DO NOT CHANGE THE CODE BELOW THIS LINE----
    return count;
}

Challenge 7: Count all the numbers up until you get -99.
#include <iostream>
#include <vector>
using namespace std;
int count_numbers(const vector<int> &vec) {
    //---- WRITE YOUR CODE BELOW THIS LINE----
    int count {};
    bool done = false;
    int i {};
    const int size {vec.size()};
    while(!done) {
        if(i==vec.size() || vec.at(i)==-99) {
            done = true;
        } else {
            count++;
            i++;
        }
    }
    //---- WRITE YOUR CODE ABOVE THIS LINE----
    //---- DO NOT MODIFY THE CODE BELOW THIS LINE-----
    return count;
}

Challenge 8: Calculate the sum of each pair multiplied by eachother.
#include <vector>
using namespace std;
int calculate_pairs(vector<int> vec) {
    //----WRITE YOUR CODE BELOW THIS LINE----
    int result {};
    for(unsigned i {}; i < vec.size()-1; i++) {
        for(unsigned j {i+1}; j < vec.size(); j++) {
            result += vec.at(i)*vec.at(j);
        }
    }
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    return result;
}

Challenge 9: Create a number management system with a menu.
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cout << "Welcome to the number collector." << "\n\n";
  char input {};
  vector <int> numbers;
  do {
    cout << "[MENU]" << endl;
    cout << "P - Print numbers..." << endl;
    cout << "A - Add a number..." << endl;
    cout << "M - Calculate mean..." << endl;
    cout << "S - Find smallest number..." << endl;
    cout << "L - Find largest number..." << endl;
    cout << "Q - Quit..." << "\n\n";

    cout << "Pick an option: ";
    cin >> input;
    switch(input) {
      case 'p':
      case 'P': {
        if(numbers.size() == 0) {
          cout << "[] - The list is empty.";
        } else {
          cout << "[";
          for(int number : numbers) {
            cout << " " << number;
          }
          cout << " ]";
        }
        break;
      }
      case 'a':
      case 'A': {
        int number_add {};
        cout << "Enter number to add: ";
        cin >> number_add;
        numbers.push_back(number_add);
        cout << number_add << " was added.";
        break;
      }
      case 'm':
      case 'M': {
        if(numbers.size() > 0) {
          double sum {};
          for(int number : numbers) {
            sum += number;
          }
          const double mean {sum/numbers.size()};
          cout << "The mean is " << mean << ".";
        } else {
          cout << "Error: List is empty.";
        }
        break;
      }
      case 's':
      case 'S': {
        if(numbers.size() > 0) {
          int number_smallest {};
          if(numbers.size() > 0) {
            number_smallest = numbers.at(0);
          }
          for(int i = 1; i < numbers.size(); i++) {
            if(numbers.at(i) < number_smallest) {
              number_smallest = numbers.at(i);
            }
          }
          cout << "The smallest number is " << number_smallest << ".";
        } else {
          cout << "Error: List is empty.";
        }
        break;
      }
      case 'l':
      case 'L': {
        if(numbers.size() > 0) {
          int number_largest {};
          if(numbers.size() > 0) {
            number_largest = numbers.at(0);
          }
          for(int i = 1; i < numbers.size(); i++) {
            if(numbers.at(i) > number_largest) {
              number_largest = numbers.at(i);
            }
          }
          cout << "The largest number is " << number_largest << ".";
        } else {
          cout << "Error: List is empty.";
        }
        break;
      }
      case 'q':
      case 'Q': {
        cout << "Quitting.";
        break;
      }
      default: cout << "Unknown selection, please try again.";
    }
    cout << "\n\n";
  } while (input != 'q' && input != 'Q');
}

Quiz 1: What is the value of num after the following code executes if the user enters 10 at the keyboard?
int num;
cin >> num;
if (num > 10)
   num -= 10;
else
   num += 10;

20

Quiz 2: What does the following code snippet display if the user enters 70 at the keyboard?
int temperature;
cout << "Enter a temperature: ";
cin >> temperature;
if (temperature < 50);
   cout << "It's cold!" << endl;
if (temperature > 50)
   cout << "It's hot!" << endl;
else
   cout << "Maybe it's raining?";

"It's cold!"
"It's hot!"

Quiz 3: What does the following code snippet display if the user enters 20 at the keyboard?
int favorite;
cout << "Enter your favorite number: ";
cin >> favorite;
if (favorite == 13)
   cout << "That my favorite number too!" << endl;
   cout << "That's amazing!" << endl;
   cout << "Great minds think alike!" << endl;

"That's amazing!"
"Great minds think alike!".

Quiz 4: What will the following code snippet display?
int num = 10;
while (num >= 1)
   cout << num << " ";
   num--;

10 10 10 ... infinitely.

Quiz 5: The while loop is an example of a(n) ________.
Pre-test loop.

Quiz 6: A do-while loop is guaranteed to execute ________.
At least once.

Quiz 7: The for loop has 3 expressions in the following order:
Initialisation, condition, increment.

Quiz 8: A loop that is located inside another loop is called a(n) ________.
Nested loop.

Quiz 9: In order to terminate the execution of a loop, we can use the ________ statement.
break.

Quiz 10: If you know ahead of time how many times you need to loop, which loop would you use?
For loop.

 */