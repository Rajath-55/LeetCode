class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<int,int>ss;
        int count = 0;
        for(auto x : s){
            ss[x]++;
        }
        for(auto x : t){
            ss[x]--;
        }
        
        for(auto x : ss){
            count+=x.second > 0 ? x.second : 0;
        }
        
        return count;
        
       
    }
};

/*
    
    bbb
    aaa
    b:3 a:2
    a:3, c : 1, d : 1
    aaacd
    bbbaa
    
    a:1, b:2
    a:2  b:1
    
    aba
    bab
    
    l:1
    e:2
    t:1
    c:1
    d:1
    o:1
    
    p:1
    e:1
    r:1
    a:1
    c:2
    t:1
    i:1
    
    
    
    
*/
