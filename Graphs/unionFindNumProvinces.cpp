class Solution {
public:
    int get_parent(int a, vector<int>& parent)
    {
        if(parent[a]==-1)
            return a;
        return parent[a] = get_parent(parent[a],parent);
    }
    
    void join(vector<vector<int>>& a, int i, int j, vector<int>& parent, vector<int>& rank)
    {
        int x=get_parent(i, parent); 
        int y=get_parent(j, parent);
        if(x==y)
            return;
        if(rank[x]>rank[y])
        {
            parent[y]=x;
            rank[x]+=rank[y];
            return;
        }
        parent[x]=y;
        rank[y]+=rank[x];
    }
    
    int findCircleNum(vector<vector<int>>& a) {
        int n=a.size(), cnt=0;
        vector<int> parent(n,-1);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(a[i][j]==1)
                {
                    rank[i]=1;
                    rank[j]=1;                    
                    join(a, i, j, parent, rank);
                }
            }
        }
        for(int i=0;i<n;i++)
            if(parent[i]==-1)
                cnt++;
        return cnt;
    }
};
