class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        int m = nums1.size();
        int n = nums2.size();
        int r = m + n;
        double ans = -1;
        int i1 = 0, i2 = 0;
        while (i1 < m && i2 < n)
        {
            if (nums1[i1] < nums2[i2])
            {
                res.push_back(nums1[i1]);
                i1++;
            }
            else
            {
                res.push_back(nums2[i2]);
                i2++;
            }
        }
        if (i1 < m)
        {
            while (i1 < m)
            {
                res.push_back(nums1[i1]);
                i1++;
            }
        }
        else if (i2 < n)
        {
            while (i2 < n)
            {
                res.push_back(nums2[i2]);
                i2++;
            }
        }
        ans = (r & 1) ? static_cast<double>(res[r / 2]) : static_cast<double>(res[r / 2] + res[r / 2 - 1]) / 2;
        return ans;
    }
};