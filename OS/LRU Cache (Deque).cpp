// https://leetcode.com/problems/lru-cache/
// https://www.geeksforgeeks.org/lru-cache-implementation/
// https://youtu.be/xDEuM5qa0zg -> Take U Forward
// Page Replacement Algorithm

/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
Implement the LRUCache class:

LRUCache(int capacity): Initialize the LRU cache with positive size capacity.
int get(int key): Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value): Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. 
                              If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.
*/


// Method 1: Using STL List or Deque

class LRUCache {
public:
    struct Node {
        int val;
        list<int>::iterator itr;
    };
    unordered_map<int, Node> cache;
    // old values move to back, new ones enter at front
    list<int> dq;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (!cache.count(key)) return -1;

        put(key, cache[key].val);
        return cache[key].val;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            dq.erase(cache[key].itr);
            cache.erase(key);
        }
        if (cache.size() == cap) {
            cache.erase(dq.back());
            dq.pop_back();
        }

        dq.push_front(key);
        cache[key] = {value, dq.begin()};
    }
};














// Method 2: Implementing our own deque list

struct Listnode {
    int data;
    Listnode *prev, *next;
    Listnode(int d) {
        data = d;
        prev = next = NULL;
    }
};

class List {
    Listnode *head, *tail;
    int count;
public:
    List() {
        head = new Listnode(-1);
        tail = new Listnode(-1);
        head->next = tail;
        tail->prev = head;
        count = 0;
    }
    int front() {
        if (count == 0) return -1;
        return head->next->data;
    }
    int back() {
        if (count == 0) return -1;
        return tail->prev->data;
    }
    Listnode* begin() {
        if (count == 0) return NULL;
        return head->next;
    }
    void push_front(int d) {
        Listnode *node = new Listnode(d);
        Listnode *temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
        count++;
    }
    void push_back(int d) {
        Listnode *node = new Listnode(d);
        Listnode *temp = tail->prev;
        tail->prev = node;
        node->next = tail;
        node->prev = temp;
        temp->next = node;
        count++;
    }
    void pop_front() {
        if (count == 0) return;
        if (count == 1) {
            Listnode *node = head->next;
            head->next = tail;
            tail->prev = head;
            delete node;
            count--;
            return;
        }

        Listnode *node = head->next;
        Listnode *temp = head->next->next;
        head->next = temp;
        temp->prev = head;
        delete node;
        count--;
    }
    void pop_back() {
        if (count == 0) return;
        if (count == 1) {
            Listnode *node = head->next;
            head->next = tail;
            tail->prev = head;
            delete node;
            count--;
            return;
        }

        Listnode *node = tail->prev;
        Listnode *temp = tail->prev->prev;
        tail->prev = temp;
        temp->next = tail;
        delete node;
        count--;
    }
    void erase(Listnode *node) {
        if (!node) return;
        Listnode *prev = node->prev, *next = node->next;
        prev->next = next;
        next->prev = prev;
        delete node;
        count--;
    }
    void print() {
        Listnode *temp = head->next;
        while (temp != tail) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class LRUCache {
public:
    struct Node {
        int val;
        Listnode *itr;
    };
    unordered_map<int, Node> cache;
    // old values move to back, new ones enter at front
    List dq;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (!cache.count(key)) return -1;

        put(key, cache[key].val);
        return cache[key].val;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            dq.erase(cache[key].itr);
            cache.erase(key);
        }
        if (cache.size() == cap) {
            cache.erase(dq.back());
            dq.pop_back();
        }

        dq.push_front(key);
        cache[key] = {value, dq.begin()};
    }
};
