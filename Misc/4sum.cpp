class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        set<set<int>>s;
        int n = nums.size();
        for(int i=0; i< n;++i){
            for(int j=i+1;j<n;++j){
                for(int k=j+1;k<n;++k){
                    for(int l=k+1;l<n;++l){
                        if(nums[i] + nums[j] + nums[k] + nums[l] == target){
                            set<int>temp;
                            temp.insert(nums[i]);
                            temp.insert(nums[j]);
                            temp.insert(nums[k]);
                            temp.insert(nums[l]);
                            if(s.find(temp)==s.end()){
                                res.push_back({nums[i], nums[j], nums[k], nums[l]});
                                s.insert(temp);
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    //extended 3sum
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n=nums.size();
        if(n<3)return res;
        sort(nums.begin(),nums.end());
        for(int k=0;k<n-3;k++){
            if(k>0 && nums[k]==nums[k-1])continue; 
            for(int l=k+1;l<n-2;l++){
                if(l>k+1 && nums[l]==nums[l-1])continue;
            int i=l+1,j=n-1;
            while(i<j){
                int sum=nums[i]+nums[j]+nums[k]+nums[l];
                if(sum==target){
                    res.push_back({nums[k],nums[l],nums[i],nums[j]});
                    while(i<j && nums[i]==nums[i+1])i++;
                    while(i<j && nums[j]==nums[j-1])j--;
                    i++;j--;
                }
                else if(sum>target)j--;
                else i++;
            }
            
          }
        
        }
        
        return res;
    }
};
