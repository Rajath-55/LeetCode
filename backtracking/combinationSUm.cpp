class Solution {
public:
    vector<vector<int>>res;
    
    
    void backtrack(vector<int>&curr, vector<int>&candidates, int start,int target){
        if(start >= candidates.size()) return;
        if(target == 0){
            res.push_back(curr);
            return;
        }
        if(target < 0) return;
        
        for(int i = start; i < candidates.size(); ++i){
            curr.push_back(candidates[i]);
            backtrack(curr, candidates, i, target - candidates[i]);
            curr.pop_back();
        }
    }
   
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>curr;
        backtrack(curr, candidates, 0,target);
        return res;
    }
};
