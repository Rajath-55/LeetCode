class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        int jumps=1;
        
        if(nums[0]==0 || n==1){
            return 0;
        }
        
        int farthest = nums[0];
        int current_end = nums[0];
        
        for(int i=0 ;i<n ;i++){
            if(i==n-1){
                return jumps;
            }
            
            farthest = max( farthest , nums[i] + i);
                if(i==current_end) {
                    jumps++;
                    current_end = farthest;
                }
        }
        return jumps;
    }
};
