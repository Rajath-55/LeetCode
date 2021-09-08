class Solution {
public:
 
    vector <int> arr;
    int dp[109][109];
 
    int solve(int idx, int jdx, int l, int r) {
        if(idx < 0 || jdx >= arr.size() || idx > jdx)
            return 0;
 
        if(idx == jdx)
            return r - l;
 
        if(dp[idx][jdx] != -1)
            return dp[idx][jdx];
 
        int ans = INT_MAX;
        for(int i = idx; i <= jdx; i++) {
            ans = min(ans, (r - l) + solve(idx, i - 1, l, arr[i]) + solve(i + 1, jdx, arr[i], r));
        }
        return dp[idx][jdx] = ans;
 
    }
 
 
 
    int minCost(int n, vector<int>& cuts) {
 
        memset(dp, -1, sizeof dp);
        sort(cuts.begin(), cuts.end());
        this->arr = cuts;
 
        return solve(0, cuts.size() - 1, 0, n);
    }
};
/*
nice little top down dp approach
sort the cuts first .
where at each point, if we do the cut we split it into two subarrays, each of which can be cut by 
cuts[low-mid - 1] and cuts[mid + 1 to high] if low and high were the parameters send into the solve function.
then the cuts array also is split and we calculate dp[i][j] for every such cut.
