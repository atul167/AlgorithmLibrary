/*
Amazon has hired n new employees (n is even). You have to send half of these employees to Bangalore and other half to Hyderabad. 
The cost for each employee for each city is given in a form of array. Find the minimum cost.

Example 1:

         BLR       HYD
         -------------
Emp1     10        30
Emp2     40        20 
Emp3     30        60
Emp4     90        70


Example 2:

         BLR       HYD
         -------------
Emp1     100       300
Emp2     700       1000 

Ans = 1000
*/




// https://stackoverflow.com/questions/47830379/minimum-sum-of-two-arrays-choosing-half-of-the-elements-in-each

bool compare(vector<int>& a, vector<int>& b) {
    return (a[0] - a[1]) < (b[0] - b[1]);
}

void solve() {
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(2));

    for(int i = 0; i < n; i++) {
        cin >> cost[i][0] >> cost[i][1];
    }
    
    sort(cost.begin(), cost.end(), compare);

    int sum = 0;
    for(int i = 0; i < n/2; i++) {
        sum += cost[i][0];
    }
    for(int i = n/2; i < n; i++) {
        sum += cost[i][1];
    }
    cout << sum;
}
