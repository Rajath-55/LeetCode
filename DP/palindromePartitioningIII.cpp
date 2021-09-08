class Solution {
public:
    vector<vector<int>>dp,cost;
    
    int getCost(string s){
        int count = 0;
        int start = 0, end = s.length() - 1;
        while(start <= end){
            count += s[start++] != s[end--];
        }
        return count;
    }
    void cacheCosts(string s){
        int n = s.length();
        for(int i = 0; i < n; ++i){
            for(int j = i; j < n; ++j){
                cost[i][j] += getCost(s.substr(i, j - i + 1));
            }
        }
    }
    int partition(string s, int start, int partCount){
        if(partCount == 0) return cost[start][s.size() - 1];
        if(start >= s.size() - 1) return 1000;
        
        if(dp[start][partCount] != -1) return dp[start][partCount];
        int ans = 1000;
        for(int i = start; i < s.size() - 1; ++i){
            ans = min(ans, cost[start][i] + partition(s, i + 1, partCount - 1));
        }
        return dp[start][partCount] = ans;
    }

    int palindromePartition(string s, int k) {
        dp.resize(101, vector<int>(101,-1));
        cost.resize(101, vector<int>(101, 0));
        cacheCosts(s);
        return partition(s, 0, k-1);
    }
};

/*
cache costs to make  i to j a palindrome
and then 
refursively call partition where partition(s, start, no of partitions);


*/
