/* Iterator  
 * #include <iterator>
 * -------------------
 *
 * An iterator is any object that, pointing to some elements in a range, has the ability to traverse the range of elements through ++ and *.
 * The most obvious form of iterator is a pointer. Based on the functionalities provided by the iterators, they can be classified into five
 * different categories. With the exception of output iterators, an iterator of a higher category provides all the operations of the iterators of  * lower categories.
 *
 *  1. input iterator - can only be read, and be moved forward
 *  2. output iterator - can only be written, and be moved forward
 *  3. forward iterator - containers: forward_list, unordered containers
 *  4. bidirectional iterator - containers: list, set/multiset, map/multimap
 *  5. random access iterator - containers: vector, deque, array
 *
 */

// 5. Random Access Iterator:  vector, deque, array
vector<int> itr;
itr = itr + 5;  // advance itr by 5
itr = itr - 4;  
if (itr2 > itr1) ...
++itr;   // faster than itr++
--itr;

// 4. Bidirectional Iterator: list, set/multiset, map/multimap
list<int> itr;
++itr;
--itr;

// 3. Forward Iterator: forward_list
forward_list<int> itr;
++itr;

// Unordered containers provide "at least" forward iterators.

// 2. Input Iterator: read and process values while iterating forward.
int x = *itr;

// 1. Output Iterator: output values while iterating forward.
*itr = 100;


// Every container has a iterator and a const_iterator
set<int>::iterator itr;
set<int>::const_iterator citr;  // Read_only access to container elements

set<int> myset = {2,4,5,1,9};
for (citr = myset.begin(); citr != myset.end(); ++citr) {
   cout << *citr << endl;
   //*citr = 3; - ERROR
}
for_each(myset.cbegin(), myset.cend(), MyFunction);  // vector::cbegin() only supported in C++ 11



// Iterator Functions:
advance(itr, 5);       // Move itr forward 5 spots.   itr += 5;
distance(itr1, itr2);  // Measure the distance between itr1 and itr2


/* Iterator Adaptor (Predefined Iterator)
 * ---------------------------------------
 * 
 * A special, more powerful iterator
 * 
 * 1. Insert iterator
 * 2. Stream iterator
 * 3. Reverse iterator
 * 4. Move iterator C++ 11
 *
 */

// 1. Insert Iterator:
vector<int> vec1 = {4,5};
vector<int> vec2 = {12, 14, 16, 18};
vector<int>::iterator it = find(vec2.begin(), vec2.end(), 16);
insert_iterator< vector<int>> i_itr(vec2, it);
copy(vec1.begin(),vec1.end(),  // source
     i_itr);                   // destination
     //vec2: {12, 14, 4, 5, 16, 18}
// Other insert iterators: back_insert_iterator, front_insert_iterator


// 2. Stream Iterator:
vector<string> vec4;
copy(istream_iterator<string>(cin), istream_iterator<string>(), 
            back_inserter(vec4));

copy(vec4.begin(), vec4.end(), ostream_iterator<string>(cout, " "));

// Make it terse:
copy(istream_iterator<string>(cin), istream_iterator<string>(), 
            ostream_iterator<string>(cout, " "));

/* sigature for std::copy() algorithms
 * -----------------------------------
 * template <class InputIterator, class OutputIterator>
 *     OutputIterator copy (InputIterator first, InputIterator last, OutputIterator result);
 * 
 */ 

// 3. Reverse Iterator:
vector<int> vec = {4,5,6,7};
reverse_iterator<vector<int>::iterator> ritr;
for (ritr = vec.rbegin(); ritr != vec.rend(); ritr++)
   cout << *ritr << endl;   // prints: 7 6 5 4

