vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        for(int i = 0; i < row; i++){
            int left = 0, right = col - 1;
            while(left <= right){
                int mid = left + (right - left) / 2;
                int l = mid - 1 >= 0 ? mat[i][mid - 1] : -1;
                int r = mid + 1 < col ? mat[i][mid + 1] : -1;
                int u = i - 1 >= 0 ? mat[i - 1][mid] : -1;
                int d = i + 1 < row ? mat[i + 1][mid] : -1;
                if(l < mat[i][mid] && r < mat[i][mid] && u < mat[i][mid] && d < mat[i][mid] ){
                    return {i, mid};
                }
                if(mat[i][left] > mat[i][mid]){
                    right = mid - 1;
                }
                else left = mid + 1;
            }
        }
        return {-1};
    }
