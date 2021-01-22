class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> negatives, res;
        if (nums.size() == 1)
        {
            nums[0] *= nums[0];
            return nums;
        }
        for (auto x : nums)
            if (x < 0)
                negatives.push_back(x);
        for (int i = 0; i < negatives.size(); ++i)
        {
            negatives[i] *= negatives[i];
        }
        int left = -1, right = negatives.size() - 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] >= 0)
            {
                left = i;
                break;
            }
        }
        if (left == -1)
        {
            for (int i = negatives.size() - 1; i >= 0; --i)
            {
                res.push_back(negatives[i]);
            }
            return res;
        }
        for (int i = left; i < nums.size(); ++i)
        {
            nums[i] *= nums[i];
        }
        while (left < nums.size() && right >= 0)
        {
            if (nums[left] > negatives[right])
            {
                res.push_back(negatives[right]);
                right--;
            }
            else
            {
                res.push_back(nums[left]);
                left++;
            }
        }
        if (left < nums.size())
        {
            while (left < nums.size())
            {
                res.push_back(nums[left]);
                left++;
            }
        }
        else if (right >= 0)
        {
            while (right >= 0)
            {
                res.push_back(negatives[right]);
                right--;
            }
        }
        return res;
    }
};


//Best solution
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> ans(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (abs(nums[left]) > abs(nums[right]))
            {
                ans[i] = nums[left] * nums[left];
                left++;
            }
            else
            {
                ans[i] = nums[right] * nums[right];
                right--;
            }
        }
        return ans;
    }
};