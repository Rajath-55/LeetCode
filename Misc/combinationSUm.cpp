class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>res;
        vector<int>dum;
        helper(res,dum,candidates,0,target);
        return res;
    }
     void helper(vector<vector<int>>&res,vector<int>&dum,vector<int>& candidates,int start,int target){
         if(start>=candidates.size())return ;
         if(target==0){
             res.push_back(dum);
         }
         if(target>0){
         for(int i=start;i<candidates.size();i++){
             if(target-candidates[i]<0)break;
             dum.push_back(candidates[i]);
             helper(res,dum,candidates,i,target-candidates[i]);
             dum.pop_back();
            }
         }
     } 
};
