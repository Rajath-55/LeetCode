class Solution {
public:
    vector<vector<int>>G;
    vector<bool>visited;
    void dfs(int u){
        visited[u] = true;
        for(auto x : G[u]){
            if(not visited[x]){
                dfs(x);
            }
        }
    }
    
    bool canReach(vector<int>& arr, int start) {
        G.resize(arr.size() + 1, vector<int>());
        visited.resize(arr.size()+ 1, false);
        vector<int>zeroIndices;
        
        for(int i = 0; i < arr.size(); ++i){
            if(arr[i] == 0) zeroIndices.push_back(i);
            if(i + arr[i] < arr.size()){
                G[i].push_back(i + arr[i]);
            }
            if(i - arr[i] >= 0){
                G[i].push_back(i - arr[i]);
            }
            
        }
       
        if(zeroIndices.size() == 0) return false;
        if(arr[start] == 0) return true;
        dfs(start);
        
        for(auto x : zeroIndices){
            if(visited[x]) return true;
        }
        
        return false;
        
    }
};


/*
dfs only


*/
