lower_bound → look for first index where arr[i] ≥ x.
upper_bound → look for first index where arr[i] > x.

int lowerBound(vector<int>& arr, int x) {
    int l = 0, r = arr.size(); // [l, r)
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] < x) l = mid + 1;
        else r = mid;
    }
    return l; // index of first >= x
}

int upperBound(vector<int>& arr, int x) {
    int l = 0, r = arr.size(); // [l, r)
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] <= x) l = mid + 1;
        else r = mid;
    }
    return l; // index of first > x
}
