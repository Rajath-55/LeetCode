class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> counts;
        for (int i = 0; i < nums.size(); ++i)
            counts[nums[i]] = i;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (counts.count(target - nums[i]) > 0)
                if (counts[target - nums[i]] != i)
                    return {i, counts[target - nums[i]]};
        }
        return {};
    }
};