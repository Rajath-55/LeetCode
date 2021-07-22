class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       unordered_map<int, int> mp;
        int cnt = 0, maxAns = 0;
        mp[0] = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1) cnt++;
            else cnt--;
            if(mp.count(cnt)) maxAns = max(maxAns, i - mp[cnt]);
            else mp[cnt] = i;
        }
        return maxAns;
       
    }
};


/*

*/
