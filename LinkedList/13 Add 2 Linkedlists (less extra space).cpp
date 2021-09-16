/*
Assumption:
Returning answer by modifying linkedlist 1 for space utilization
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->val = val;
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

Node* Add(Node* h1, Node* h2) {
    if (!h1) return h2;
    if (!h2) return h1;

    Node *l1 = reverseList(h1), *l2 = reverseList(h2);

    int carry = 0, total = 0;
    Node *res = l1, *prev;

    while (l1 && l2) {
        total = l1->val + l2->val + carry;
        l1->val = total % 10;
        carry = total / 10;

        prev = l1;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1) {
        total = l1->val + carry;
        l1->val = total % 10;
        carry = total / 10;

        prev = l1;
        l1 = l1->next;
    }
    while (l2) {
        total = l2->val + carry;
        prev->next = newNode(total % 10);
        carry = total / 10;

        prev = prev->next;
        l2 = l2->next;
    }
    while (carry) {
        prev->next = newNode(carry % 10);
        carry /= 10;

        prev = prev->next;
    }

    res = reverseList(res);
    return res;
}

int32_t main() {
    Node* head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);

    Node* head2 = newNode(1);
    head2->next = newNode(2);
    head2->next->next = newNode(0);
    head2->next->next->next = newNode(0);

    head1 = Add(head1, head2);

    if (!head1) cout << 0 << endl;

    while (head1) {
        cout << head1 -> val << " ";
        head1 = head1 -> next;
    }
}
