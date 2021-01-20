class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        set<int> s;
        for (auto x : nums)
            s.insert(x);
        int ans = 1;
        int res = -1;
        while (true)
        {
            if (s.find(ans) != s.end())
            {
                ans++;
            }
            else
            {
                res = ans;
                break;
            }
        }
        return res;
    }
};