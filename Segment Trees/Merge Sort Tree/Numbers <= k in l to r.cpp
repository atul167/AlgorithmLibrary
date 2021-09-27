// https://www.spoj.com/problems/MKTHNUM/
// https://www.geeksforgeeks.org/merge-sort-tree-for-range-order-statistics/

/*
You were asked to write a new data structure that would be able to return quickly k-th order statistics in the array segment.
That is, given an array a[1 ... n] of different integer numbers, your program must answer a series of questions Q(i, j, k) in the form: 
"What would be the k-th number in a[i ... j] segment, if this segment was sorted?"

For example, consider the array a = (1, 5, 2, 6, 3, 7, 4). 
Let the query be Q(2, 5, 3). 
The segment a[2 ... 5] is (5, 2, 6, 3). 
If we sort this segment, we get (2, 3, 5, 6), the third number is 5, and therefore the answer to the question is 5.
*/


const int N = 1e5 + 5;
int n, m;

int arr[N];
pair<int, int> v[N];
vector<int> st[4 * N];

void build(int si, int ss, int se) {
    if (ss == se) {
        st[si].pb(v[ss].second);
        return;
    }

    int mid = (ss + se) / 2;
    build(2 * si, ss, mid);
    build(2 * si + 1, mid + 1, se);

    merge(all(st[2 * si]), all(st[2 * si + 1]), back_inserter(st[si]));
}

int query(int si, int ss, int se, int qs, int qe, int k) {
    if (ss == se) {
        return st[si].back();
    }

    int mid = (ss + se) / 2;
    int x = upper_bound(all(st[si * 2]), qe) - lower_bound(all(st[si * 2]), qs);
    if (x >= k) {
        return query(si * 2, ss, mid, qs, qe, k);
    } else {
        return query(si * 2 + 1, mid + 1, se, qs, qe, k - x);
    }
}

void solve() {
    int l, r, k;
    cin >> n >> m;
    loop(i, 1, n) {
        cin >> arr[i];
        v[i] = {arr[i], i};
    }

    sort(v + 1, v + n + 1);

    build(1, 1, n);

    while (m--) {
        cin >> l >> r >> k;
        int x = query(1, 1, n, l, r, k);
        cout << arr[x] << endl;
    }
}
