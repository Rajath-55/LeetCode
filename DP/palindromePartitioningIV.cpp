class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<int>dp(n + 1, INT_MAX);
        vector<vector<int>>isPalindrome(n+1, vector<int>(n+1));
        dp[n] = 0;
        dp[n-1] = 0;
        for(int i = 0; i < n; ++i){
            int start = i, end = i;
            while(start >=0 and end < n and s[start] == s[end]){
                isPalindrome[start][end] = 1;
                start--;
                end++;
            }
            start = i, end = i + 1;
             while(start >=0 and end < n and s[start] == s[end]){
                isPalindrome[start][end] = 1;
                start--;
                end++;
            }
        }
        
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n - 1; ++j){
                if(isPalindrome[0][i] and isPalindrome[i+1][j] and isPalindrome[j+1][n-1]) return true;
            }
        }
        
        
        return false;
    }
};

/*
preprocessing is the important bit.
preprocess all palindromes in isPalindrome[i][j]
and then for every i, for every j, check if 0 to i, i + 1 to j, and j + 1 to n-1 are palindromes at the same time
if so return true;

*/
