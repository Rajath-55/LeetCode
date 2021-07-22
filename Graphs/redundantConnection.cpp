class Solution {
public:
    vector<int>parent;
    int find(int u){
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    void set_union(int u, int v){
        int a = find(u);
        int b = find(v);
        if(a!=b) parent[b] = a;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        for(int i = 0; i < n+1; ++i){
            parent[i] = i;
        }
        vector<int>ans;
       
        for(int i = 0; i < n; ++i){
            auto x = edges[i];
            int a = find(x[0]);
            int b= find(x[1]);
            if(a==b){
                ans = x;
            }else{
                set_union(x[0], x[1]);
            } 
            
        }
        return ans;
    
    }
};
/*
This screams union find lmao
the one edge that can be returned is when find(a) == find(b);




*/
