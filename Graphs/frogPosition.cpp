class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) 
    {
        vector<vector<int>>mat(n+1);
        for(auto e:edges)
        {
            mat[e[0]].push_back(e[1]);
            mat[e[1]].push_back(e[0]);
        }
        int time=0;
        vector<bool>vis(n+1,false);
        vis[1]=true;
        queue<pair<int,double>>q;q.push({1,1.0});
        while(!q.empty() && time<=t)
        {
            int size=q.size();
            while(size--)
            {
                int i=q.front().first;
                double p=q.front().second;q.pop();
                if(time==t && i==target)
                {
                    return p;
                }
                double unvisited=0.0;
                for(auto e:mat[i])
                    if(!vis[e])
                        unvisited+=1.0;
                if(time<t && i==target)
                {
                    if(unvisited==0.0)
                        return p;
                    return 0.0;
                }
                for(auto e:mat[i])
                {
                    if(!vis[e])
                    {
                        vis[e]=true;
                        q.push({e,p/unvisited});
                    }
                }
            }
            time++;
        }
        return 0.0;
    }
};

/*
BFS, O(N) and O(N) space
Keep track of time as per level
and if time < given and we found target then return its prob
otherwise do BFS on its vertices
*/
