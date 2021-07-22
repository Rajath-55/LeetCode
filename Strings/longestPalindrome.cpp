class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string best = "";
        int maxi = 0;
        for(int mid = 0; mid < n; ++mid){
            for(int x = 0; mid - x >=0 and mid + x < n; ++x){
                if(s[mid+x] != s[mid-x]) break;
                int len = 2*x + 1;
                if(len > maxi){
                    maxi = len;
                    best = s.substr(mid - x, len);
                }
            }
        }
        
        for(int mid = 0; mid < n - 1; ++mid){
            for(int x = 1; mid - x + 1 >=0 and mid + x < n; ++x){
                if(s[mid - x + 1] != s[mid +x]){
                    break;
                }
                int len = 2*x;
                if(len > maxi){
                    maxi = len;
                    best = s.substr(mid - x + 1, len);
                }
            }
        }
        return best;
        
        
        
    }
};


/*
brute force approach:
produce all substrings, and check if there is a palindrome
and this takes O(n^3), n^2 substrings, and to check if palindrome

better approach is dynamic programming:

states: dp[i][j] = the length of the longest substring starting at i and ending at j
fill the length 1 and length 2 substrings as the base case:
length 1 will always be a palindrome, and length 2 is if both elements are same

for other things, optimal substructure is that 
there exists a palindrome s, if s[start] = s[end], and the substring exlcuding 
first and last is a palindrome
this is for length >=3;
preprocess length 1 and 2 

dp iteration over lengths as in length 1,2,,....s.size();


filling table like this is length dp, because for length i, checking border values
and then checking if the smaller substring is calculated is done in constant time

dp time complexity = O(N^2);


*/
