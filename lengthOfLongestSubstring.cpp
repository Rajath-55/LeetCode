class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        map<char, int> last;

        int i = 0;
        int res = 0;
        int end = -1;

        while (i < s.size())
        {

            if (last.find(s[i]) != last.end())
            {
                end = max(last[s[i]], end);
            }
            res = max(res, i - end);
            last[s[i]] = i;
            i++;
        }
        return res;
    }
};