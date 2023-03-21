int kadane(std::vector<int> &v) {
    int max_num = *max_element(v.begin(), v.end());

    // if the array contains all negative values, return the maximum element
    if (max_num < 0) {
        return max_num;
    }
    int maxSoFar = 0;
    int mx = 0;
    for (auto i : v) {
        maxSoFar = max(maxSoFar + i, 0);
        mx = max(mx, maxSoFar);
    }
    return mx;
}
