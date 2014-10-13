/*
 * STL: Standard Template Library
 *   -- Data Structures and Algorithms
 */


// First Example:
using namespace std;

vector<int> vec;
vec.push_back(4);
vec.push_back(1);
vec.push_back(8);  // vec: {4, 1, 8}

vector<int>::iterator itr1 = vec.begin();  // half-open:  [begin, end)
vector<int>::iterator itr2 = vec.end();

// AW - prefer ++itr to itr++.
// itr++ needs to return a temporary object, which is more expensive
for (vector<int>::iterator itr = itr1; itr != itr2; ++itr)
   cout << *itr << " ";  // Print out:  4 1 8

// AW - sort need random access iterator
sort(itr1, itr2);  // vec: {1, 4, 8}



/*
 * common STL Headers
 */

/* -------------------
 * sequence containers 
 * -------------------
 */
#include <vector>
#include <deque>
#include <list>  // AW - sequence container, and is implemented as double-linked list
#include <forward_list> // included in C++ 11


/* ----------------------
 * associative containers 
 * ----------------------
 */
#include <set>   // set and multiset
#include <map>   // map and multimap
#include <unordered_set>  // unordered set/multiset
#include <unordered_map>  // unordered map/multimap

/* ----------------------------------------------------------------------------------------------------------
 * An iterator is an object, pointing to some element in a range, and has the ability to traverse (++ and *)
 * The most obvious form of iterator is a pointer.
 * 
 * Iterators are classified into five categories based on their provided functionality.
 * ------------------------------------------------------------------------------------
 */
#include <iterator>


#include <algorithm>   // a collection of functions on ranges of elements, designed for STL
#include <numeric>     // some numeric algorithm - accumulate/adjacent_difference/inner_product/partial_sum. More like scientific computation
#include <functional>  // predefined functors



/********
 * vector
 ********/
vector<int> vec;   // vec.size() == 0
vec.push_back(4);
vec.push_back(1);
vec.push_back(8);  // vec: {4, 1, 8};    vec.size() == 3

/*
 * AW - both [] and at() returns the reference to the pointed element.
 * -------------------------------------------------------------------
 */
cout << vec[2];     // 8  (no range check)
cout << vec.at(2);  // 8  (throw range_error exception of out of range) - out_of_range &e


// three different ways to traverse a vector
for (int i; i < vec.size(); i++) cout << vec[i] << " ";
for (vector<int>::iterator itr = vec.begin(); itr!= vec.end(); ++itr) cout << *itr << " ";  
for (auto &x: vec) cout << x << " "; // C++ 11

/* -------------------------------------------------------------
 * vector is a dynamically allocated contiguous array in memory.
 * Therefore, it can be passed to the regular C functions.
 * 
 * NOTES: the allocated memory can be reallocated, so the pointer
 *        might get invalidated in the future.
 * -------------------------------------------------------
 */
int* p = &vec[0];   p[2] = 6;


// Common member functions of all containers.
// vec: {4, 1, 8}
if (vec.empty()) { cout << "Not possible.\n"; }
cout << vec.size();   // 3
vector<int> vec2(vec);  // Copy constructor, vec2: {4, 1, 8}
vec.clear();    // Remove all items in vec;   vec.size() == 0
vec2.swap(vec);   // vec2 becomes empty, and vec has 3 items.

/* Properties of vector:
 * ---------------------
 * 1. fast insert/remove at the end: O(1)
 * 2. slow insert/remove at the begining or in the middle: O(n)
 * 3. slow search: O(n)
 */


/*******
 * deque
 *******/
deque<int> deq = { 4, 6, 7 };
deq.push_front(2);  // deq: {2, 4, 6, 7}
deq.push_back(3);   // deq: {2, 4, 6, 7, 3}

// Deque has similar interface with vector
cout << deq[1];  // 4


/* Properties of deque:
 * --------------------
 * 1. fast insert/remove at the begining and the end;
 * 2. slow insert/remove in the middle: O(n)
 * 3. slow search: O(n)
 */


/*
 * list
 *  -- double linked list
 */
