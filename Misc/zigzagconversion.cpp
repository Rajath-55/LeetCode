class Solution {
public:
    string convert(string s, int numRows) {
        int m = numRows;
        int n = 2*s.length() - 2;
        vector<vector<char>>grid(m, vector<char>(n, ' '));
        int length = s.length();
        int start = 0;
        bool down = true;
        if(numRows == 1 or s.length() == 1) return s;
       
        
        int i = 0, j = 0;
        while(start < length and i < m and i >=0 and j < n and j >=0){
            grid[i][j] = s[start];
            start++;
            if(down){
                if(i == m - 1){
                    down = false;
                    i--;
                    j++;
                }else{
                    i++;
                }
            }else{
                if(i == 0){
                    down = true;
                    i++;
                }else{
                    i--;
                    j++;
                }
            }
        }
        string res = "";
        for(auto x : grid){
            for(auto y : x) if(y != ' ') res+=y;
        }
        return res;
        
    }
};

//down, diagonal upward
//diagonal upward = i-1, j + 1;
//while isValid bla bla that it

