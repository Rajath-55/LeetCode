class Solution {
public:     
    int maxSubarraySumCircular(vector<int>& A) {
        if (A.size() == 1) return A[0];
        int m = kadane(A, 0, A.size(), 1);
        int sum = accumulate(A.begin(), A.end(), 0);
        
        m = max(m, sum + kadane(A, 0, A.size()-1, -1));
        m = max(m, sum + kadane(A, 1, A.size(), -1));
        return m;
    }
    
    int kadane(vector<int>& nums, int i, int j, int s) {
        int ret = INT_MIN, prev = 0, curr = 0;
        for (int idx=i; idx < j; idx++)
            ret = max(ret,  curr = prev = max(s*nums[idx], s*nums[idx]+prev));
        return ret;
    }

};
