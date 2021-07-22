class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        return (i >=0 and i < m and j >=0 and j < n);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<pair<int,int>>dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        queue<pair<int,int>>q;
        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(mat[i][j] == 1){
                    mat[i][j] = -1;
                }else{
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            for(auto x : dirs){
                int new_i = front.first + x.first;
                int new_j = front.second + x.second;
                if(isValid(new_i, new_j , m, n)){
                    if(mat[new_i][new_j] == -1){
                        mat[new_i][new_j] = mat[front.first][front.second] + 1;
                        q.push({new_i, new_j});
                    }
                }
            }  
        }
        return mat;
        
    }
};
