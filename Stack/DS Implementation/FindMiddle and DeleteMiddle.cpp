// https://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/

/*
Implement a stack which will support following operations in O(1) time complexity? 
1) push() which adds an element to the top of stack. 
2) pop() which removes an element from top of stack. 
3) findMiddle() which will return middle element of the stack. 
4) deleteMiddle() which will delete the middle element. 
*/


/* C++ Program to implement a stack that supports findMiddle() and deleteMiddle in O(1) time */
#include <bits/stdc++.h>
using namespace std;

/* A Doubly Linked List Node */
class DLLNode {
public:
    int data;
    DLLNode *prev, *next;
    DLLNode(int d) {
        data = d;
        prev = next = NULL;
    }
};

/* Representation of the stack data structure that supports findMiddle() in O(1) time.
The Stack is implemented using Doubly Linked List.
It maintains pointer to head node and middle node and count of nodes */
class MyStack {
public:
    DLLNode *head, *mid;
    int count;

    MyStack() {
        count = 0;
        head = mid = NULL;
    };

    // adds elements at the beginning of doubly linkedlist
    void push(int data) {
        DLLNode* node = new DLLNode(data);

        /* Since we are adding at the beginning, prev is always NULL */
        node->prev = NULL;

        /* link the old list off the new DLLNode */
        node->next = head;

        /* Increment count of items in stack */
        count += 1;

        /* Change mid pointer in two cases
        1) Linked List is empty
        2) Number of nodes in linked list is odd */
        if (count == 1) {
            mid = node;
        } else {
            head->prev = node;

            // Update mid if count is even
            if (!(count & 1)) {
                mid = mid->prev;
            }
        }

        /* move head to point to the new DLLNode */
        head = node;
    }

    int pop() {
        /* Stack underflow */
        if (count == 0) {
            cout << "Stack is empty\n";
            return -1;
        }

        DLLNode* tempHead = head;
        int headValue = head->data;
        head = head->next;

        // If linked list doesn't become empty, update prev of new head as NULL
        if (head != NULL) {
            head->prev = NULL;
        }

        count -= 1;

        // update the mid pointer when we have odd number of elements in the stack,
        //i,e move down the mid pointer.
        if ((count) & 1) {
            mid = mid->next;
        }

        delete tempHead;
        return headValue;
    }

    int findMiddle() {
        if (count == 0) {
            cout << "Stack is empty now\n";
            return -1;
        }
        return mid->data;
    }

    int deletemiddle() {
        int midValue = mid->data;
        DLLNode *tempMid = mid;
        mid->prev->next = mid->next;
        mid->next->prev = mid->prev->next;

        mid = mid->next;
        delete tempMid;
        return midValue;
    }
};

int main() {
    MyStack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    st.push(66);
    st.push(77);

    cout << "Middle Element = " << st.findMiddle() << endl;
    cout << "Item popped = " << st.pop() << endl;
    cout << "Item popped = " << st.pop() << endl;
    cout << "Item popped = " << st.pop() << endl;
    cout << "Middle Element = " << st.findMiddle() << endl;
    cout << "Deleted Middle Element = " << st.deletemiddle() << endl;
    cout << "Middle Element = " << st.findMiddle() << endl;
    return 0;
}
