/*
 * Algorithms - mostly loops
 * -------------------------
 *
 * The header <algorithm> defines a collection of functions especially designed to be used on ranges of elements.
 * A range is any sequence of objects that can be accessed through iterators or pointers,
 * such as an array or an instance of some of the STL containers
 *
 * All range iterators for algorithms are in half-open way: [begin, end)
 * 
 * NOTES: algorithms operate through iterators directly on the values, 
 *        not affecting in any way the structure of any possible container (it never affects the size or storage allocation of the container).
 *
 *
 */
vector<int> vec = { 4, 2, 5, 1, 3, 9};   
vector<int>::iterator itr = min_element(vec.begin(), vec.end()); // itr -> 1
sort(vec.begin(), itr);  // vec: { 2, 4, 5, 1, 3, 9}
reverse(itr, vec.end());  // vec: { 2, 4, 5, 9, 3, 1}   itr => 9

/*
 * template <class InputIterator, class OutputIterator>
 *      OutputIterator copy (InputIterator first, InputIterator last, OutputIterator result);
 * ------------------------------------------------------------------------------------------
 *
 * - Copy the elements in the range [first,last) into the range beginning at result 
 * - if used with insert_iterator, it will cause the result container to expand one by one - inefficient.
 *
 */ 

// Note 2:
vector<int> vec2(3);
copy(itr, vec.end(),  // Source
     vec2.begin());   // Destination
     //vec2 needs to have at least space for 3 elements. - undefined behavior if vec2 does not have enough space


// Note 3:
vector<int> vec3;
copy(itr, vec.end(), back_inserter(vec3));  // Inserting instead of overwriting 
                  // back_insert_iterator Not efficient - expand the vec3 one by one for each insert

// preferred solition comparing to the std::copy. the container size can be increased effectively based on the #elems.
vec3.insert(vec3.end(), itr, vec.end());  // Efficient and safe


// Note 4: Algorithm with function
bool isOdd(int i) {
   return i%2;
}

int main() {
   vector<int> vec = {2, 4, 5, 9, 2}
   vector<int>::iterator itr = find_if(vec.begin(), vec.end(), isOdd); 
   	                             // itr -> 5
}

// Note 5: Algorithm with native C++ array
int arr[4] = {6,3,7,4};
sort(arr, arr+4);

// Vector pitfalls:
// -----------------
// Reallocate vector
// Remove items 

/*
 * Reasons to use C++ standard library:
 * ------------------------------------
 * 1. Code reuse, no need to re-invent the wheel.
 * 2. Efficiency (fast and use less resources). Modern C++ compiler are usually
 *    tuned to optimize for C++ standard library code.
 * 3. Accurate, less buggy.
 * 4. Terse, readable code; reduced control flow.
 * 5. Standardization, guarenteed availability
 * 6. A role model of writing library.
 * 7. Good knowledge of data structures and algorithms.
 */
