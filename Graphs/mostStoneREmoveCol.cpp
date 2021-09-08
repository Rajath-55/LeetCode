class Solution {
public:
    vector<int>vis;
    vector<vector<int>>G;
    void dfs(int i){
        vis[i] = 1;
        for(auto x : G[i]){
            if(not vis[x]){
                dfs(x);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vis.resize(n, 0);
        G.resize(n);
        for(int i = 0; i< n; i++){
            for(int j = i+1; j < n ; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        int count = 0;
        for(int i = 0; i < n; ++i){
            if(not vis[i]){
                count++;
                dfs(i);
            }
        }
        return n - count;
        
        
    }
};
/*
dfs solution

no of connected componets

*/
