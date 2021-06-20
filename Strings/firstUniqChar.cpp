class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>counts;
        for(auto x : s) counts[x]++;
        
        for(int i=0; i < s.length(); ++i){
            if(counts[s[i]] == 1) return i;
        }
        
        
        return -1;
        
       
    }
};
