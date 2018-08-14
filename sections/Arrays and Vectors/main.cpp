#include <iostream>
using namespace std;

int main() {
    int test_score_1 {0};
    int test_score_2 {0};
    int test_score_3 {0};
    // ... there could be tens/hundreds/thousands/etc of records.
    // A better solution is to use a compound data type - the array, to store them.
    int test_score_literal [3];
    // Can use variables to set the size.
    const int num = 3;
    int test_scores_const [num];
    // Arrays can be directly initialised using list initialisers.
    int test_scores [3] {}; // All elements set to zero.
    cout << "Enter score 1: "; cin >> test_scores[0]; // Arrays use a zero-based index.
    cout << "Enter score 2: "; cin >> test_scores[1]; // 0 is the first element.
    cout << "Enter score 3: "; cin >> test_scores[2]; // 2 is the third/last element.
    test_scores[2] = 5; // Can directly set value using assignment operator.
    // test_scores[3] = 4; // Runtime error, out of bounds.
    // The name of the array represents the location of the first element.
    // THe [index] represents the offset in memory.
    cout << "Test score (no index, index 0): " << test_scores << ", " << test_scores[0];

    // Multidimensional arrays are used to represent grids/table/spreadsheets.
    // Assuming
    const int movies = 3;
    const int reviewers = 2;
    int movie_ratings[movies][reviewers] { {100, 90}, // Each movie has two ratings.
                                           {70, 65},
                                           {20, 30}};
    // The first [] represents the row, the second [] represents the column, etc.
    // If you specify two indices, then a specific integer will be returned.
    int movie1_rating2 = movie_ratings[0][1];

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
 */