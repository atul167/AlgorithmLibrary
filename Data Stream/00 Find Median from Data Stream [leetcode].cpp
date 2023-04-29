// https://leetcode.com/problems/find-median-from-data-stream/

/*
I keep two heaps:
Max-heap: Left has the smaller half of the numbers.
Min-heap: Right has the larger half of the numbers.
*/

// Method 1
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.size() == right.size()) {
            right.push(num);
            left.push(right.top());
            right.pop();
        } else {
            left.push(num);
            right.push(left.top());
            left.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0;
        } else if(left.size() < right.size()) {
            return right.top();
        } else {
            return left.top();
        }
    }
};


// Method 2
class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty() || (left.top() > num)) 
            left.push(num);
        else 
            right.push(num); 
        
        // rebalance the two halfs to make sure the length difference is no larger than 1
        if(left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
        if(right.size() > left.size() + 1) {
            left.push(right.top());
            right.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0;
        } else if(left.size() < right.size()) {
            return right.top();
        } else {
            return left.top();
        }
    }
};


















// https://leetcode.com/problems/sliding-window-median/
// Sliding Window Median
class Solution {
public:
    using ld = long double;
    multiset<int, greater<int>> left;
    multiset<int> right;
    vector<double> res;
    
    void addEle(int val) {
        if(left.empty() || (*left.begin()) > val) {
            left.insert(val);
        } else {
            right.insert(val);
        }
    }
    
    void reshuffle() {
        if(left.size() > right.size() + 1) {
            right.insert(*left.begin());
            left.erase(left.begin());
        }
        if(right.size() > left.size() + 1) {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
    }
    
    void setAnswer() {
        if(left.size() == right.size()) {
            ld median = ((ld)(*left.begin()) + (ld)(*right.begin())) / 2.0;
            res.push_back(median);
        } else if(left.size() < right.size()) {
            res.push_back(*right.begin());
        } else {
            res.push_back(*left.begin());
        }
    }
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        res.clear();
        left.clear(), right.clear();
        
        
        for(int i = 0; i < k; i++) {
            addEle(nums[i]);
            reshuffle();
            
        }
        setAnswer();
        
        for(int i = k; i < n; i++) {
            int x = nums[i - k];
            if(left.find(x) != left.end()) {
                left.erase(left.find(x));
            } else {
                right.erase(right.find(x));
            }
            reshuffle();
            
            addEle(nums[i]);
            reshuffle();
            
            setAnswer();
        }
        
        return res;
    }
};
