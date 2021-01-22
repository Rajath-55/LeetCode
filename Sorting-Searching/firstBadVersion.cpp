// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int left = 1;
        int right = n;
        int ans = 0;
        while (left <= right)
        {
            if (left == right)
            {
                ans = left;
                break;
            }
            int mid = left + ((right - left) / 2);
            if (isBadVersion(mid) == false)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return ans;
    }
};