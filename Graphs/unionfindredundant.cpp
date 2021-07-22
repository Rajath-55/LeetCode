class Solution {
public:
    
    int find(int a, vector<int>&parent){
        if(parent[a] == -1) return a;
        return find(parent[a], parent);
    }
    
    bool myunion(int a, int b, vector<int>&parent){
        int p = find(a, parent);
        int q = find(b, parent);
        
        if(p==q) return true;
        parent[p] =  q;
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       vector<int>parent(edges.size() + 1, -1);
       
        
        for(auto x : edges){
            if(myunion(x[0], x[1], parent)){
                return x;
            }
        }
        return edges[0];
        
        
    }
};
