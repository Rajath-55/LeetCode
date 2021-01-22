class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int maxp = 0;
        int stock = prices[0];
        for (int i = 1; i < n; ++i)
        {
            if (prices[i] > stock)
            {
                maxp = max(maxp, prices[i] - stock);
            }
            else
            {
                stock = prices[i];
            }
        }

        return maxp;
    }
};