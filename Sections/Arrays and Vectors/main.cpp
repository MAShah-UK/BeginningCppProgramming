#include <iostream>
#include <vector> // Defines the vector class.
using namespace std;

int main() {
    int score_1 {0};
    int score_2 {0};
    int score_3 {0};
    // ... there could be tens/hundreds/thousands/etc of records.
    // A better solution is to use a compound data type - the array, to store them.
    int scores_literal [3];
    // Can use variables to set the size.
    const int num = 3;
    int scores_const [num];
    // Arrays can be directly initialised using list initialisers.
    int scores [3] {}; // All elements set to zero.
    cout << "Enter score 1: "; cin >> scores[0]; // Arrays use a zero-based index.
    cout << "Enter score 2: "; cin >> scores[1]; // 0 is the first element.
    cout << "Enter score 3: "; cin >> scores[2]; // 2 is the third/last element.
    scores[2] = 5; // Can directly set value using assignment operator.
    // scores[3] = 4; // Runtime error, out of bounds.
    // The name of the array represents the location of the first element.
    // THe [index] represents the offset in memory.
    cout << "Score (no index, index 0): " << scores << ", " << scores[0] << endl;

    // Multidimensional arrays are used to represent grids/table/spreadsheets.
    // Assuming
    const int movies = 3;
    const int reviewers = 2;
    int movie_ratings[movies][reviewers] {
        {100, 90}, // Each movie has two ratings.
        {70, 65},
        {20, 30}
    };
    // The first [] represents the row, the second [] represents the column, etc.
    // If you specify two indices, then a specific integer will be returned.
    int movie1_rating2 = movie_ratings[0][1];

    // Vectors are preferred in many cases over built-in arrays.
    // Vector is a template class so you must specify element type in angled brackets.
    vector <int> vscores (2);   // 2 elements initialised to 0.
    vscores[0] = 5;             // Can set element using subscript operator. No bounds checking done.
    vscores.at(1) = 3;          // Performs bounds checking.
    vscores.push_back(4);       // Adds a new element to the end of the vector.
    cout << "Vector scores: " << vscores[0] << " " << vscores.at(1) << " " << vscores.at(2) << endl;
    cout << "Size of vector: " << vscores.size();
    // vscores[3]; // Causes exception.

    // 2D vector:
    vector <vector<int>> vmovie_ratings = {
            {100, 90},
            {70, 65},
            {20, 30}
    }; // Can access 2D elements using subscript operator, or multiple at() calls.
    cout << "Ratings for movie 1: " << vmovie_ratings[0][0] << " " << vmovie_ratings.at(0).at(1) << endl;

    return 0;
}

/*
Challenge 1: Declare, initialise, and reassign array elements.
#include <vector>
using namespace std;
vector<int> use_array() {
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR CODE BELOW THIS LINE----
    int arr [10] {};
    arr[0] = 100;
    arr[9] = 1000;
    //-----WRITE YOUR ABOVE THIS LINE----
    //-----DO NOT CHANGE THE CODE BELOW THIS LINE----
    vector<int> v(arr, arr + sizeof arr / sizeof arr[0]);
    return v;
}

Challenge 2: Declare, initialise, and reassign vector elements.
#include <vector>
using namespace std;
vector<int> use_vector() {
    //----WRITE YOUR CODE BELOW THIS LINE----
    vector <int> vec {10, 20, 30, 40, 50};
    vec.at(0) = 100;
    vec.at(4) = 1000;
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----NO NOT MODIFY THE CODE BELOW THIS LINE----
    return vec;
}

Challenge 3: 1D/2D vector manipulation.
#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector <int> vector1;
  vector <int> vector2;
  // vector1.
  vector1.push_back(10);
  vector1.push_back(20);
  cout << "vector1 elements: " << vector1.at(0) << " " << vector1.at(1) << endl;
  cout << "vector1 size: " << vector1.size() << endl;
  // vector2.
  vector2.push_back(100);
  vector2.push_back(200);
  cout << "vector2 elements: " << vector2.at(0) << " " << vector2.at(1) << endl;
  cout << "vector2 size: " << vector2.size() << endl;
  // vector_2d.
  vector <vector<int>> vector_2d;
  vector_2d.push_back(vector1);
  vector_2d.push_back(vector2);
  cout << "vector_2d elements: " << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << " "
       << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;

  vector1.at(0) = 1000;
  cout << "vector_2d elements: " << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << " "
       << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;
  cout << "vector1 elements: " << vector1.at(0) << " " << vector1.at(1) << endl;
  // I expect only vector1 to be different since it was passed by value to vector_2d.
}

Quiz 1: Arrays are always indexed starting at subscript ________.
0.

Quiz 2: How many integers can the array named numbers contain?
int numbers[10];
10.

Quiz 3: Which of the following is a legal array definition in C++?
float numbers[10];

Quiz 4: C++ treats an array name as?
The location in memory of the first array element.

Quiz 5: All array elements must be?
Of the same type.

Quiz 6: Given the following array declaration, how would you display "100.7" from the array?
double temperatures[] = {98.6, 95.2, 88.7, 100.7, 89.0};
cout << temperatures[3] << endl;

Quiz 7: Given the following array declaration, what would the following code display?
double temperatures[] = {98.6, 95.2, 88.7, 100.7, 89.0};
cout << temperatures[5] << endl;
Undefined.

Quiz 8: How would you define a vector named temperatures that contains doubles?
vector <double> temperatures;

Quiz 9: How would you determine the number of elements contained in a vector named temperatures?
temperatures.size();

Quiz 10: What is one way that vectors and arrays are different?
Arrays have a fixed size. Vectors have a dynamic size.

 */