class Solution {
public:
    void dfs(int root,vector<vector<int>>isConnected, vector<bool>&visited){
        visited[root] = true;
        for(int i=0; i<isConnected[root].size();++i){
            if(visited[i] == false && isConnected[root][i] == 1){
                dfs(i, isConnected, visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int res = 0;
        vector<bool>visited(isConnected.size(), 0);
        
        for(int i=0; i<isConnected.size(); ++i){
            if(!visited[i]){
                res++;
                dfs(i, isConnected, visited);
            }
        }
        return res;
    }
};
