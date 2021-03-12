int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    vector<int>xorArr(n,0);
    unordered_map<int,int>mp;
    xorArr[0] = A[0];
    for(int i=1;i<A.size();++i) xorArr[i] = xorArr[i-1]^A[i];
    
    int ans = 0;
    int temp;
    for(int i=0;i<n;++i){
        temp = B^xorArr[i];
        if(xorArr[i]==B) ans++;
        ans+=mp[temp];
        mp[xorArr[i]]++;
    }
    return ans;
}
