class Solution {
public:
    bool isPossible(vector<int>&nums, int mid, int m){
        int sum = 0;
        int splits = 1;
        for(int i = 0; i < nums.size(); ++i){
            sum +=nums[i];
            if(sum > mid){
                splits++;
                sum = nums[i];
            }
        }
            
        return splits <=m;
    }
    int splitArray(vector<int>& nums, int m) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        
        while(low < high){
            int mid = low + (high - low)/2;
            if(isPossible(nums,mid,m)){
                high = mid;
            }else{
                low = mid + 1;
            }
        }
        return high;
    }
};

/*
minimize the maxsum
binary search in this 
*/
