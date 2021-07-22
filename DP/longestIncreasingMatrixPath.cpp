class Solution {
public:
    int n,m;
    int dp[201][201];
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    bool isvalid(int r,int c){
        if(r<0 || r>=n || c<0 || c>=m) return false;
        return true;
    }
    int dfs(int r,int c,vector<vector<int>>& matrix)
    {
        if(r<0 || r>=n || c<0 || c>=m) return 0;
        if(dp[r][c]!=-1) return dp[r][c];
        int ans = 0;
        for(int i=0;i<4;i++)
        {
            int x = r + dx[i];
            int y = c + dy[i];
            if(isvalid(x,y) && matrix[r][c]<matrix[x][y])
            {
                ans = max(ans,1 + dfs(x,y,matrix));
            }
        }
        return dp[r][c] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        n = matrix.size();
        m = matrix[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) dp[i][j] = -1;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(dp[i][j]==-1) dfs(i,j,matrix);
        int ans = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) ans = max(ans,dp[i][j]);
        return ans+1;
    }
};
