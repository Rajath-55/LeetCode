class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int size = nums.size();
        vector<int>res(size, 0);
        
        for(int i = size - 2; i >=0; --i){
            st.push(nums[i]);
        }
        
        for(int i = size - 1; i >=0; --i){
            int ele = nums[i];
            while(not st.empty() and st.top() <= ele)
                st.pop();
            if(st.empty()) res[i] = -1;
            else res[i] = st.top();
            
            st.push(ele);
        }
        return res;
    }
};
