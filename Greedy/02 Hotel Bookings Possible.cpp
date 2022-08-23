// https://www.scaler.com/problems/hotel-bookings-possible/

/*
A hotel manager has to process N advance bookings of rooms for the next season. His hotel has K rooms.
Bookings contain an arrival date and a departure date.
He wants to find out whether there are enough rooms in the hotel to satisfy the demand.


Problem Constraints
1 <= N <= 10^6
1 <= K <= 10^6
0 <= arrive[i] <= depart[i] <= 10^8
*/




bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    if (K == 0) return false;
    int n = arrive.size();

    vector<pair<int, int> > vec;
    for (int i = 0; i < n; ++i) {
        vec.push_back({arrive[i], 0});
        vec.push_back({depart[i], 1});
    }

    sort(vec.begin(), vec.end());

    int curActive = 0;
    int res = 0;
    for (int i = 0; i < vec.size(); i++) {
        // arrival
        if (vec[i].second == 0) {
            curActive++;
        } else {
            curActive--;
        }
        res = max(res, curActive);
    }

    return res <= K;
}











bool Solution::hotel(vector<int> &arr, vector<int> &dep, int K) {
    int n = arr.size();
    // Sort arrival and departure vectors
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    // room_needed indicates number of rooms needed at a time
    int room_needed = 1, result = 1;
    int i = 1, j = 0;

    // Similar to merge in merge sort to process all events in sorted order
    while (i < n && j < n) {
        // If next event in sorted order is arrival, increment count of room_needed
        if (arr[i] <= dep[j]) {
            room_needed++;
            i++;
        }
        // Else decrement count of room_needed
        else {
            room_needed--;
            j++;
        }

        result = max(result, room_needed);
    }

    return result <= K;
}








bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    int n = arrive.size();
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
        
    // min heap
    priority_queue<int, vector<int>, greater<int>> heap;

    int rooms = 0;
    heap.push(depart[0]);
    rooms++;

    for (int i = 1; i < n; i++) {
        // use < or <= as per question
        if (arrive[i] <= heap.top()) {
            rooms++;
        } else {
            heap.pop();
        }
        heap.push(depart[i]);
    }

    return rooms <= K;
}
