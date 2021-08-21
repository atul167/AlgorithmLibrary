// https://youtu.be/EuPSibuIKIg

/*
Find number of rectangles from a given set of coordinates. The edges of rectangle should be parallel to coordinate axes.
*/

int n, m;

void solve() {
    int x, y;
    cin >> n;
    vector<pair<int, int>> points;
    f(i, n) {
        cin >> x >> y;
        points.pb({x, y});
    }

    map<pair<int, int>, int> count;
    int res = 0;

    for(auto p: points) {
        for(auto p_above: points) {
            if(p.first == p_above.first && p.second < p_above.second) {
                res += count[{p.second, p_above.second}];
                count[{p.second, p_above.second}]++;
            }
        }
    }

    cout << res;
}

















/*
For every pair of points, say (x1, y1) and (x2, y2) consider it to be the diagonal of some rectangle. 
If there exist points (x1, y2) and (x2, y1) in the initial set then we have found our rectangle. 
It should be noted that there will exist 2 diagonals which will represent the same rectangle so we divide the final answer by 2.
*/

int n, m;

void solve() {
    int x, y;
    cin >> n;

    set<pair<int, int>> points;

    f(i, n) {
        cin >> x >> y;
        points.insert({x, y});
    }

    int res = 0;

    for(auto i = points.begin(); i != points.end(); i++) {
        for(auto j = i; j != points.end(); j++) {
            pair<int, int> p1 = *i;
            pair<int, int> p2 = *j;

            if(p1.first == p2.first || p1.second == p2.second) {
                continue;
            }

            // now p1 and p2 are end points of diagonal
            // thus p3 and p4 should also be end points of diagonal

            pair<int, int> p3 = make_pair(p1.first, p2.second);
            pair<int, int> p4 = make_pair(p2.first, p1.second);

            if(points.find(p3) != points.end() && points.find(p4) != points.end()) {
                ++res;
            }
        }
    }

    cout << res / 2;
}
