/*
Basically Kadane's Algorithm, whence we 
keep track of runningSum and globalSum, and then 
take the maximum over the for loop
*/


class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int res = nums[0];
        int runningSum = nums[0];
        for (int i = 1; i < n; ++i)
        {
            runningSum = max(nums[i], runningSum + nums[i]);
            res = max(res, runningSum);
        }
        return res;
    }
};
