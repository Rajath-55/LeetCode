class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(), 1);
        if(nums.size() == 1) return 1;
        dp[0] = 1;
        
        
        
        for(int i=1; i < nums.size(); ++i){
            int maxiNow = nums[i];
            for(int j = i-1; j >=0; --j){
                if(nums[j] < maxiNow){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        
        
        return *max_element(dp.begin(), dp.end());
    }
};

/*

dp again, with dp[i] = length of the longest
increasing subsequence until i;
state = perfix subsequence in this case.

for an element at nums[i], for all elements before that,
we see if its < nums[i], then at dp[i] = max(dp[j] + 1, dp[i])
We cannot be sure of our answer with just the previous index.
That is why we need to go through all before.
if it were a contiguous thingy then fine.



*/

// N log n solution called "patience sort"
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        int len = 1;
        dp[0] = nums[0];
        for(int i=1; i < n; ++i){
            int index = lower_bound(dp.begin(), dp.begin() + len, nums[i]) - dp.begin();
            if(index == len){
                len++;
            }
            dp[index] = nums[i];
        }
        return len;
    }
};

/*

dp again, with dp[i] = length of the longest
increasing subsequence until i;
state = perfix subsequence in this case.

for an element at nums[i], for all elements before that,
we see if its < nums[i], then at dp[i] = max(dp[j] + 1, dp[i])
We cannot be sure of our answer with just the previous index.
That is why we need to go through all before.
if it were a contiguous thingy then fine.


sort based soluchan;
solution boils down to finding the correct position for yout element
make the ending element the least possible, so that there is 
a higher chance of the next element being greater than the last one
lower bound based sol



*/