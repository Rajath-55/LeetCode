class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        for(int i = n - 2; i >= 0; --i){
            for(int j = 0; j < triangle[i].size(); ++j){
                triangle[i][j] = min(triangle[i+1][j], triangle[i+1][j+1]) + triangle[i][j];
            }
        }
        return triangle[0][0];
        
    }
};

/*
    1
   2 3
  4 5 6
 7 8 9 10
11 12 13 14 15

i-1,j and i-1,j-1 wherever valid and minimum of the two is the path sum
lmao





*/
