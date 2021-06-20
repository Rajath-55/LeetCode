class Solution {
public: 
    int ans = 0;
    
    void merge(vector<int>&nums1, vector<int>&nums2, vector<int>&nums){
        int invCount = 0;
        int s1 = 0, s2 =0;
        
        while(s1 < nums1.size() and s2 < nums2.size()){
            if(nums1[s1] > (long)2*nums2[s2]){
                ans+=nums1.size() - s1;
                s2++;
            }else{
                s1++;
            }
        }
        s1 = 0; s2 = 0;
        int idx = 0;
        
        while(s1 < nums1.size() and s2 < nums2.size()){
            if(nums1[s1] < nums2[s2]){
                nums[idx++] = nums1[s1++];
            }else{
               nums[idx++] = nums2[s2++];
            }
        }
        if(s1 < nums1.size()){
            while(s1 < nums1.size()){
                nums[idx++] = nums1[s1++];
            }
        }
        if(s2 < nums2.size()){
            while(s2 < nums2.size()){
                nums[idx++] = nums2[s2++];
            }
        }
        
       
    }
    
    vector<int>getInversionCount(vector<int>&nums){
        if(nums.size() > 1){
            int mid = nums.size()/2;
            vector<int>left(nums.begin(), nums.begin() + mid);
            vector<int>right(nums.begin() + mid, nums.end());
            left = getInversionCount(left);
            right = getInversionCount(right);
            merge(left, right, nums);
        }
        return nums;
    }
    
   
    int reversePairs(vector<int>& nums) {
        getInversionCount(nums);
        return ans;
    }
};




/*

merge sort inversion count ?




*/
