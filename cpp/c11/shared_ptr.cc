/*
 * Smart pointer
 * 
 * pitfalls for raw pointer
 * ------------------------
 * 1. when a pointer outlives pointee - dangling pointer problem
 * 2. when a pointee outlives all its pointers - resource leak problem
 * 
 * Smart Pointers: Make sure the lifetime of a pointer and pointee match.
 */

class Dog {
    string m_name;
  public:
      void bark() { cout << "Dog " << m_name << " rules!" << endl; }
      Dog(string name) { cout << "Dog is created: " << name << endl; m_name = name; }
      Dog() { cout << "Nameless dog created." << endl; m_name = "nameless"; }
     ~Dog() { cout << "dog is destroyed: " << m_name << endl; }
	  //void enter(DogHouse* h) { h->setDog(shared_from_this()); }  // Dont's call shared_from_this() in constructor
};

class DogHouse {
    shared_ptr<Dog> m_pD;
public:
    void setDog(shared_ptr<Dog> p) { m_pD = p; cout << "Dog entered house." << endl;}
};

int main ()
{

    shared_ptr<Dog> pD = make_shared<Dog>("Gunner"); // faster and safer
    // shared_ptr<Dog> pD(new Dog("Gunner"));
    // shared_ptr<Dog> pD = make_shared<Dog>(new Dog("Gunner")); - this calls different ctor, and it works as well.
    
    pD->bark();
    // (*pD).bark(); - Okay. dereference operator is overloaded as well.
    
    DogHouse* ph = new DogHouse();
    ph->setDog(pD);
    delete ph;   // - no resource leak here, even the shared_ptr<Dog> inside DogHouse is not paid special attention

    /* -------------------------------------------------
     * Dog("Smokey") is a temporary object on the stack.
     * 
     *     ----
     *     |  |----> mem on heap
     *     ----
     *    smart pointer
     * -------------------------------------------------*/
    // auto pD2 = make_shared<Dog>(Dog("Smokey") ); // ERROR - Don't use shared pointer for an object on stack.

    /* -----------------------------------------------------------------
     * when using smart pointers, try to avoid raw pointers in all means
     * -----------------------------------------------------------------*/
    // Dog* p = new Dog();
    // shared_ptr<int> p1(p);
    // shared_ptr<int> p2(p);  // Erroneous - p will be deleted twice by the dtors of p1 and p2

   
    shared_ptr<int> sp;  // sp is null
    sp.reset(new int);  
    *sp = 10;
    sp.reset(new int);   // deleted the first managed int
    *sp = 20;
    sp.reset();         // deletes the managed object


    shared_ptr<Dog> sp_d(new Dog("Kevin"));
    shared_ptr<Dog> sp_d1(new Dog("Bryan"));
    sp_d1 = sp_d; 
    /* -----------------------
     * 1. sp_d.use_count() = 2
     * 2. Dog("Bryan") will be freed
     *    cout << sp_d1.use_count() << endl; - use_count = 2
     * -----------------------------
     */
    
    /* 
     * when it comes to the features of smart pointer, we use . operator
     * To manipulate the object pointed by the smart pointer, we use operator ->.
     */

    
    shared_ptr<Dog> pD3;
    pD3.reset(new Dog("Tank"));
    pD3.reset();  // Dog destroyed. Same effect as: pD3 = nullptr;

    //pD3.reset(pD.get());  // crashes - pD and pD3 will double delete the managed object
    

    /* Specify customized deleter */
    shared_ptr<Dog> pD4(new Dog("Victor"), 
                        [](Dog* p) {cout << "deleting a dog.\n"; delete p;}
                        );

    /* default deleter is operator delete */
    // shared_ptr<Dog> pDD(new Dog[3]);  // default deleter will have memory leak on Dog[1] and Dog[2]
    shared_ptr<Dog> pDD(new Dog[3], [](Dog* p) {delete[] p;});

    {
        Dog *d = p1.get(); // returns the raw pointer - try to avoid it.
        delete d; 
        shared_ptr<Dog> p2(d); // the dtor of p2 will delete one more time, cause error
    }


/* weak_ptr
 * --------
 *  A companion class, which is a weak reference to an object managed by a shared_ptr.
 */
class Dog {
    //shared_ptr<Dog> m_pFriend; - can cause memory leak problem by mutal reference
    weak_ptr<Dog> m_pFriend; // Dog *m  - weak_ptr has no deleter
    string m_name;

  public:
    void bark() { cout << "Dog " << m_name << " rules!" << endl; }
    Dog(string name) { cout << "Dog is created: " << name << endl; m_name = name; }
    ~Dog() { cout << "dog is destroyed: " << m_name << endl; }
    void makeFriend(shared_ptr<Dog> f) { m_pFriend = f; }
    
    /* 
     * In order to access the object pointed by weak_ptr, we need to use weak_ptr<T>::lock().
     *     - lock() will create a shared_ptr out of the weak_ptr
     *     - make sure the shared_ptr is still valid, and the object will be not deleted  - only when no shared_ptr is pointing
     *
     * shared_ptr<element_type> lock() const noexcept;
     * -----------------------------------------------
     * Returns a shared_ptr with the information preserved by the weak_ptr object if it is not expired.
     *
     *
     * how to create a weak_ptr? weak_ptr is always a companion class with shared_ptr.
     * -------------------------------------------------------------------------------
     *     std::shared_ptr<int> shared = make_shared<int>(10);
     *     std::weak_ptr<int> weak(shared);
     */
    void showFriend() { 
                         if (!m_pFriend.expired()) cout << "My friend is: " << m_pFriend.lock()->m_name << endl;
                         cout << " He is owned by " << m_pFriend.use_count() << " pointers." << endl; }
};

int main ()
{
    shared_ptr<Dog> pD(new Dog("Gunner"));
    shared_ptr<Dog> pD2(new Dog("Smokey"));
    pD->makeFriend(pD2);
    pD2->makeFriend(pD);  // will cause memory leak problem if Dog::m_pFriend is defined as shared_ptr<T>
    
    pD->showFriend();
}




/* unique_ptr
 * ----------
 *     - owns the object to which it points exclusively - no copy and assignment is allowed.
 *     - exclusive owenership, light weight smart pointer
 */
class Dog {
    // Bone* pB; - SHOULD BE AVOIDED BY ALL MEANS!!
    unique_ptr<Bone> pB;  // This prevents memory leak even constructor fails.
    string m_name;

public:
    void bark() { cout << "Dog " << m_name << " rules!" << endl; }
    Dog() { pB = new Bone(); cout << "Nameless dog created." << endl; m_name = "nameless"; }
    Dog(string name) { cout << "Dog is created: " << name << endl; m_name = name; }
    ~Dog() { delete pB; cout << "dog is destroyed: " << m_name << endl; }
};

void test() {
    
    // Dog* pD = new Dog("Gunner");
    // pD does a bunch of different things
    // delete pD;   

    unique_ptr<Dog> pD(new Dog("Gunner"));
    
    pD->bark();

    /*
     * pointer release() noexcept;
     * ---------------------------
     * Releases ownership of its stored pointer, by returning its value and replacing it with a null pointer.
     * This call does not destroy the managed object, but the unique_ptr object is released from the responsability of deleting the object. 
     * Some other entity must take responsibility for deleting the object at some point.
     *
     */
    // Dog* p = pD.release();
    // shared_ptr.get() does not give up ownership, but unique_ptr gives up the ownership
 
    pD = nullptr; // pD.reset() equivalanet
    // pD.reset(new Dog("Smokey"));
    
    if(!pD) {
        cout << "pD is empty.\n";
    }
    
}

void f(unique_ptr<Dog> p) {
    p->bark();
}

unique_ptr<Dog> getDog() {
    unique_ptr<Dog> p(new Dog("Smokey"));
    return p;
}

void test2() {
    unique_ptr<Dog> pD(new Dog("Gunner"));
    unique_ptr<Dog> pD2(new Dog("Smokey"));
    pD2 = move(pD);
    // 1. Smokey is destroyed
    // 2. pD becomes empty.
    // 3. pD2 owns Gunner.

    pD2->bark();
//    f(move(pD));
//    if (!pD) {
//        cout << "pD is empty.\n";
//    }
//    
//    unique_ptr<Dog> pD2 = getDog();
//    pD2->bark();
    
    // unique_ptr<T[]> does not need to specify extra deleter.
    // shared_ptr<T> pDD(new T[3], [](T* p) {delete[] p;});
    unique_ptr<Dog[]> dogs(new Dog[3]);
    dogs[1].bark();
    // (*dogs).bark(); // * is not defined
}

void test3() {
    // prevent resource leak even when constructor fails
}


int main ()
{
    test2();
}
