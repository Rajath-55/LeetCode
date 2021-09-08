class Solution {
public:
    int ans;
    
    void backtrack(vector<int>&vis, int n, int size){
        if(size == n + 1){
            ans++;
            return;
        }
        for(int i = 1; i <= n; ++i){
            if(!vis[i]) continue;
            if(i%size == 0 or size%i == 0){
                vis[i] = 0;
                backtrack(vis, n, size + 1);
                vis[i] = 1;
            }
        }
    }
    
    int countArrangement(int n) {
        vector<int>vis(n + 1, 1);
        ans = 0;
        
        backtrack(vis, n, 1);
        return ans;
    }
};
/*
3  2  1
2 1 3
1 2 3



*/
