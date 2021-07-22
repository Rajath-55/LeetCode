class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<pair<int,int>>env;
        for(auto x : envelopes){  
            env.push_back({x[0],x[1]});   
        }
        sort(env.begin(), env.end());
        vector<int>dp(env.size(), 1);
        if(envelopes.size() == 1) return 1;
        
        dp[0] = 1;
        
        for(int i = 1; i < env.size(); ++i){
            for(int j = 0; j < i; ++j ){
                if(env[i].first <= env[j].first) continue;
                if(env[j].second < env[i].second){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
/*
longest increasing subsequence
but with a caveat that one of the states must be sorted already



*/
