class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> res;
        int i = 0, j = n;
        int iorj = 0;
        while (i < n && j < 2 * n)
        {
            if (iorj == 0)
            {
                res.push_back(nums[i]);
                iorj = 1;
                i++;
            }
            else
            {
                res.push_back(nums[j]);
                iorj = 0;
                j++;
            }
        }
        if (i < n)
        {
            while (i < n)
            {
                res.push_back(nums[i]);
                i++;
            }
        }
        if (j < 2 * n)
        {
            while (j < 2 * n)
            {
                res.push_back(nums[j]);
                j++;
            }
        }
        return res;
    }
};