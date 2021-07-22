class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int>presums(nums.size() + 1, 0);
        presums[0] = nums[0];
        for(int i = 1; i <= nums.size(); ++i){
            presums[i] = presums[i-1] + nums[i-1];
        }
        int left = 0, right = 1;
        int ans = INT_MAX;
        if(presums[left] == target) return 1;
        while(right <= nums.size()){
            if(presums[right] - presums[left] < target){
                right++;
            }
            if(right > nums.size()) break;
            while(presums[right] - presums[left] >= target){
                ans = min(ans, right - left);
                left++;
            }
        }
        return (ans == INT_MAX ? 0 : ans);
    }
};
/*
Prefix sums, then two pointers
Check if there exists right - left such that prefixsum[right] - [prefixsum[legt]] >= target;

*/
