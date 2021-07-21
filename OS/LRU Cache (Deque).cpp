// https://leetcode.com/problems/lru-cache/
// https://www.geeksforgeeks.org/lru-cache-implementation/


class LRUCache {
public:
    struct Node {
        int value;
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
        
        dq.erase(cache[key].itr);
        dq.push_front(key);
        cache[key].itr = dq.begin();
        return cache[key].value;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            if (cache.size() == cap) {
                cache.erase(dq.back());
                dq.pop_back();
            }
        } else {
            dq.erase(cache[key].itr);
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
