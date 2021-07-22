class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        
        for(auto x : nums){
            if(i < 2 or nums[i-2] < x){
                nums[i++] = x;
            }
        }
        return i;
    }
};
