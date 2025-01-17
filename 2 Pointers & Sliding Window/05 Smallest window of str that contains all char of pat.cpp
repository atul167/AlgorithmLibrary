// https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1
// https://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/

/*
Given two strings Str and Pat. Find the smallest window in the string Str consisting of all the characters(including duplicates) of the string Pat.  
Return "-1" in case there is no such window present. 
In case there are multiple such windows of same length, return the one with the least starting index. 

Example 1:

Input:
Str = "timetopractice"
Pat = "toc"

Output: 
toprac
// https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1

Explanation: "toprac" is the smallest substring in which "toc" can be found.
*/

class Solution {
public:
    const int MAX_CHARS = 256;
    
    // Function to find the smallest window in the string s consisting of all the characters of string p.
    string smallestWindow (string str, string pat) {
        int n = str.length();
        int m = pat.length();
        if (n < m) return "-1";

        int hash_str[MAX_CHARS] = { 0 };
        int hash_pat[MAX_CHARS] = { 0 };

        for (int i = 0; i < m; i++) 
            hash_pat[pat[i]]++;


        int left = 0, start_index = -1, min_len = INT_MAX, count = 0;

        for (int right = 0; right < n; right++) {
            hash_str[str[right]]++;
            
            if (hash_str[str[right]] <= hash_pat[str[right]])
            count++;

            // if all the characters are matched
            if (count == m) {
                // Try to minimize the window
                while (hash_str[str[left]] > hash_pat[str[left]]) {
                    hash_str[str[left]]--;
                    left++;
                }

                int cur_window = right - left + 1;
                if (min_len > cur_window) {
                    min_len = cur_window;
                    start_index = left;
                }
            }
        }
        
        if(start_index == -1) return "-1";

        // Return substring starting from start_index and length min_len
        return str.substr(start_index, min_len);
    }
};
