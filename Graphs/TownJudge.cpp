/*
O(NlogN) solution, basically find a node with indegree=N-1 and 
outdegree = 0;
*/

class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        int res = -1;
        if (trust.size() == 0 && N == 1)
            return 1;
        unordered_map<int, int> degrees;
        for (auto x : trust)
        {
            degrees[x[0]]--;
            degrees[x[1]]++;
        }
        for (auto x : degrees)
        {
            if (x.second == N - 1)
                res = x.first;
        }

        return res;
    }
};