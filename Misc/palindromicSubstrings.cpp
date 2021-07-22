class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        
        int ans = 0;
        
        //expand from i and i, i + 1
        for(int i = 0; i < n; ++i){
            int start = i, end = i;
            while(start >=0 and end < n and s[start--] == s[end++]) ans++;
            start = i, end = i + 1;
            while(start >=0 and end < n and s[start--] == s[end++]) ans++;
        }
        return ans;
        
    }
};
