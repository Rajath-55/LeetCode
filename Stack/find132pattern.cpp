class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int>st;
        vector<int>minimum(nums.size());
        minimum[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            minimum[i] = min(nums[i], minimum[i-1]);
        }
        
        for(int i = 0; i < nums.size(); ++i){
            while(st.size() && nums[st.top()] <= nums[i]) st.pop();
            if (st.size() && st.top()!=0 && minimum[st.top()-1]<nums[i]) return true;
            st.push(i);
        }
        return false;
        
    }
};

/*

3 1 4 2

3 1 1 1



*/
