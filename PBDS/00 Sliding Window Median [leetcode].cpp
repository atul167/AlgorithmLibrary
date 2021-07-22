#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class Solution {
public:
    #define ld long double
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        ordered_set st;
        vector<double> res;
        
        for(int i = 0; i < k; i++) st.insert(nums[i]);

        if(k % 2) {
            res.push_back(*st.find_by_order(k / 2));
        } else {
            ld x = *st.find_by_order(k / 2) + *st.find_by_order(k/2 - 1);
            res.push_back(x / 2.0); 
        }

        for(int i = k; i < n; i++) {
            st.erase(st.find_by_order(st.order_of_key(nums[i - k])));
            st.insert(nums[i]);
            if(k % 2) {
                res.push_back(*st.find_by_order(k / 2));
            } else {
                ld x = *st.find_by_order(k / 2) + *st.find_by_order(k/2 - 1);
                res.push_back(x / 2.0); 
            }
        }
        
        return res;
    }
};
