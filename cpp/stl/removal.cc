/* ------------------------------------
 * NOTES ON REMOVE FOR STL CONTAINERS
 * ------------------------------------*/

 // Remove from Vector or Deque
  vector<int> vec = {1, 4, 1, 1, 1, 12, 18, 16}; // To remove all '1'
  for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
     if ( *itr == 1 ) {
        vec.erase(itr); // AW: erase() in vector will invalidate existing iterators
     }
  }   // vec: { 4, 12, 18, 16}
  // Complexity: O(n*m)  AW - where m is the #1s.


  
  // AW: remove() from algorithm does not know how to modify the
  // the data structure of the container, so it moves the elements
  // around instead of deleting them 
  remove(vec.begin(), vec.end(), 1);  // O(n) 
                                      // vec: {4, 12, 18, 16, ?, ?, ?, ?}
  vector<int>::iterator newEnd = remove(vec.begin(), vec.end(), 1);   // O(n)
  vec.erase(newEnd, vec.end());  


  // Similarly for algorithm: remove_if() and unique()
  // vec still occupy 8 int space: vec.capacity() == 8

  vec.shrink_to_fit();   // C++ 11
  // Now vec.capacity() == 4 

  // For C++ 03:
  // AW - create an temperoray vector using the vec,
  //      and swap it into the original vec
  vector<int>(vec).swap(vec); // Release the vacant memory



/*
 * Remove from List
 */
  list<int> mylist = {1, 4, 1, 1, 1, 12, 18, 16};

  // option1 
  list<int>::iterator newEnd = remove(mylist.begin(), mylist.end(), 1);  
  mylist.erase(newEnd, mylist.end());

  // option2 - preferred option
  // --------------------------
  // AW - Removes from the container all the elements that compare equal to val. 
  // This calls the destructor of these objects and 
  // reduces the container size by the number of elements removed.
  // 
  // similar function remove_if(pred)
  mylist.remove(1);  // faster

 

/*
 * Remove from associative containers or unordered containers
 */
  multiset<int> myset = {1, 4, 1, 1, 1, 12, 18, 16};

  multiset<int>::iterator newEnd = remove(myset.begin(), myset.end(), 1);  
  myset.erase(newEnd, myset.end()); // O(n)


  // AW - preferred option
  myset.erase(1); // O(log(n)) or O(1)

/* --------------------------------------------------
 * vector - std:remove() and vector::erase()
 * list/map/set/unordered_map/unordered_set
 * -- use its own erase() and remove() for efficiency
 * -------------------------------------------------- */





// *****************************************
// Remove and do something else with the elem
// *****************************************

// Associative Container:
multiset<int> s = {1, 4, 1, 1, 1, 12, 18, 16};;

// AW - ERROR
multiset<int>::iterator itr;
for (itr=s.begin(); itr!=s.end(); itr++) {
   if (*itr == 1) {
      s.erase(itr); // itr will be invalidated after erase()      
      cout << "Erase one item of " << *itr << endl;
   } 
}

// First erase OK; second one is undefined behavior


//Solution:
//AW - erase() does not invalidate the remaining iterators
multiset<int>::iterator itr;
for (itr=s.begin(); itr!=s.end(); ) {
   if (*itr == 1) {
      cout << "Erase one item of " << *itr << endl;
      s.erase(itr++);
   } else {
      itr++;
   }
}


// Sequence Container: - AW ERROR solution
vector<int> v = {1, 4, 1, 1, 1, 12, 18, 16};
vector<int>::iterator itr2;
for (itr2=v.begin(); itr2!=v.end(); ) {
   if (*itr2 == 1) {
      cout << "Erase one item of " << *itr2 << endl;
      // after erasing an elem, the remaining iterators are invalidated in vector case
      // so itr2+1 is invalid as well. - vector is stored continiously
      v.erase(itr2++); 
   } else {
      itr2++;
   }
}


// Sequence container and unordered container's erase() returns  
// iterator pointing to next item after the erased item.

//Solution:
for (itr2=v.begin(); itr2!=v.end(); ) {
   if (*itr2 == 1) {
      cout << "Erase one item of " << *itr2 << endl;
      itr2 = v.erase(itr2);
   } else {
      itr2++;
   }
}

// *********************************************
// 1. Sequence container and unordered container's erase() returns the next 
//    iterator after the erased item.
// 2. Associative container's erase() returns nothing.
// 
// *********************************************

vector<int> c = {1, 4, 1, 1, 1, 12, 18, 16};

// Use Algorithm
bool equalOne(int e) {
   if (e == 1) {
      cout << e << " will be removed" << endl;
      return true;
   }
   return false;
}
auto itr = remove_if(c.begin(), c.end(), equalOne);
c.erase(itr, c.end());



// Use bind():
bool equalOne(int e, int pattern) {
   if (e == pattern) {
      cout << e << " will be removed" << endl;
      return true;
   }
   return false;
}
remove_if(v.begin(), v.end(), bind(equalOne, placeholders::_1, 1));



// Lambda:
auto itr = remove_if(v.begin(), v.end(), 
      [](int e){ 
         if(e == 1) {
            cout << e << " will be removed" <<endl; return true; 
         } 
      } 
   );

/* --------------------------------------------------
 * if you need to remove elements mannully, then make
 * sure the remaining iterators are still valid for use.
 *
 * for vector, vector::erase() will invalidate remaining 
 * remaing iterators, so make sure to catch the new 
 * iterator using itr = vector::erase()
 * -- applies to list as well.
 *
 *    iterator erase (const_iterator position);
 *    iterator erase (const_iterator first, const_iterator last);
 *
 *    it = vec.erase(it);
 *
 * in C++ 98
 * ---------
 * for set/map/unordered_map/unordered_set
 * erase() will not invaliate the remaining iterators,
 * but it will for sure invalidate the current iterator.
 * so it makes sense to store the next iterator in advance.
 * 
 *     map.erase(it++);
 *
 * in C++ 11
 * ---------
 *     it = map.erase(it); works as well.
 * -------------------------------------------------- */
