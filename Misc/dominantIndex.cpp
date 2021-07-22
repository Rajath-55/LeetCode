class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        bool visited = false;
        int idx = -1;
        for(int i=0; i< nums.size(); ++i){
            if(nums[i] == maxi && !visited){
                visited = true;
                idx = i;
                continue;
                
            } 
            if(2*nums[i] > maxi){
                return -1;
            }
        }
        return idx;
    }
};
