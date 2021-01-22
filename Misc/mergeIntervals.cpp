/*
O(nlogn) with sorting
add the first sorted vector into res, have 2 condition
check if the last element of the last vector in res is >= first element in 
intervals, if so then merge, otherwise just add the vector as is
*/


class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        int n = intervals.size();
        int i = 1;
        while (i < n)
        {

            if (res[res.size() - 1][1] >= intervals[i][0])
            {
                if (res[res.size() - 1][1] < intervals[i][1])
                {
                    res[res.size() - 1][1] = intervals[i][1];
                }
            }
            else
            {
                res.push_back(intervals[i]);
            }
            i++;
        }
        return res;
    }
};