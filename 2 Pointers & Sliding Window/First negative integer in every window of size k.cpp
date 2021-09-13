

vector<ll> printFirstNegativeInteger(ll a[], ll n, ll k) {
    deque<ll> dq;
    vector<ll> res;

    for (int i = 0; i < k; i++) {
        if (a[i] < 0) dq.push_back(i);
    }

    if (dq.empty()) {
        res.push_back(0);
    } else {
        res.push_back(a[dq.front()]);
    }

    for (int i = k; i < n; i++) {
        while (!dq.empty() && dq.front() <= (i - k)) {
            dq.pop_front();
        }
        if (a[i] < 0) dq.push_back(i);

        if (dq.empty()) {
            res.push_back(0);
        } else {
            res.push_back(a[dq.front()]);
        }
    }

    return res;
}
