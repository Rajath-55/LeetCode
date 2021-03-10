<<<<<<< HEAD
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int idx = 0, length = nums.size();
        while(idx < length){
            if(nums[idx] == val){
                nums[idx] = nums[length-1];
                length--;
            }else
                idx++;
        }
        return length;
    }
=======
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int idx = 0, length = nums.size();
        while(idx < length){
            if(nums[idx] == val){
                nums[idx] = nums[length-1];
                length--;
            }else
                idx++;
        }
        return length;
    }
>>>>>>> 673ed86091449e4adc8c32e9546b1b85b39181ad
};