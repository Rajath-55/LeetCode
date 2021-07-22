class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i = 0; i < nums.size(); ++i){
            for(int j = i+1; j< nums.size(); ++j){
                mp[nums[i]*nums[j]]++;
            }
        }
        int ans = 0;
        for(auto x : mp){
            ans+=4*(x.second - 1)*(x.second);
        }
        
        return ans;
    }
};
/*

a*b = c*d

ab is divisible by cd

2*3 2*4 2*6
3*4 3*6
4*6

6:1
8:1
12:2
18:1
24:1

i,j,k,l

pick two 
Keep a map to track all possible pairwise products.
every pairwise product tuple is gonna add 8 combinations 
and nc2 ways to get two of them

*/
