class Solution {
public:
    int comp;
    map<int, vector<int>> g;
    
    void dfs(int node ,vector<bool> &visited){
        visited[node] = true;
        for(auto i: g[node]){
            if(visited[i]) continue;
            dfs(i, visited);
        }       
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        comp = 0;
        g.clear();
        vector<bool> visited(n, false);

        for(auto p: connections){
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
        }
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                comp++;
                dfs(i, visited);
            }
        }
        if(connections.size() >= n-1) return comp - 1;
        return -1;
        
    }
};
