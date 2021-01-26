class Solution
{
public:
    int myAtoi(string s)
    {
        bool negative = false, start = false;
        ;
        long long value = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] == ' ') && !start)
            {
                continue;
            }
            else if ((s[i] == '-') && (!start))
            {
                negative = true;
                start = true;
            }
            else if ((s[i] == '+') && (!start))
            {
                start = true;
            }
            else if (!isdigit(s[i]))
            {
                break;
            }
            else
            {
                value = (value * 10) + s[i] - '0';
                if (value > INT_MAX)
                {
                    return (negative) ? INT_MIN : INT_MAX;
                }
                start = true;
            }
        }
        return negative ? -value : value;
    }
};