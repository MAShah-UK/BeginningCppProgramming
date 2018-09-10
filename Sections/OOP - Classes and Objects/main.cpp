#include <iostream> // This syntax is used for system file includes.
#include <string>
#include "Player.h" // This syntax is used for local/project file includes.
#include "Account.h"

using namespace std;

void display_player(Player player);

int main() {
    // OOP

    const Player frank("Frank", 100, 10); // Can only call const methods for const object.
    //frank.name = "Frank";       // Using dot operator to access attribute.
    //frank.health = 100;
    //frank.xp = 10;
    frank.talk("Hi there. :)"); // Using dot operator to access method.

    Player hero("Hero");
    hero.talk("Watch out, I'm the hero.");

    Player players[3] {frank, hero}; // Copies frank and hero to create new objects.

    Player *enemy {nullptr};
    enemy = new Player; // No arguments provided. Uses default constructor.
    //(*enemy).name = "Enemy"; // Dot operator syntax with pointers.
    //enemy->health = 100;     // Recommend: Arrow/member-of-pointer operator.
    //enemy->xp = 15;
    enemy->talk("I will destroy you!");
    cout << "Players count before deleting enemy: " << Player::get_player_count() << endl;
    delete enemy; // Destructor called for Player object that enemy points to.
    cout << "Players count after deleting enemy: " << Player::get_player_count() << endl;
    cout << endl;

    display_player(frank);
    cout << endl;

    Account franks_account;
    //franks_account.name = "Frank's Account"; // Should use getters and setters instead - encapsulation.
    //franks_account.balance = 5000.0;
    franks_account.set_name("Frank's Account");
    franks_account.deposit(1000.0);
    franks_account.withdraw(500.0);
    cout << endl;

    Account jim_acc;

    // l-value references vs. r-value references.
    int x {100};    // l-value: is addressable.
    20;             // r-value: not addressable.
    x+20;           // r-value: not addressable.
    Player {"Bob"}; // r-value: not addressable.

    int &l_ref {x};     // l-value reference: can only initialise with l-values.
    // int &l_ref {20}; // Compilation error.

    int &&r_ref {20};   // r-value reference: can only initialise with r-values.
    // int &&r_ref {x}; // Compilation error.

    return 0;
} // Destructor called for all objects on stack at the end of every function.

void display_player(Player player) { // Creates Player object through copy constructor due to pass-by-value.
    cout << "Player statistics for: " << player.name << endl; // Access to private members due to friendship.
    cout << "Health: " << player.health << endl;
    cout << "Experience: " << player.xp << endl;
}

/*
Challenge 1: Create Dog object and initialise it.
#include "Dog.h"
Dog test_dog() {
    Dog spot;
    spot.name = "Spot";
    spot.age = 5;
    return spot;
}

Challenges 2, 3, 4, 5, and 6: Write various methods for the Dog class.
class Dog {
private:
    string name;
    int age;
public:
    Dog() : Dog("None", 0) { };
    Dog(const Dog &source) : Dog {source.name, source.age} {
        cout << "Copy Constructor";
    }
    Dog(string name, int age) : name{name}, age{age} { }

    string get_name() {return name; }
    void set_name(string n) {name = n; }
    int get_age() {return age; }
    void set_age(int a) { age = a;}
    int get_dog_years() { return age * 7; }
    string speak() { return "Woof";}
};

Challenge 7: Create a basic movie management system.
#include <iostream>
#include <string>
#include <vector>

class Movie { // Should be refactored to Movie.h and Movie.cpp.
  std::string name {"N/A"};
  std::string rating {"N/A"};
  unsigned watch_count {};
public:
  Movie(const std::string &name, const std::string &rating, unsigned watch_count = 0)
    : name(name), rating(rating), watch_count(watch_count) {}

  std::string get_name() const { return name; }
  std::string get_rating() const { return rating; }
  unsigned get_watch_count() const { return watch_count; }
  void increment_watch_count() { ++watch_count; }

  void display() const {
    std::cout << "[name]: " << name <<
                  " [rating] " << rating <<
                  " [watches] " << watch_count;
  }
};

class Movies { // Should be refactored to Movies.h and Movies.cpp.
  std::vector<Movie> movies;

  Movie *find_movie(const std::string &name) {
    for(Movie &movie : movies) {
      if(movie.get_name() == name) {
        return &movie;
      }
    }
    return nullptr;
  }
public:
  void display_movies() const {
    if(movies.size() > 0) {
      std::cout << "The following movies are in the library:" << std::endl;
      for(size_t i {}; i < movies.size(); ++i) {
        const Movie &movie {movies.at(i)};
        std::cout << "\t" << (i+1) << ") ";
        movie.display();
        std::cout << std::endl;
      }
    } else {
      std::cout << "The movie library is empty." << std::endl;
    }
  }
  bool add_movie(const std::string &name, const std::string &rating, unsigned watch_count) {
    bool is_valid = (find_movie(name) == nullptr);
    std::string message;
    if(is_valid) {
      movies.push_back(Movie {name, rating, watch_count});
      message = " was added.";
    } else {
      message = " wasn't added. It already exists.";
    }
    std::cout << name << message << std::endl;
    return is_valid;
  }
  bool increment_count(const std::string &name) {
    Movie *movie = find_movie(name);
    bool is_valid = (movie != nullptr);
    std::string message;
    if(is_valid) {
      movie->increment_watch_count();
      message = name + "'s watch count was incremented.";
    } else {
      message = name + " doesn't exist in the library.";
    }
    std::cout << message << std::endl;
    return is_valid;
  }
};

int main() {
  Movies movies;

  movies.display_movies();
  std::cout << std::endl;

  movies.add_movie("Die Hard", "R", 100);
  movies.add_movie("The Expendables", "R", 50);
  movies.add_movie("Die Hard", "R", 50);
  movies.increment_count("Die Hard");
  movies.increment_count("Harry Potter");
  std::cout << std::endl;

  movies.display_movies();
}

Quiz 1: A Class is ________.
a user-defined data type

Quiz 2: The ________ of a class is used to initialize objects of that class type.
constructor

Quiz 3: Class member attributes can be accessed with the ________ operator.
dot .

Quiz 4: If no user-defined constructors are provided for a class, C++ will
automatically generate a ________ constructor.
default/no-args

Quiz 5: ________ and ________ determine the access allowed to class members.
public, private

Quiz 6: The copy semantics provided by the default C++ Copy Constructor is ________.
shallow/memberwise copy

Quiz 7: ________ are associated with the C++ Move Constructor.
R-value references

Quiz 8: The class ________ is called when an object goes out of scope.
destructor

Quiz 9: What does the following code display?
#include <iostream>
using namespace std;
class Test {
private:
   int num;
   void increment_num() {
      num++;
   }
public:
   Test(int num) : num{num} { }
};
int main() {
   Test object {100};
   cout << object.increment_num() << endl;
   return 0;
}

Compilation error - trying to access private method.

Quiz 10: Given the following class declaration, which statement is NOT true?
class Test {
private:
   int num;
   void increment_num() {
      num++;
   }
public:
   Test(int num) : num{num} { }
   void decrement_num() {
      num--;
   }
};

The compiler will generate a default constructor.
 */