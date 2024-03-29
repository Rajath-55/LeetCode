class Solution {
public:
    #define ll long long
    ll dp[102][102];
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        
        for(int i = cuts.size() - 1; i>=0; --i){
            for(int j = i+1; j < cuts.size(); ++j){
                if(i + 1 < j){
                    dp[i][j] =LLONG_MAX;
                    for(int k = i + 1; k < j; ++k){
                       dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                        
                    }
                    dp[i][j] += cuts[j] - cuts[i];
                    
                }
            }
        }
        
        return dp[0][cuts.size() - 1];
        
    }
};
