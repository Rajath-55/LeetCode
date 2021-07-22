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
        return ans;
    }
};

/*
Recursive solution:
It is just that we need to see if at index i, nums[i] can be included in the subset or it cannot 
there are 2 ways and this can be incrementally built in bottom up manenr




*/
