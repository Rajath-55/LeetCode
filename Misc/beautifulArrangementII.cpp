class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int highest = k + 1 , lowest = 1;
        vector<int>ans(n, 0);
        for(int i = 0; i <=k ; ++i){
            ans[i] = i&1 ? highest-- : lowest++;
        }
        for(int i = k + 1; i <n; ++i){
            ans[i] = i + 1;
        }
        
        return ans;
    }
};
