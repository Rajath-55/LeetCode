class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int visited[1001] = {false};
        for (auto x : arr)
        {
            visited[x] = true;
        }
        int res;
        int temp = k;
        int count = 0;
        for (int i = 1; i < 1001; ++i)
        {
            if (visited[i] == false)
            {
                temp--;
                count++;
            }
            if (count == k)
            {
                res = i;
                break;
            }
        }
        if (temp > 0)
        {
            res += temp - 1;
        }
        return res;
    }
};