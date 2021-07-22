class Solution {
public:
    unordered_map<int,vector<int>>G;
  
   
    
    int dfs(int i, vector<int>&informTime){
       
        int ans = 0;
        for(auto x : G[i]){
            ans = max(ans, dfs(x, informTime));
        }
        return ans + informTime[i];
        
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for(int i = 0; i < n; ++i) G[i] ={};
        for(int i = 0; i < n; ++i){
            if(manager[i]!=-1)
            G[manager[i]].push_back(i);
        }
       
        int maxi = dfs(headID, informTime);
        return maxi;
    }
};
/*
DFS with keeping track of time needed until then, and taking the maximum of that
*/
