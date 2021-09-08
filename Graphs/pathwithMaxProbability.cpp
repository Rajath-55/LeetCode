class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        priority_queue<pair<double,int>>pq;
        vector<vector<pair<int,double>>>G(n+1);
        for(int i = 0; i < edges.size(); ++i){
            int a = edges[i][0], b = edges[i][1];
            G[a].push_back({b, succProb[i]});
            G[b].push_back({a, succProb[i]});
        }
        vector<double>shortest(n+1, 0.0);
        shortest[start] = (double)1.0;
        pq.push({shortest[start], start});
        
        while(not pq.empty()){
            auto [weight, src] = pq.top();
            pq.pop();
            
            for(auto x : G[src]){
                if(shortest[x.first] < shortest[src]*x.second){
                    shortest[x.first] = shortest[src]*x.second;
                    pq.push({shortest[x.first], x.first});
                }
            }
            
        }
        return shortest[end];
        
    }
};
/*
dijkstras with a twist?
like, maintain a maxheap instead of a minheap with probabilities.
and then keep changing max probability as youd change in weights 
*/
