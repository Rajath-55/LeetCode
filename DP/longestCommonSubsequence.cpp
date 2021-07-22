class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        vector<vector<int>>dp(len1 + 1, vector<int>(len2 + 1, 0));
        for(int i = 1; i <= len1; ++i){
            for(int j = 1; j <=len2; ++j){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        
        
        
        
        
        return dp[len1][len2];
        
    }
};


/*
state will depend on both the strings
hence it has two parameters
and subsequently its a 2d dp
one parameter to each string
state = i,j i = index of first string, j = index of second
dp[i][j] = LCS if i only ocnsider the prefix til i for first strring and prefix till j for the second string.
thus dp[n-1][m-1] is our answer.

i-1 and j-1 had x , then i,j are same then add 1,
if they are not equal, there is a possibility 

take for example :
abcde
aef
best is ae
the subproblem : We try to look at the lcs for i,j-1 and i-1,j
this is if they are not equal when compared .

NOTE : longest palindromic subsequence -> reverse the string and aply lcs there.
*/
