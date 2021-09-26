// https://leetcode.com/problems/min-stack/
// https://practice.geeksforgeeks.org/problems/special-stack/1
// https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/

// https://youtu.be/Trz7JM610Uc

/*
Design a data-structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() 
and an additional operation getMin() which should return minimum element from the SpecialStack. 
Your task is to complete all the functions, using stack data-Structure.
*/

// With extra space
struct MinStack {
    // normal stack
    stack<int> s;
    // supporting stack (stores min element)
    stack<int> ss;

    void push(int a) {
        s.push(a);
        if(ss.empty() || ss.top() >= a) {
            ss.push(a);
        }
    }

    int pop() {
        if(s.empty()) return -1;
        int x = s.top();
        s.pop();
        if(ss.top() == x) ss.pop();
    }

    int getMin() {
        if(ss.empty()) return -1;
        return ss.top();
    }

    bool isEmpty() {
        return s.empty();
    }

    bool isFull(int n) {
        return s.size() == n;
    }
};

void solve() {
    int x, y, z;
    MinStack s;
    s.push(3);
    s.push(5);
    cout << s.getMin() << endl;
    s.push(2);
    s.push(1);
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    s.pop();
}
















// With O(1) space
struct MinStack {
    // normal stack
    stack<int> s;
    int minElement;

    void push(int a) {
        if(s.empty()) {
            s.push(a);
            minElement = a;
        } else {
            if(a >= minElement) {
                s.push(a);
            } else {
                s.push(2*a - minElement);
                minElement = a;
            }
        }
    }

    int pop() {
        if(s.empty()) return -1;
        
        if(s.top() < minElement) {
            minElement = 2 * minElement - s.top();
        }
        s.pop();
    }

    int getMin() {
        if(s.empty()) return -1;
        return minElement;
    }

    int top() {
        if(s.empty()) return -1;
        
        if(s.top() < minElement) {
            return minElement;
        } else {
            return s.top();
        }
    }

    bool isEmpty() {
        return s.empty();
    }

    bool isFull(int n) {
        return s.size() == n;
    }
};

void solve() {
    int x, y, z;
    MinStack s;
    s.push(3);
    s.push(5);
    cout << s.getMin() << endl;
    s.push(2);
    s.push(1);
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    s.pop();
}
































#include <bits/stdc++.h>
using namespace std;

/* A simple stack class with basic stack funtionalities */
class Stack {
    static const int max = 100;
    int arr[max];
    int topIdx;
public:
    Stack() {
        topIdx = -1;
    }
    bool isEmpty() {
        return topIdx == -1;
    }
    bool isFull() {
        return topIdx == max - 1;
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow";
            abort();
        }
        int x = arr[topIdx];
        topIdx--;
        return x;
    }
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow";
            abort();
        }
        topIdx++;
        arr[topIdx] = x;
    }
    int top() {
        if (isEmpty()) {
            cout << "Stack Underflow";
            abort();
        }
        return arr[topIdx];
    }
};


class SpecialStack: public Stack {
    Stack st, minSt;
public:
    void push(int x) {
        st.push(x);
        if (minSt.isEmpty() || x <= minSt.top()) {
            minSt.push(x);
        }
    }
    int pop() {
        int x = st.pop();
        if (minSt.top() == x) {
            minSt.pop();
        }
        return x;
    }
    int getMin() {
        return minSt.top();
    }

};

int main() {
    SpecialStack s;
    s.push(20);
    s.push(30);
    s.push(10);
    cout << s.getMin() << endl;
    s.push(5);
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    return 0;
}













#include <bits/stdc++.h>
using namespace std;

/* A simple stack class with basic stack funtionalities */
class Stack {
    vector<int> arr;
public:
    Stack() {
        arr = {};
    }
    bool isEmpty() {
        return arr.empty();
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow";
            abort();
        }
        int x = arr.back();
        arr.pop_back();
        return x;
    }
    void push(int x) {
        arr.push_back(x);
    }
    int top() {
        if (isEmpty()) {
            cout << "Stack Underflow";
            abort();
        }
        return arr.back();
    }
};


class SpecialStack: public Stack {
    Stack st, minSt;
public:
    void push(int x) {
        st.push(x);
        if (minSt.isEmpty() || x <= minSt.top()) {
            minSt.push(x);
        }
    }
    int pop() {
        int x = st.pop();
        if (minSt.top() == x) {
            minSt.pop();
        }
        return x;
    }
    int getMin() {
        return minSt.top();
    }
};

int main() {
    SpecialStack s;
    s.push(20);
    s.push(30);
    s.push(10);
    cout << s.getMin() << endl;
    s.push(5);
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    return 0;
}
