int solve(int* a, int n, int B) {
    int xr = 0;
    map<int, int> mpp; 
    mpp[xr]++; 
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        xr = xr ^ a[i];
        int x = xr ^ k;
        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;
}
