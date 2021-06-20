class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int>prefix(nums.size() + 1,0);
        if(nums.size() == 1){
            return (nums[0] >= target) ? 1 : 0;
        }
        
        for(int i = 1; i <= nums.size(); ++i){
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        
        int left = 0, right = 1;
        int ans = INT_MAX;
        
        while(right <= nums.size()){
            if(prefix[right] - prefix[left] < target){
                right++;
                
            }
            if(right > nums.size()) break;
            while(prefix[right] - prefix[left] >= target){
                    ans = min(ans, right - left);
                    left++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
