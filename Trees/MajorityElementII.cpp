class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>counts;
        vector<int>res;
        for(auto x : nums) counts[x]++;
        
        for(auto x : counts)
            if(x.second > nums.size()/3){
                 res.push_back(x.first);
            }
        return res;
    }
};
