// https://www.geeksforgeeks.org/smart-pointers-cpp/
// https://youtu.be/UOB7-B2MfwA

/*
Types of Smart Pointers
1. unique_ptr
2. shared_ptr
3. weak_ptr 
*/


#include <bits/stdc++.h>
using namespace std;

class Entity {
public:
    Entity() {
        cout << "Constructor\n";
    }
    ~Entity() {
        cout << "Destructor\n";
    }
};

int main() {
    unique_ptr<Entity> pUnique0 = make_unique<Entity>();
    // we cannot copy it (below line will throw an error)
    // unique_ptr<Entity> pUnique1 = pUnique0;
}

/*
Constructor
Destructor
*/







#include <bits/stdc++.h>
using namespace std;

class Entity {
public:
    Entity() {
        cout << "Constructor\n";
    }
    ~Entity() {
        cout << "Destructor\n";
    }
};

int main() {
    shared_ptr<Entity> pShared0 = make_shared<Entity>();
    shared_ptr<Entity> pShared1 = pShared0;
    cout << pShared0.use_count() << endl;
}

/*
Constructor
2
Destructor
*/








#include <bits/stdc++.h>
using namespace std;

class Entity {
public:
    Entity() {
        cout << "Constructor\n";
    }
    ~Entity() {
        cout << "Destructor\n";
    }
};

int main() {
    shared_ptr<Entity> pShared0 = make_shared<Entity>();
    weak_ptr<Entity> pWeak1 = pShared0;
    cout << pShared0.use_count() << endl;
}

/*
Constructor
1
Destructor
*/
