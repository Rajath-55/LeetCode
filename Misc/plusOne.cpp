class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i)
        {
            int temp = digits[i] + carry;
            if (temp > 9)
            {
                carry = temp / 10;
                digits[i] = temp % 10;
            }
            else
            {
                digits[i] = temp;
                carry = 0;
            }
        }
        if (carry == 1)
        {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};