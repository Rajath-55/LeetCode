class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int idx = 0;
        int size = nums.size();
        int res = INT_MAX;
        while(idx < size && res!=0){
            int low = idx+1, high = size - 1;
            while(low < high){
                int temp = nums[idx] + nums[low] + nums[high];
                cout<<temp<<endl;
                if(abs(target - temp) < abs(res)) res = target - temp;
                else if(temp < target) low++;
                else high--;
            }
            idx++;
        }
        return target - res;
        
    }
};


/*

-4 -1 1 2
closestsum = INT_MIN;
if target - currsum < closestsum then closestsum = target - currsum

 

*/
