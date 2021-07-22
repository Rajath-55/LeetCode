class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //board[i] = (i/3)*3 + j/3
        vector<unordered_set<char>>rows(9), cols(9), boards(9);
        for(int i = 0 ; i < 9; ++i){
            for(int j  = 0; j < 9; ++j){
                if(board[i][j] == '.') continue;
                
                char toFind = board[i][j];
                if(rows[i].count(toFind) or cols[j].count(toFind) or boards[(i/3)*3 + j/3].count(toFind)) return false;
                
                rows[i].insert(toFind);
                cols[j].insert(toFind);
                boards[(i/3)*3 + j/3].insert(toFind);
            }
        }
        return true;
    }
};
