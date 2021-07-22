class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int count = 0;
        int idx = 0;
        while(idx < nums.size() - 1){
            count+= min(nums[idx], nums[idx + 1]);
            idx+=2;
        }
        return count;
    }
};
