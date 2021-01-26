/*
Just compare the lexicographically smallest and the largest strings, and then
see their common substring basically.
*/


class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string res = "";
        if (strs.empty())
            return res;
        sort(strs.begin(), strs.end());
        string begin = strs[0];
        string end = strs[strs.size() - 1];

        for (int i = 0; i < (int)min(begin.size(), end.size()); ++i)
        {
            if (begin[i] == end[i])
                res += begin[i];
            else
                return res;
        }
        return res;
    }
};