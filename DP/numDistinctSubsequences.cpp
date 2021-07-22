class Solution {
    #define ull unsigned long long
public:
    int numDistinct(string s, string t) {
        vector<vector<ull>>dp(s.size() + 1, vector<ull>(t.size() + 1, 0));
        for(int i = 0; i < s.size() + 1; ++i){
            dp[i][0] = 1;
        }
        for(int i = 1; i < s.size() + 1; ++i){
            for(int j = 1; j < t.size() + 1; ++j){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                    
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[s.size()][t.size()];
    }
};

/*
dp[i][j] = length i from s and length j from t, no of subsequence;
empty string is always a subsequence of itself
if chars are equal then you need to add the two cases:
taking one char less from s but same chars in t, and one char less in each
*/

