class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixProducts(n),suffixProducts(n);
        
        
        for(int i = 0; i < n; ++i){
            if(i == 0){
                prefixProducts[i] = nums[i];
                continue;
            }
            
            prefixProducts[i] = prefixProducts[i-1]*nums[i];
        }
        for(int i = n-1; i >=0 ; --i){
            if(i == n-1){
                suffixProducts[i] = nums[i];
                continue;
            }
            suffixProducts[i] = suffixProducts[i+1]*nums[i];
        }
        vector<int>ans(n);
        for(int i = 0; i < n; ++i){
            cout<<prefixProducts[i] <<" "<< suffixProducts[i]<<"\n";
        }
        for(int i = 0; i < n; ++i){
            if(i == 0){
                ans[i] = suffixProducts[1];
                continue;
            }
            if(i == n-1){
                ans[i] = prefixProducts[n-2];
                continue;
            }
            ans[i] = prefixProducts[i-1]*suffixProducts[i+1];
        }
        return ans;
         
            
    }
};
/*
Perhaps prefixProducts and suffixProducts
*/
