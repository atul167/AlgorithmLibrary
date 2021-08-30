// https://www.geeksforgeeks.org/minimize-cash-flow-among-given-set-friends-borrowed-money/
// https://youtu.be/Vy5PLlpDoks


/*
Given a number of friends who have to give or take some amount of money from one another. 
Design an algorithm by which the total cash flow among all the friends is minimized. 
*/


// Given the list of M transacations b/w N people, find out the minimum amount of cash flow required to settle it up!
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, u, v, w, poor, x, rich, y;
    cin >> n >> m;

    vector<int> balance(n+1, 0);

    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        //u has to pay v an amount w
        balance[u] -= w;
        balance[v] += w;
    }
    
    multiset<tuple<int, int>> st;
    for(int i = 1; i <= n; i++) {
        if(balance[i] != 0) st.insert(make_tuple(balance[i], i));
    }
       
    int transactions = 0;
    while(!st.empty()) {
        tie(poor, x) = *st.begin(); st.erase(st.begin());
        tie(rich, y) = *st.rbegin(); st.erase(prev(st.end()));
        int amount = min(-poor, rich);
        
        transactions++;
        // poor pays amount "amount" to rich
        printf("%d pays %d amount to %d\n", x, amount, y);
        poor += amount;
        rich -= amount;
        
        if (poor) st.insert(make_tuple(poor, x));
        if (rich) st.insert(make_tuple(rich, y));
    }
    
    cout << transactions << endl;
}
