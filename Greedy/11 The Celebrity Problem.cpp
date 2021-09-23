// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

class Solution  {
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) {
        int i = 0, j = n - 1;
        while (i < j) {
            // i knows j, thus i cannot be celebrity
            if (M[i][j] == 1)
                i++;
            // i does not know j, thus j cannot be celebrity
            else
                j--;
        }
        
        // i points to our celebrity candidate
        int candidate = i;
 
        // Now, all that is left is to check that whether
        // the candidate is actually a celebrity i.e: he is
        // known by everyone but he knows no one
        for (i = 0; i < n; i++) {
            if (i != candidate) {
                if (M[i][candidate] == 0 || M[candidate][i] == 1)
                    return -1;
            }
        }
        // if we reach here this means that the candidate
        // is really a celebrity
        return candidate;
    }
};
