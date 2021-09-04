// https://www.geeksforgeeks.org/virtual-destructor/

/*
Deleting a derived class object using a pointer of base class type that has a non-virtual destructor results in undefined behavior. 
To correct this situation, the base class should be defined with a virtual destructor. 

Note: Base class pointer can point to the objet of derived class but not vice versa
*/

/*
CPP program without virtual destructor causing undefined behavior due to early binding concept.
*/

#include <bits/stdc++.h>
using namespace std;

class base {
public:
    base() {
        cout << "Constructing base \n";
    }
    ~base() {
        cout << "Destructing base \n";
    }
};

class derived: public base {
public:
    derived() { 
        cout << "Constructing derived \n"; 
    }
    ~derived() { 
        cout << "Destructing derived \n"; 
    }
};

int main() {
    derived *d = new derived();
    base *b = d;
    delete b;
}













/*
Correction by using virtual destructor in base class
*/

#include <bits/stdc++.h>
using namespace std;

class base {
public:
    base() {
        cout << "Constructing base \n";
    }
    virtual ~base() {
        cout << "Destructing base \n";
    }
};

class derived: public base {
public:
    derived() { 
        cout << "Constructing derived \n"; 
    }
    ~derived() { 
        cout << "Destructing derived \n"; 
    }
};

int main() {
    derived *d = new derived();
    base *b = d;
    delete b;
}
