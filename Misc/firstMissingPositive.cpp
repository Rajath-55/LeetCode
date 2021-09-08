class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //Mark all zero and -ve number as INT_MAX to eliminate them as that doesnt affect our answer
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=0)
            {
                nums[i]=INT_MAX;
            }
        }
        int n=nums.size();
        int ans=n+1;  
        //We will use given array as map and mark -ve (if not already -ve) when we find number [1,n]
        for(int i=0;i<n;i++)
        {
            if(abs(nums[i])-1<n)
            {
                if(nums[abs(nums[i])-1]>0)
                    nums[abs(nums[i])-1]=(-1)*nums[abs(nums[i])-1];
            }
        }
        //Check from first index if number is -ve means i+1 already found in given array else that is the first smallest +ve
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
                continue;
            else
            {
                ans=i+1;
                break;
            }
        }
        return ans;
    }
};
