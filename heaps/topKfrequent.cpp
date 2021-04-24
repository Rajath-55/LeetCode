struct myComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        return a.second < b.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>res;
        priority_queue<pair<int,int>, vector<pair<int,int> >, myComp>pq;
        unordered_map<int,int>mp;
        for(auto x : nums) mp[x]++;
        
        for(auto x : mp){
            pq.push(make_pair(x.first, x.second));
        }
        
        while(k--){
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
        
        
    }
};
