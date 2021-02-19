class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int idx = 0, length = nums.size();
        while(idx < length){
            if(nums[idx] == val){
                nums[idx] = nums[length-1];
                length--;
            }else
                idx++;
        }
        return length;
    }
};