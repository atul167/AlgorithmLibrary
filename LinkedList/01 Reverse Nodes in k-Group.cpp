// https://leetcode.com/problems/reverse-nodes-in-k-group/

 
// recursive soln
class Solution {
public:    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0; 
        ListNode *temp = head;
        while(temp && count < k) {
            temp = temp->next;
            count++;
        }
        
        // if we dont have enought nodes
        if(count < k) return head;
        
        ListNode *curr = head, *prev = NULL, *nxt = NULL;
        count = 0;
        // reversing the first K nodes
        while(curr and count < k) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            count++;
        }
        
        // if the next segment nodes is not null
        if(curr) head->next = reverseKGroup(curr, k);
        
        return prev;
    }
};





// recursive soln
class Solution {
public:
    ListNode* reverse(ListNode* head, int k) {
        ListNode *prev = NULL, *cur = head, *next = NULL;
        int cnt = 0;
        while (cur && cnt < k) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            cnt++;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        auto cur = head;
        for (int i = 0; i < k; ++i) {
            // nothing to do list too sort
            if (!cur) return head;
            cur = cur->next;
        }

        auto new_head = reverse(head, k);
        head->next = reverseKGroup(cur, k);
        return new_head;
    }
};
