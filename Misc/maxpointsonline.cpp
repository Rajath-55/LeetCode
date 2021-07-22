class Solution {
public:
    int maxPoints(vector<vector<int>>& arr) {
      int n=arr.size();
        if(n==1) return 1;
        unordered_map<double, int> m;
        int ans=0;
        for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
            double slop;
           if(arr[i][1]-arr[j][1]==0) slop=DBL_MAX;
           else{
             slop = (double)(arr[i][0]-arr[j][0])/(arr[i][1]-arr[j][1]);
           }
           if(m.find(slop)==m.end()) m[slop]+=2;
           else m[slop]++;
           ans=max(ans,m[slop]);
           }
         m.clear();
      }
        
   return ans;  
    }
};
