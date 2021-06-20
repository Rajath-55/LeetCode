class Solution {
public:
    int beautySum(string s) {
        unordered_map<int,int>k;
        long int count = 0;
        
        for(int i=0; i < s.size(); ++i){
            k.clear();
            k[s[i]]++;
            for(int j = i+1 ; j < s.size(); ++j){
                k[s[j]]++;
                int maxi = INT_MIN, mini = INT_MAX;
                for(auto x : k){
                    mini = min(mini, x.second);
                    maxi = max(maxi, x.second);
                }
                count+=maxi - mini;
            }
        }
        return (int)count;
        
    }
};


/*
 aabcb
 a:2
 b:2
 c:1
 
 aabcbaa
 



*/