list<int> mylist = {5, 2, 9 }; 
mylist.push_back(6);  // mylist: { 5, 2, 9, 6}
mylist.push_front(4); // mylist: { 4, 5, 2, 9, 6}

   
list<int>::iterator itr = find(mylist.begin(), mylist.end(), 2); // itr -> 2
mylist.insert(itr, 8);   // mylist: {4, 5, 8, 2, 9, 6}  
                         // O(1), faster than vector/deque

itr++;                   // itr -> 9
mylist.erase(itr);       // mylist: {4, 8, 5, 2, 6}   O(1)

// transfer the elements from mylist2 to mylist, and the time complexity is O(1)
mylist1.splice(itr, mylist2, itr_a, itr_b );   // O(1)

/* Properties of list:
 * -------------------
 * 1. fast insert/remove at any place: O(1)
 * 2. slow search: O(n)
 * 3. no random access, no [] operator.
 */




/*
 * Associative Container
 * ----------------------
 *    Always sorted, default criteria is <.
 *
 *    The keys are const, and cannot be modified. 
 *    The modification will invalidate the underneath data structure.
 *     
 *    No push_back(), push_front(). Only insert()
 *
 */


/*****
 * set
 *****
 * - No duplicates
 */
  set<int> myset;
  myset.insert(3);    // myset: {3}
  myset.insert(1);    // myset: {1, 3}
  myset.insert(7);    // myset: {1, 3, 7},  O(log(n))

  set<int>::iterator it;
  it = myset.find(7);  // O(log(n)), it points to 7
                       // Sequence containers don't even have find() member function

  pair<set<int>::iterator, bool> ret;
  ret = myset.insert(3);  // no new element inserted
  if (ret.second == false) it = ret.first; // "it" now points to element 3

  myset.insert(it, 9);  // myset:  {1, 3, 7, 9}   O(log(n)) => O(1)
                         // it points to 3

  myset.erase(it);         // myset:  {1, 7, 9}

  myset.erase(7);   // myset:  {1, 9}
     // Note: none of the sequence containers provide this kind of erase.



// multiset is a set that allows duplicated items
multiset<int> myset;

// set/multiset: value of the elements cannot be modified
*it = 10;  // *it is read-only


/* Properties of set:
 * ------------------
 * 1. Fast search: O(log(n))
 * 2. Traversing is slow (compared to vector & deque)
 * 3. No random access, no [] operator.
 */




/*****
 * map
 ***** 
 *  keys cannot be modified 
 *
 *  typedef pair<const Key, T> value_type; 
 *
 * - No duplicated key
 */
map<char, int> mymap;
mymap.insert(pair<char,int>('a',100));
mymap.insert(make_pair('z',200));

map<char, int>::iterator it = mymap.begin();
mymap.insert(it, pair<char,int>('b', 300));  // "it" is a hint, and it can speed up the insertion into O(1) time complexity

it = mymap.find('z');  // O(log(n))

// showing contents:
for(auto it = mymap.begin() ; it != mymap.end(); ++it)
    cout << it->first << " => " << it->second << endl;
  //cout << (*it).first << " => " << (*it).second << endl;


/**********
 * multimap
 **********
 *
 * multimap is a map that allows duplicated keys
 * 
 */
multimap<char, int> mymap;

// map/multimap: 
//  -- keys cannot be modified
//     type of *it:   pair<const char, int>
     (*it).first = 'd';  // Error


/*
 *  Unordered Container - C++ 11
 *   - Unordered set and multiset
 *   - Unordered map and multimap
 * 
 *  Order not defined, and may change overtime
 *  Default hash function defined for fundamental types and string.
 * 
 *  template < class Key,                                // unordered_map::key_type
 *         class T,                                      // unordered_map::mapped_type
 *         class Hash = hash<Key>,                       // unordered_map::hasher
 *         class Pred = equal_to<Key>,                   // unordered_map::key_equal - use operator== by default
 *         class Alloc = allocator< pair<const Key,T> >  // unordered_map::allocator_type
 *         > class unordered_map;
 *
 *  No subscript operator[] or at()  --- NO SUBSCRIPT OPERATOR[]?
 *  No push_back(), push_front()
 */

