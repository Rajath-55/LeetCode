class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<pair<int,int>>all;
        vector<int>mp(n, 0);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < nums[i].size(); ++j){
                all.push_back({nums[i][j], i});
            }
        }
        sort(all.begin(), all.end());
        int seen = 0, minDiff = INT_MAX;
        vector<int>ans;
        int j = 0;
        //two pointer method moment
        
        for(int i = 0; i < all.size(); ++i){
            mp[all[i].second]++;
            if(mp[all[i].second] == 1){
                seen++;
            }
            if(seen == n){
                if(all[i].first - all[j].first + 1 < minDiff){
                    minDiff = all[i].first - all[j].first + 1;
                    ans = {all[j].first, all[i].first};
                }
            }
            //two pointer logic
            if(seen == n){
                while(seen == n){
                    if(mp[all[j].second] > 1) mp[all[j++].second]--;
                    else break;
                }
                //again heck if ans has changed:
                if(all[i].first - all[j].first + 1 < minDiff){
                    minDiff = all[i].first - all[j].first + 1;
                    ans = {all[j].first, all[i].first};
                }
            }
            
        }
        return ans;
    }
};
/*
Two pointer method;
First, add the elements as pairs with the index associated with them into a 1d array.
sort the array.
keep a map to track each element occuring how many times.
then check count of uniqure elements 
if count == n while count == n and the j element has > 1 times seen remove thta
then check for minimum difference again and updte anwer
*/
