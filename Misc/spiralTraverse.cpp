class Solution {
public:
    vector<vector<int>>ans;
    int sq;
    int currCount;
    
    void recursiveMatrix(int startRow, int startCol, int endRow, int endCol){
        if(startRow > endRow or startCol > endCol) return;
        cout<<startRow<<" "<<startCol<<" "<<endRow<<" "<<endCol<<" "<<currCount<<"\n";
        for(int col = startCol; col <= endCol; ++col){
            ans[startRow][col] = currCount++;
        }
        for(int row = startRow + 1; row <= endRow; ++row){
            ans[row][endCol] = currCount++;
        }
        for(int col = endCol - 1; col >= startCol; --col){
            if(startRow == endRow) break;
            ans[endRow][col] = currCount++;
        }
        for(int row = endRow - 1; row >= startRow + 1; --row){
            if(startCol == endCol) break;
            ans[row][startCol] = currCount++;
        }
        recursiveMatrix(startRow + 1, startCol + 1, endRow - 1, endCol - 1);
    }
    vector<vector<int>> generateMatrix(int n) {
        sq = n*n;
        currCount = 1;
        ans.resize(n, vector<int>(n));
        recursiveMatrix(0, 0, n - 1, n-1);
        return ans;
    }
};

/*

Easy brute force 
keep track of count <= n**2
and start row column wise recursion

one caveat is where there is an odd number of elements in n^2, and youll
need to take care of that

recurse by row start end col start end

*/
