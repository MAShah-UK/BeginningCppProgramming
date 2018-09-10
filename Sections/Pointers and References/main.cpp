#include <iostream>
#include <string>
using namespace std;
int main() {
    // Pointers work with addresses of variables directly.
    int *int_ptr; // * can be next to the name.
    double* double_ptr; // Or next to the type.
    char *char_ptr {nullptr}; // Should initialise to nullptr which represents address 0
    short *short_ptr {}; // Also initialises to nullptr.

    // Address and dereference operators.
    int age_data {18};
    int *age_address {&age_data}; // Pointer type and target type must be the same.
    cout << "Age is: " << *age_address << endl; // Dereferences the pointer.
    cout << "Age address: " << &age_data << endl; // Address operator returns address.
    cout << "int size: " << sizeof(*age_address) << endl;
    cout << "int* size: " << sizeof(age_address) << endl;
    *age_address = 19; // Reassigned age_data via the dereference operator.
    cout << "Reassigned age is: " << *age_address << "\n\n";
    age_address = nullptr; // Reassigned the pointer to point to another address (0).

    string name {"Tim"};
    string *name_ptr {&name};
    (*name_ptr).append("o");
    name_ptr->append("thy"); // (*object).method() is equivalent to object->method().
    cout << "Name is: " << *name_ptr << "\n\n";

    // Allocating on the heap.
    int *datum = new int {5}; // Memory for int allocated on the heap, and address returned.
    cout << "Value of data is: " << *datum << endl;
    delete datum; // Delete keyword deallocates/frees memory from heap.

    int *data {new int[5]{1, 2, 3, 4, 5}}; // Allocated array on heap.
    delete [] data; // Deallocated array from heap.

    // Pointer arithmetic.
    int count [] {1, 2, 3, 4, 5};
    int *ptr = count; // Array name returns address to first element.
    cout << "First array element is: " << *ptr << endl; // Dereference returns first element.
    cout << "Second element is: " << *(ptr+1) << endl;  // Pointer arithmetic moves to next address/element.
    cout << "Third element is: " << *ptr+2 << endl;     // + has higher precedence over *.
    cout << "Fourth element is: " << ptr[3] << endl;  // Recommended/simpler syntax.

    int *last {&count[4]};
    int *first {count};
    unsigned long element_count = last-first; // Returns number of elements: (last_address-first_address)/sizeof(type).
    cout << "From the first element to the last element there are: " << element_count << " elements." << "\n\n";

    // Pointer / underlying type mutability.
    int account_number {12345};
    int *mt_mp {&account_number};               // Mutable type, mutable pointer.
    const int *ct_mp {&account_number};         // Constant type, mutable pointer.
    int *const mt_cp {&account_number};         // Mutable type, constant pointer.
    const int *const ct_cp {&account_number};   // Constant type, constant pointer.

    return 0;
}
/*
Challenge: Write a function that accepts two arrays, and outputs a larger array
in which each element from input elements is multiplied together (use pointers).
#include <iostream>
using namespace std;
void print(const int *const array, size_t size) {
  cout << "[ ";
  for(size_t i {}; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << "]" << endl;
}
int *apply_all(const int *const array1, size_t size1,
               const int *const array2, size_t size2) {
  size_t out_size {size1*size2};
  int *const output {new int[out_size]{}};
  for(size_t i {}; i < size1; i++) {
    for(size_t j {}; j < size2; j++) {
      size_t k = i*size2 + j;
      output[k] = array1[i]*array2[j];
    }
  }
  return output;
}
int main() {
  int array1[] {1,2,3,4,5};
  int array2[] {10,20,30};
  cout << "Array 1: ";
  print(array1, 5);
  cout << "Array 2: ";
  print(array2, 3);

  int *results = apply_all(array1, 5, array2, 3);
  cout << "Result: ";
  print(results, 15);
  delete [] results;

  return 0;
}

Quiz 1: A pointer variable can store ________.
addresses of other variables

Quiz 2: In order to determine the address of a variable in C++, we can use the ________ operator.
address (&)

Quiz 3: Pointer variables must always be ________ before they are used.
initialised

Quiz 4: In order to follow a pointer and access the data that it is pointing to,
we must ________ the pointer using the ________ operator.
dereference, *

Quiz 5: Pointers can be used to dynamically allocate storage from the ________ at ________.
heap/freestore, runtime

Quiz 6: When using raw pointers and dynamic storage allocation, we must always
de-allocate the used storage by using ________ to prevent ________.
delete, memory leaks

Quiz 7: ________ and pointers can be used interchangeably in many contexts.
Array names

Quiz 8: What types of variables can ptr store given the following declaration below?
int **ptr;

Addresses of pointers to an integer.

Quiz 9: What does the following code snippet display?
int *data = new int[5];
for (int i = 0; i<5; i++)
   *(data + i) = i*2;
for (int i = 0; i<=4; i++)
   cout << data[i] << " " ;
cout << endl;
delete data;

0 2 4 6 8

Quiz 10: Given the following pointer declarations, what can you say about ptr1 and ptr2?
int *ptr1;
int *ptr2 {nullptr};

Only ptr2 has been initialised.

 */