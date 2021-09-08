vector<int> Solution::grayCode(int A) {
    int total = 1 << A;
    vector<int>ans(total);
    for(int i = 0; i < total; ++i){
        ans[i] = i^(i >> 1);
    }
    return ans;
}

