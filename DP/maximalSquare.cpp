class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
       int m = matrix.size();
        int n = matrix[0].size();
        
        int arr[m+1][n+1];
        for(int i  = 0;i<=m;i++)
            arr[i][0] = 0;
        for(int i = 0;i<=n;i++)
            arr[0][i] = 0;
        int maxi = 0;
        for(int i = 1;i<=m;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                if(matrix[i-1][j-1] == '0')
                    arr[i][j] = 0;
                else
                { arr[i][j] = 1+min(arr[i-1][j],min(arr[i-1][j-1],arr[i][j-1]));
                  maxi = max(maxi,arr[i][j]);
                }
                
            }
        }
        return maxi*maxi;
        
    }
};
