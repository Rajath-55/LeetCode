class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int s = 0;
        for (auto& x: nums) {
            s += x;
        }  // Get the sum of all the elements. Each subset sum must be s/k
		
        if (s % k != 0) {
            return false;
        } // Not perfectly divisble by k
		
        int target = s/k;
        return dfs(nums, k, target, 0, 0);
    }
    
    bool dfs(vector<int>& nums, int k, int& target, int currSubsetSum, int index) {
        if (k == 0) {
		// No subsets remaining
            return true;
        }
        
        if (currSubsetSum == target) {
		// The current subset we are filling up has been filled perfectly
		// Decrement k and start over from the first index
            return dfs(nums, k-1, target, 0, 0);
        }
        
        for (int i = index; i < nums.size(); ++i) {
		// Iterate through all the integers and try to fill the current subset at each step
		
            if (nums[i] == 0 or nums[i] + currSubsetSum > target) {
			// We can ignore the zero case - it implies the number is already picked for a different subset
			// We also ignore cases where the current subset would "overflow" if nums[i] enters
                continue;
            }
			
            int temp = nums[i]; 
            nums[i] = 0; // Shows that the number at the ith index has been taken
            if (dfs(nums, k, target, currSubsetSum+temp, i+1)) {
                return true;
            }
            nums[i] = temp; // The backtracking step - "un-take" the number at the ith index since it does not lead to a solution
        }
        
        return false; // This is the case where none of the numbers taken to fill the current subset would lead to a solution
    }
};
