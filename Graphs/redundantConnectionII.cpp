struct DSU {
    vector<int> parent;
    vector<int> size;
    DSU(int n):parent(n),size(n,0) {
        for (int i=0; i<n; ++i) parent[i]=i;
        
    }
    int root(int i) {
        while(parent[i]!=i) i=parent[i];
        return i;
    }
    void join(int ri, int rj) {
        if (size[ri]==size[rj]) {
            parent[ri]=rj;
            size[rj]++;
        } else if (size[ri]<size[rj]) {
            parent[ri] = rj;
        } else {
            parent[rj] = ri;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> indegree(n+1,0);
        vector<vector<int>> adj(n+1);
        for (auto &e: edges) {
            indegree[e[1]]++;
            adj[e[0]].push_back(e[1]);
        }
        vector<int> visited(n+1,0);
        
        vector<int> ans;
            
        function<void(int,int)> dfs=[&](int i, int frm) {
            if (visited[i]==1) {
                ans = {frm,i};
                return;
            }
            if (visited[i]==2) return;
            visited[i]=1;
            for (auto j: adj[i]) {
                dfs(j,i);
            }
            visited[i]=2;
        };
        for (int i=1; i<=n; ++i) {
            if (indegree[i]==0)
                dfs(i,i);
        }
        if (ans.size())
            return ans;
        fill(begin(indegree),end(indegree),0);
        DSU dsu(n+1);
        for (auto e: edges) {
            int ri = dsu.root(e[0]);
            int rj = dsu.root(e[1]);
            indegree[e[1]]++;
            if (indegree[e[1]]>1)
                return e;
            if (ri==rj) {
                return e;
            }
            dsu.join(ri,rj);
        }
        return {};
    }
};