/*
 * unordered set
 * 
 * template < class Key,                     // unordered_set::key_type/value_type
 *         class Hash = hash<Key>,           // unordered_set::hasher
 *         class Pred = equal_to<Key>,       // unordered_set::key_equal
 *         class Alloc = allocator<Key>      // unordered_set::allocator_type
 *         > class unordered_set;
 */
  unordered_set<string> myset = { "red","green","blue" };
  unordered_set<string>::const_iterator itr = myset.find ("green"); // O(1)
  if (itr != myset.end())   // Important check 
     cout << *itr << endl;
  myset.insert("yellow");  // O(1)

  vector<string> vec = {"purple", "pink"};
  myset.insert(vec.begin(), vec.end());

  // Hash table specific APIs:
  cout << "load_factor = " << myset.load_factor() << endl;
  string x = "red";
  cout << x << " is in bucket #" << myset.bucket(x) << endl;
  cout << "Total bucket #" << myset.bucket_count() << endl;




// unordered multiset: unordered set that allows duplicated elements
// unordered map: unordered set of pairs
// unordered multimap: unordered map that allows duplicated keys
// hash collision => performance degrade


/* Properties of Unordered Containers:
 * -----------------------------------
 * 1. Fastest search/insert at any place: O(1)
 *     Associative Container takes O(log(n))
 *     vector, deque takes O(n)
 *     list takes O(1) to insert, O(n) to search
 *
 * 
 * 2. Unorderd set/multiset: element value cannot be changed - because underlying data structure needs to be maintained
 *    Unorderd map/multimap: element key cannot be changed.
 */


/*
 * Associative Array
 * - map and unordered map
 */
unordered_map<char, string> day = {{'S',"Sunday"}, {'M',"Monday"}};

cout << day['S'] << endl;    // No range check
cout << day.at('S') << endl; // Has range check

vector<int> vec = {1, 2, 3};
vec[5] = 5;   // Compile Error
day['W'] = "Wednesday";  // Inserting {'W', "Wednesday}

// pair<iterator,bool> insert ( const value_type& val );
// operator[] will return:
//       mapped_type& operator[] ( const key_type& k );
day.insert(make_pair('F', "Friday"));  // Inserting {'F', "Friday"}
day.insert(make_pair('M', "MONDAY"));  // Fail to modify, it's an unordered_map
day['M'] = "MONDAY";                   // Succeed to modify


void foo(const unordered_map<char, string>& m) {
   //m['S'] = "SUNDAY";    - ERROR
   //cout << m['S'] << endl; - ERROR
   auto itr = m.find('S');  // itr can be used to modify the content?
   if (itr != m.end())
      cout << *itr << endl;
}
foo(day);

/*******
 * Array
 *******
 */
int a[3] = {3, 4, 5};
array<int, 3> a = {3, 4, 5};
a.begin();
a.end();
a.size();
a.swap();
array<int, 4> b = {3, 4, 5};
// array<int, 3> and array<int, 4> are different data types.


/*
 * Container Adaptor
 * -----------------
 *  - Provide a restricted interface to meet special needs
 *  - Implemented with fundamental container classes
 *
 *  1. stack:  LIFO
 *  - template <class T, class Container = deque<T> > class stack;
 *
 *  2. queue:  FIFO
 *  - template <class T, class Container = deque<T> > class queue;
 *
 *  3. priority queue: first item always has the greatest priority 
 *  - template <class T, class Container = vector<T>,
 *    class Compare = less<typename Container::value_type>> class priority_queue;
 */


/*
 * Another way of categorizing containers:
 *
 * 1. Array based containers: vector, deque
 *
 * 2. Node base containers: list + associative containers + unordered containers
 *
 * Array based containers invalidates pointers:
 *    - Native pointers, iterators, references
 */

 vector<int> vec = {1,2,3,4};
 int* p = &vec[2];   // p points to 3
 vec.insert(vec.begin(), 0);
 cout << *p << endl;   // 2, or ? --undefined

