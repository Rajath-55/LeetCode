class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int last = -1;
        unordered_map<char,int>mp;
        for(int i = 0; i < s.size(); ++i){
            if(mp.count(s[i])){
                last = max(last, mp[s[i]]);
            }
            mp[s[i]] = i;
            res = max(res, i - last);
        }
        return res;
    }
};



/*

last = -1; //index
res = 0; // length
unordered_map<char,int>mp;

for(int i = 0;  i < s.size();++i){}

map.count(key) returns 0 if key is not present else returns value

last = index of last character which is in the valid substring


*/
