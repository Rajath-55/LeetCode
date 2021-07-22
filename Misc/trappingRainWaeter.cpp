class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmax(n,-1);
        vector<int> rmax(n,-1);
        int prev=0;
        for(int i=0;i<n;++i) {
            lmax[i] = max(prev,height[i]);
            prev=lmax[i];
        }
        prev=0;
        for(int i=n-1;i>=0;--i) {
            rmax[i]=max(prev,height[i]);
            prev=rmax[i];
        }
        int water=0;
        for(int i=0;i<n;++i) {
            int h = min(lmax[i],rmax[i]);
            water = water + abs(h-height[i]);
        }
        return water;
        
        
    }
};
/*
Maximum area histogram question written differently
on second thought its not that 
left max and right max prefixes


*/
