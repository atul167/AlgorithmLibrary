// https://practice.geeksforgeeks.org/problems/queries-on-a-matrix0443/1

/*
You are given a matrix of dimension n*n. All the cells are initially, zero. You are given Q queries, which contains 4 integers a b c d 
where (a,b) is the TOP LEFT cell and (c,d) is the Bottom Right cell of a submatrix. 
Now, all the cells of this submatrix have to be incremented by one. After all the Q queries have been performed. 
Your task is to find the final resulting Matrix.
*/


class Solution {
  public:
    vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries) {
        vector<vector<int>> a(n,vector<int>(n,0));

        // ham har row ke lie 1D array wala logic laga denge seperately
        for(auto it: Queries) {
            int x1 = it[0];
            int y1 = it[1];
            int x2 = it[2];
            int y2 = it[3];
            
            for(int i = x1; i <= x2; i++) {
                a[i][y1]++;
                if(y2 + 1 < n) {
                    a[i][y2 + 1]--;
                }
            }
        }
        
        // ham har row ke lie 1D array wala logic ki tarah add kar denge
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < n; j++) {
                a[i][j] += a[i][j - 1];
            }
        }

        return a;
// https://practice.geeksforgeeks.org/problems/queries-on-a-matrix0443/1

/*
Note : Zero-Based Indexing is used for cells of the matrix. 
*/}


};
