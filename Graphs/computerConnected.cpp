class Solution {
public:
    vector<int>parent;
    int find(int u){
        if(parent[u] == u) return u;
        return find(parent[u]);
    }
    void set_union(int u, int v){
        int a = find(u);
        int b = find(v);
        if(a==b) return;
        parent[b] = a;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        for(int i = 0; i < n; ++i) parent[i] = i;
        
        if(connections.size() < n - 1) return -1;
        
        for(auto x : connections){
            int u = x[0];
            int v = x[1];
            set_union(u,v);
        }
        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(parent[i] == i) ans++;
        }
        return ans-1;
       
    }
};
/*
Number of extra edges in a cycle must equal the number of connected components -1
how to account for cycles? union find i think is the best way
if find(a) == find(b) then there is a cycle.
count++

*/
