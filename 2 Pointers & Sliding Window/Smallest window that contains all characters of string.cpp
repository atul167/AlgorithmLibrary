// https://www.geeksforgeeks.org/smallest-window-contains-characters-string/
// https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1


// Length of the smallest sub-string consisting of maximum distinct characters
// Smallest window that contains all characters of string itself


class Solution {
public:
    const int MAX_CHARS = 256;

    string findSubString(string str) {
        int n = str.length();
        if (n <= 1) return str;

        // Count all distinct characters in input str
        set<char> st;
        for (char x : str) st.insert(x);
        int dist_count = st.size();


        int left = 0, start_index = 0, min_len = INT_MAX, count = 0;
        int curr_count[MAX_CHARS] = { 0 };

        for (int right = 0; right < n; right++) {
            curr_count[str[right]]++;

            if (curr_count[str[right]] == 1) count++;

            // if all the characters are matched
            if (count == dist_count) {
                // Try to minimize the window
                // i.e., check if any character is occurring more no. of times than its occurrence in pattern,
                // if yes then remove it from starting and also remove the useless characters.
                while (curr_count[str[left]] > 1) {
                    curr_count[str[left]]--;
                    left++;
                }

                // Update window size
                int cur_window = right - left + 1;
                if (min_len > cur_window) {
                    min_len = cur_window;
                    start_index = left;
                }
            }
        }

        // Return substring starting from start_index
        // and length min_len
        return str.substr(start_index, min_len);
    }
};
