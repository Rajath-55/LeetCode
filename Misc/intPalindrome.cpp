class Solution
{
public:
    bool isPalindrome(int x)
    {
        long int rev = 0;
        int r = x;
        if (r < 0)
            return false;
        while (r != 0)
        {
            rev *= 10;
            rev += r % 10;
            r /= 10;
        }
        return rev == x;
    }
};

//1 2 3 2 1