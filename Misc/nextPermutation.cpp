class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i, j;
        for(i = n - 2; i >=0; --i){
            if(nums[i] < nums[i+1]) break;
        }
        if(i == -1){
            reverse(nums.begin(), nums.end());
            return ;
        }
        for(j = n - 1; j > i; --j){
            if(nums[j] > nums[i]) break;
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end() );
        return ;
    }
};
/*
Find the first number from the right whose next is > it
then if there is none like that reverse the array and return.
if there is one like that, then find the point where there is a number between the end and i 
which is > nums[i];
swap nums[j] and nums[i]
and reverse from i + 1, to end.
*/
