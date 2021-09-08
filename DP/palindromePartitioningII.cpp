#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int minCut(string s) {
        vector<int>dp(s.size() + 1, INT_MAX);
        dp[s.size()] = 0;
        dp[s.size() - 1] = 0;
        int n = s.size();
        vector<vector<int>>isPalindrome(s.size() + 1, vector<int>(s.size() + 1));
        for(int i = 0; i < n; ++i){
            int start = i, end = i;
            while(start >=0 and end < n and s[start] == s[end]){
                isPalindrome[start][end] = 1;
                start--;
                end++;
            }
            start = i;
            end = i + 1;
            while(start >=0 and end < n and s[start] == s[end]){
                isPalindrome[start][end] = 1;
                start--;
                end++;
            }
            
        }
        //main logic : For every index, go forward from there till the end, if you find a palindrome, the ans for that index = min(ans, 1 + dp[j]) where j is the first index after the palindromic sequence.
        for(int i = n - 2; i >=0; --i){
            int start = i, length = 1;
            dp[i] = min(dp[i], n - i - 1);
            for(int j = i; j < n; ++j){
                if(isPalindrome[i][j]){
                    if(j == n - 1){
                        dp[i] = 0;
                        break;
                    }
                    // cout<<s.substr(i, j - i)<<"\n";
                    dp[i] = min(dp[i], 1 + dp[j + 1]);
                }
            }  
            
        }
        return dp[0];
    }
};

/*

its a dp problem.

brute force would be cut at every index, and find the minimum by recursing
the substrings formed by the cut.
answer would be minimum of all such cuts.

if i cut aabacd

and i cut at a|abacd
then there are two substrings : a, abacd and we can recursively move there.

at every index i, we can store the minimum no of cuts required to make the substring starting from i a palindrome.

let me make a dp of is palindrome and precompute all i, j palindromes.

*/
