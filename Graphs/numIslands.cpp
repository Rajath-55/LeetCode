class Solution {
public:
    int m,n;
    vector<pair<int,int>>dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    bool check(int x,int y){
        return (x >=0 and x < m and y >=0 and y < n);
    }
    

    
    void dfs(int i, int j, vector<vector<char>>&grid,vector<vector<bool>>&visited){
        visited[i][j] = true;
        for(auto x : dir){
            int new_i = x.first + i;
            int new_j = j + x.second;
            if(check(new_i, new_j) and grid[new_i][new_j] =='1' and !visited[new_i][new_j] ){
                dfs(new_i, new_j, grid,visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>>visited(301,vector<bool>(301,false));
        for(int i=0; i <grid.size(); ++i){
            for(int j=0; j < grid[i].size(); ++j){
                if(grid[i][j]=='1' and !visited[i][j]){
                    ans++;
                    dfs(i,j,grid,visited);
                }
            }
        }
        return ans;
    }
};



/*

no of connected components where 1 is a directed edge
couple of things to do in a grid based thing:
do a dir based vector in dfs calls it makes it easier



*/
