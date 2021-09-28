// https://leetcode.com/problems/lfu-cache/
// https://youtu.be/0PSB9y8ehbk
// https://leetcode.com/problems/lfu-cache/discuss/937737/C%2B%2B%3A-O(1)-time-complexity-with-algorithm
// Page Replacement Algorithm


class LFUCache {
private:
    struct Node {
        int value;
        list<int>::iterator itr;
    };

    // <key, Node>
    unordered_map<int, Node> cache;
    // <key, freq>
    unordered_map<int, int> freq;
    // <freq, list<key>>
    unordered_map<int, list<int>> m_countKeyMap;
    int minFrequency;
    int cap;

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFrequency = 0;
    }

    int get(int key) {
        if (cache.find(key) == cache.end() || cap <= 0) return -1;

        // update frequency and return value
        put(key, cache[key].value);
        return cache[key].value;
    }

    void put(int key, int value) {
        if (cap <= 0) return;

        // If key is not present and capacity has exceeded,
        // then remove the key entry with least frequency
        // else just make the new key entry
        if (cache.find(key) == cache.end()) {
            if (cache.size() == cap) {
                int keyToDelete = m_countKeyMap[minFrequency].back();
                m_countKeyMap[minFrequency].pop_back();
                if (m_countKeyMap[minFrequency].empty()) {
                    m_countKeyMap.erase(minFrequency);
                }
                cache.erase(keyToDelete);
                freq.erase(keyToDelete);
            }
            cache[key].value = value;
            freq[key] = 0;
            minFrequency = 0;
            m_countKeyMap[freq[key]].push_front(key);
            cache[key].itr = m_countKeyMap[0].begin();
        }
        // Just update value and frequency
        else {
            m_countKeyMap[freq[key]].erase(cache[key].itr);
            if (m_countKeyMap[freq[key]].empty()) {
                if (minFrequency == freq[key]) {
                    minFrequency++;
                }
                m_countKeyMap.erase(freq[key]);
            }
            cache[key].value = value;
            freq[key]++;
            m_countKeyMap[freq[key]].push_front(key);
            cache[key].itr = m_countKeyMap[freq[key]].begin();
        }
    }
};
