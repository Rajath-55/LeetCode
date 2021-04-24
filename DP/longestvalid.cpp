class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length()==0) return 0;
        vector<int>dp(s.length()+1,0);
        int res = 0;
        for(int i=1;i<s.length(); ++i){
            if(s[i]==')' && s[i-1] == '('){
                dp[i] = (i > 1 ? dp[i-2] + 2 : 2);
            }else if(s[i]==')' && s[i-1] == ')'){
                if(i - dp[i-1] > 0 && s[i-dp[i-1] - 1] == '('){
                    dp[i] = dp[i-1] + ((i - dp[i-1]) >=2 ? dp[i-dp[i-1] -2] : 0) + 2;
                }
            }
            res = max(res, dp[i]);
        }
        return res;
        
    }
};
