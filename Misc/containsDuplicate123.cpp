class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        set<int> visited;
        for (auto x : nums)
        {
            if (visited.find(x) != visited.end())
                return true;
            else
                visited.insert(x);
        }
        return false;
    }
};

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> counts;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (counts.count(nums[i]) > 0 && (i - counts[nums[i]]) <= k)
            {
                return true;
            }
            counts[nums[i]] = i;
        }
        return false;
    }
};

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        if (nums.size() <= 1)
            return false;
        multiset<long> s;
        int j = 0;
        t = (long)t;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (i - j > k)
                s.erase(s.find(nums[j++]));
            long lower = (long)nums[i] - t, upper = (long)nums[i] + t;
            auto it = s.lower_bound(lower);
            if (it != s.end() && *it <= upper)
                return true;
            s.insert(nums[i]);
        }
        return false;
    }
};