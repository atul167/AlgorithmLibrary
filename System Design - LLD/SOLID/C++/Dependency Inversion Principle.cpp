// https://hackernoon.com/solid-design-dependency-inversion-principle-in-c-weq3ujp
// http://www.vishalchovatiya.com/dependency-inversion-principle-in-cpp-solid-as-a-rock/


/*
Intent
--------
1. High-level modules should not depend on low-level modules. Both should depend on abstractions.
2. Abstractions should not depend on details. Details should depend on abstractions.

What are the High-level & Low-level modules?
---------------------------------------------
High-level modules: 
describes operations which is more abstract in nature & contain more complex logic. These modules orchestrate low-level modules in our application.

Low-level modules: 
describes implementations more specific & individual to components focusing on details & smaller parts of the application. 
These modules are used inside the high-level modules.
*/





// Motivation: Violating Dependency Inversion Principle

#include <bits/stdc++.h>
using namespace std;

enum Relationship { parent, child, sibling };

class Person {
public:
    string name;
};

// Low-level <<<<<<<<<<<<-------------------------
class Relationships {
public:
    vector<tuple<Person, Relationship, Person>> m_relations;

    void add_parent_and_child(const Person &parent, const Person &child) {
        m_relations.push_back({parent, Relationship::parent, child});
        m_relations.push_back({child, Relationship::child, parent});
    }
};

// High-level  <<<<<<<<<<<<------------------------
class Research {
public:
    Research(const Relationships &relationships) {
        for (auto && [first, rel, second] : relationships.m_relations) {
            if (first.name == "John" && rel == Relationship::parent)
                cout << "John has a child called " << second.name << endl;
        }
    }
};

int main() {
    Person parent{"John"};
    Person child1{"Chris"};
    Person child2{"Matt"};

    Relationships relationships;
    relationships.add_parent_and_child(parent, child1);
    relationships.add_parent_and_child(parent, child2);

    Research _(relationships);

    return EXIT_SUCCESS;
}

/*
John has a child called Chris
John has a child called Matt
*/



/*
1) When later on the container of Relationships changes from vector to set or any other container, 
   you need to change in many places which isn’t a very good design. 
   Even if just the name of data member i.e. Relationships::m_relations changes, you will find yourself breaking other parts of code.
2) As you can see Low-level module i.e. Relationships directly depend on High-level module i.e. Research which is essentially a violation of DIP.
*/













// Solution: Example of Dependency Inversion Principle in C++

#include<bits/stdc++.h>
using namespace std;

enum Relationship { parent, child, sibling };

class Person {
public:
    string name;
};

class RelationshipBrowser {
public:
    virtual vector<Person> find_all_children_of(const string &name) = 0;
};

// Low-level <<<<<<<<<<<<<<<------------------------
class Relationships : public RelationshipBrowser {
public:
    vector<tuple<Person, Relationship, Person>> m_relations;

    void add_parent_and_child(const Person &parent, const Person &child) {
        m_relations.push_back({parent, Relationship::parent, child});
        m_relations.push_back({child, Relationship::child, parent});
    }

    vector<Person> find_all_children_of(const string &name) {
        vector<Person> result;
        for (auto && [first, rel, second] : m_relations) {
            if (first.name == name && rel == Relationship::parent) {
                result.push_back(second);
            }
        }
        return result;
    }
};

// High-level <<<<<<<<<<<<<<<----------------------
class Research {
public:
    Research(RelationshipBrowser &browser) {
        for (auto &child : browser.find_all_children_of("John")) {
            cout << "John has a child called " << child.name << endl;
        }
    }
};

int main() {
    Person parent{"John"};
    Person child1{"Chris"};
    Person child2{"Matt"};

    Relationships relationships;
    relationships.add_parent_and_child(parent, child1);
    relationships.add_parent_and_child(parent, child2);

    Research _(relationships);

    return EXIT_SUCCESS;
}

/*
John has a child called Chris
John has a child called Matt
*/



/*
1) Rather we should create an abstraction and bind Low-level & High-level module to that abstraction.
2) Now no matter, the name of container or container itself changes in Low-level module, 
   High-level module or other parts of code which followed DIP will be in-tact.
3) The Dependency Inversion Principle (DIP) suggest that the most flexible systems are those in which 
   source code dependencies refer only to abstractions, not to concretions.
4) This is the reason why most experienced dev uses STL or library functions along with generic containers. 
   Even using an auto keyword at appropriate places may help in creating generic behaviour with less fragile code.
5) There are many ways you can implement DIP, as long as C++ concerns most people use static polymorphism(i.e. CRTP unless they need dynamic one), 
   template specialization, Adapter Design Pattern, type-erasure, etc.
*/
