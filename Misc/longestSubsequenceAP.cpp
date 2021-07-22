class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        unordered_map<int,int>count;
        int ans=1;
        for(int i = 0; i < arr.size();++i){
            int toFind = arr[i] - difference;
            count[arr[i]] = count[toFind] + 1;
            ans = max(ans, count[arr[i]]);
        }
        return ans;
        
        
    }
};


/*

dp with state i = dp[i] holds the largest length until i;

1 2 3 5 7
1 3 5 7


*/
