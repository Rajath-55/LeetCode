class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char, int>mp;
        for(auto x : s) mp[x]++;
        if(k == s.length()) return true;
        if(k > s.length()) return false;
        int countOdd = 0;
        for(auto x : mp) if(x.second&1) countOdd++;
        return countOdd <=k;
    }
};

/*
each palindrome has one odd character at best, and every other character occurs evven no of times.

k pairs, and <=k singles?
truetrue
4
tt rr uu ee

ttttrrrruuuueeee
trtrtrt

*/
