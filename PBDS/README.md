### ordered_set

```
void solve() {
    ordered_set st;
    st.insert(1);
    st.insert(1);
    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(4);

    // 1 1 1 2 3 4 
    for(int i: st) cout << i << " ";
    cout << endl;

    st.erase(st.find_by_order(st.order_of_key(2)));

    // 1 1 1 3 4 
    for(int i: st) cout << i << " ";
    cout << endl;

    st.erase(st.find_by_order(st.order_of_key(1)));

    // 1 1 3 4 
    for(int i: st) cout << i << " ";
    cout << endl;
}
```
