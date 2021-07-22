class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int>res;
        if(nums.size() == 1 ) return nums;
        stack<int>st;
        int i = 0;
        for(int i = 0; i < nums.size(); ++i){
            while(not st.empty() and st.top() > nums[i] and st.size() + nums.size() - i > k) st.pop();
            
            if(st.size() < k) st.push(nums[i]);
        }
        while(not st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
        
        
        
    }
};


/*

3 5 2 6

3 5 


2 4 3 3 5 4 9 6

2 4 3 3 




*/
