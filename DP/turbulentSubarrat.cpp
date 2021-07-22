class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() == 1) return 1;
        if(arr.size() == 2){
            return (arr[0] == arr[1] ? 1 : 2);
        }
        int ans = 0;
        vector<int>comparison;
        for(int i = 1; i < arr.size(); ++i){
            if(arr[i] == arr[i-1])ans++;
        }
        if(ans == arr.size() - 1) return 1;
    
        for(int i = 1; i < arr.size(); ++i){
            if(arr[i] < arr[i-1]){
                comparison.push_back(0);
            }else if(arr[i] > arr[i-1]){
                comparison.push_back(1);
            }else{
                comparison.push_back(-1);
            }
        }
        int maxi = 0, count = 0;
       
        for(int i = 1; i < comparison.size(); ++i){
            if(comparison[i] == 0 and comparison[i-1] == 1){
                count++;
            }else if(comparison[i] == 1 and comparison[i-1] == 0){
                count++;
            }else{
                maxi = max(maxi, count);
                count = 0;
            }
        }
        //last iteration might have increased count till last element to get that max
        maxi = max(maxi, count);
        
        
        return maxi + 2;
        
    }
};

/*
Assign 0 = <
       1 = >
       -1 = =
       
Then sliding window for maximum alternating 0 and 1s.
*/
