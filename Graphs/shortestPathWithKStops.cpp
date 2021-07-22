class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        using ip = pair<int, int>;
        vector<vector<ip>> adj(n);
        for (auto& f : flights) adj[f[0]].push_back({f[1], f[2]});
        using arr = array<int, 3>;
        priority_queue<arr, vector<arr>, greater<arr>> pq;
        vector<int> dist(n, INT_MAX);
        pq.push({0, src, 0});
        while (!pq.empty()) {
            auto [cost, node, stops] = pq.top();
            pq.pop();
            if (node == dst) return cost;
            if (stops > k) continue;
            if (dist[node] != INT_MAX && dist[node] < stops) continue;
            dist[node] = stops;
            for (auto& [next, price] : adj[node]) {
                pq.push({cost + price, next, stops + 1});
            }
        }
        return -1;
    }
};
