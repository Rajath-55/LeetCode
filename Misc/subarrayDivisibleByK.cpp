class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>remainders;
        int runningSum = 0;
        remainders[0]++;
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i){
            runningSum+=nums[i];
            int rem = runningSum%k;
            if(rem < 0) rem+=k;
            if(remainders.find(rem)!=remainders.end()){
                ans+=remainders[rem];
                remainders[rem]++;
            }else{
                remainders[rem]++;
            }
        }
        return ans;
    }
};

/*
O(N) time ans space;
the idea here is to keep track of reminders;
if reminder in i th pos = r and jth pos = r, 
then j - i sum is divisible by k
and if there were more counts of the same before that then they would also add,
say k < i was there then j - k would also be divisible for all k
keeping counts of remainder occurences, we can get the sums divisible effectively.


*.
