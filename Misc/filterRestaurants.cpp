class Solution {
public:
    static bool compareByRating(const vector<int>& v1, const vector<int>&v2){
        if(v1[1] == v2[1])
            return v1[0] > v2[0];
        return v1[1] > v2[1];
    }
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<int>res;
        vector<vector<int>>firstFilter;
        if(veganFriendly){ 
            for(auto x : restaurants){
                if(x[2]){
                    firstFilter.push_back(x);
                }
            }    
        }else{
            firstFilter = restaurants;
        }
        vector<vector<int>>finalFilter;
        for(auto x : firstFilter){
            if(x[3] <= maxPrice and x[4] <= maxDistance){
                finalFilter.push_back(x);
            }
        }
        sort(finalFilter.begin(), finalFilter.end(), compareByRating);
        for(auto x : finalFilter){
            res.push_back(x[0]);
        }
        return res;
    }
};
