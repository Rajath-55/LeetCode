class Solution {
public:
    int m,n;
    int dx[4]={1,0,0,-1};
    int dy[4]={0,1,-1,0};
    vector<vector<bool>>vis;
    bool valid(int i,int j)
    {
        if(i<0 || j<0 || i>=m || j>=n)
            return false;
        return true;
    }
    bool dfs(int i,int j,int pi,int pj,vector<vector<char>>& grid)
    {
        vis[i][j]=true;
        for(int k=0;k<4;k++)
        {
            int x=i+dx[k],y=j+dy[k];
            if(valid(x,y) && grid[x][y]==grid[i][j])
            {
                if(!vis[x][y])
                {
                    if(dfs(x,y,i,j,grid))
                        return true;
                }
                else if(!(x==pi && y==pj))
                    return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) 
    {
        m=grid.size(),n=grid[0].size();
        vis.resize(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j])
                {
                    if(dfs(i,j,-1,-1,grid))
                        return true;
                }
            }
        }
        return false;
    }
};
