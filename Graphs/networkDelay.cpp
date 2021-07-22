class Solution {
public:
    vector<int>shortest;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    vector<vector<pair<int,int>>>G;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        G.resize(n + 1);
        shortest.resize(n+1, INT_MAX);
        for(auto x : times){
            G[x[0]].push_back({x[1], x[2]});
        }
        shortest[k] = 0;
        pq.push({0,k});
        while(not pq.empty()){
            auto top = pq.top();
            int weight = top.first;
            int vertex = top.second;
            pq.pop();
            for(auto x : G[vertex]){
                if(shortest[x.first] > shortest[vertex] + x.second){
                    shortest[x.first] = shortest[vertex] + x.second;
                    pq.push({shortest[x.first], x.first});
                }
            }
        }
        int maxi = *max_element(shortest.begin() + 1, shortest.end());
        return (maxi == INT_MAX) ? -1 : maxi;
    }
};
/*
Dijksta nothing else
*/
