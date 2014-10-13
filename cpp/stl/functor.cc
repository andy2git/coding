
/*
 * Function Objects (functors)
 * It can take any number of parameters, and return any data type. It is like z=f(a, b, c, d, e)
 *
 * Example:
 */
struct X {
   void operator()(string str) { 
      cout << "Calling functor X with parameter " << str<< endl;
   }  
};

//AW - prefer to use struct instead of class
struct X{
    void operator()(const string &str){
        // do something here
    }
}

int main()
{
   X foo;
   foo("Hi");    // Calling functor X with parameter Hi
}
/*
 * Benefits of functor:
 * 1. Smart function: capabilities beyond operator(). It can remember state - it has data fields.
 * 2. It can have its own type.
 */


/*
 * Parameterized Function
 */
struct X {
   X(int i) {}
   void operator()(string str) { 
      cout << "Calling functor X with parameter " << str<< endl;
   }
};

int main() {
   X(8)("Hi"); //AW - can store the state, and X(8) create a function object
}



void add2(int i) {
   cout << i+2 << endl;
}

// Nontype Template parameter
// val has to be constant 
template<int val>
void addVal(int i) {
   cout << val+i << endl;
}

struct AddValue {
   int val;
   AddValue(int j) : val(j) {}

   void operator()(int i) {
      cout << i+val << endl;
   }
};

int main()
{
   vector<int> vec = { 2, 3, 4, 5};   
   //for_each(vec.begin(), vec.end(), add2); // {4, 5, 6, 7}
   int x = 2;
   //for_each(vec.begin(), vec.end(), addVal<x>); // {4, 5, 6, 7} - ERROR, x is a variable. need constantexpr
   for_each(vec.begin(), vec.end(), AddValue(x)); // {4, 5, 6, 7}
}


/*
 * Build-in Functors
 * -----------------
 * 
 * Several predefined handy template class functors defined in <functional> are ready for us to use. 
 * They can be used conveniently with STL algorithms - and they behave like a wrapper for regular operators.
 * 
 * For example, if you need to compare two string variables, you can use st1 < st2 or st1.compare(st2).
 * In order to represent this relationship in the STL algorithm, you need to functor/function to capture this
 * comparision logic. You could define your own functors/function. Fortunately, they are predefined as the 
 * template functor class in <functional> header.
 *
 *       less<T> greater<T>  greater_equal<T>  less_equal<T>  not_equal_to<T>
 *       logical_and<T>  logical_not<T>  logical_or<T>
 *       multiplies minus<T>  plus<T>  divide<T>  modulus<T>  negate<T>
 * ----------------------------------------------------------------------------------------------------------
 */

// AW - do not forget the () - it means to create an object of the class. 
// less<T>(** parameters for ctor **) (** parameters for the operator() **)
int x = multiplies<int>()(3,4);  //  x = 3 * 4 

if (not_equal_to<int>()(x, 10))   // if (x != 10)
   cout << x << endl;



/*
 * Parameter Binding - C++ 11
 * --------------------------
 * 
 *
 *    template <class Fn, class... Args>
 *         unspecified  bind (Fn&& fn, Args&&... args);
 *    template <class Ret, class Fn, class... Args>
 *         unspecified bind (Fn&& fn, Args&&... args);
 *
 * std::bind() - Returns a function object based on fn, but with its arguments bound to args.
 */
set<int> myset = { 2, 3, 4, 5};   
vector<int> vec;


int x = multiplies<int>()(3,4);  //  x = 3 * 4 

// Multiply myset's elements by 10 and save in vec:
transform(myset.begin(), myset.end(),    // source
	      back_inserter(vec),              // destination
			bind(multiplies<int>(), placeholders::_1, 10));  // functor
    // AW - bind a binary function into unary function
    //
    // First parameter of multiplies<int>() is substituted with myset's element
    // vec: {20, 30, 40, 50}


void addVal(int i, int val) {
   cout << i+val << endl;
}
for_each(vec.begin(), vec.end(), bind(addVal, placeholders::_1, 2));

// C++ 03: bind1st, bind2nd


void addVal(int i, int val) {
   cout << i+val << endl;
}
for_each(vec.begin(), vec.end(), bind(addVal, placeholders::_1, 2));


// C++ 03: bind1st, bind2nd





// Convert a regular function to a functor
double Pow(double x, double y) {
	return pow(x, y);
}

int main()
{
  set<int> myset = {3, 1, 25, 7, 12};
  deque<int> d;
  // **************************************
  // AW - convert a function into a functor
  // Not needed in this case, std::bind() works for function/functors
  // **************************************
  auto f = function<double (double,double)>(Pow);   //C++ 11
  transform(myset.begin(), myset.end(),     // source
		      back_inserter(d),              // destination
				bind(f, placeholders::_1, 2));  // functor
            //  d: {1, 9, 49, 144, 625}
}
// C++ 03 uses ptr_fun 



set<int> myset = {3, 1, 25, 7, 12};
// when (x > 20) || (x < 5),  copy from myset to d
deque<int> d;

bool needCopy(int x){
   return (x>20)||(x<5);
}


transform(myset.begin(), myset.end(),     // source
          back_inserter(d),               // destination
          needCopy
          );

// C++ 11 lambda function: - anonymous functor
transform(myset.begin(), myset.end(),     // source
          back_inserter(d),              // destination
          [](int x){return (x>20)||(x<5);}
          );

/* ----------------------------------------------------------------------
 * Applies an operation sequentially to the elements of one or two ranges 
 * and stores the result in the range that begins at result.
 * ----------------------------------------------------------------------
 */


/* ------------------------------
 * Why do we need functor in STL?
 * ------------------------------
 */

// ********************************
// template < class T,                       // set::key_type/value_type
//           class Compare = less<T>,        // set::key_compare/value_compare
//           class Alloc = allocator<T> >    // set::allocator_type
//           > class set;
//
//
// As a reference for unordered_set
// template < class Key,                       // unordered_set::key_type/value_type
//           class Hash = hash<Key>,           // unordered_set::hasher
//           class Pred = equal_to<Key>,       // unordered_set::key_equal
//           class Alloc = allocator<Key>      // unordered_set::allocator_type
//           > class unordered_set;
//
set<int> myset = {3, 1, 25, 7, 12}; // myset: {1, 3, 7, 12, 25}
// same as:
set<int, less<int> > myset = {3, 1, 25, 7, 12};

bool lsb_less(int x, int y) {
      return (x%10)<(y%10);
}

class Lsb_less {
   public:
   bool operator()(int x, int y) {
      return (x%10)<(y%10);
   }
};
int main() {
  // ************************************************************************
  // AW - lsb_less will not work here, because set<T, ...> is expecting
  // a type. class Lsb_less is a type, and lsb_less() is not a type. However, 
  // you could pack the type for lsl_less to pass it in. 
  //
  // Not Lsb_less()
  // ************************************************************************
  set<int, Lsb_less> myset = {3, 1, 25, 7, 12};  // myset: {1,12,3,25,7}
}

/*
 * Predicate - Predicate is used for comparison or condition checkher
 *
 * A functor or function that:
 *     1. Returns a boolean
 *     2. *** Does not modify data ***
 */

struct NeedCopy {
   bool operator()(int x){   
      return (x>20)||(x<5);  
   }
};

transform(myset.begin(), myset.end(),     // source
          back_inserter(d),               // destination
          NeedCopy()
          );

