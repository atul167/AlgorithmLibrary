// https://leetcode.com/problems/find-median-from-data-stream/

/*
I keep two heaps:
Max-heap: Left has the smaller half of the numbers.
Min-heap: Right has the larger half of the numbers.
*/


class MedianFinder {
public:
    /** initialize your data structure here. */
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
        if(left.size() > (right.size() + 1)) {
            right.push(left.top());
            left.pop();
        }
        if(left.size() + 1 < right.size()) {
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

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */






class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty()) {
            left.push(num);
        } else if(right.empty()) {
            if(left.top() > num) {
                right.push(left.top());
                left.pop();
                left.push(num);
            } else {
                right.push(num);
            }
        } else {
            if(left.size() == right.size()) {
                if(num <= right.top()) {
                    left.push(num);
                } else {
                    right.push(num);
                }
            }
            else if(left.size() < right.size()) {
                if(num <= right.top()) {
                    left.push(num);
                } else {
                    left.push(right.top());
                    right.pop();
                    right.push(num);
                }
            } else {
                if(num >= left.top()) {
                    right.push(num);
                } else {
                    right.push(left.top());
                    left.pop();
                    left.push(num);
                }
            }
        }
    }
    
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

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
