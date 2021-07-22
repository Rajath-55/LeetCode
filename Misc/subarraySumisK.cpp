class Solution {
public:
    int subarraySum(vector<int>& a, int k) 
    {
        int i,n=a.size(),sum=0,ans=0;
        unordered_map<int,int> A;
        A[0]=1;
        for(i=0;i<n;i++){
            sum+=a[i];
            if(A.find(sum-k)!=A.end()) ans+=A[sum-k];
            A[sum]++;
        }
        return ans;
    }
};
