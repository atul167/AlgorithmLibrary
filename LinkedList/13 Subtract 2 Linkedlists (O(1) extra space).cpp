/*
Assumption:
head1 linkedlist numeric value >= head2 linkedlist numeric value
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

Node* reverseList(Node* head) {
    if (!head) return head;

    Node *prev = NULL, *cur = head, *nxt = NULL;
    while (cur) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

Node* Subtract(Node* h1, Node* h2) {
    if (!h1 || !h2) return h1;
    Node *rH1 = reverseList(h1);
    Node *rH2 = reverseList(h2);
    Node *temp1 = rH1;
    Node *temp2 = rH2;

    int carry = 0;
    while (temp1 && temp2) {
        int cur1 = (temp1 -> data);
        int cur2 = (temp2 -> data);
        if (carry) {
            cur1--;
            carry = 0;
        }
        if (cur1 < cur2) {
            cur1 += 10;
            carry = 1;
        }

        int res = cur1 - cur2;
        temp1 -> data = res;
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
    while (temp1) {
        int cur1 = (temp1 -> data);
        int cur2 = 0;
        if (carry) {
            cur1--;
            carry = 0;
        }
        if (cur1 < cur2) {
            carry = 1;
            cur1 += 10;
        }

        int res = cur1 - cur2;
        temp1 -> data = res;
        temp1 = temp1 -> next;
    }

    rH1 = reverseList(rH1);
    // removing leading zeros from answer
    while (rH1 -> next && rH1 -> data == 0) {
        rH1 = rH1 -> next;
    }
    return rH1;
}

int32_t main() {
    Node* head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);

    Node* head2 = newNode(1);
    head2->next = newNode(2);
    head2->next->next = newNode(0);

    head1 = Subtract(head1, head2);

    if (!head1) cout << 0 << endl;

    while (head1) {
        cout << head1 -> data << " ";
        head1 = head1 -> next;
    }
}


/*
10040
42

3 
*/
