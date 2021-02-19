#include <bits/stdc++.h>
using namespace std;
string addBinary(string a, string b)

/*
1011
110
110111
011
100 



*/
{
    int carry = 0;
    string res = "";
    int minsize = min(a.size(), b.size());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int i;

    for (i = 0; i < minsize; ++i)
    {
        int r = a[i] - '0', s = b[i] - '0';
        int add = r + s + carry;
        if (add == 2)
        {
            carry = 1;
            res += '0';
        }
        else if (add == 3)
        {
            carry = 1;
            res += '1';
        }
        else if (add == 0)
        {
            carry = 0;
            res += '0';
        }
        else if (add == 1)
        {
            carry = 0;
            res += '1';
        }
    }
    if (i < a.size())
    {
        while (i < a.size())
        {
            int r = a[i] - '0';
            int add = r + carry;
            /*
1011
110
110111
011
100000 
0000001


*/

            if (add == 0)
            {
                res += '0';
                carry = 0;
            }
            if (add == 1)
            {
                res += '1';
                carry = 0;
            }
            if (add == 2)
            {
                res += '0';
                carry = 1;
            }
            i++;
        }
    }
    if (i < b.size())
    {
        while (i < b.size())
        {
            int r = b[i] - '0';
            int add = r + carry;
            if (add == 0)
            {
                res += '0';
                carry = 0;
            }
            if (add == 1)
            {
                res += '1';
                carry = 0;
            }
            if (add == 2)
            {
                res += '0';
                carry = 1;
            }
            i++;
        }
    }
    if (carry == 1)
    {
        res += '1';
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string a = "111011", b = "110";
    string res = addBinary(a, b);
    cout << res << endl;
}