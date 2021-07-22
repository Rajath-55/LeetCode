class Solution {
public:
    vector<vector<int>>res;
    unordered_map<int,int>lastIdx;
    void backtrack(vector<int>&candidates, vector<int>&curr, int start, int target){
        
        if(target == 0) res.push_back(curr);
        if(target < 0) return;
        
        //to keep track of whether last accessed candidate is the same as this one keep a prev
        int prev = -1;
        for(int i = start; i < candidates.size(); ++i){
            if(candidates[i] == prev) continue;
            curr.push_back(candidates[i]);
            backtrack(candidates, curr, i + 1, target - candidates[i]);
            curr.pop_back();
            prev = candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>curr;
        sort(candidates.begin(), candidates.end());
        for(int i = 0; i < candidates.size(); ++i){
            lastIdx[candidates[i]] = i;
        }
        backtrack(candidates, curr, 0, target);
        return res;
    }
};

/*

Same as combination sum, except that when you have used a number, you move the start to the 
next greater number in the sorted list.

*/
