class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start = -1,  temp = -1, ans = 0;
        int i;
        for(i = 0; i < nums.size(); ++i){
            if(nums[i] == 0){
                if(start == -1){
                    start = 0;
                    
                }else{
                    ans = max(i - start - 1, ans);
                    start = temp + 1;
                }
                temp = i;
            }
        }
        if(start == -1) return nums.size() - 1;
        return max(ans, i - start - 1);
    }
};
/*
2 Pointer approach, store where last zero was deleted,store the beginniing of this subarray is and update the length 
*/
