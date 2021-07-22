class Solution {
    void dfshelper(int i,int j,int n,int m,vector<vector<int>>&grid,int &flag)
    {
        if(i<0||i>=n||j<0||j>=m||grid[i][j]!=0)
        {
            if(i<0||i>=n||j<0||j>=m)flag=1;
            return;
        }
        grid[i][j]=2;
        dfshelper(i-1,j,n,m,grid,flag);
        dfshelper(i+1,j,n,m,grid,flag);
        dfshelper(i,j-1,n,m,grid,flag);
        dfshelper(i,j+1,n,m,grid,flag);
        
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int flag=0,ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
             if(grid[i][j]==0)
             {
             flag=0; 
             dfshelper(i,j,n,m,grid,flag);
             if(!flag)ans++;
             }
            }
        }
        return ans;
    }
};
