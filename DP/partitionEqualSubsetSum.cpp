class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i = 0 ; i < nums.size() ; i++){
            sum+=nums[i];
        }
        if(sum % 2 != 0){
            return false;
        }
        int toFind = sum/2;
        vector<vector<bool>> grid(nums.size()+1 , vector<bool>(toFind+1 , 0));
        grid[0][0]=true;
        for(int i = 1 ; i <= nums.size() ; i++){
            for(int j = 0 ; j <= toFind ; j++){
                if(j == 0){
                    grid[i][j] = true;
                }
                else if(nums[i-1] > j){
                    grid[i][j] = grid[i-1][j];
                }
                else{
                    grid[i][j] = (grid[i-1][j-nums[i-1]] || grid[i-1][j]);
                }
            }
        }
        return grid[nums.size()][toFind];
    }
};

//top down version
class Solution {
public:
    vector<int>dp;
    bool recurse(vector<int>&nums, int start, int target, int currSum){
        if(start >= nums.size()) return target/2 == currSum;
        if(dp[currSum] != -1) return dp[currSum];
        return dp[currSum] = recurse(nums, start + 1, target, currSum + nums[start]) || recurse(nums, start + 1, target, currSum);
        
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        dp.resize(20001, -1);
        for(auto x : nums) total+=x;
        if(total&1) return false;
        return recurse(nums, 0, total, 0);
    }
};

/*
Equal sum subsets
consider the subsets to be A and B
for every element i you can either put it in A or you can put it in B


Since equal sums, they are gonna be = total/2;

0-1 knapsack for sum of 11, weights 1.


*/
