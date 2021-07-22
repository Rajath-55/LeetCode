class Solution {
public:
    bool isValid(int i, int j, int curri, int currj){
        return !(curri >= i || curri < 0 || currj >= j || currj< 0);
    }
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>>die,revive;
        
        for(int i=0; i < board.size(); ++i){
            for(int j = 0; j < board[i].size(); ++j){
                int temp = 0;
                vector<pair<int,int>>neighbours = {{-1,-1}, {-1,0}, {0,-1}, {0,1}, {1,0}, {1,1}, {-1,1}, {1,-1} };
                for(auto x : neighbours){
                    int curri = i + x.first;
                    int currj = j + x.second;
                    if(isValid(row, col, curri, currj)){
                        if(board[curri][currj] == 1){
                            temp++;
                        }
                    }
                }
                if(board[i][j] == 1){
                    if(temp < 2 or temp > 3) die.push_back({i,j});
                }else{
                    if(temp == 3) revive.push_back({i,j});
                }
            }
        }
        
        for(auto x : die){
            board[x[0]][x[1]] = 0;
        }
        for(auto x : revive){
            board[x[0]][x[1]] = 1;
        }
    }
};
