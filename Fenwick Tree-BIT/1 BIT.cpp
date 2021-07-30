// https://youtu.be/9uaXG62Y8Uw
// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/tutorial/

int BIT[1000], a[1000];

void update(int i, int val) {
    while(i <= n) {
        BIT[i] += val;
        i += (i&-i);
    }
}

int query(int i) {
    int sum = 0;
    while(i > 0) {
        sum += BIT[i];
        i -= (i&-i);
    }
    return sum;
}

void solve() {
    cin >> n;
    loop(i, 1, n) {
    	cin >> a[i];
    	update(i, a[i]);
    }

    cout << "Sum of first 3 elements is: " << query(3) << endl;
} 

/*
Input:
5
1 2 3 4 5

Output:
Sum of first 3 elements is: 6

*/
