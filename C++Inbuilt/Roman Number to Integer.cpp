// https://www.geeksforgeeks.org/converting-roman-numerals-decimal-lying-1-3999/
// https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1


/*
Input: IX
Output: 9
IX is a Roman symbol which represents 9 

Input: XL
Output: 40
XL is a Roman symbol which represents 40

Input: MCMIV
Output: 1904
M is a thousand, 
CM is nine hundred and 
IV is four
*/


class Solution {
  public:
    int value(char r) {
        if (r == 'I')
            return 1;
        if (r == 'V')
            return 5;
        if (r == 'X')
            return 10;
        if (r == 'L')
            return 50;
        if (r == 'C')
            return 100;
        if (r == 'D')
            return 500;
        if (r == 'M')
            return 1000;
     
        return -1;
    }
    
    int romanToDecimal(string &str) {
        int res = 0;
        
        for (int i = 0; i < str.length(); i++) {
            // Getting value of symbol s[i]
            int s1 = value(str[i]);
     
            if (i + 1 < str.length()) {
                // Getting value of symbol s[i+1]
                int s2 = value(str[i + 1]);
     
                // Comparing both values
                if (s1 >= s2) {
                    // Value of current symbol is greater or equal to the next symbol
                    res = res + s1;
                }
                else {
                    // Value of current symbol is less than the next symbol
                    res = res + s2 - s1;
                    // increment i since next symbol is used
                    i++;
                }
            } else {
                res = res + s1;
            }
        }
        return res;
    }
};
