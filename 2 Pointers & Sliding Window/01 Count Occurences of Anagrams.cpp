// https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

/*
Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.

Example:
txt = forxxorfxdofr
pat = for
Output: 
3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.
*/

class Solution {
public:
    int search(string pat, string txt) {
        // code here
        vector<int> freqP(26), freqT(26);
        for (char x : pat) freqP[x - 'a']++;

        int l = 0, res = 0;
        for (int r = 0; r < txt.size(); r++) {
            freqT[txt[r] - 'a']++;
            while (freqT[txt[l] - 'a'] > freqP[txt[l] - 'a']) {
                freqT[txt[l] - 'a']--;
                l++;
            }

            if (freqT == freqP) res++;
        }

        return res;
    }
};
