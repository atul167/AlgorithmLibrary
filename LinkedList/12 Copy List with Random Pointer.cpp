// https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> vis;
    
    Node* cloneList(Node* head) {
        if(!head) return head;
        if(vis[head]) return vis[head];
        
        Node* cloned = new Node(head->val);
        vis[head] = cloned;
        
        if(head->next) {
            cloned->next = cloneList(head->next);
        }
        
        return cloned;
    }

    void cloneRandom(Node* head, Node* clonedRoot) {
        if(!head) return;
        
        if(head->random) {
            clonedRoot->random =  vis[head->random];
        }
        
        cloneRandom(head->next, clonedRoot->next);
    }
    
    Node* copyRandomList(Node* head) {
        Node* cloned = cloneList(head);
        cloneRandom(head, cloned);
        return cloned;
    }
};
