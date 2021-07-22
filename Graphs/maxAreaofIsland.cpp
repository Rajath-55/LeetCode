class Solution {
public:
    vector<pair<int,int>>dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vector<bool>>visited;
    int m,n;
    bool isValid(int i, int j){
        return (i >=0 and j >=0 and i < m and j < n);
    }
    void dfs(int i, int j, int &currArea, vector<vector<int>>grid){
        visited[i][j] = true;  
        currArea+=1;
        for(auto x : dirs){
            int new_i = i + x.first;
            int new_j = j + x.second;
            if(isValid(new_i, new_j) and not visited[new_i][new_j] and grid[new_i][new_j] == 1){
                dfs(new_i, new_j, currArea,grid);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       m = grid.size();
       n = grid[0].size();
        visited.resize(51, vector<bool>(51,false));
        int maxArea = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(not visited[i][j] and grid[i][j] == 1){
                    int temp = 0;
                    dfs(i,j,temp, grid);
                    maxArea = max(maxArea, temp);  
                    
                }
            }
        }
        return maxArea;
        
    }
};


/*
same as first q,
dfs call with areas = count of no of elements in each component
max of those areas is the ans


*/
