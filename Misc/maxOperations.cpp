class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
       int ans=0;
         unordered_map<int,int> mp;
         for(int i=0; i<nums.size(); i++) mp[nums[i]]++;
         for(int i=0; i<nums.size(); i++) {
              if(mp[nums[i]]>0 && mp[k-nums[i]]>0) {
                  if(nums[i]!=k-nums[i]) {
                     mp[nums[i]]--;
                     mp[k-nums[i]]--;
                     ans++;
                  }else if(mp[nums[i]]>1) {
                      mp[nums[i]]-=2;
                      ans++;
                  }
              }
         }
        return ans;
    }
};
