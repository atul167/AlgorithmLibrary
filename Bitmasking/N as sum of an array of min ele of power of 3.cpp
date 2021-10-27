/*
Given a positive integer N. Return an array of minimum length whose elements represent the powers of 3 and the sum of all the elements is equal to N.

Input: 13
Output: [1, 3, 9]

Input: 3
Output: [3]

Problem Constraints
1 <= N <= 10^9
*/

vector<int> Solution::solve(int N) {
    vector<int> bits, solution;

    while (N) {
        bits.push_back(N % 3);
        N /= 3;
    }

    for (int i = 0; i < bits.size(); ++i) {
        if (bits[i] != 0) {
            int tmp = 0;
            while (tmp++ < bits[i]) {
                solution.push_back(pow(3, i));
            }
        }
    }
    return solution;
}
