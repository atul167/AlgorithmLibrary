// https://leetcode.com/problems/lru-cache/
// https://youtu.be/xDEuM5qa0zg


class LRUCache {
private:
    struct node {
        int key;
        int val;
        node* prev;
        node* next;
        node(int _key, int _val) {
            key = _key;
            val = _val;
            next = prev = nullptr;
        }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    int cap;
    unordered_map<int, node*> cache;
    
    void addNode(node* newnode) {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deleteNode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        delete delnode;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;    
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!cache.count(key)) return -1;

        node* resnode = cache[key];
        int value = resnode->val;
        cache.erase(key);
        deleteNode(resnode);
        
        addNode(new node(key, value));
        cache[key] = head->next;
        return value;
    }
    
    void put(int key, int value) {
        if(cache.count(key)) {
            node* existingnode = cache[key];
            cache.erase(key);
            deleteNode(existingnode);
        }
        if(cache.size() == cap) {
          cache.erase(tail->prev->key);
          deleteNode(tail->prev);
        }
        
        addNode(new node(key, value));
        cache[key] = head->next; 
    }
};
