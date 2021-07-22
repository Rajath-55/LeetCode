class Solution {
public: 
    int majorityElement(vector<int>& nums) {
        int c=1;
        int element=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==element) c++;
            else {
                if(c==1){
                  element = nums[i];
                    c=1;
                }
                else c--;
            }
        }
        return element;
    }
};
