class Solution {
public:
    vector<pair<double,vector<int>>>distances;
    
    double getDistance(vector<int>coords){
        double ans = 0;
        ans+=sqrt(coords[0]*coords[0] + coords[1]*coords[1]);
        return ans;
    }
    
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for(auto x : points){
            distances.push_back({getDistance(x),x});
        }
        sort(distances.begin(), distances.end());
        vector<vector<int>>ans;
        for(int i = 0; i < k; ++i)
            ans.push_back(distances[i].second);
        return ans;
    }
};

/*

O(nlogn) complexity;

Basically brute force in this case;

another way with custom compare, smaller code:






*/






class Solution {
public:
    static bool customCompare(const vector<int>&a, const vector<int>&b){
        return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), customCompare);
        vector<vector<int>>ans(points.begin(), points.begin() + k);
        return ans;
        
    }
};
