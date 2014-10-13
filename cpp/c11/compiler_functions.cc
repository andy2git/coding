/*
 * This code snippets cover the functions genereted by the compiler.
 * 
 */
class Dog{} ; // 1, 2, 3, 4, 5, 6

/*
 * C++ 03
 * 1. default ctor - generated only if no ctor is declared by the user
 * 2. copy ctor - generated only if no 5, 6 declared by the user
 * 3. copy assignment operator - generated only if 5, 6 not declared by the user
 * 4. dtor
 *
 * C++ 11
 * 5. move ctor - generated only if 2, 3, 4, 6 not delcared by the user
 * 6. move assignment operator - generated only 2, 3, 4, 5 not declared by the user
 */


class Cat{ // 3, 4 - 3 is deprecated in C++11
    Cat(const Cat&){}   // copy ctor
};

class Duck{  // 4 - good for non-copyable resources. i.e. mutex, file handler
    Duck(Duck&&){}      // move ctor
};

class Frog{ // 4
    Frog(Frog &&, int = 0){} // move ctor
    // Frog(int = 0){} - default ctor
    // Frog(const Frog&, int = 0) {} - copy ctor
};

class Fish{ // 1, 2, 3  - 2,3 are deprecated in C++11
    ~Fish(){}
};

class Cow{ // 1, 2, 4 - delete function is considered as the declaration from the user (2 is deprecated in C++11)
   Cow& operator=(const Cow&) = delete;
   Cow(const Cow&) = default;
};

/*
 * C++ 11
 * 1. default ctor - generated only if no ctor is declared by the user
 * 2. copy ctor - generated only if no 3, 4, 5, 6 declared by the user
 * 3. copy assignment operator - generated only if 2, 4, 5, 6 not declared by the user
 * 4. dtor
 * 5. move ctor - generated only if 2, 3, 4, 6 not delcared by the user
 * 6. move assignment operator - generated only 2, 3, 4, 5 not declared by the user
 */
