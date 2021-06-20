class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // standard kadanes algorithm
        int maxi = -1e6, best = -1e6;
        
        for(int i = 0; i < nums.size(); ++i){
            maxi = max(nums[i], maxi + nums[i]);
            best = max(best, maxi);
        }
        return best;
    }
};
