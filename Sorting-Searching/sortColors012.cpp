class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x : nums) mp[x]++;
        
        int start = 0;
        for(int i = 0; i <=2; ++i){
            while(mp[i]--) nums[start++] = i;
        }
        
    }
};
