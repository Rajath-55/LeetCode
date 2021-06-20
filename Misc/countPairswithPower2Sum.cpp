class Solution {
    
public:
    const int mod = 1e9 + 7;
   
    int countPairs(vector<int>& deliciousness) {
       vector<int>powers(23,0);
        int power=1;
        for(int i=0;i<=22;i++)
        {
            powers[i]=power;
            power=power*2;
        }
        
        int count=0;
        unordered_map<int,int>mp;
        for(int i=0;i<deliciousness.size();i++)
        {
            for(auto it:powers)
            {
                if(mp.find(it-deliciousness[i])!=mp.end())
                {
                    count=(count+mp[it-deliciousness[i]])%mod;
                }
            }
            mp[deliciousness[i]]++;
        }
        return count%mod;
        
    }
};

/*

1 + 3 = 4
1 + 7 = 8


*/
