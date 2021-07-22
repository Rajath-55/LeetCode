class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int lowrow = 0, highrow = m - 1;
        
        while(lowrow <= highrow){
            int mid = lowrow + (highrow - lowrow)/2;
            
            if(matrix[mid][0] <= target and matrix[mid][n-1] >= target){
                int lowCol = 0, highCol = n - 1;
                while(lowCol <= highCol){
                    int midCol = (highCol - lowCol)/2 + lowCol;
                    if(matrix[mid][midCol] == target) return true;
                    else if(matrix[mid][midCol] > target) highCol = midCol - 1;
                    else lowCol = midCol + 1;
                }
                return false;
            }else if(matrix[mid][0] > target){
                highrow = mid - 1;
            }else{
                lowrow = mid + 1;
            }
        }
        return false;
    }
};
