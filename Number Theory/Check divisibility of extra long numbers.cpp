/*
Constraint:
number = consists of upto 1e6 digits without leading zero
divisor = [1, 1e9]
*/

void solve() {
    string number;
    int divisor;
    cin >> number;
    cin >> divisor;
    n = number.size();

    vector<int> remainder(n);
    
    remainder[0] = (number[0] - '0') % divisor;
    for(int i = 1; i < n; i++) {
        remainder[i] = (remainder[i - 1] * 10 + (number[i] - '0')) % divisor;
    }

    if(remainder[n - 1] == 0) {
        cout << number << " is divisible by " << divisor << endl;
    } else {
        cout << number << " is NOT divisible by " << divisor << endl;
    }
}
