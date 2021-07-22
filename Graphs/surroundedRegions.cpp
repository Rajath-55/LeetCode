class Solution {
public:
    int n,m;
    vector<vector<bool>>visited;
    vector<pair<int,int>>dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    
    bool inValid(int i, int j, vector<vector<char>>&board){
        return (i <0 or i >= m or j <0 or j >= n or board[i][j] !='O' or visited[i][j]);
    }
    
    void dfs(int i, int j, vector<vector<char>>&board){
        visited[i][j] = true;
        for(auto x : dirs){
            int new_i = i + x.first;
            int new_j = j + x.second;
            if(!inValid(new_i, new_j, board) and board[i][j] =='O'){
                dfs(new_i, new_j, board);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        visited.resize(m+1, vector<bool>(n+1,false));
        
        for(int i = 0; i < m; ++i){
            if(not visited[i][0] and board[i][0] =='O'){
                dfs(i,0,board);
            }
            if(not visited[i][n-1] and board[i][n-1] == 'O')
                dfs(i,n-1,board);
        }
        for(int i = 0; i < n; ++i){
            if(not visited[0][i] and board[0][i] =='O'){
                dfs(0,i,board);
            }
            if(not visited[m-1][i] and board[m-1][i] == 'O')
                dfs(m-1,i,board);
        }
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] == 'O' and not visited[i][j])
                    board[i][j] ='X';
            }
        }
    }
};

/*
Basically do dfs from the boundary Os and visit all
possible Os like this.
Then whatever Os are unvisited are gonna be surounded regions and 
can be converted to Xs.
