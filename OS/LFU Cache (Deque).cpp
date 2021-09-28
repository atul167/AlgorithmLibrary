// https://leetcode.com/problems/lfu-cache/
// https://youtu.be/0PSB9y8ehbk
// https://leetcode.com/problems/lfu-cache/discuss/937737/C%2B%2B%3A-O(1)-time-complexity-with-algorithm

class LFUCache {
private:
    struct Node {
        int value;
        list<int>::iterator itr;
    };
    
    // <key, Node>
    unordered_map<int, Node> m_values;
    // <key, freq>
    unordered_map<int, int> m_counts;
    // <freq, list<key>>
    unordered_map<int, list<int>> m_countKeyMap;
    int m_lowestFrequency;
    int m_maxCapacity;

public:
    LFUCache(int capacity) {
        m_maxCapacity = capacity;
        m_lowestFrequency = 0;
    }

    int get(int key) {
        if (m_values.find(key) == m_values.end() || m_maxCapacity <= 0) return -1;
        
        // update frequency and return value
        put(key, m_values[key].value);
        return m_values[key].value;
    }

    void put(int key, int value) {
        if (m_maxCapacity <= 0) return;

        // If key is not present and capacity has exceeded,
        // then remove the key entry with least frequency
        // else just make the new key entry
        if (m_values.find(key) == m_values.end()) {
            if (m_values.size() == m_maxCapacity) {
                int keyToDelete = m_countKeyMap[m_lowestFrequency].back(); 
                m_countKeyMap[m_lowestFrequency].pop_back();
                if (m_countKeyMap[m_lowestFrequency].empty()) {
                    m_countKeyMap.erase(m_lowestFrequency);
                }
                m_values.erase(keyToDelete);
                m_counts.erase(keyToDelete);
            }
            m_values[key].value = value;
            m_counts[key] = 0;
            m_lowestFrequency = 0;
            m_countKeyMap[m_counts[key]].push_front(key);
            m_values[key].itr = m_countKeyMap[0].begin();
        }
        // Just update value and frequency
        else {
            m_countKeyMap[m_counts[key]].erase(m_values[key].itr);
            if(m_countKeyMap[m_counts[key]].empty()) {
                if (m_lowestFrequency == m_counts[key]) {
                    m_lowestFrequency++;
                }
                m_countKeyMap.erase(m_counts[key]);
            }
            m_values[key].value = value;
            m_counts[key]++;
            m_countKeyMap[m_counts[key]].push_front(key);
            m_values[key].itr = m_countKeyMap[m_counts[key]].begin();
        }
    }
};








// LRU que. type variables
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
