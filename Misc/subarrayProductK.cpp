class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start = 0, end = 0;
        int curr = 1;
        int n = nums.size();
        int ans = 0;
        
        while(start <=end and end < n){
            curr*=nums[end];
            if(curr < k){
                ans += end - start + 1;
                end++;
                continue;
            }
            while(start <= end and curr >= k){
                curr/=nums[start];
                start++;
            }
            if(start > end and start < n){
                end = start;
                curr = nums[start];
            }
            if(start <=end and curr < k){
                ans += end - start + 1;
            }
            end++;
            
        }
        return ans;
        
    }
};
