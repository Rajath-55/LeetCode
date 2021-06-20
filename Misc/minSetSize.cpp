class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>count;
        for(auto x : arr) count[x]++;
        vector<int>res;
        for(auto x : count){
            res.push_back(x.second);
        }
        sort(res.begin(), res.end(), greater<int>());
        int idx = 0,ans=0;
        int size = arr.size();
        int temp = size;
        while(temp > size/2 and idx < size){
            temp-=res[idx];
            idx++;
            ans++;
        }
        return ans;
        
    }
};
