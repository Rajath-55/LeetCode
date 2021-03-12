#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res = {-1,-1};
        auto l = lower_bound(nums.begin(), nums.end(), target);
        auto r = upper_bound(nums.begin(), nums.end(), target);
        
        if(l == nums.end() || l == r) return res;
        res[0] = (int) (l - nums.begin());
        res[1] = (int) (r - 1 - nums.begin());
        return res;
    }
    
};