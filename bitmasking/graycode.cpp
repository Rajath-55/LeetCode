class Solution
{

    vector<int> grayCode(int n)
    {
        int num = (1 << n);
        vector<int> res(num);
        for (int i = 0; i < num; i++)
        {
            res[i] = (i ^ (i >> 1));
        }
        return res;
    }
}
