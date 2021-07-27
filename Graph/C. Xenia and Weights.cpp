/*
Xenia has a set of weights and pan scales. Each weight has an integer weight from 1 to 10 kilos. 
Xenia is going to play with scales and weights a little. For this, she puts weights on the scalepans, one by one. 
The first weight goes on the left scalepan, the second weight goes on the right scalepan, 
the third one goes on the left scalepan, the fourth one goes on the right scalepan and so on. 
Xenia wants to put the total of m weights on the scalepans.

Simply putting weights on the scales is not interesting, so Xenia has set some rules. 
First, she does not put on the scales two consecutive weights of the same weight. 
That is, the weight that goes i-th should be different from the (i + 1)-th weight for any i (1 ≤ i < m). 
Second, every time Xenia puts a weight on some scalepan, she wants this scalepan to outweigh the other one. 
That is, the sum of the weights on the corresponding scalepan must be strictly greater than the sum on the other pan.

You are given all types of weights available for Xenia. You can assume that the girl has an infinite number of weights of each specified type. 
Your task is to help Xenia lay m weights on ​​the scales or to say that it can't be done.

Input:
The first line contains a string consisting of exactly ten zeroes and ones: 
the i-th (i  ≥  1) character in the line equals "1" if Xenia has i kilo weights, otherwise the character equals "0". 
The second line contains integer m (1 ≤ m ≤ 1000).

Output
In the first line print "YES", if there is a way to put m weights on the scales by all rules. Otherwise, print in the first line "NO". 
If you can put m weights on the scales, then print in the next line m integers — the weights' weights in the order you put them on the scales.
If there are multiple solutions, you can print any of them.

Examples:

Input:
0000000101
3

Output:
YES
8 10 8
*/


int res[1005], weight[2];
string str;

void dfs(int i) {
    if(i == m) {
        cout << "YES" << endl;
        for(int j = 0; j < m; j++) {
            cout << res[j] << ' ';
        }
        exit(0);
    }
    for(int j = 0; j < 10; j++) {
        int num = j+1;
        if(str[j] == '1' and (i == 0 || num != res[i - 1]) and (weight[i % 2] + num > weight[(i + 1) % 2])) {
            res[i] = num;
            weight[i % 2] += num;
            dfs(i + 1);
            weight[i % 2] -= num;
        }
    }
}
 
void solve() {
    cin >> str >> m;
    dfs(0);
    cout << "NO" << endl;
}
