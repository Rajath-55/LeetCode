class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
       sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int s1 = accumulate(nums1.begin(), nums1.end(),0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);
        
        if(s2 > s1){
            swap(nums1,nums2);
            swap(s1,s2);
        }
        if(s1==s2) return 0;
        int count = 0, diff = s1 - s2;
        int idx1 = nums1.size()-1, idx2 = 0;
        
        
        while((idx1 >=0 || idx2 < nums2.size()) && diff!=0){
            int add = idx2 < nums2.size() ? 6 - nums2[idx2] : -1;
            int sub = idx1 >=0 ? nums1[idx1] - 1 : -1;
            
            if(add > sub){
                diff-=min(diff, add);
                // nums2[idx2]+=min(diff,add);
                idx2++;
            }
            else{
                diff-=min(diff,sub);
                // nums1[idx1]-=min(diff,sub);
                idx1--;
            }
            count++;
        }
        
        return (diff == 0) ? count : -1;
        
      
        
    }
};

/*
[6,6,6,1] 
[3,4]
19 - 7 = 12
2
1 1 4








*/
