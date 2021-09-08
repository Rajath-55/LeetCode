class Solution {
public:
   
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>distances(n, vector<int>(n, 10001));
        for(auto x : edges){
            distances[x[0]][x[1]] = x[2];
            distances[x[1]][x[0]] = x[2];
        }
        for(int i= 0; i < n; ++i){
            distances[i][i] = 0;
        }
        for(int k = 0; k < n; ++k){
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
                }
            }
        }
        int res = INT_MAX;
        int city = -1;
        for(int i = 0; i < n; ++i){
            int temp = 0;
            for(int j = 0; j < n; ++j){
                if(distances[i][j] <= distanceThreshold) temp++;
            }
            if(temp <= res){
                res = temp;
                city = i;
            }
        }
        return city;
    }
};
/*
floyd warshall all pairs shortest path code
basically



*/
