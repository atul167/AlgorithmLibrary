// https://leetcode.com/problems/lru-cache/
// https://www.geeksforgeeks.org/lru-cache-implementation/
// https://youtu.be/xDEuM5qa0zg -> Take U Forward

/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
Implement the LRUCache class:

LRUCache(int capacity): Initialize the LRU cache with positive size capacity.
int get(int key): Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value): Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. 
                              If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.
*/


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
        
        int value = cache[key].val;
        dq.erase(cache[key].itr);
        cache.erase(key);
        
        dq.push_front(key);
        cache[key] = {value, dq.begin()};
        return value;
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


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
