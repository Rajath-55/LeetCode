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


//optimised:
class Solution {
public:
    bool judgeSquareSum(int c) {
       int low = 0, high = sqrt(c);
        while(low<=high){
            if(low*1ll*low + high*1ll*high > c) high--;
            else if(low*1ll*low + high*1ll*high ==c) return true;
            else low++;
        }
        return false;
       
    }
    
    
    
};