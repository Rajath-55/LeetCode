class Solution {
public:
    vector<vector<int>>G;
    int n;
    vector<bool>visited;
    
    void dfs(int i, int &ans){
        visited[i] = true;
        ans++;
        for(auto x : G[i]){
            if(!visited[x])
                dfs(x,ans);
        }
    }
    
    int arrayNesting(vector<int>& nums) {
        vector<vector<int>>adj(nums.size() + 1, vector<int>());
        G = adj;
        n = nums.size();
        int res = INT_MIN;
        visited = vector<bool>(n+1,false);
        for(int i = 0; i < nums.size(); ++i){
            G[nums[i]].push_back(i);
            G[i].push_back(nums[i]);
        }
        for(int i = 0; i < nums.size(); ++i){
            if(!visited[i]){
                int ans = 0;
                dfs(i,ans);
                res = max(res,ans);
                
            }
        }
        
        return res;
        
        
    }
};
