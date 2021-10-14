// https://leetcode.com/problems/reverse-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return head;
        }
        ListNode *prev = NULL, *cur = head, *nxt = NULL;
        while(cur != NULL){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
};





// recursive

ListNode* reverseList(ListNode* head) {
  // too confusing to always call current node "head"
  ListNode* current = head;

  // new head found
  if (!current || !current->next) return current;

  // search for new head via recursion
  ListNode* new_head = reverseList(current->next);

  // reverse list: make next node point to this node
  current->next->next = current;

  // tricky part: make current node point to null. Only stays null for new tail
  // otherwise, the line above sets this node to point to the previous node
  // on the next recursion
  current->next = NULL;

  // continue to pass new head along to original function call
  return new_head;
}
