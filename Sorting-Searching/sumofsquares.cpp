class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_set<long long >s;
        
        for(long int i=0;i*i<=c; ++i){
            s.insert(i*i);
        }
        for(long int i=0;i*i<=c;++i){
            if(s.find(c-i*1ll*i)!=s.end()) return true;
        }
            
        return false;
    }
    
    
    
};