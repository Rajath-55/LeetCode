class Solution {
public:
    vector<vector<int>>G;
    vector<int>colors;
    bool bfs(int i){
        queue<int>q;
        q.push(i);
        colors[i] = 0;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for(auto x : G[front]){
                if(colors[x] == -1){
                    colors[x] = 1 - colors[front];
                    q.push(x);
                }else if(colors[x] == colors[front]) return false;
            }
                
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        G.resize(n+1);
        colors.resize(n + 1, -1);
        for(auto x : dislikes){
            G[x[0]].push_back(x[1]);
            G[x[1]].push_back(x[0]);
        }
        for(int i = 1; i < n; ++i){
            if(colors[i] == -1){
                bool res = bfs(i);
                if(not res) return res;
            }
        }
        return true;
        
        
    }
};

/*
BFS with red blue coloring
while doing a bfs (depth wise) if we get the adjacent elements same color it obh
disconnected components might exist so do that also

*/

