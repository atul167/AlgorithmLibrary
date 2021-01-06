// https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// not memory efficient
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        
        map<ListNode*, int> mp;
        
        while(head) {
            if(mp[head]) return true;
            mp[head] = 1;
            head = head->next;
        }
        
        return false;
    }
};


// slow fast pointer
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        
        ListNode *slow = head, *fast = head;
        
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) return true;
        }
        
        return false;
    }
};
