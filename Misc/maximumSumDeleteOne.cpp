class Solution {
public:
    int maximumSum(vector<int>& a) {
        int prevNotDeleted = a[0];
        int prevDeleted = 0;
        int maxi = a[0];
        int n = a.size();
        for(int i=1; i<n; i++)
        {
            prevDeleted = max(prevNotDeleted, prevDeleted+a[i]);
            prevNotDeleted = max(prevNotDeleted+a[i], a[i]);
            maxi = max(maxi, max(prevNotDeleted, prevDeleted));
        }
        return maxi;
    }
};
/*
Kadanes algorithm modification
every element, check if deleting that and computing max subarray sum is greater than
not deleting that and computing max subarray sum;

*/
