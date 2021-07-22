class Solution {
public:
    vector<pair<int,int>>dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vector<bool>>visited;
    int m,n;
    bool isValid(int i, int j){
        return (i >=0 and i < m and j >=0 and j < n);
    }
    void dfs(vector<vector<int>>grid, int i, int j){
        visited[i][j] = true;
        for(auto x : dirs){
            int new_i = x.first + i;
            int new_j = x.second + j;
            
            if(isValid(new_i, new_j) and not visited[new_i][new_j] and grid[new_i][new_j] == 1){
                dfs(grid, new_i, new_j);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited.resize(m, vector<bool>(n,false));
        int ans = 0;
        
        for(int i = 0; i < m; ++i){
            if(not visited[i][0] and grid[i][0] == 1)
            dfs(grid, i, 0);
            if(not visited[i][n-1] and grid[i][n-1] == 1)
                dfs(grid, i, n-1);
        }
        for(int i = 0; i < n; ++i){
            if(not visited[0][i] and grid[0][i] == 1)
                dfs(grid, 0, i);
            if(not visited[m-1][i] and grid[m-1][i] == 1)
                dfs(grid, m-1, i);
        }
       
        for(int i = 0; i < m ; ++i){
            for(int j = 0; j < n ; ++j){
                if(grid[i][j] == 1 and not visited[i][j]) ans++;
            }
        }
        
        return ans;
        
    }
};
