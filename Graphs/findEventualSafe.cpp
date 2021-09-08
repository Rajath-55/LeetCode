class Solution{
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
        /*We need to store reverse edges, as we will be traveling
          in reverse from terminal nodes to other nodes*/
        vector<vector<int>> ugraph(graph.size());
        
        //we need a vector to store out answer (all terminal nodes will be pushed initially)
        vector<int> ans;
        
        //A map to store count of non-terminal edges connected to an edge
        // It will be updated sqeuntially as we counter a new terminal edges
        map<int,int> count;
        
        // We need a queue to travel through the edges (BFS)
        queue<int> q;
        
        //Initializing queue with adding terminal edges
        for(int i=0;i<graph.size();i++){
            if(graph[i].size()==0) {
                ans.push_back(i);
                q.push(i);
            }
            count[i] = graph[i].size();
            for(int j=0;j<graph[i].size();j++){
                ugraph[graph[i][j]].push_back(i);
            }
        }
        
        //Now, as we counter a terminal edge we reduce the count (map) all edges directed at it
        // If this becomes zero then all its connected edges are terminal and we then add it to queue and ans
        
        while(!q.empty()){
            int f = q.front(); q.pop();
            for(auto i : ugraph[f]){
                count[i]--;
                if(count[i]==0){
                    ans.push_back(i);
                    q.push(i);
                }
            }
        }
        
        //Sorting before returning
        sort(ans.begin(),ans.end());
        return ans;
    }
};
