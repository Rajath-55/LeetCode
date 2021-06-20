class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return helper(nums, 0 , nums.size()-1);
    }
    int helper(vector<int>&nums, int start, int end){
        int mid = start + (end - start)/2;
        if(start == end) return end;
        if(nums[mid] > nums[mid+1]) return helper(nums, start, mid);
        else
            return helper(nums,mid+1, end);
            
    }
};
