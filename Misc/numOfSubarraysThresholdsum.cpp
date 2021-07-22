class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int avg = 0;
        int ans = 0;
        for(int i = 0; i < k; ++i){
            avg+=arr[i];
        }
        int t = avg/k;
        if(t >= threshold) ans++;
        
        for(int i = k ; i < arr.size(); ++i){
            avg = avg + arr[i] - arr[i-k];
            if(avg/k >= threshold) ans++;
        }
        
        return ans;
    }
};
