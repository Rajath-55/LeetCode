class Solution {
public:
    vector<vector<int>>ans;
    vector<int>temp;
    void recursion(vector<int>&nums, int idx){
        if(idx == nums.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        recursion(nums, idx + 1);
        temp.pop_back();
        recursion(nums, idx + 1);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1<<n;
        for(int i = 0; i < maxi; ++i){
            int temp = i;
            vector<int>t;
            int j = 0;
            while(temp){
                int lastBit = temp&1;
                if(lastBit){
                    t.push_back(nums[j]);
                }
                j++;
                temp = temp >> 1;
            }
            ans.push_back(t);
        }
        return ans;
    }
};

/*
Both solutions run in O(2^n) time only

Recursive solution:
It is just that we need to see if at index i, nums[i] can be included in the subset or it cannot 
there are 2 ways and this can be incrementally built in bottom up manenr

Iterative solution (Bit masking technique)
for every number in the range 0 to 2^n-1, if the ith bit is set then



*/
