class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int,int>mp;
        for(auto x :nums) mp[x]++;
        bool ans = true;
        
        for(int i = 0; i < nums.size(); ++i){
            if(mp[nums[i]]){
                mp[nums[i]]--;
                int size = 1;
                int start = nums[i];
                while(size!=k){
                    start++;
                    if(mp[start]){
                        mp[start]--;
                        size++;
                    }else{
                       return false;
                    }
                    
                }
                // size = 0;
            }
        }
        return ans;
          
    }
};

/*
sort and hash
then greedily take as many as possible until k
if not possible then exit with false





*/
