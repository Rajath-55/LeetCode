class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int>ans;
        int start = 0;
        int num = 1;
        int last = n;
        bool isAlternating = false;
        
        while(start <n){
            if(start == n- k){
                ans.push_back(last--);
                start++;
                continue;
            }
            if(last != n){
                if(isAlternating){
                    ans.push_back(last--);
                }else{
                    ans.push_back(num++);
                }
                isAlternating = !isAlternating;
            }else{
                ans.push_back(num++);
            }
            start++;
            
        }
        return ans;
        
    }
};


/*

add n-k consecutive, then
alternating last next pattern 
O(n) only

*/
