class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(auto &x : nums) if(x ==0) x=-1;
        unordered_map<int,int>preSums;
        int ans = 0, maxUntilNow = 0,preSum = 0;
        for(int i = 0; i < nums.size(); ++i){
            preSum+=nums[i];
            if(preSum == 0) maxUntilNow = i+1;
            else if(preSums.count(preSum)) maxUntilNow = i - preSums[preSum];
            else if(preSums.count(preSum) == 0) preSums[preSum] = i;
            ans = max(ans, maxUntilNow);
        }
        return ans;
    }
};
/*
hashmap solution 
keep track of prefixsums in hashmap
so that if twice the same sum comes, then the diff in indices is the length
for this convert all 0s to -1 to get a sum == 0thing




*/
