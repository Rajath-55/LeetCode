/*
O(n^2), and for each index, check whether left side has a bigger palindrome 
if any, or the right side does.
If you get none, return the first element by itself
*/


class Solution
{
public:
    string longestPalindrome(string s)
    {
        int start = 0, end = 1;
        for (int i = 0; i < s.size(); ++i)
        {
            int j = i, k = i;
            while (j >= 0 && k < s.size())
            {
                if (s[j] != s[k])
                    break;
                if (k - j + 1 > end)
                {
                    start = j;
                    end = k - j + 1;
                }
                j--;
                k++;
            }
            j = i;
            k = i + 1;
            while (j >= 0 && k < s.size())
            {
                if (s[j] != s[k])
                    break;
                if (k - j + 1 > end)
                {
                    start = j;
                    end = k - j + 1;
                }
                j--;
                k++;
            }
        }
        return s.substr(start, end);
    }
};